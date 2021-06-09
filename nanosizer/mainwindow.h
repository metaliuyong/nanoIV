#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QLabel>



class QTableWidgetItem;
class QTextStream;
class QPushButton;

class Session;
class Plot;

class IVSweep;
class IVSweepAverage;
class IVProtocol;
class CurrentSampleProtocol;
class MeasurementProtocol;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void RequestCoProtocolPause();

public:

    //////////////////////////
    //Initialization functions
    //////////////////////////

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void SetUp_UI();

    void SetUp_StyleSheets();

    void SetUp_IV_Labels();

    void SetUp_IV_SweepTable();

    void SetUp_IV_SweepAverageTable();

    void SetUp_IV_Fields();

    void SetUp_CurrentSample_Fields();

    void SetUp_Buttons();

    void Bind_Objects(IVProtocol* ivprotocol, CurrentSampleProtocol* currentsampleprotocol, Plot* ivplot, Plot* currentsampleplot);

    void InitializePlots(Plot* currentsampleplot, Plot* ivplot);

    ////////////////////////
    //IV parameter functions
    ////////////////////////

    void IV_LoadParameters(QString filename);

    void IV_SaveParameters(QString filename);

    void IV_SetLabel_OK(QLabel* label, bool ok);

    void IV_Check_All_Fields_OK();

    void IV_Check_SweepsCount_Field_OK();

    void IV_Check_StartVoltage_Field_OK();

    void IV_Check_EndVoltage_Field_OK();

    void IV_Check_VoltageIncrement_Field_OK();

    void IV_Check_Pause_Field_OK();

    bool CheckStreamEmpty(QTextStream* stream);

    bool CreateOverwriteFileDialogue(QString string);


