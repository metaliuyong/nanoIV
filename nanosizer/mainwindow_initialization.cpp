#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

#include "typeconversions.h"
#include "session.h"
#include "currentsampleprotocol.h"
#include "ivprotocol.h"

MainWindow::MainWindow( QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setWindowTitle("nanoIV");

    currentsamplethread_ = new QThread();
    ivthread_ = new QThread();

    parsdirectory_ = "C:/nanoIV/pars/";
    defaultparsfilename_ = "default.par";
    savedirectory_ = "C:/nanoIV/save/";

    IV_LoadParameters(parsdirectory_ + defaultparsfilename_);

    SetUp_UI();

    IV_Check_All_Fields_OK();

}

MainWindow::~MainWindow()
{
    //Close threads
    int i = 0;
    std::cerr << "0" << "\n";

    //currentsampleprotocol_->StopRoutine();
    std::cerr << "1" << "\n";

    currentsamplethread_->quit();
    std::cerr << "2" << "\n";

    //currentsamplethread_->wait();
    std::cerr << "3" << "\n";

    delete currentsamplethread_;
    std::cerr << "4" << "\n";


    //ivprotocol_->StopRoutine();
    std::cerr << "5" << "\n";

    ivthread_->quit();
    std::cerr << "6" << "\n";

    //ivthread_->wait();
    std::cerr << "7" << "\n";

    delete ivthread_;
    std::cerr << "8" << "\n";


    Session::EndSession();

    delete ui;
}


