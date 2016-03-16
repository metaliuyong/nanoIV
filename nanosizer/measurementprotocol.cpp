#include "measurementprotocol.h"

#include <iostream>

#include "session.h"

MeasurementProtocol::MeasurementProtocol()
{
    started_ = false;
    paused_ = false;
    stopped_ = true;

}

void MeasurementProtocol::StartRoutine()
{
    mutex_.lock();
    started_ = true;
    paused_ = false;
    stopped_ = false;
    mutex_.unlock();

    emit RequestRunRoutine();
    return;
}

void MeasurementProtocol::PauseRoutine()
{
    if(started_)
    {
        paused_ = true;
    }

    return;
}

void MeasurementProtocol::StopRoutine()
{
    if(started_)
    {
        started_ = false;
        stopped_ = true;
        emit RequestEndRoutine();
    }


    Session::DisableVoltageControlMode();
    return;
}

void MeasurementProtocol::PauseCoProtocolRoutine()
{
    emit RequestCoProtocolPause();

    return;
}



//////////////
//GetSet below
//////////////


bool MeasurementProtocol::started()
{
    return started_;
}

bool MeasurementProtocol::paused()
{
    return paused_;
}

bool MeasurementProtocol::stopped()
{
    return stopped_;
}

void MeasurementProtocol::SetCoProtocol(MeasurementProtocol* coprotocol)
{
    coprotocol_ = coprotocol;

    return;
}

MeasurementProtocol* MeasurementProtocol::coprotocol()
{
    return coprotocol_;
}


void MeasurementProtocol::SetPlot(Plot* plot)
{
    plot_ = plot;
    return;
}

Plot* MeasurementProtocol::plot()
{
    return plot_;
}
