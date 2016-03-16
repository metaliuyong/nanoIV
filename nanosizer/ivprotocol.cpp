#include "ivprotocol.h"

#include "ivsweepaverage.h"
#include "session.h"
#include "ivsweep.h"
#include "typeconversions.h"
#include "plot.h"

IVProtocol::IVProtocol()
{
    currentsweep_ = NULL;

 }

void IVProtocol::UnpauseRoutine()
{
    paused_ = false;

    return;
}

void IVProtocol::RunRoutine()
{
    Session::EnableVoltageControlMode();

    if(currentsweep_ == NULL)
    {
        emit RequestEndRoutine();
        return;
    }

    emit RequestUpdateProgress(currentsweep_->sweepnumber());

    while(started_)
    {
        if(!paused_)
        {
            RunRoutine_CheckSweep();

            if(!paused_)
            {
                RunRoutine_ChangeVoltage();

                RunRoutine_Pause();

                currentsweep_->AddCurrentMeasurement(Session::MeasureCurrent());

                currentsweep_->parentaverage()->UpdateAverage();

                emit RequestUpdatePlot(currentsweep_->parentgraph(), currentsweep_->x(), currentsweep_->y());

                emit RequestUpdateAveragePlot(currentsweep_->parentaverage()->parentgraph(), currentsweep_->parentaverage()->xaverage(), currentsweep_->parentaverage()->yaverage());

                Sleep(SecToMs(Session::interruptwait()));

                emit RequestCoProtocolUnpause();
            }
        }
    }
    return;
}

void IVProtocol::RunRoutine_CheckSweep()
{
    if(currentsweep_->direction() == forward)
    {
        emit RequestSetPlotStyleActiveForward(currentsweep_->parentgraph());
        emit RequestSetPlotStyleAverageActiveForward(currentsweep_->parentaverage()->parentgraph());
    }
    else
    {
        emit RequestSetPlotStyleActiveReverse(currentsweep_->parentgraph());
        emit RequestSetPlotStyleAverageActiveReverse(currentsweep_->parentaverage()->parentgraph());
    }

    if(currentsweep_->sweepnumber() == sweeplist_.size() - 1 && currentsweep_->finished())
    {
        if(started_)
        {
            started_ = false;
            stopped_ = true;
            paused_ = true;

            Session::SetVoltage(0);
            Session::DisableVoltageControlMode();

            emit RequestUpdateProgress(currentsweep_->sweepnumber() + 1);

            if(currentsweep_->direction() == forward)
            {
                emit RequestSetPlotStyleInactiveForward(currentsweep_->parentgraph());
                emit RequestSetPlotStyleInactiveForward(currentsweep_->parentaverage()->parentgraph());
            }
            else
            {
                emit RequestSetPlotStyleInactiveReverse(currentsweep_->parentgraph());
                emit RequestSetPlotStyleInactiveReverse(currentsweep_->parentaverage()->parentgraph());
            }

            emit RequestEndRoutine();

        }
    }

    else if(currentsweep_->finished())
    {
        if(currentsweep_->direction() == forward)
        {
            emit RequestSetPlotStyleInactiveForward(currentsweep_->parentgraph());
            emit RequestSetPlotStyleAverageInactiveForward(currentsweep_->parentaverage()->parentgraph());
        }
        else
        {
            emit RequestSetPlotStyleInactiveReverse(currentsweep_->parentgraph());
            emit RequestSetPlotStyleAverageInactiveReverse(currentsweep_->parentaverage()->parentgraph());
        }

        currentsweep_ = sweeplist_[currentsweep_->sweepnumber() + 1];

        if(currentsweep_->direction() == forward)
        {
            emit RequestSetPlotStyleActiveForward(currentsweep_->parentgraph());
            emit RequestSetPlotStyleAverageActiveForward(currentsweep_->parentaverage()->parentgraph());
        }
        else
        {
            emit RequestSetPlotStyleActiveReverse(currentsweep_->parentgraph());
            emit RequestSetPlotStyleAverageActiveReverse(currentsweep_->parentaverage()->parentgraph());
        }

        emit RequestUpdateProgress(currentsweep_->sweepnumber());
    }

    return;
}

