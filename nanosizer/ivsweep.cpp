#include "ivsweep.h"

#include <iostream>

#include "typeconversions.h"



IVSweep::IVSweep(int sweepnumber, double startvoltage, double endvoltage, double voltageincrement, float pausetime, QCPGraph* parentgraph):
    sweepnumber_(sweepnumber),
    startvoltage_(startvoltage),
    endvoltage_(endvoltage),
    voltageincrement_(voltageincrement),
    pausetime_(pausetime),
    parentgraph_(parentgraph)
{

    totalvoltages_ = static_cast<int>((fabs(endvoltage_ - startvoltage_)/(1.0*voltageincrement_) + 0.5) + 1);


    started_ = false;
    finished_ = false;

    x_.resize(totalvoltages_);
    y_.resize(totalvoltages_);

    if(startvoltage_ <= endvoltage_)
    {
        direction_ = forward;
        for(unsigned int i = 0; i < totalvoltages_; i++)
        {
            x_[i] = startvoltage_ + i*voltageincrement_;
        }
    }
    else
    {
        direction_ = reverse;
        for(unsigned int i = 0; i < totalvoltages_; i++)
        {
            x_[i] = startvoltage_ - i*voltageincrement_;
        }
    }

    currentindex_ = 0;
    currentvoltage_ = x_[0];

    includeinaverage_ = true;
}

void IVSweep::AddCurrentMeasurement(float current)
{
    started_ = true;

    if(currentindex_ == totalvoltages_ - 1)
    {
        finished_ = true;
    }

    y_[currentindex_] = current;

    if(finished_ == false)
    {
        currentindex_++;
        currentvoltage_ = x_[currentindex_];
    }

    return;
}


QVector<double>& IVSweep::x()
{
    return x_;
}

QVector<double>& IVSweep::y()
{
    return y_;
}

std::string IVSweep::name() const
{
    return name_;
}

void IVSweep::SetName(std::string name)
{
    name_ = name;
    return;
}

unsigned int IVSweep::sweepnumber() const
{
    return sweepnumber_;
}

void IVSweep::SetSweepNumber(unsigned int sweepnumber)
{
    sweepnumber_ = sweepnumber;
    return;
}

bool IVSweep::started() const
{
    return started_;
}

bool IVSweep::finished() const
{
    return finished_;
}


Direction IVSweep::direction() const
{
    return direction_;
}

double IVSweep::startvoltage() const
{
    return startvoltage_;
}

double IVSweep::endvoltage() const
{
    return endvoltage_;
}

double IVSweep::voltageincrement() const
{
    return voltageincrement_;
}

double IVSweep::currentvoltage() const
{
    return currentvoltage_;
}

unsigned int IVSweep::currentindex() const
{
    return currentindex_;
}

float IVSweep::pausetime() const
{
    return pausetime_;
}

bool IVSweep::includeinaverage() const
{
    return includeinaverage_;
}

void IVSweep::SetIncludeInAverage(bool includeinaverage)
{
    includeinaverage_ = includeinaverage;
    return;
}

QCPGraph* IVSweep::parentgraph()
{
    return parentgraph_;
}

void IVSweep::SetParentGraph(QCPGraph* parentgraph)
{
    parentgraph_ = parentgraph;
    return;
}

int IVSweep::totalvoltages()
{
    return totalvoltages_;
}

IVSweepAverage* IVSweep::parentaverage()
{
    return parentaverage_;
}

void IVSweep::SetParentAverage(IVSweepAverage* parentaverage)
{
    parentaverage_ = parentaverage;
    return;
}

bool IVSweep::save()
{
    return save_;
}

void IVSweep::SetSave(bool save)
{
    save_ = save;
    return;
}
