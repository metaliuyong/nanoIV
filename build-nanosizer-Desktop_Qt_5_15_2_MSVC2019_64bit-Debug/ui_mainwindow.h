/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *GetInstrumentID;
    QPushButton *OpenDevice;
    QPushButton *ZCheck_Off;
    QPushButton *ZCheck_On;
    QPushButton *IncrementVoltage;
    QPushButton *DecrementVoltage;
    QPushButton *GetVoltage;
    QCheckBox *IV_Cycle;
    QCustomPlot *IV_PlotWidget;
    QCustomPlot *CurrentSample_PlotWidget;
    QPushButton *CurrentSample_Start;
    QPushButton *CurrentSample_Pause;
    QPushButton *CurrentSample_Stop;
    QPushButton *IV_Start;
    QPushButton *IV_Pause;
    QPushButton *IV_Stop;
    QPlainTextEdit *IV_SavePath_Field;
    QPlainTextEdit *IV_StartVoltage_Field;
    QPlainTextEdit *IV_EndVoltage_Field;
    QPlainTextEdit *IV_VoltageIncrement_Field;
    QPushButton *IV_IncreaseSweepCount;
    QPushButton *IV_DecreaseSweepCount;
    QLabel *IV_SweepControls_Label;
    QLabel *IV_SweepsCount_Label;
    QLabel *IV_StartVoltage_Label;
    QLabel *IV_EndVoltage_Label;
    QLabel *IV_VoltageIncrement_Label;
    QPushButton *IV_AddToSweepQueue;
    QLabel *IV_Pause_Label;
    QPlainTextEdit *IV_Pause_Field;
    QPlainTextEdit *IV_SweepsCount_Field;
    QPushButton *IV_LoadParameters;
    QPushButton *IV_SaveParameters;
    QLabel *IV_Progress_Label;
    QPushButton *IV_SaveSelectedSweeps;
    QPushButton *IV_SaveAllSweeps;
    QTableWidget *IV_SweepTable;
    QPushButton *IV_SetSavePath;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QTableWidget *IV_SweepAverageTable;
    QPushButton *VoltageOff;
    QPushButton *VoltageOn;
    QCheckBox *IV_Autoscale;
    QPushButton *IV_ZoomInX;
    QPushButton *IV_ZoomInY;
    QPushButton *IV_ZoomOutX;
    QPushButton *IV_ZoomOutY;
    QCheckBox *CurrentSample_Autoscale;
    QPushButton *CurrentSample_ZoomOutY;
    QPushButton *CurrentSample_ZoomInY;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1526, 877);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 246, 232)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GetInstrumentID = new QPushButton(centralWidget);
        GetInstrumentID->setObjectName(QString::fromUtf8("GetInstrumentID"));
        GetInstrumentID->setGeometry(QRect(1290, 630, 151, 31));
        OpenDevice = new QPushButton(centralWidget);
        OpenDevice->setObjectName(QString::fromUtf8("OpenDevice"));
        OpenDevice->setGeometry(QRect(1290, 670, 151, 151));
        ZCheck_Off = new QPushButton(centralWidget);
        ZCheck_Off->setObjectName(QString::fromUtf8("ZCheck_Off"));
        ZCheck_Off->setGeometry(QRect(1070, 650, 141, 51));
        ZCheck_On = new QPushButton(centralWidget);
        ZCheck_On->setObjectName(QString::fromUtf8("ZCheck_On"));
        ZCheck_On->setGeometry(QRect(1070, 590, 141, 51));
        IncrementVoltage = new QPushButton(centralWidget);
        IncrementVoltage->setObjectName(QString::fromUtf8("IncrementVoltage"));
        IncrementVoltage->setGeometry(QRect(880, 620, 141, 51));
        DecrementVoltage = new QPushButton(centralWidget);
        DecrementVoltage->setObjectName(QString::fromUtf8("DecrementVoltage"));
        DecrementVoltage->setGeometry(QRect(880, 680, 141, 51));
        GetVoltage = new QPushButton(centralWidget);
        GetVoltage->setObjectName(QString::fromUtf8("GetVoltage"));
        GetVoltage->setGeometry(QRect(880, 740, 141, 51));
        IV_Cycle = new QCheckBox(centralWidget);
        IV_Cycle->setObjectName(QString::fromUtf8("IV_Cycle"));
        IV_Cycle->setGeometry(QRect(1300, 120, 61, 31));
        IV_PlotWidget = new QCustomPlot(centralWidget);
        IV_PlotWidget->setObjectName(QString::fromUtf8("IV_PlotWidget"));
        IV_PlotWidget->setGeometry(QRect(10, 30, 621, 511));
        CurrentSample_PlotWidget = new QCustomPlot(centralWidget);
        CurrentSample_PlotWidget->setObjectName(QString::fromUtf8("CurrentSample_PlotWidget"));
        CurrentSample_PlotWidget->setGeometry(QRect(10, 570, 621, 251));
        CurrentSample_Start = new QPushButton(centralWidget);
        CurrentSample_Start->setObjectName(QString::fromUtf8("CurrentSample_Start"));
        CurrentSample_Start->setGeometry(QRect(640, 760, 61, 61));
        CurrentSample_Pause = new QPushButton(centralWidget);
        CurrentSample_Pause->setObjectName(QString::fromUtf8("CurrentSample_Pause"));
        CurrentSample_Pause->setGeometry(QRect(720, 760, 61, 61));
        CurrentSample_Stop = new QPushButton(centralWidget);
        CurrentSample_Stop->setObjectName(QString::fromUtf8("CurrentSample_Stop"));
        CurrentSample_Stop->setGeometry(QRect(800, 760, 61, 61));
        IV_Start = new QPushButton(centralWidget);
        IV_Start->setObjectName(QString::fromUtf8("IV_Start"));
        IV_Start->setGeometry(QRect(640, 460, 61, 61));
        IV_Pause = new QPushButton(centralWidget);
        IV_Pause->setObjectName(QString::fromUtf8("IV_Pause"));
        IV_Pause->setGeometry(QRect(720, 460, 61, 61));
        IV_Stop = new QPushButton(centralWidget);
        IV_Stop->setObjectName(QString::fromUtf8("IV_Stop"));
        IV_Stop->setGeometry(QRect(800, 460, 61, 61));
        IV_SavePath_Field = new QPlainTextEdit(centralWidget);
        IV_SavePath_Field->setObjectName(QString::fromUtf8("IV_SavePath_Field"));
        IV_SavePath_Field->setGeometry(QRect(640, 370, 511, 51));
        IV_StartVoltage_Field = new QPlainTextEdit(centralWidget);
        IV_StartVoltage_Field->setObjectName(QString::fromUtf8("IV_StartVoltage_Field"));
        IV_StartVoltage_Field->setGeometry(QRect(1240, 210, 41, 31));
        IV_EndVoltage_Field = new QPlainTextEdit(centralWidget);
        IV_EndVoltage_Field->setObjectName(QString::fromUtf8("IV_EndVoltage_Field"));
        IV_EndVoltage_Field->setGeometry(QRect(1420, 210, 41, 31));
        IV_VoltageIncrement_Field = new QPlainTextEdit(centralWidget);
        IV_VoltageIncrement_Field->setObjectName(QString::fromUtf8("IV_VoltageIncrement_Field"));
        IV_VoltageIncrement_Field->setGeometry(QRect(1240, 300, 41, 31));
        IV_IncreaseSweepCount = new QPushButton(centralWidget);
        IV_IncreaseSweepCount->setObjectName(QString::fromUtf8("IV_IncreaseSweepCount"));
        IV_IncreaseSweepCount->setGeometry(QRect(1270, 120, 21, 23));
        IV_DecreaseSweepCount = new QPushButton(centralWidget);
        IV_DecreaseSweepCount->setObjectName(QString::fromUtf8("IV_DecreaseSweepCount"));
        IV_DecreaseSweepCount->setGeometry(QRect(1270, 140, 21, 23));
        IV_SweepControls_Label = new QLabel(centralWidget);
        IV_SweepControls_Label->setObjectName(QString::fromUtf8("IV_SweepControls_Label"));
        IV_SweepControls_Label->setGeometry(QRect(1220, 0, 271, 61));
        IV_SweepsCount_Label = new QLabel(centralWidget);
        IV_SweepsCount_Label->setObjectName(QString::fromUtf8("IV_SweepsCount_Label"));
        IV_SweepsCount_Label->setGeometry(QRect(1210, 80, 91, 41));
        IV_StartVoltage_Label = new QLabel(centralWidget);
        IV_StartVoltage_Label->setObjectName(QString::fromUtf8("IV_StartVoltage_Label"));
        IV_StartVoltage_Label->setGeometry(QRect(1200, 180, 121, 21));
        IV_EndVoltage_Label = new QLabel(centralWidget);
        IV_EndVoltage_Label->setObjectName(QString::fromUtf8("IV_EndVoltage_Label"));
        IV_EndVoltage_Label->setGeometry(QRect(1380, 180, 121, 21));
        IV_VoltageIncrement_Label = new QLabel(centralWidget);
        IV_VoltageIncrement_Label->setObjectName(QString::fromUtf8("IV_VoltageIncrement_Label"));
        IV_VoltageIncrement_Label->setGeometry(QRect(1190, 270, 141, 21));
        IV_AddToSweepQueue = new QPushButton(centralWidget);
        IV_AddToSweepQueue->setObjectName(QString::fromUtf8("IV_AddToSweepQueue"));
        IV_AddToSweepQueue->setGeometry(QRect(1190, 450, 331, 71));
        IV_Pause_Label = new QLabel(centralWidget);
        IV_Pause_Label->setObjectName(QString::fromUtf8("IV_Pause_Label"));
        IV_Pause_Label->setGeometry(QRect(1390, 270, 101, 21));
        IV_Pause_Field = new QPlainTextEdit(centralWidget);
        IV_Pause_Field->setObjectName(QString::fromUtf8("IV_Pause_Field"));
        IV_Pause_Field->setGeometry(QRect(1420, 300, 41, 31));
        IV_SweepsCount_Field = new QPlainTextEdit(centralWidget);
        IV_SweepsCount_Field->setObjectName(QString::fromUtf8("IV_SweepsCount_Field"));
        IV_SweepsCount_Field->setGeometry(QRect(1220, 120, 41, 31));
        IV_LoadParameters = new QPushButton(centralWidget);
        IV_LoadParameters->setObjectName(QString::fromUtf8("IV_LoadParameters"));
        IV_LoadParameters->setGeometry(QRect(1190, 370, 161, 51));
        IV_LoadParameters->setStyleSheet(QString::fromUtf8("#IV_LoadParameters\n"
"{\n"
"	font: 75 8pt \"Arial\";\n"
"	rgb: (15, 159, 180);\n"
"}\n"
""));
        IV_SaveParameters = new QPushButton(centralWidget);
        IV_SaveParameters->setObjectName(QString::fromUtf8("IV_SaveParameters"));
        IV_SaveParameters->setGeometry(QRect(1360, 370, 161, 51));
        IV_Progress_Label = new QLabel(centralWidget);
        IV_Progress_Label->setObjectName(QString::fromUtf8("IV_Progress_Label"));
        IV_Progress_Label->setGeometry(QRect(1370, 120, 141, 31));
        IV_SaveSelectedSweeps = new QPushButton(centralWidget);
        IV_SaveSelectedSweeps->setObjectName(QString::fromUtf8("IV_SaveSelectedSweeps"));
        IV_SaveSelectedSweeps->setGeometry(QRect(1020, 310, 131, 51));
        IV_SaveAllSweeps = new QPushButton(centralWidget);
        IV_SaveAllSweeps->setObjectName(QString::fromUtf8("IV_SaveAllSweeps"));
        IV_SaveAllSweeps->setGeometry(QRect(880, 310, 131, 51));
        IV_SweepTable = new QTableWidget(centralWidget);
        IV_SweepTable->setObjectName(QString::fromUtf8("IV_SweepTable"));
        IV_SweepTable->setGeometry(QRect(640, 20, 521, 131));
        IV_SetSavePath = new QPushButton(centralWidget);
        IV_SetSavePath->setObjectName(QString::fromUtf8("IV_SetSavePath"));
        IV_SetSavePath->setGeometry(QRect(640, 310, 101, 51));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 540, 1511, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(1160, 10, 20, 521));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(640, 430, 521, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(640, 290, 521, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        IV_SweepAverageTable = new QTableWidget(centralWidget);
        IV_SweepAverageTable->setObjectName(QString::fromUtf8("IV_SweepAverageTable"));
        IV_SweepAverageTable->setGeometry(QRect(640, 170, 521, 111));
        VoltageOff = new QPushButton(centralWidget);
        VoltageOff->setObjectName(QString::fromUtf8("VoltageOff"));
        VoltageOff->setGeometry(QRect(1070, 770, 141, 51));
        VoltageOn = new QPushButton(centralWidget);
        VoltageOn->setObjectName(QString::fromUtf8("VoltageOn"));
        VoltageOn->setGeometry(QRect(1070, 710, 141, 51));
        IV_Autoscale = new QCheckBox(centralWidget);
        IV_Autoscale->setObjectName(QString::fromUtf8("IV_Autoscale"));
        IV_Autoscale->setGeometry(QRect(10, 0, 70, 17));
        IV_ZoomInX = new QPushButton(centralWidget);
        IV_ZoomInX->setObjectName(QString::fromUtf8("IV_ZoomInX"));
        IV_ZoomInX->setGeometry(QRect(90, 0, 31, 23));
        IV_ZoomInY = new QPushButton(centralWidget);
        IV_ZoomInY->setObjectName(QString::fromUtf8("IV_ZoomInY"));
        IV_ZoomInY->setGeometry(QRect(180, 0, 31, 23));
        IV_ZoomOutX = new QPushButton(centralWidget);
        IV_ZoomOutX->setObjectName(QString::fromUtf8("IV_ZoomOutX"));
        IV_ZoomOutX->setGeometry(QRect(130, 0, 31, 23));
        IV_ZoomOutY = new QPushButton(centralWidget);
        IV_ZoomOutY->setObjectName(QString::fromUtf8("IV_ZoomOutY"));
        IV_ZoomOutY->setGeometry(QRect(220, 0, 31, 23));
        CurrentSample_Autoscale = new QCheckBox(centralWidget);
        CurrentSample_Autoscale->setObjectName(QString::fromUtf8("CurrentSample_Autoscale"));
        CurrentSample_Autoscale->setGeometry(QRect(10, 550, 70, 17));
        CurrentSample_ZoomOutY = new QPushButton(centralWidget);
        CurrentSample_ZoomOutY->setObjectName(QString::fromUtf8("CurrentSample_ZoomOutY"));
        CurrentSample_ZoomOutY->setGeometry(QRect(150, 550, 31, 23));
        CurrentSample_ZoomInY = new QPushButton(centralWidget);
        CurrentSample_ZoomInY->setObjectName(QString::fromUtf8("CurrentSample_ZoomInY"));
        CurrentSample_ZoomInY->setGeometry(QRect(110, 550, 31, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1526, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        GetInstrumentID->setText(QCoreApplication::translate("MainWindow", "get instrument ID", nullptr));
        OpenDevice->setText(QCoreApplication::translate("MainWindow", "Open Device", nullptr));
        ZCheck_Off->setText(QCoreApplication::translate("MainWindow", "zch off", nullptr));
        ZCheck_On->setText(QCoreApplication::translate("MainWindow", "zch on", nullptr));
        IncrementVoltage->setText(QCoreApplication::translate("MainWindow", "Increase Voltage", nullptr));
        DecrementVoltage->setText(QCoreApplication::translate("MainWindow", "Decrease Voltage", nullptr));
        GetVoltage->setText(QCoreApplication::translate("MainWindow", "getvoltage", nullptr));
        IV_Cycle->setText(QCoreApplication::translate("MainWindow", "Cycle?", nullptr));
        CurrentSample_Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        CurrentSample_Pause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        CurrentSample_Stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        IV_Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        IV_Pause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        IV_Stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        IV_IncreaseSweepCount->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        IV_DecreaseSweepCount->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        IV_SweepControls_Label->setText(QCoreApplication::translate("MainWindow", "Sweep Controls", nullptr));
        IV_SweepsCount_Label->setText(QCoreApplication::translate("MainWindow", "Sweep count", nullptr));
        IV_StartVoltage_Label->setText(QCoreApplication::translate("MainWindow", "Start Voltage", nullptr));
        IV_EndVoltage_Label->setText(QCoreApplication::translate("MainWindow", "End Voltage", nullptr));
        IV_VoltageIncrement_Label->setText(QCoreApplication::translate("MainWindow", "Voltage Increment", nullptr));
        IV_AddToSweepQueue->setText(QCoreApplication::translate("MainWindow", "Add to sweep queue", nullptr));
        IV_Pause_Label->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        IV_LoadParameters->setText(QCoreApplication::translate("MainWindow", "Load Parameters", nullptr));
        IV_SaveParameters->setText(QCoreApplication::translate("MainWindow", "Save Parameters", nullptr));
        IV_Progress_Label->setText(QCoreApplication::translate("MainWindow", "Progress", nullptr));
        IV_SaveSelectedSweeps->setText(QCoreApplication::translate("MainWindow", "Save Selected", nullptr));
        IV_SaveAllSweeps->setText(QCoreApplication::translate("MainWindow", "Save All Sweeps", nullptr));
        IV_SetSavePath->setText(QCoreApplication::translate("MainWindow", "Save Path", nullptr));
        VoltageOff->setText(QCoreApplication::translate("MainWindow", "Voltage Off", nullptr));
        VoltageOn->setText(QCoreApplication::translate("MainWindow", "Voltage On", nullptr));
        IV_Autoscale->setText(QCoreApplication::translate("MainWindow", "Autoscale", nullptr));
        IV_ZoomInX->setText(QCoreApplication::translate("MainWindow", "+x", nullptr));
        IV_ZoomInY->setText(QCoreApplication::translate("MainWindow", "+y", nullptr));
        IV_ZoomOutX->setText(QCoreApplication::translate("MainWindow", "-x", nullptr));
        IV_ZoomOutY->setText(QCoreApplication::translate("MainWindow", "-y", nullptr));
        CurrentSample_Autoscale->setText(QCoreApplication::translate("MainWindow", "Autoscale", nullptr));
        CurrentSample_ZoomOutY->setText(QCoreApplication::translate("MainWindow", "-y", nullptr));
        CurrentSample_ZoomInY->setText(QCoreApplication::translate("MainWindow", "+y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
