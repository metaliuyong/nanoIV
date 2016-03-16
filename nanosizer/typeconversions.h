#ifndef TYPECONVERSIONS
#define TYPECONVERSIONS

#include <string>
#include <QString>
#include "ivsweep.h"

std::string UnsignedCharToString(unsigned char* input);

float UnsignedCharToFloat(unsigned char* input);

std::string FloatToString(float input);

std::string DoubleToString(double input);

std::string DoubleToStringScientific(double input);

float StringToFloat(std::string input);

int StringToInt(std::string input);

unsigned int StringToUInt(std::string input);

float QStringToFloat(QString input);

int QStringToInt(QString input);

unsigned int QStringToUInt(QString input);

QString UIntToQString(unsigned int input);

unsigned int SecToMs(float sec);

double MsToSec(double ms);

bool IsInteger(float input);

bool EpsilonEqual(double a, double b);

bool EpsilonEqual(float a, float b);

std::string DirectionToString(Direction direction);

#endif // TYPECONVERSIONS

