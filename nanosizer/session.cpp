#include "session.h"

#include "typeconversions.h"


Session::Session()
{


}

void Session::InitializeSession()
{

    vistatus = viOpenDefaultRM(&defaultsession);

    CheckDisplayError(vistatus, "Cannot open default session!\n");

    SetSessionParameters();
}

void Session::SetSessionParameters()
{
    instr_timeout = 3000;
    maxreadbytes = 200;

    ZEROCHECK_0 = DISABLE;
    VOLTAGEINCREMENT_0 = 0.1;


    samplingfrequency = 10;

    measurecurrentmode = false;
    voltagecontrolmode = false;

    return;
}

void Session::OpenInstrumentSession()
{

    vistatus = viOpen(defaultsession, (char*) "GPIB0::22::INSTR", VI_NULL, VI_NULL, &instrumentsession);

    CheckDisplayError(vistatus, "ERROR: Cannot open instrument session.\n");

    WriteToInstrument("*RST\n");

    SetInstrumentParameters();

    return;
}


void Session::SetInstrumentParameters()
{

    vistatus = viSetAttribute(instrumentsession, VI_ATTR_TMO_VALUE, instr_timeout);

    return;
}

void Session::GetInstrumentID()
{
    ReadWriteInstrument("*IDN?\n");

    PrintBuffer();

    return;
}

bool Session::CheckInstrumentOpen()
{
    bool writeok, readok;
    bool instrumentopen;

    WriteToInstrument("*IDN?\n");
    writeok = CheckError(vistatus);
    ReadFromInstrument();
    readok = CheckError(vistatus);
    if(writeok == false || readok == false)
    {
        instrumentopen = false;
    }

    else
    {
        instrumentopen = true;
    }

    return instrumentopen;

}

float Session::interruptwait()
{
    return interruptwait_;
}

void Session::EndSession()
{
    WriteToInstrument("*RST\n");

    vistatus = viClose(instrumentsession);
    vistatus = viClose(defaultsession);

    return;
}

float Session::MAXVOLTAGE()
{
    return MAXVOLTAGE_;
}
