#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

#include "typeconversions.h"
#include "session.h"
#include "currentsampleprotocol.h"
#include "ivprotocol.h"



void MainWindow::on_CurrentSample_Start_clicked()
{
    if(currentsampleprotocol_->started() == false)
    {
        DisableGreenButton(ui->CurrentSample_Start);
        EnableYellowButton(ui->CurrentSample_Pause);
        EnableRedButton(ui->CurrentSample_Stop);
        currentsampleprotocol_->StartRoutine();
    }
    else
    {
        DisableGreenButton(ui->CurrentSample_Start);
        EnableYellowButton(ui->CurrentSample_Pause);
        EnableRedButton(ui->CurrentSample_Stop);
        currentsampleprotocol_->UnpauseRoutine();
    }
    return;
}

void MainWindow::on_CurrentSample_Pause_clicked()
{
    if(currentsampleprotocol_->started())
    {
        EnableGreenButton(ui->CurrentSample_Start);
        DisableYellowButton(ui->CurrentSample_Pause);
        EnableRedButton(ui->CurrentSample_Stop);
        currentsampleprotocol_->PauseRoutine();
    }

    return;
}




void MainWindow::on_CurrentSample_Unpause_clicked()
{
    if(currentsampleprotocol_->started())
    {
        //Added 7-29 to fix issue where the incorrect buttons were highlighted
        //while co-routine (IV sweep) runs. This is because coprotocol requests
        //CurrentSample protocol pauses by connecting to the "on_CurrentSample_Pause_clicked()"
        //slot

        DisableGreenButton(ui->CurrentSample_Start);
        EnableYellowButton(ui->CurrentSample_Pause);
        EnableRedButton(ui->CurrentSample_Stop);


        currentsampleprotocol_->UnpauseRoutine();
    }

    return;
}

void MainWindow::on_CurrentSample_Stop_clicked()
{
    EnableGreenButton(ui->CurrentSample_Start);
    DisableYellowButton(ui->CurrentSample_Pause);
    DisableRedButton(ui->CurrentSample_Stop);
    currentsampleprotocol_->StopRoutine();
    return;
}

void MainWindow::on_CurrentSample_Autoscale_clicked()
{
    if(ui->CurrentSample_Autoscale->checkState() == Qt::Checked)
    {
        currentsampleprotocol_->plot()->SetAutoscaleY(true);
    }

    else
    {
        currentsampleprotocol_->plot()->SetAutoscaleY(false);
    }


    return;
}

void MainWindow::on_CurrentSample_ZoomOutY_clicked()
{
    currentsampleprotocol_->plot()->ZoomOutY();
    return;
}

void MainWindow::on_CurrentSample_ZoomInY_clicked()
{
    currentsampleprotocol_->plot()->ZoomInY();
    return;
}




