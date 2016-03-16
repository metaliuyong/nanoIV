#include "mainwindow.h"

#include <windows.h>
#include <iostream>

#include <QApplication>

#include "session.h"
#include "data.h"
#include "measurementprotocol.h"
#include "currentsampleprotocol.h"
#include "ivprotocol.h"
#include "objectbinds.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    //

    MainWindow w;

    //

    Session::InitializeSession();

    //

    CurrentSampleProtocol currentsampleprotocol;

    IVProtocol ivprotocol;

    //

    Plot currentsampleplot;

    Plot ivplot;

    //

    w.Bind_Objects(&ivprotocol, &currentsampleprotocol, &ivplot, &currentsampleplot);

    //

    w.show();

    //

    return a.exec();
}
