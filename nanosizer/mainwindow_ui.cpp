#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

#include "typeconversions.h"
#include "session.h"
#include "currentsampleprotocol.h"
#include "ivprotocol.h"


void MainWindow::SetUp_UI()
{
    setFixedSize(this->geometry().width(),this->geometry().height());

    SetUp_StyleSheets();
    SetUp_IV_Labels();
    SetUp_IV_SweepTable();
    SetUp_IV_SweepAverageTable();
    SetUp_IV_Fields();
    SetUp_CurrentSample_Fields();
    SetUp_Buttons();

    return;
}

void MainWindow::SetUp_StyleSheets()
{
    mainlabel_ss_ = "QLabel { "
                    "background-color : ; "
                    "font: bold 18px 'Arial'; "
                    "color: rgb(64, 64, 64);"
                    "}";

    regularlabel_ss_ = "QLabel { "
                    "background-color : ; "
                    "font: bold 14px 'Arial'; "
                    "color: rgb(64, 64, 64);"
                    "}";

    neutralbutton_released_ss_ = "QPushButton { "
                                "background-color : rgb(255, 255, 255);"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 6px;"
                                //"border-color: rgb(64, 64, 64);"
                                "font: bold 14px 'Arial';"
                                "color: rgb(64, 64, 64);"
                                "}";

    neutralbutton_pressed_ss_ = "QPushButton { "
                                "background-color : rgb(220, 220, 220);"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 6px;"
                                //"border-color: rgb(64, 64, 64);"
                                "font: bold 14px 'Arial';"
                                "color: rgb(64, 64, 64);"
                                "}";

    bluebutton_released_ss_ = "QPushButton { "
                                "background-color : rgb(0, 172, 233);"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 10px;"
                                "border-color: rgb(64, 64, 64);"
                                "font: bold 14px 'Arial';"
                                "color: rgb(64, 64, 64);"
                                "}";


    bluebutton_pressed_ss_ = "QPushButton { "
                                "background-color : rgb(0, 132, 193);"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 10px;"
                                "border-color: rgb(64, 64, 64);"
                                "font: bold 14px 'Arial';"
                                "color: rgb(64, 64, 64);"
                                "}";

    greenbutton_released_ss_ = "QPushButton { "
                                "background-color : rgb(31, 218, 154);"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 10px;"
                                "border-color: rgb(64, 64, 64);"
                                "font: bold 14px 'Arial';"
                                "color: rgb(64, 64, 64);"
                                "}";


    greenbutton_pressed_ss_ = "QPushButton { "
                                "background-color : rgb(0, 178, 114);"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 10px;"
                                "border-color: rgb(64, 64, 64);"
                                "font: bold 14px 'Arial';"
                                "color: rgb(64, 64, 64);"
                                "}";

    yellowbutton_released_ss_ = "QPushButton { "
                                "background-color : rgb(233, 188, 27);"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 10px;"
                                //"border-color: rgb(64, 64, 64);"
                                "font: bold 14px 'Arial';"
                                "color: rgb(64, 64, 64);"
                                "}";

    yellowbutton_pressed_ss_ = "QPushButton { "
                                "background-color : rgb(193, 148, 0);"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 10px;"
                                //"border-color: rgb(64, 64, 64);"
                                "font: bold 14px 'Arial';"
                                "color: rgb(64, 64, 64);"
                                "}";

    redbutton_released_ss_ = "QPushButton { "
                                "background-color : rgb(238, 75, 62);"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 10px;"
                                "border-color: rgb(64, 64, 64);"
                                "font: bold 14px 'Arial';"
                                "color: rgb(64, 64, 64);"
                                "}";

    redbutton_pressed_ss_ = "QPushButton { "
                                "background-color : rgb(132, 0, 0);"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 10px;"
                                "border-color: rgb(64, 64, 64);"
                                "font: bold 14px 'Arial';"
                                "color: rgb(64, 64, 64);"
                                "}";


    field_ss_ = "QPlainTextEdit { "
                                  "background-color : rgb(255, 255, 255);"
                                  "border-style: outset;"
                                  "border-width: 2px;"
                                  "border-radius: 1px;"
                                  "border-color: rgb(128, 128, 128);"
                                  "font: bold 14px 'Arial';"
                                  "color: rgb(64, 64, 64);"
                                  "}";

    return;
}

