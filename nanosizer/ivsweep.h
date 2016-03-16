#ifndef IVSWEEP_H
#define IVSWEEP_H

#include "QVector"

#include "datapoint.h"


class QCPGraph;
class IVSweepAverage;


enum Direction
{
    forward, reverse
};



class IVSweep
{
public:
    IVSweep(int sweepnumber_, double startvoltage, double endvoltage, double voltageinterval, float pausetime, QCPGraph* parentgraph);
    void AddCurrentMeasurement(float current);

    QVector<double>& x();
    QVector<double>& y();


    std::string name() const;
    void SetName(std::string name);

    unsigned int sweepnumber() const;

    void SetSweepNumber(unsigned int sweepnumber);



    bool started() const;
    bool finished() const;

    Direction direction() const;

    double startvoltage() const;

    double endvoltage() const;

    double voltageincrement() const;

    double currentvoltage() const;

    unsigned int currentindex() const;

    float pausetime() const;

    bool includeinaverage() const;

    void SetIncludeInAverage(bool inaverage);

    QCPGraph* parentgraph();

    void SetParentGraph(QCPGraph* parentgraph);

    int totalvoltages();

    IVSweepAverage* parentaverage();

    void SetParentAverage(IVSweepAverage* parentaverage);

    bool save();

    void SetSave(bool save);



private:
    QVector<double> x_;
    QVector<double> y_;

    std::string name_;

    unsigned int sweepnumber_;

    bool started_;

    bool finished_;

    QCPGraph* parentgraph_;

    IVSweepAverage* parentaverage_;


    Direction direction_;

    const double startvoltage_, endvoltage_;

    const double voltageincrement_;

    unsigned int totalvoltages_;

    double currentvoltage_;

    unsigned int currentindex_;

    float pausetime_;

    bool includeinaverage_;

    bool save_;





};

#endif // IVSWEEP_H
