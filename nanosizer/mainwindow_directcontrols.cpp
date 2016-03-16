#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

#include "typeconversions.h"
#include "session.h"
#include "currentsampleprotocol.h"
#include "ivprotocol.h"

void MainWindow::on_GetInstrumentID_clicked()
{
    Session::GetInstrumentID();
    return;
}

void MainWindow::on_OpenDevice_clicked()
{
    Session::OpenInstrumentSession();
    return;
}

void MainWindow::on_ZCheck_Off_clicked()
{
    Session::EnDisableZeroCheck(false);
    return;
}

void MainWindow::on_ZCheck_On_clicked()
{
    Session::EnDisableZeroCheck(true);
    return;
}

void MainWindow::on_IncrementVoltage_clicked()
{
    Session::IncrementVoltage();
    return;
}

void MainWindow::on_DecrementVoltage_clicked()
{
    Session::DecrementVoltage();
    return;
}

void MainWindow::on_GetVoltage_clicked()
{
    Session::GetVoltage();
    return;
}

void MainWindow::on_VoltageOn_clicked()
{
    Session::EnableVoltageControlMode();
    return;
}

void MainWindow::on_VoltageOff_clicked()
{
    Session::DisableVoltageControlMode();
    return;
}