void MainWindow::SetUp_IV_Labels()
{
    ui->IV_SweepControls_Label->setStyleSheet(mainlabel_ss_);
    ui->IV_Progress_Label->setStyleSheet(regularlabel_ss_);

    ui->IV_SweepControls_Label->setAlignment(Qt::AlignCenter);
    ui->IV_SweepsCount_Label->setAlignment(Qt::AlignCenter);
    ui->IV_StartVoltage_Label->setAlignment(Qt::AlignCenter);
    ui->IV_EndVoltage_Label->setAlignment(Qt::AlignCenter);
    ui->IV_VoltageIncrement_Label->setAlignment(Qt::AlignCenter);
    ui->IV_Pause_Label->setAlignment(Qt::AlignCenter);
    ui->IV_Progress_Label->setAlignment(Qt::AlignCenter);

    ui->IV_SweepControls_Label->setTextInteractionFlags(Qt::NoTextInteraction);
    ui->IV_SweepsCount_Label->setTextInteractionFlags(Qt::NoTextInteraction);
    ui->IV_StartVoltage_Label->setTextInteractionFlags(Qt::NoTextInteraction);
    ui->IV_EndVoltage_Label->setTextInteractionFlags(Qt::NoTextInteraction);
    ui->IV_VoltageIncrement_Label->setTextInteractionFlags(Qt::NoTextInteraction);
    ui->IV_Pause_Label->setTextInteractionFlags(Qt::NoTextInteraction);
    ui->IV_Progress_Label->setTextInteractionFlags(Qt::NoTextInteraction);




    return;
}


void MainWindow::SetUp_IV_SweepTable()
{
    int columncount = 9;
    int leftmargin = 10;
    ui->IV_SweepTable->setFrameStyle(0);
    ui->IV_SweepTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->IV_SweepTable->setColumnCount(columncount);

    QStringList tablelabels;
    QString delta(0x0394);
    tablelabels << "Plot" << "Average" << "Save" << "Vi" << "Vf" << delta + "V" << "Direction" << "Pause" << "Erase";
    ui->IV_SweepTable->setHorizontalHeaderLabels(tablelabels);
    for(int i = 0; i < columncount; i++)
    {
        ui->IV_SweepTable->setColumnWidth(i, static_cast<int>(1.0*ui->IV_SweepTable->width()/columncount) - leftmargin);
    }

    ui->IV_SweepTable->setSortingEnabled(false);


    return;
}

void MainWindow::SetUp_IV_SweepAverageTable()
{
    int columncount = 6;
    int leftmargin = 10;
    ui->IV_SweepAverageTable->setFrameStyle(0);
    ui->IV_SweepAverageTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->IV_SweepAverageTable->setColumnCount(columncount);

    QStringList tablelabels;
    QString delta(0x0394);
    tablelabels << "Plot" << "Save" << "Vi" << "Vf" << delta + "V" << "Direction";
    ui->IV_SweepAverageTable->setHorizontalHeaderLabels(tablelabels);
    for(int i = 0; i < columncount; i++)
    {
        ui->IV_SweepAverageTable->setColumnWidth(i, static_cast<int>(1.0*ui->IV_SweepAverageTable->width()/columncount) - leftmargin);
    }

    ui->IV_SweepAverageTable->setSortingEnabled(false);


    return;
}

void MainWindow::SetUp_IV_Fields()
{

    ui->IV_SweepsCount_Field->setStyleSheet(field_ss_);
    ui->IV_StartVoltage_Field->setStyleSheet(field_ss_);
    ui->IV_EndVoltage_Field->setStyleSheet(field_ss_);
    ui->IV_VoltageIncrement_Field->setStyleSheet(field_ss_);
    ui->IV_Pause_Field->setStyleSheet(field_ss_);
    ui->IV_SavePath_Field->setStyleSheet(field_ss_);
    ui->IV_SavePath_Field->setPlainText("C:/nanoIV/save/default.txt");

    ui->IV_Autoscale->setCheckState(Qt::Checked);

    return;
}

void MainWindow::SetUp_CurrentSample_Fields()
{
    ui->CurrentSample_Autoscale->setCheckState(Qt::Checked);

    return;
}

