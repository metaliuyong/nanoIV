#ifndef IVPROTOCOL_H
#define IVPROTOCOL_H
#include <vector>
#include <string>
#include <ctime>
#include <iostream>

#include "IVSweep.h"
#include "measurementprotocol.h"

class IVSweepAverage;


class IVProtocol: public MeasurementProtocol
{
    Q_OBJECT
signals:
    void RequestUpdateProgress(int sweepnumber);



    void RequestAddSweepToSweepTable(const IVSweep& ivsweep);

    void RequestDeleteSweepFromSweepTable(const unsigned int sweepnumber);

    void RequestAddSweepAverageToSweepAverageTable(IVSweepAverage& ivsweepaverage);

    void RequestDeleteSweepAverageFromSweepAverageTable(IVSweepAverage* ivsweepaverage);

    void RequestUpdateAveragePlot(QCPGraph* graph, QVector<double> x, QVector<double> y);

    void RequestSetPlotStyleActiveForward(QCPGraph* graph);
    void RequestSetPlotStyleAverageActiveForward(QCPGraph* graph);
    void RequestSetPlotStyleActiveReverse(QCPGraph* graph);
    void RequestSetPlotStyleAverageActiveReverse(QCPGraph* graph);

    void RequestSetPlotStyleInactiveForward(QCPGraph* graph);
    void RequestSetPlotStyleAverageInactiveForward(QCPGraph* graph);
    void RequestSetPlotStyleInactiveReverse(QCPGraph* graph);
    void RequestSetPlotStyleAverageInactiveReverse(QCPGraph* graph);






public slots:
    void RunRoutine();
    void UnpauseRoutine();

public:
    IVProtocol();



    void AddSweepToSweepList(float startvoltage, float endvoltage, float voltageincrement, float pausetime);
    void DeleteSweep(unsigned int sweepnumber);
    void DeleteFinishedSweep(unsigned int sweepnumber);
    void DeleteCurrentSweep();
    void DeleteUnfinishedSweep(unsigned int sweepnumber);





    void CheckCreateNewSweepAverage(IVSweep* ivsweep);
    void AddSweepToSweepAverageSweepList(IVSweep* ivsweep);
    void CheckRemoveSweepAverageFromSweepAverageTable(IVSweep* ivsweep);






    void PerformRoutine();    


    void RunRoutine_CheckSweep();

    void RunRoutine_ChangeVoltage();

    void RunRoutine_Pause();

    static bool CheckMatchingParameters(IVSweep* ivsweep1, IVSweep* ivsweep2);





    std::vector<IVSweep*>& sweeplist();
    std::vector<IVSweepAverage*>& sweepaveragelist();




private:
    std::vector<IVSweep*> sweeplist_;
    std::vector<IVSweepAverage*> sweepaveragelist_;
    IVSweep* currentsweep_;

};

#endif // IVPROTOCOL_H
