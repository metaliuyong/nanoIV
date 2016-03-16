#ifndef IVSWEEPAVERAGE_H
#define IVSWEEPAVERAGE_H

#include "ivsweep.h"

class QCPGraph;

class IVSweepAverage
{

public:
    IVSweepAverage(double startvoltage, double endvoltage, double voltageincrement, Direction direction, QCPGraph* parentgraph);

    void AddSweepToSweepList(IVSweep* ivsweep);
    void RemoveSweepFromSweepList(IVSweep* ivsweep);

    void UpdateAverage();



    QCPGraph* parentgraph();
    void SetParentGraph(QCPGraph* parentgraph);

    double startvoltage();
    void SetStartVoltage(double startvoltage);

    double endvoltage();
    void SetEndVoltage(double endvoltage);

    int totalvoltages();

    double voltageincrement();
    void SetVoltageIncrement(double voltageincrement);

    Direction direction();
    void SetDirection(Direction direction);

    std::vector<IVSweep*> sweeplist();

    QVector<double>& xaverage();
    QVector<double>& yaverage();

    bool save();

    void SetSave(bool save);



private:
    std::vector<IVSweep*> sweeplist_;

    QVector<double> xaverage_;
    QVector<double> yaverage_;

    unsigned int numberofsweepsinaverage_;

    QCPGraph* parentgraph_;

    double startvoltage_, endvoltage_, voltageincrement_;
    int totalvoltages_;
    Direction direction_;

    bool save_;


};

#endif // IVSWEEPAVERAGE_H