void MainWindow::SetUp_Buttons()
{
    ui->IV_AddToSweepQueue->setStyleSheet(neutralbutton_released_ss_);
    ui->IV_LoadParameters->setStyleSheet(neutralbutton_released_ss_);
    ui->IV_SaveParameters->setStyleSheet(neutralbutton_released_ss_);
    ui->IV_SaveAllSweeps->setStyleSheet(neutralbutton_released_ss_);
    ui->IV_SaveSelectedSweeps->setStyleSheet(neutralbutton_released_ss_);
    ui->IV_SetSavePath->setStyleSheet(neutralbutton_released_ss_);

    ui->IV_Start->setStyleSheet(greenbutton_released_ss_);
    ui->IV_Pause->setStyleSheet(yellowbutton_released_ss_);
    ui->IV_Stop->setStyleSheet(redbutton_released_ss_);

    ui->IV_ZoomInX->setStyleSheet(neutralbutton_released_ss_);
    ui->IV_ZoomOutX->setStyleSheet(neutralbutton_released_ss_);
    ui->IV_ZoomInY->setStyleSheet(neutralbutton_released_ss_);
    ui->IV_ZoomOutY->setStyleSheet(neutralbutton_released_ss_);

    ui->IncrementVoltage->setStyleSheet(neutralbutton_released_ss_);
    ui->DecrementVoltage->setStyleSheet(neutralbutton_released_ss_);
    ui->ZCheck_On->setStyleSheet(neutralbutton_released_ss_);
    ui->ZCheck_Off->setStyleSheet(neutralbutton_released_ss_);
    ui->OpenDevice->setStyleSheet(neutralbutton_released_ss_);
    ui->GetInstrumentID->setStyleSheet(neutralbutton_released_ss_);
    ui->GetVoltage->setStyleSheet(neutralbutton_released_ss_);

    ui->CurrentSample_Start->setStyleSheet(greenbutton_released_ss_);
    ui->CurrentSample_Pause->setStyleSheet(yellowbutton_released_ss_);
    ui->CurrentSample_Stop->setStyleSheet(redbutton_released_ss_);
    ui->CurrentSample_ZoomOutY->setStyleSheet(neutralbutton_released_ss_);
    ui->CurrentSample_ZoomInY->setStyleSheet(neutralbutton_released_ss_);

    ui->VoltageOn->setStyleSheet(neutralbutton_released_ss_);
    ui->VoltageOff->setStyleSheet(neutralbutton_released_ss_);




    DisableYellowButton(ui->IV_Pause);
    DisableRedButton(ui->IV_Stop);
    DisableYellowButton(ui->CurrentSample_Pause);
    DisableRedButton(ui->CurrentSample_Stop);

    return;
}

