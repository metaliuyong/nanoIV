#ifndef MEASUREMENTPROTOCOL_H
#define MEASUREMENTPROTOCOL_H

#include <QApplication>
#include <QLabel>
#include <QThread>
#include <QMutex>


class Plot;
class QCPGraph;

class MeasurementProtocol: public QObject
{
    Q_OBJECT

signals:
    void RequestRunRoutine();
    void RequestEndRoutine();
    void RequestUpdatePlot(QCPGraph* graph, QVector<double> x, QVector<double> y);
    void RequestUpdatePlot(int graphnumber, QVector<double> x, QVector<double> y);
    void RequestCoProtocolPause();
    void RequestCoProtocolUnpause();

public slots:
    virtual void RunRoutine() = 0;
    virtual void UnpauseRoutine() = 0;


public:
    MeasurementProtocol();



    void StartRoutine();

    void PauseRoutine();

    virtual void StopRoutine();

    void PauseCoProtocolRoutine();

    bool started();
    bool paused();
    bool stopped();

    MeasurementProtocol* coprotocol();
    void SetCoProtocol(MeasurementProtocol* coprotocol);

    Plot* plot();
    void SetPlot(Plot* plot);



protected:
    QMutex mutex_;

    bool started_, paused_, stopped_;

    MeasurementProtocol* coprotocol_;

    Plot* plot_;





private:

};






#endif // MEASUREMENTPROTOCOL_H


