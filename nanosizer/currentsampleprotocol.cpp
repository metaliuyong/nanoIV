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
        QString my_current_series_file = QFileDialog::getOpenFileName();
        QFile file {my_current_series_file};
        QTextStream stream {&file};
        if(file.open(QIODevice::ReadWrite)){
            for(int iii = 0; iii < my_time_vector.size(); iii++){
                stream << QString::number(my_time_vector[iii]) << "\t" << QString::number(my_current_vector[iii]) << "\t" << QString::number(my_voltage_vector[iii]) << "\n";
            }
        }
        file.close();
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
    bool my_flag {true};
    while(started_)
    {
        if(my_flag == true){
            my_index = 0;
            my_start_time = timeGetTime();
            my_flag = false;
            my_time_vector.clear();
            my_time_vector.reserve(1024);
            my_current_vector.clear();
            my_current_vector.reserve(1024);
        }
        if(!paused_)
        {
            if(seriesindex_ == 0){
                starttime_ = timeGetTime();
            }
            my_temp_current = Session::MeasureCurrent();

            x_[seriesindex_] = MsToSec(timeGetTime() - starttime_);
            my_time_vector.append(MsToSec(timeGetTime() - my_start_time));
            y_[seriesindex_] = my_temp_current;
            my_current_vector.append(my_temp_current);
            my_voltage_vector.append(Session::GetVoltage());
            seriesindex_ = (seriesindex_ + 1)%serieslength_;

            emit RequestUpdatePlot(0, x_, y_);
            Sleep(SecToMs(period_));
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




