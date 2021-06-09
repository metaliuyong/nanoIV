#ifndef SESSION_H
#define SESSION_H
#include "C:\Program Files\IVI Foundation\VISA\Win64\Include\visa.h"
#include "gpiberror.h"
#include "stdint.h"
#include <cstring>
#include <string>
#include "windows.h"
#include "datapoint.h"
#include <vector>
#include "time.h"

#define ENABLE true
#define DISABLE false


class Session
{
public:
    Session();
    static ViStatus vistatus;
    static ViSession defaultsession, instrumentsession;
    static bool measurecurrentmode;
    static bool voltagecontrolmode;

    static void InitializeSession();

    static void OpenInstrumentSession();

    static void SetSessionParameters();
    static void SetInstrumentParameters();
    static void GetInstrumentID();
    static bool CheckInstrumentOpen();

    static float MeasureCurrent();
    static float MeasureVoltage();

    static void EnDisableZeroCheck(bool zerocheck);
    static void EnDisableZeroCorrection(bool zerocorrection);

    static void ReadWriteInstrument(std::string message);
    static void WriteToInstrument(std::string message);
    static void ReadFromInstrument();
    static void PrintBuffer();


    static void EnableVoltageControlMode();
    static void DisableVoltageControlMode();

    static void EnableMeasureCurrentMode();
    static void EnableHighFrequencyReadings();


    static float GetVoltage();
    static void PerformVoltageScan();


    //static void PerformHighFrequencyCurrentScan(int duration = 1000*10);


    static void SetVoltage(float voltagevalue = 0);
    static void IncrementVoltage(float voltageincrement = 0.1);
    static void DecrementVoltage(float voltageincrement = 0.1);

    static void EndSession();

    static float interruptwait();

    static float MAXVOLTAGE();


private:

    //Instrument parameters
    static ViUInt32 instr_timeout;

    static bool ZEROCHECK_0;
    static float VOLTAGEINCREMENT_0;

    static float MAXVOLTAGE_;

    static float interruptwait_;

    static int samplingfrequency;

    static std::string stringreadbuffer;
    static unsigned char* readbuffer;
    static ViUInt32 maxreadbytes;
    static ViUInt32 bytestransferred;



};

#endif // SESSION_H