void IVProtocol::RunRoutine_ChangeVoltage()
{
    emit RequestCoProtocolPause();
    Sleep(SecToMs(Session::interruptwait()));
    Session::SetVoltage(currentsweep_->currentvoltage());
    Sleep(SecToMs(Session::interruptwait()));
    emit RequestCoProtocolUnpause();

    return;
}

void IVProtocol::RunRoutine_Pause()
{

    emit RequestCoProtocolPause();
    Sleep(SecToMs(currentsweep_->pausetime() - Session::interruptwait()));

    return;
}

void IVProtocol::AddSweepToSweepList(float startvoltage, float endvoltage, float voltageincrement, float pausetime)
{
    int totalsweeps = sweeplist_.size();

    QCPGraph* parentgraph = plot_->AddGraph();

    IVSweep* ivsweep = new IVSweep(totalsweeps, startvoltage, endvoltage, voltageincrement, pausetime, parentgraph);
    //
    if(totalsweeps == 0 || currentsweep_ == NULL)
    {
        currentsweep_ = ivsweep;
    }


    sweeplist_.push_back(ivsweep);


    CheckCreateNewSweepAverage(ivsweep);

    AddSweepToSweepAverageSweepList(ivsweep);


    emit RequestAddSweepToSweepTable(*ivsweep);

    emit RequestUpdateProgress(ivsweep->sweepnumber());

    return;
}

void IVProtocol::CheckCreateNewSweepAverage(IVSweep* ivsweep)
{
    bool createsweepaverage = true;

    createsweepaverage = true;


    for(unsigned int j = 0; j < sweepaveragelist_.size(); j++)
    {
        if(EpsilonEqual(ivsweep->startvoltage(), sweepaveragelist_[j]->startvoltage()))
        {
            if(EpsilonEqual(ivsweep->endvoltage(), sweepaveragelist_[j]->endvoltage()))
            {
                if(EpsilonEqual(ivsweep->voltageincrement(), sweepaveragelist_[j]->voltageincrement()))
                {
                    if(ivsweep->direction() == sweepaveragelist_[j]->direction())
                    {
                        createsweepaverage = false;
                    }
                }
            }
        }
    }

    if(createsweepaverage == true)
    {
        double startvoltage = ivsweep->startvoltage();
        double endvoltage = ivsweep->endvoltage();
        double voltageincrement = ivsweep->voltageincrement();
        Direction direction = ivsweep->direction();
        QCPGraph* parentgraph = plot_->AddGraph();

        IVSweepAverage* ivsweepaverage = new IVSweepAverage(startvoltage, endvoltage, voltageincrement, direction, parentgraph);

        sweepaveragelist_.push_back(ivsweepaverage);

        emit RequestAddSweepAverageToSweepAverageTable(*ivsweepaverage);
    }

    return;
}

void IVProtocol::AddSweepToSweepAverageSweepList(IVSweep* ivsweep)
{
    for(unsigned int i = 0; i < sweepaveragelist_.size(); i++)
    {
        if(EpsilonEqual(ivsweep->startvoltage(), sweepaveragelist_[i]->startvoltage()))
        {
            if(EpsilonEqual(ivsweep->endvoltage(), sweepaveragelist_[i]->endvoltage()))
            {
                if(EpsilonEqual(ivsweep->voltageincrement(), sweepaveragelist_[i]->voltageincrement()))
                {
                    if(ivsweep->direction() == sweepaveragelist_[i]->direction())
                    {
                        sweepaveragelist_[i]->AddSweepToSweepList(ivsweep);
                    }
                }
            }
        }
    }

    return;
}

void IVProtocol::DeleteSweep(unsigned int sweepnumber)
{
    IVSweep* ivsweep = sweeplist_[sweepnumber];
    ivsweep->parentaverage()->RemoveSweepFromSweepList(ivsweep);
    CheckRemoveSweepAverageFromSweepAverageTable(ivsweep);


    if(sweepnumber < currentsweep_->sweepnumber())
    {
        DeleteFinishedSweep(sweepnumber);
    }
    else if(sweepnumber == currentsweep_->sweepnumber())
    {
        DeleteCurrentSweep();
    }
    else if(sweepnumber > currentsweep_->sweepnumber())
    {
        DeleteUnfinishedSweep(sweepnumber);
    }



    return;
}

