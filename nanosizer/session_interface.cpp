#include "session.h"

#include "typeconversions.h"

void Session::ReadWriteInstrument(std::string message)
{
    WriteToInstrument(message);
    ReadFromInstrument();
    return;
}

void Session::WriteToInstrument(std::string message)
{
    int bytes = strlen(message.c_str());
    vistatus = viWrite(instrumentsession, (unsigned char*) message.c_str(), bytes, &bytestransferred);

    CheckDisplayError(vistatus, "ERROR: viWrite: " + message + "\n");
    return;
}

void Session::ReadFromInstrument()
{
    delete[] readbuffer;
    readbuffer = new unsigned char[maxreadbytes];

    vistatus = viRead(instrumentsession, readbuffer, maxreadbytes, &bytestransferred);

    CheckDisplayError(vistatus, "ERROR: viRead.\n");

    return;
}


void Session::PrintBuffer()
{
    std::string readbuffer_string = UnsignedCharToString(readbuffer);
    std::cerr << "buffer: " << readbuffer_string << "\n";

    return;
}
