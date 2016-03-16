#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>

#include "typeconversions.h"
#include "session.h"
#include "currentsampleprotocol.h"
#include "ivprotocol.h"
#include "ivsweepaverage.h"


void MainWindow::on_IV_Start_clicked()
{
    DisableNeutralButton(ui->IV_AddToSweepQueue);
    DisableNeutralButton(ui->VoltageOff);
    DisableNeutralButton(ui->VoltageOn);
    DisableNeutralButton(ui->ZCheck_Off);
    DisableNeutralButton(ui->ZCheck_On);
    DisableNeutralButton(ui->GetInstrumentID);
    DisableNeutralButton(ui->GetVoltage);
    DisableNeutralButton(ui->OpenDevice);
    DisableNeutralButton(ui->IncrementVoltage);
    DisableNeutralButton(ui->DecrementVoltage);

    if(ivprotocol_->started() == false)
    {
        if(!Session::CheckInstrumentOpen())
        {
            Session::OpenInstrumentSession();
        }

        DisableGreenButton(ui->IV_Start);
        EnableYellowButton(ui->IV_Pause);
        EnableRedButton(ui->IV_Stop);
        ivprotocol_->StartRoutine();
    }

    else
    {
        DisableGreenButton(ui->IV_Start);
        EnableYellowButton(ui->IV_Pause);
        EnableRedButton(ui->IV_Stop);
        ivprotocol_->UnpauseRoutine();
    }

    return;
}

void MainWindow::on_IV_Pause_clicked()
{
    if(ivprotocol_->started())
    {
        if(ivprotocol_->paused())
        {
            ivprotocol_->UnpauseRoutine();
        }
        else
        {

            EnableGreenButton(ui->IV_Start);
            DisableYellowButton(ui->IV_Pause);
            EnableRedButton(ui->IV_Stop);

            ivprotocol_->PauseRoutine();
        }
    }

    return;
}

void MainWindow::on_IV_Unpause_clicked()
{
    if(ivprotocol_->started())
    {
        DisableGreenButton(ui->IV_Start);
        EnableYellowButton(ui->IV_Pause);
        EnableRedButton(ui->IV_Stop);
        ivprotocol_->UnpauseRoutine();
    }

    return;
}

void MainWindow::on_IV_Stop_clicked()
{
    EnableNeutralButton(ui->IV_AddToSweepQueue);
    EnableNeutralButton(ui->VoltageOff);
    EnableNeutralButton(ui->VoltageOn);
    EnableNeutralButton(ui->ZCheck_Off);
    EnableNeutralButton(ui->ZCheck_On);
    EnableNeutralButton(ui->GetInstrumentID);
    EnableNeutralButton(ui->GetVoltage);
    EnableNeutralButton(ui->OpenDevice);
    EnableNeutralButton(ui->IncrementVoltage);
    EnableNeutralButton(ui->DecrementVoltage);

    EnableGreenButton(ui->IV_Start);
    DisableYellowButton(ui->IV_Pause);
    DisableRedButton(ui->IV_Stop);

    ivprotocol_->StopRoutine();
    return;
}



