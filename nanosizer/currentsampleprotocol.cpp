#include "currentsampleprotocol.h"

#include <iostream>
#include <random>

#include "session.h"
#include "typeconversions.h"
#include "Windows.h"

CurrentSampleProtocol::CurrentSampleProtocol()
{
    ResizeCurrentTimeSeries(100);

    SetFrequency(10);

    seriesindex_ = 0;

}

void CurrentSampleProtocol::StopRoutine()
{
    std::cerr << "??\n";
    if(started_)
    {
        started_ = false;
        stopped_ = true;
        emit RequestEndRoutine();
    }
    return;
}

void CurrentSampleProtocol::UnpauseRoutine()
{
    paused_ = false;


    return;
}

void CurrentSampleProtocol::ResizeCurrentTimeSeries(int newserieslength)
{
    serieslength_ = newserieslength;
    seriesduration_ = serieslength_*period_;

    starttime_ = time(0);

    x_.resize(newserieslength);
    //SetXPoints();
    y_.resize(newserieslength);

    return;
}

void CurrentSampleProtocol::RunRoutine()
{



    while(started_)
    {
        if(!paused_)
        {
            Sleep(SecToMs(period_));
            if(seriesindex_ == 0)
            {
                starttime_ = timeGetTime();
            }
            x_[seriesindex_] = MsToSec(timeGetTime() - starttime_);

            y_[seriesindex_] = Session::MeasureCurrent();
            seriesindex_ = (seriesindex_ + 1)%serieslength_;

            emit RequestUpdatePlot(0, x_, y_);

        }
    }


    return;
}


double CurrentSampleProtocol::frequency()
{
    return frequency_;
}

void CurrentSampleProtocol::SetFrequency(double frequency)
{
    frequency_ = frequency;
    period_ = 1.0/frequency_;
    return;
}

double CurrentSampleProtocol::period()
{
    return period_;
}

void CurrentSampleProtocol::SetPeriod(double period)
{
    period_ = period;
    frequency_ = 1.0/period_;
    return;
}

void CurrentSampleProtocol::SetXPoints()
{
    for(int i = 0; i < serieslength_; i++)
    {
        x_[i] = i;
    }

    return;
}