void MainWindow::Bind_Objects(IVProtocol* ivprotocol, CurrentSampleProtocol* currentsampleprotocol, Plot* ivplot, Plot* currentsampleplot)
{
    //bind protocol to this
    currentsampleprotocol_ = currentsampleprotocol;
    ivprotocol_ = ivprotocol;

    //bind protocol to protocol
    currentsampleprotocol_->SetCoProtocol(ivprotocol_);
    ivprotocol_->SetCoProtocol(ivprotocol_);

    //bind plot to protocol
    InitializePlots(currentsampleplot, ivplot);




    //push protocols to threads
    currentsampleprotocol_->moveToThread(currentsamplethread_);
    ivprotocol_->moveToThread(ivthread_);

    //connect protocols' and threads' signals to slots
    connect(currentsampleprotocol_, SIGNAL(RequestRunRoutine()), currentsamplethread_, SLOT(start()));
    connect(currentsamplethread_, SIGNAL(started()), currentsampleprotocol_, SLOT(RunRoutine()));
    connect(currentsampleprotocol_, SIGNAL(RequestEndRoutine()), currentsamplethread_, SLOT(quit()));


    connect(ivprotocol_, SIGNAL(RequestRunRoutine()), ivthread_, SLOT(start()));
    connect(ivthread_, SIGNAL(started()), ivprotocol_, SLOT(RunRoutine()));
    connect(ivprotocol_, SIGNAL(RequestEndRoutine()), ivthread_, SLOT(quit()));
    connect(ivprotocol_, SIGNAL(RequestEndRoutine()), this, SLOT(Enable_AddToSweepQueue_Button()));
    connect(ivprotocol_, SIGNAL(RequestEndRoutine()), this, SLOT(on_IV_Stop_clicked())); //new 7-29


    //connect protocols' pause and resume functions
    connect(currentsampleprotocol_, SIGNAL(RequestCoProtocolPause()), this, SLOT(on_IV_Pause_clicked()));
    connect(currentsampleprotocol_, SIGNAL(RequestCoProtocolUnpause()), this, SLOT(on_IV_Start_clicked()));

    //connect(ivprotocol_, SIGNAL(RequestCoProtocolPause()), this, SLOT(on_CurrentSample_Pause_clicked()));
    connect(ivprotocol_, SIGNAL(RequestCoProtocolPause()), this, SLOT(CurrentSample_Pause()));
    connect(ivprotocol_, SIGNAL(RequestCoProtocolUnpause()), this, SLOT(on_CurrentSample_Unpause_clicked()));

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //ADDED 8-18-2015 TO FIX ISSUE WHERE IVPROTOCOL PAUSES CURRENTSAMPLE, DOES NOT RESUME!
    //connect(ivprotocol_, SIGNAL(RequestCoProtocolUnpause()), this, SLOT(on_CurrentSample_Start_clicked()));
    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    //connect protocols signal to plot slot
    qRegisterMetaType<QVector<double>>("QVector<double>");
    qRegisterMetaType<QCPGraph*>("QCPGraph*");

    connect(currentsampleprotocol_, SIGNAL(RequestUpdatePlot(int, QVector<double>, QVector<double>)), currentsampleprotocol_->plot(), SLOT(UpdatePlot(int, QVector<double>, QVector<double>)));

    connect(ivprotocol_, SIGNAL(RequestUpdatePlot(QCPGraph*, QVector<double>, QVector<double>)), ivprotocol_->plot(), SLOT(UpdatePlot(QCPGraph*, QVector<double>, QVector<double>)));

    connect(ivprotocol_, SIGNAL(RequestUpdateAveragePlot(QCPGraph*, QVector<double>, QVector<double>)), ivprotocol_->plot(), SLOT(UpdateAveragePlot(QCPGraph*, QVector<double>, QVector<double>)));;

    connect(ivprotocol_, SIGNAL(RequestSetPlotStyleActiveForward(QCPGraph*)), ivprotocol_->plot(), SLOT(Set_PlotStyle_ActiveForward(QCPGraph*)));

    connect(ivprotocol_, SIGNAL(RequestSetPlotStyleInactiveForward(QCPGraph*)), ivprotocol_->plot(), SLOT(Set_PlotStyle_InactiveForward(QCPGraph*)));

    connect(ivprotocol_, SIGNAL(RequestSetPlotStyleAverageActiveForward(QCPGraph*)), ivprotocol_->plot(), SLOT(Set_PlotStyle_AverageActiveForward(QCPGraph*)));

    connect(ivprotocol_, SIGNAL(RequestSetPlotStyleAverageInactiveForward(QCPGraph*)), ivprotocol_->plot(), SLOT(Set_PlotStyle_AverageInactiveForward(QCPGraph*)));

    connect(ivprotocol_, SIGNAL(RequestSetPlotStyleActiveReverse(QCPGraph*)), ivprotocol_->plot(), SLOT(Set_PlotStyle_ActiveReverse(QCPGraph*)));

    connect(ivprotocol_, SIGNAL(RequestSetPlotStyleInactiveReverse(QCPGraph*)), ivprotocol_->plot(), SLOT(Set_PlotStyle_InactiveReverse(QCPGraph*)));

    connect(ivprotocol_, SIGNAL(RequestSetPlotStyleAverageActiveReverse(QCPGraph*)), ivprotocol_->plot(), SLOT(Set_PlotStyle_AverageActiveReverse(QCPGraph*)));

    connect(ivprotocol_, SIGNAL(RequestSetPlotStyleAverageInactiveReverse(QCPGraph*)), ivprotocol_->plot(), SLOT(Set_PlotStyle_AverageInactiveReverse(QCPGraph*)));

    //connect protocol progress to UI update progress element
    qRegisterMetaType<int>("int");

    connect(ivprotocol_, SIGNAL(RequestUpdateProgress(int)), this, SLOT(IV_UpdateProgress(int)));

    //connect protocol sweep list to UI update sweep list
    typedef std::vector<IVSweep*> ivsweepvec;
    qRegisterMetaType<ivsweepvec>("ivsweepvec");
    qRegisterMetaType<unsigned int>("unsigned int");


    connect(ivprotocol_, SIGNAL(RequestAddSweepToSweepTable(const IVSweep&)), this, SLOT(IV_AddSweepToSweepTable(const IVSweep&)));
    connect(ivprotocol_, SIGNAL(RequestDeleteSweepFromSweepTable(unsigned int)), this, SLOT(IV_DeleteSweepFromSweepTable(unsigned int)));
    connect(ui->IV_SweepTable, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(IV_SweepTableChanged(QTableWidgetItem*)));

    connect(ivprotocol_, SIGNAL(RequestAddSweepAverageToSweepAverageTable(IVSweepAverage&)), this, SLOT(IV_AddSweepAverageToSweepAverageTable(IVSweepAverage&)));
    connect(ivprotocol_, SIGNAL(RequestDeleteSweepAverageFromSweepAverageTable(IVSweepAverage*)), this, SLOT(IV_DeleteSweepAverageFromSweepAverageTable(IVSweepAverage*)));
    connect(ui->IV_SweepAverageTable, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(IV_SweepAverageTableChanged(QTableWidgetItem*)));





    return;
}

void MainWindow::InitializePlots(Plot* currentsampleplot, Plot* ivplot)
{
    currentsampleprotocol_->SetPlot(currentsampleplot);
    ivprotocol_->SetPlot(ivplot);

    currentsampleprotocol_->plot()->SetPlotWidget(ui->CurrentSample_PlotWidget);
    currentsampleprotocol_->plot()->AddGraph();

    ivprotocol_->plot()->SetPlotWidget(ui->IV_PlotWidget);

    currentsampleprotocol_->plot()->SetXAxisText("time (s)");
    currentsampleprotocol_->plot()->SetYAxisText("Current (A)");


    ivprotocol_->plot()->SetXAxisText("Voltage (V)");
    ivprotocol_->plot()->SetYAxisText("Current (A)");



    currentsampleprotocol_->plot()->plotwidget()->axisRect()->setRangeDrag(Qt::Vertical);
    currentsampleprotocol_->plot()->plotwidget()->axisRect()->setRangeZoom(Qt::Vertical);


    return;
}




