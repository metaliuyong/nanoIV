#include "session.h"

ViStatus Session::vistatus;
ViSession Session::defaultsession;
ViSession Session::instrumentsession;

ViUInt32 Session::instr_timeout;

bool Session::ZEROCHECK_0;
float Session::VOLTAGEINCREMENT_0;

int Session::samplingfrequency;

std::string Session::stringreadbuffer;
unsigned char* Session::readbuffer;
ViUInt32 Session::maxreadbytes;
ViUInt32 Session::bytestransferred;

bool Session::measurecurrentmode;
bool Session::voltagecontrolmode;

float Session::interruptwait_ = 0.05;

float Session::MAXVOLTAGE_ = 10.0;