void IVProtocol::CheckRemoveSweepAverageFromSweepAverageTable(IVSweep* ivsweep)
{
    if(ivsweep->parentaverage()->sweeplist().size() == 0)
    {

        emit RequestDeleteSweepAverageFromSweepAverageTable(ivsweep->parentaverage());


        for(unsigned int i = 0; i < sweepaveragelist_.size(); i++)
        {
            if(EpsilonEqual(ivsweep->startvoltage(), sweepaveragelist_[i]->startvoltage()))
            {
                if(EpsilonEqual(ivsweep->endvoltage(), sweepaveragelist_[i]->endvoltage()))
                {
                    if(EpsilonEqual(ivsweep->voltageincrement(), sweepaveragelist_[i]->voltageincrement()))
                    {
                        if(ivsweep->direction() == sweepaveragelist_[i]->direction())
                        {
                            plot_->DeleteGraph(sweepaveragelist_[i]->parentgraph());
                            sweepaveragelist_.erase(sweepaveragelist_.begin() + i);
                        }
                    }
                }
            }
        }
    }
    return;
}


void IVProtocol::DeleteFinishedSweep(unsigned int sweepnumber)
{

    IVSweep* sweeptodelete = sweeplist_[sweepnumber];

    emit RequestDeleteSweepFromSweepTable(sweepnumber);

    for(unsigned int i = sweepnumber + 1; i < sweeplist_.size(); i++)
    {
        sweeplist_[sweepnumber + i]->SetSweepNumber(sweeplist_[sweepnumber + i]->sweepnumber() - 1);
    }


    plot_->DeleteGraph(sweeptodelete->parentgraph());


    sweeplist_.erase(sweeplist_.begin() + sweepnumber);



    return;
}

void IVProtocol::DeleteCurrentSweep()
{

    IVSweep* sweeptodelete = currentsweep_;

    emit RequestDeleteSweepFromSweepTable(currentsweep_->sweepnumber());

    if(currentsweep_->sweepnumber() == sweeplist_.size() - 1)
    {
        currentsweep_ = sweeplist_[sweeplist_.size() - 2];
    }
    else
    {
        currentsweep_ = sweeplist_[currentsweep_->sweepnumber() + 1];
    }

    for(unsigned int i = sweeptodelete->sweepnumber() + 1; i < sweeplist_.size(); i++)
    {
        sweeplist_[sweeptodelete->sweepnumber() + i]->SetSweepNumber(sweeplist_[sweeptodelete->sweepnumber() + i]->sweepnumber() - 1);
    }

    plot_->DeleteGraph(sweeptodelete->parentgraph());
    sweeplist_.erase(sweeplist_.begin() + sweeptodelete->sweepnumber());

    return;
}

void IVProtocol::DeleteUnfinishedSweep(unsigned int sweepnumber)
{
    IVSweep* sweeptodelete = sweeplist_[sweepnumber];

    emit RequestDeleteSweepFromSweepTable(sweepnumber);

    for(unsigned int i = sweepnumber + 1; i < sweeplist_.size(); i++)
    {
        sweeplist_[i]->SetSweepNumber(sweeplist_[i]->sweepnumber() - 1);
    }

    plot_->DeleteGraph(sweeptodelete->parentgraph());
    sweeplist_.erase(sweeplist_.begin() + sweepnumber);

    return;
}

std::vector<IVSweep*>& IVProtocol::sweeplist()
{
    return sweeplist_;
}

std::vector<IVSweepAverage*>& IVProtocol::sweepaveragelist()
{
    return sweepaveragelist_;
}

bool IVProtocol::CheckMatchingParameters(IVSweep* ivsweep1, IVSweep* ivsweep2)
{
    bool matching = false;

    if(!(ivsweep1 == NULL || ivsweep2 == NULL))
    {
        if(ivsweep1->startvoltage() == ivsweep2->startvoltage())
        {
            if(ivsweep1->endvoltage() == ivsweep2->endvoltage())
            {

                if(ivsweep1->voltageincrement() == ivsweep2->voltageincrement())
                {

                    if(ivsweep1->direction() == ivsweep2->direction())
                    {
                        matching = true;
                    }
                }
            }
        }
    }

    return matching;
}

