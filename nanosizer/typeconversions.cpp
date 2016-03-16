#include "typeconversions.h"
#include <sstream>

std::string UnsignedCharToString(unsigned char* input)
{
    std::string output(reinterpret_cast<char*>(input));
    return output;
}

float UnsignedCharToFloat(unsigned char* input)
{
    float output_float = 0;

    std::string output_string(reinterpret_cast<char*>(input));
    if(!output_string.empty())
    {
        output_float = std::stof(output_string);
    }


    return output_float;
}

std::string FloatToString(float input)
{
    std::string output = std::to_string(input);
    return output;
}

std::string DoubleToStringScientific(double input)
{
    std::stringstream outputss;
    outputss.setf(std::ios::scientific);
    outputss.precision(6);
    outputss << input;

    return outputss.str();
}

std::string DoubleToString(double input)
{
    std::string output;
    output = std::to_string(input);
    return output;
}

float StringToFloat(std::string input)
{
    float output = std::stof(input);
    return output;
}

int StringToInt(std::string input)
{
    int output = static_cast<int>(std::stof(input));
    return output;
}

unsigned int StringToUInt(std::string input)
{
    unsigned int output = static_cast<unsigned int>(std::stof(input));
    return output;
}

float QStringToFloat(QString input)
{
    float output = input.toFloat();
    return output;
}

int QStringToInt(QString input)
{
    int output = 0;

    if(input.isEmpty() == false)
    {
        std::string stringoutput = input.QString::toStdString();

        output = StringToInt(stringoutput);
    }

    return output;
}

unsigned int QStringToUInt(QString input)
{
    unsigned int output = 0;

    if(input.isEmpty() == false)
    {
        std::string stringoutput = input.QString::toStdString();

        output = StringToUInt(stringoutput);
    }


    return output;
}

QString UIntToQString(unsigned int input)
{
    std::string output_string = std::to_string(input);
    QString output_qstring = QString::fromStdString(output_string);

    return output_qstring;
}

unsigned int SecToMs(float sec)
{
    unsigned int ms = static_cast<int>(sec*1000.0);
    return ms;
}

double MsToSec(double ms)
{
    double sec = ms/1000.0;
    return sec;
}

bool IsInteger(float input)
{
  return std::floor(input) == input;
}

bool EpsilonEqual(float a, float b)
{
    bool equal;
    float epsilon = 0.00001;
    if(fabs(a - b) < epsilon)
    {
        equal = true;
    }

    else
    {
        equal = false;
    }

    return equal;
}

bool EpsilonEqual(double a, double b)
{
    bool equal;
    double epsilon = 0.00001;
    if(fabs(a - b) < epsilon)
    {
        equal = true;
    }

    else
    {
        equal = false;
    }

    return equal;
}

std::string DirectionToString(Direction direction)
{

    std::string output_string;

    if(direction == forward)
    {
        output_string = "forward";
    }
    else
    {
        output_string = "reverse";
    }

    return output_string;
}
