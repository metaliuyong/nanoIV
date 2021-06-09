#ifndef CURRENTSAMPLEPROTOCOL_H
#define CURRENTSAMPLEPROTOCOL_H

#include <vector>


#include "measurementprotocol.h"

#include "datapoint.h"
#include "plot.h"

class CurrentSampleProtocol: public MeasurementProtocol
{
    Q_OBJECT
public slots:
    void RunRoutine();
    void UnpauseRoutine();

public:
    CurrentSampleProtocol();

    void StopRoutine();

    QVector<double> x_;
    void SetXPoints();
    QVector<double> y_;

    QVector<double> my_time_vector;
    QVector<double> my_current_vector;
    QVector<double> my_voltage_vector;

    void ResizeCurrentTimeSeries(int newserieslength);

    double frequency();
    void SetFrequency(double frequency);

    double period();
    void SetPeriod(double period);

    double seriesduration();
    int serieslength();

private:
    double frequency_;
    double period_;


    double seriesduration_;
    int serieslength_;

    int seriesindex_;

    double starttime_;

    double my_start_time;

    int my_index;

    double my_temp_current;
};

#endif // CURRENTSAMPLEPROTOCOL_H
