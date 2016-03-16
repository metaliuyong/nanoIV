#include "session.h"

#include "typeconversions.h"

void Session::EnDisableZeroCheck(bool zerocheck)
{
    if(zerocheck == true)
    {
        WriteToInstrument("SYST:ZCH ON\n");
    }
    else
    {
        WriteToInstrument("SYST:ZCH OFF\n");
    }

    return;
}

float Session::GetVoltage()
{
    WriteToInstrument("SOUR:VOLT?\n");
    ReadFromInstrument();
    return UnsignedCharToFloat(readbuffer);
}

void Session::EnableVoltageControlMode()
{
    if(voltagecontrolmode == false)
    {
        WriteToInstrument("SOUR:VOLT:RANG 10\n");

        WriteToInstrument("SOUR:VOLT:ILIM 2.5e-3\n");

        WriteToInstrument("SOUR:VOLT:STAT ON\n");

        voltagecontrolmode = true;
    }

    return;
}

void Session::DisableVoltageControlMode()
{
    if(voltagecontrolmode == true)
    {
        WriteToInstrument("SOUR:VOLT:STAT OFF\n");
        voltagecontrolmode = false;
    }

    return;
}

void Session::SetVoltage(float voltage_float)
{

    std::string voltage_string = FloatToString(voltage_float);

    std::string command = "SOUR:VOLT " + voltage_string + "\n";

    WriteToInstrument("SOUR:VOLT " + voltage_string + "\n");

    return;
}



void Session::IncrementVoltage(float voltageincrement)
{
    float oldvoltage = GetVoltage();

    float newvoltage = oldvoltage + voltageincrement;

    SetVoltage(newvoltage);

    return;
}

void Session::DecrementVoltage(float voltageincrement)
{

    float oldvoltage = GetVoltage();

    float newvoltage = oldvoltage - voltageincrement;

    SetVoltage(newvoltage);

    return;
}

void Session::EnableMeasureCurrentMode()
{
    if(measurecurrentmode == false)
    {
        WriteToInstrument("SENS:FUNC 'CURR'\n");
        WriteToInstrument("SENS:CURR:RANGE:AUTO ON\n");
        WriteToInstrument("SYST:ZCH OFF\n");
        measurecurrentmode = true;

        EnableHighFrequencyReadings();
    }
    return;
}

void Session::EnableHighFrequencyReadings()
{
    //Need to fix this part
    //WriteToInstrument("DISP:ENAB OFF\n");
    //WriteToInstrument("TRIG:COUNT 1\n");
    //WriteToInstrument("SAMP:COUNT 1000\n");
    //WriteToInstrument("TRIG:DELAY 0.0\n");

    return;
}

float Session::MeasureCurrent()
{

    EnableMeasureCurrentMode();


    WriteToInstrument("READ?\n");

    ReadFromInstrument();

    return UnsignedCharToFloat(readbuffer);
    return 0;

}
