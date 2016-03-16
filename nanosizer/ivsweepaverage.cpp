#include "ivsweepaverage.h"

#include <iostream>

#include "ivsweep.h"


IVSweepAverage::IVSweepAverage(double startvoltage, double endvoltage, double voltageincrement, Direction direction, QCPGraph* parentgraph):
    startvoltage_(startvoltage),
    endvoltage_(endvoltage),
    voltageincrement_(voltageincrement),
    direction_(direction),
    parentgraph_(parentgraph)
{

    totalvoltages_ = static_cast<int>(fabs(endvoltage_ - startvoltage_)/voltageincrement_ + 0.5) + 1;

    xaverage_.resize(totalvoltages_);
    yaverage_.resize(totalvoltages_);


    for(int i = 0; i < totalvoltages_; i++)
    {
        if(direction_ == forward)
        {
            xaverage_[i] = startvoltage_ + i*voltageincrement_;
        }
        else
        {
            xaverage_[i] = startvoltage_ - i*voltageincrement_;
        }

        yaverage_[i] = 0;
    }

}

void IVSweepAverage::UpdateAverage()
{

    int sweepsinaverage = 0;

    for(int j = 0; j < totalvoltages_; j++)
    {
        yaverage_[j] = 0;
    }

    for(unsigned int i = 0; i < sweeplist_.size(); i++)
    {
        if(sweeplist_[i]->includeinaverage() == true && sweeplist_[i]->started())
        {
            sweepsinaverage++;

            for(int j = 0; j < totalvoltages_; j++)
            {
                yaverage_[j] = yaverage_[j] + sweeplist_[i]->y()[j];
            }
        }
    }

    for(int j = 0; j < totalvoltages_; j++)
    {
        yaverage_[j] = yaverage_[j]/sweepsinaverage;
    }


    return;
}

void IVSweepAverage::AddSweepToSweepList(IVSweep* ivsweep)
{
    ivsweep->SetParentAverage(this);
    sweeplist_.push_back(ivsweep);


    return;
}

void IVSweepAverage::RemoveSweepFromSweepList(IVSweep* ivsweep)
{
    for(unsigned int i = 0; i < sweeplist_.size(); i++)
    {
        if(sweeplist_[i]->sweepnumber() == ivsweep->sweepnumber())
        {
            sweeplist_.erase(sweeplist_.begin() + i);
        }
    }

    UpdateAverage();

    return;
}






















double IVSweepAverage::startvoltage()
{
    return startvoltage_;
}

void IVSweepAverage::SetStartVoltage(double startvoltage)
{
    startvoltage_ = startvoltage;
    return;
}

double IVSweepAverage::endvoltage()
{
    return endvoltage_;
}

void IVSweepAverage::SetEndVoltage(double endvoltage)
{
    endvoltage_ = endvoltage;
    return;
}

double IVSweepAverage::voltageincrement()
{
    return voltageincrement_;
}

void IVSweepAverage::SetVoltageIncrement(double voltageincrement)
{
    voltageincrement_ = voltageincrement;
    return;
}

Direction IVSweepAverage::direction()
{
    return direction_;
}

void IVSweepAverage::SetDirection(Direction direction)
{
    direction_ = direction;
    return;
}


QCPGraph* IVSweepAverage::parentgraph()
{
    return parentgraph_;
}

void IVSweepAverage::SetParentGraph(QCPGraph* parentgraph)
{
    parentgraph_ = parentgraph;
    return;
}

std::vector<IVSweep*> IVSweepAverage::sweeplist()
{
    return sweeplist_;
}

QVector<double>& IVSweepAverage::xaverage()
{
    return xaverage_;
}

QVector<double>& IVSweepAverage::yaverage()
{
    return yaverage_;
}

int IVSweepAverage::totalvoltages()
{
    return totalvoltages_;
}

bool IVSweepAverage::save()
{
    return save_;
}

void IVSweepAverage::SetSave(bool save)
{
    save_ = save;
    return;
}