void MainWindow::on_IV_AddToSweepQueue_pressed()
{
    ui->IV_AddToSweepQueue->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_IV_AddToSweepQueue_released()
{
    ui->IV_AddToSweepQueue->setStyleSheet(neutralbutton_released_ss_);

    return;
}


void MainWindow::on_IV_LoadParameters_pressed()
{
    ui->IV_LoadParameters->setStyleSheet(neutralbutton_pressed_ss_);

    return;
}
void MainWindow::on_IV_LoadParameters_released()
{
    ui->IV_LoadParameters->setStyleSheet(neutralbutton_released_ss_);

    return;
}

void MainWindow::on_IV_SaveParameters_pressed()
{
    ui->IV_SaveParameters->setStyleSheet(neutralbutton_pressed_ss_);

    return;
}
void MainWindow::on_IV_SaveParameters_released()
{
    ui->IV_SaveParameters->setStyleSheet(neutralbutton_released_ss_);

    return;
}


void MainWindow::on_IV_SaveAllSweeps_pressed()
{
    ui->IV_SaveAllSweeps->setStyleSheet(neutralbutton_pressed_ss_);

    return;
}

void MainWindow::on_IV_SaveAllSweeps_released()
{
    ui->IV_SaveAllSweeps->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_IV_SaveSelectedSweeps_pressed()
{
    ui->IV_SaveSelectedSweeps->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_IV_SaveSelectedSweeps_released()
{
    ui->IV_SaveSelectedSweeps->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_IV_SetSavePath_pressed()
{
    ui->IV_SetSavePath->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_IV_SetSavePath_released()
{
    ui->IV_SetSavePath->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_IV_Start_pressed()
{
    ui->IV_Start->setStyleSheet(greenbutton_pressed_ss_);
    return;
}
void MainWindow::on_IV_Start_released()
{
    ui->IV_Start->setStyleSheet(greenbutton_released_ss_);
    return;
}

void MainWindow::on_IV_Pause_pressed()
{
    ui->IV_Pause->setStyleSheet(yellowbutton_pressed_ss_);
    return;
}

void MainWindow::on_IV_Pause_released()
{
    ui->IV_Pause->setStyleSheet(yellowbutton_released_ss_);
    return;
}

void MainWindow::on_IV_Stop_pressed()
{
    ui->IV_Stop->setStyleSheet(redbutton_pressed_ss_);
    return;
}

void MainWindow::on_IV_Stop_released()
{
    ui->IV_Stop->setStyleSheet(redbutton_released_ss_);
    return;
}

void MainWindow::on_IV_ZoomOutX_pressed()
{
    ui->IV_ZoomOutX->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_IV_ZoomOutX_released()
{
    ui->IV_ZoomOutX->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_IV_ZoomInX_pressed()
{
    ui->IV_ZoomInX->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_IV_ZoomInX_released()
{
    ui->IV_ZoomInX->setStyleSheet(neutralbutton_released_ss_);
    return;
}


void MainWindow::on_IV_ZoomOutY_pressed()
{
    ui->IV_ZoomOutY->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_IV_ZoomOutY_released()
{
    ui->IV_ZoomOutY->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_IV_ZoomInY_pressed()
{
    ui->IV_ZoomInY->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_IV_ZoomInY_released()
{
    ui->IV_ZoomInY->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_CurrentSample_Start_pressed()
{
    ui->CurrentSample_Start->setStyleSheet(greenbutton_pressed_ss_);
    return;
}

void MainWindow::on_CurrentSample_Start_released()
{
    ui->CurrentSample_Start->setStyleSheet(greenbutton_released_ss_);
    return;
}
void MainWindow::on_CurrentSample_Pause_pressed()
{
    ui->CurrentSample_Pause->setStyleSheet(yellowbutton_pressed_ss_);
    return;
}
void MainWindow::on_CurrentSample_Pause_released()
{
    ui->CurrentSample_Pause->setStyleSheet(yellowbutton_released_ss_);
    return;
}
void MainWindow::on_CurrentSample_Stop_pressed()
{
    ui->CurrentSample_Stop->setStyleSheet(redbutton_pressed_ss_);
    return;
}
void MainWindow::on_CurrentSample_Stop_released()
{
    ui->CurrentSample_Stop->setStyleSheet(redbutton_released_ss_);
    return;
}

void MainWindow::on_CurrentSample_ZoomOutY_pressed()
{
    ui->CurrentSample_ZoomOutY->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_CurrentSample_ZoomInY_pressed()
{
    ui->CurrentSample_ZoomInY->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_CurrentSample_ZoomOutY_released()
{
    ui->CurrentSample_ZoomOutY->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_CurrentSample_ZoomInY_released()
{
    ui->CurrentSample_ZoomInY->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_ZCheck_On_pressed()
{
    ui->ZCheck_On->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_ZCheck_On_released()
{
    ui->ZCheck_On->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_ZCheck_Off_pressed()
{
    ui->ZCheck_Off->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_ZCheck_Off_released()
{
    ui->ZCheck_Off->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_IncrementVoltage_pressed()
{
    ui->IncrementVoltage->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_IncrementVoltage_released()
{
    ui->IncrementVoltage->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_DecrementVoltage_pressed()
{
    ui->DecrementVoltage->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_DecrementVoltage_released()
{
    ui->DecrementVoltage->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_GetVoltage_pressed()
{
    ui->GetVoltage->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_GetVoltage_released()
{
    ui->GetVoltage->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_GetInstrumentID_pressed()
{
    ui->GetInstrumentID->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_GetInstrumentID_released()
{
    ui->GetInstrumentID->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_OpenDevice_pressed()
{
    ui->OpenDevice->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_OpenDevice_released()
{
    ui->OpenDevice->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::on_VoltageOn_pressed()
{
    ui->VoltageOn->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_VoltageOn_released()
{
    ui->VoltageOn->setStyleSheet(neutralbutton_released_ss_);
    return;
}


void MainWindow::on_VoltageOff_pressed()
{
    ui->VoltageOff->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::on_VoltageOff_released()
{
    ui->VoltageOff->setStyleSheet(neutralbutton_released_ss_);
    return;
}





