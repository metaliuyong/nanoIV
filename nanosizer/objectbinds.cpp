#include "objectbinds.h"
#include "mainwindow.h"
#include "measurementprotocol.h"
#include "currentsampleprotocol.h"
#include "ivprotocol.h"


void Bind_Protocol_To_Protocol(MeasurementProtocol* protocol1, MeasurementProtocol* protocol2)
{
    protocol1->SetDependentProtocol(protocol2);
    protocol2->SetDependentProtocol(protocol1);
    return;
}