private slots:

    ///////////////
    //Button clicks
    ///////////////

    void Enable_AddToSweepQueue_Button();

    void EnableNeutralButton(QPushButton* button);

    void DisableNeutralButton(QPushButton* button);

    void EnableGreenButton(QPushButton* button);

    void DisableGreenButton(QPushButton* button);

    void EnableYellowButton(QPushButton* button);

    void DisableYellowButton(QPushButton* button);

    void EnableRedButton(QPushButton* button);

    void DisableRedButton(QPushButton* button);


    /////////////
    //IV protocol
    /////////////

    void on_IV_Start_clicked();

    void on_IV_Pause_clicked();

    void on_IV_Unpause_clicked();

    void on_IV_Stop_clicked();

    void on_IV_SweepsCount_Field_textChanged();

    void on_IV_IncreaseSweepCount_clicked();

    void on_IV_DecreaseSweepCount_clicked();



    void on_IV_StartVoltage_Field_textChanged();

    void on_IV_EndVoltage_Field_textChanged();

    void on_IV_VoltageIncrement_Field_textChanged();

    void on_IV_Pause_Field_textChanged();

    void on_IV_AddToSweepQueue_clicked();


    void on_IV_LoadParameters_clicked();

    void on_IV_SaveParameters_clicked();

    void on_IV_SaveAllSweeps_clicked();

    void on_IV_SaveSelectedSweeps_clicked();

    void on_IV_SetSavePath_clicked();




    /////////////////////////
    //Current sample protocol
    /////////////////////////

    void on_CurrentSample_Start_clicked();

    void on_CurrentSample_Pause_clicked();

    void on_CurrentSample_Unpause_clicked();

    void on_CurrentSample_Stop_clicked();

    /////////////////
    //Direct controls
    /////////////////

    void on_OpenDevice_clicked();

    void on_IncrementVoltage_clicked();

    void on_DecrementVoltage_clicked();

    void on_GetVoltage_clicked();

    void on_GetInstrumentID_clicked();

    void on_ZCheck_Off_clicked();

    void on_ZCheck_On_clicked();



    /////////////////////////////
    //External UI update requests
    /////////////////////////////

    void IV_UpdateProgress(int sweepnumber);
    void IV_UpdateProgressLabel();
    void IV_UpdateProgressHighlights(int sweepnumber);


    void IV_AddSweepToSweepTable(const IVSweep& ivsweep);
    void IV_DeleteSweepFromSweepTable(unsigned int sweepnumber);
    void IV_SweepTableChanged(QTableWidgetItem* item);



    void IV_AddSweepAverageToSweepAverageTable(IVSweepAverage& ivsweepaverage);
    void IV_DeleteSweepAverageFromSweepAverageTable(IVSweepAverage* ivsweepaverage);
    void IV_SweepAverageTableChanged(QTableWidgetItem* item);


    void on_IV_Autoscale_clicked();

    void on_IV_AddToSweepQueue_pressed();

    void on_IV_AddToSweepQueue_released();

    void on_IV_LoadParameters_pressed();

    void on_IV_LoadParameters_released();

    void on_IV_SaveParameters_pressed();

    void on_IV_SaveParameters_released();

    void on_IV_SetSavePath_pressed();

    void on_IV_SetSavePath_released();

    void on_IV_SaveAllSweeps_pressed();

    void on_IV_SaveAllSweeps_released();

    void on_IV_SaveSelectedSweeps_pressed();

    void on_IV_SaveSelectedSweeps_released();

    void on_IV_Start_pressed();

    void on_IV_Start_released();

    void on_IV_Pause_pressed();

    void on_IV_Pause_released();

    void on_IV_Stop_pressed();

    void on_IV_Stop_released();

    void on_IV_ZoomOutX_clicked();

    void on_IV_ZoomInX_clicked();

    void on_IV_ZoomOutY_clicked();

    void on_IV_ZoomInY_clicked();


    void on_IV_ZoomInX_pressed();

    void on_IV_ZoomInX_released();

    void on_IV_ZoomOutX_pressed();

    void on_IV_ZoomOutX_released();

    void on_IV_ZoomInY_pressed();

    void on_IV_ZoomInY_released();

    void on_IV_ZoomOutY_pressed();

    void on_IV_ZoomOutY_released();


    void on_CurrentSample_Start_pressed();

    void on_CurrentSample_Start_released();

    void on_CurrentSample_Pause_pressed();

    void on_CurrentSample_Pause_released();

    void on_CurrentSample_Stop_pressed();

    void on_CurrentSample_Stop_released();

    void on_ZCheck_On_pressed();

    void on_ZCheck_On_released();

    void on_ZCheck_Off_pressed();

    void on_ZCheck_Off_released();

    void on_IncrementVoltage_pressed();

    void on_IncrementVoltage_released();

    void on_DecrementVoltage_pressed();

    void on_DecrementVoltage_released();

    void on_GetVoltage_pressed();

    void on_GetVoltage_released();

    void on_GetInstrumentID_pressed();

    void on_GetInstrumentID_released();

    void on_OpenDevice_pressed();

    void on_OpenDevice_released();

    void on_VoltageOn_clicked();

    void on_VoltageOff_clicked();

    void on_VoltageOn_pressed();

    void on_VoltageOn_released();

    void on_VoltageOff_pressed();

    void on_VoltageOff_released();


    std::vector<IVSweep*> SortSweepList(std::vector<IVSweep*>& sweeplist);
    void PrintSaveMatrix(std::vector<std::vector <std::string>> savematrix);










    void on_CurrentSample_Autoscale_clicked();

    void on_CurrentSample_ZoomOutY_clicked();

    void on_CurrentSample_ZoomInY_clicked();


    void on_CurrentSample_ZoomOutY_pressed();

    void on_CurrentSample_ZoomOutY_released();

    void on_CurrentSample_ZoomInY_pressed();

    void on_CurrentSample_ZoomInY_released();

    void on_actionZeroCorrectionOn_triggered();

    void on_actionZeroCorrectionOff_triggered();

private:
    Ui::MainWindow *ui;

    IVProtocol* ivprotocol_;
    CurrentSampleProtocol* currentsampleprotocol_;

    QThread* currentsamplethread_;
    QThread* ivthread_;

    bool iv_all_fields_ok_;
    bool iv_sweepscount_field_ok_;
    bool iv_startvoltage_field_ok_;
    bool iv_endvoltage_field_ok_;
    bool iv_voltageincrement_field_ok_;
    bool iv_pause_field_ok_;

    //int iv_progress_;

    QString parsdirectory_;
    QString defaultparsfilename_;
    QString savedirectory_;

    //////////////
    //Style Sheets
    //////////////
    QString neutralbutton_pressed_ss_;
    QString neutralbutton_released_ss_;

    QString greenbutton_pressed_ss_;
    QString greenbutton_released_ss_;

    QString bluebutton_pressed_ss_;
    QString bluebutton_released_ss_;

    QString yellowbutton_pressed_ss_;
    QString yellowbutton_released_ss_;

    QString redbutton_pressed_ss_;
    QString redbutton_released_ss_;

    QString mainlabel_ss_;

    QString regularlabel_ss_;

    QString field_ss_;



};

#endif // MAINWINDOW_H
