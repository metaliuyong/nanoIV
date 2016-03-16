#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>

#include "typeconversions.h"
#include "session.h"
#include "currentsampleprotocol.h"
#include "ivprotocol.h"



void MainWindow::IV_Check_All_Fields_OK()
{
    iv_all_fields_ok_ = true;

    IV_Check_SweepsCount_Field_OK();
    IV_Check_StartVoltage_Field_OK();
    IV_Check_EndVoltage_Field_OK();
    IV_Check_VoltageIncrement_Field_OK();
    IV_Check_Pause_Field_OK();

    if(iv_sweepscount_field_ok_ == false)
    {
        iv_all_fields_ok_ = false;
    }

    if(iv_startvoltage_field_ok_ == false)
    {
        iv_all_fields_ok_ = false;
    }

    if(iv_endvoltage_field_ok_ == false)
    {
        iv_all_fields_ok_ = false;
    }

    if(iv_voltageincrement_field_ok_ == false)
    {
        iv_all_fields_ok_ = false;
    }

    if(iv_pause_field_ok_ == false)
    {
        iv_all_fields_ok_ = false;
    }

    if(iv_all_fields_ok_ == false)
    {

            DisableNeutralButton(ui->IV_AddToSweepQueue);

    }

    else
    {
            if(ivprotocol_->started() == false)
            {
                EnableNeutralButton(ui->IV_AddToSweepQueue);
            }

    }

    return;
}



void MainWindow::IV_SetLabel_OK(QLabel* label, bool ok)
{
    if(ok)
    {
        label->setStyleSheet("QLabel { background-color : ;font: bold 14px 'Arial'; color : rgb(0, 172, 233); }");
    }

    else
    {
        label->setStyleSheet("QLabel { background-color : ; font: bold 14px 'Arial'; color : rgb(212, 63, 63); }");
    }

    return;
}

void MainWindow::IV_Check_SweepsCount_Field_OK()
{
    iv_sweepscount_field_ok_ = true;

    int fieldtext_int = QStringToInt(ui->IV_SweepsCount_Field->toPlainText());

    if(fieldtext_int <= 0)
    {
        iv_sweepscount_field_ok_ = false;
    }

    IV_SetLabel_OK(ui->IV_SweepsCount_Label, iv_sweepscount_field_ok_);

    return;
}

void MainWindow::on_IV_SweepsCount_Field_textChanged()
{

    IV_Check_All_Fields_OK();

    return;
}

void MainWindow::on_IV_IncreaseSweepCount_clicked()
{
    unsigned int sweepcount = QStringToInt(ui->IV_SweepsCount_Field->toPlainText());
    unsigned int newsweepcount = sweepcount + 1;

    QString newsweepcount_qstring = UIntToQString(newsweepcount);

    ui->IV_SweepsCount_Field->setPlainText(newsweepcount_qstring);

    IV_Check_SweepsCount_Field_OK();

    return;
}

void MainWindow::on_IV_DecreaseSweepCount_clicked()
{
    int sweepcount = QStringToInt(ui->IV_SweepsCount_Field->toPlainText());
    int newsweepcount = sweepcount - 1;

    if(newsweepcount < 0)
    {
        newsweepcount = 0;
    }

    QString newsweepcount_qstring = UIntToQString(newsweepcount);

    ui->IV_SweepsCount_Field->setPlainText(newsweepcount_qstring);

    IV_Check_SweepsCount_Field_OK();

    return;
}



void MainWindow::IV_Check_StartVoltage_Field_OK()
{
    iv_startvoltage_field_ok_ = true;



    float startvoltage = QStringToFloat(ui->IV_StartVoltage_Field->toPlainText());

    float endvoltage = QStringToFloat(ui->IV_EndVoltage_Field->toPlainText());

    if(abs(startvoltage) > Session::MAXVOLTAGE())
    {
        iv_startvoltage_field_ok_ = false;
    }

    if(startvoltage > endvoltage)
    {
        iv_startvoltage_field_ok_ = false;
    }

    if(ui->IV_StartVoltage_Field->toPlainText() == NULL)
    {
        iv_startvoltage_field_ok_ = false;
    }



    IV_SetLabel_OK(ui->IV_StartVoltage_Label, iv_startvoltage_field_ok_);

    return;
}

void MainWindow::on_IV_StartVoltage_Field_textChanged()
{
    IV_Check_All_Fields_OK();

    return;
}

void MainWindow::IV_Check_EndVoltage_Field_OK()
{
    iv_endvoltage_field_ok_ = true;

    float startvoltage = QStringToFloat(ui->IV_StartVoltage_Field->toPlainText());

    float endvoltage = QStringToFloat(ui->IV_EndVoltage_Field->toPlainText());

    if(abs(endvoltage) > Session::MAXVOLTAGE())
    {
        iv_endvoltage_field_ok_ = false;
    }

    if(startvoltage > endvoltage)
    {
        iv_endvoltage_field_ok_ = false;
    }

    if(ui->IV_EndVoltage_Field->toPlainText() == NULL)
    {
        iv_endvoltage_field_ok_ = false;
    }

    IV_SetLabel_OK(ui->IV_EndVoltage_Label, iv_endvoltage_field_ok_);

    return;
}

void MainWindow::on_IV_EndVoltage_Field_textChanged()
{
    IV_Check_All_Fields_OK();

    return;
}


void MainWindow::IV_Check_VoltageIncrement_Field_OK()
{
    iv_voltageincrement_field_ok_ = true;

    float voltageincrement = QStringToFloat(ui->IV_VoltageIncrement_Field->toPlainText());
    float startvoltage = QStringToFloat(ui->IV_StartVoltage_Field->toPlainText());
    float endvoltage = QStringToFloat(ui->IV_EndVoltage_Field->toPlainText());


    if(voltageincrement <= 0)
    {
        iv_voltageincrement_field_ok_ = false;
    }

    if(!IsInteger((endvoltage - startvoltage)/voltageincrement))
    {
        iv_voltageincrement_field_ok_ = false;
    }

    if(ui->IV_VoltageIncrement_Field->toPlainText() == NULL)
    {
        iv_voltageincrement_field_ok_ = false;
    }

    IV_SetLabel_OK(ui->IV_VoltageIncrement_Label, iv_voltageincrement_field_ok_);


    return;
}


void MainWindow::on_IV_VoltageIncrement_Field_textChanged()
{
    IV_Check_All_Fields_OK();


    return;
}



void MainWindow::IV_Check_Pause_Field_OK()
{

    iv_pause_field_ok_ = true;

    float pausetime_ = QStringToFloat(ui->IV_Pause_Field->toPlainText());

    if(pausetime_ <= 0)
    {
        iv_pause_field_ok_ = false;
    }

    if(ui->IV_Pause_Field->toPlainText() == NULL)
    {
        iv_pause_field_ok_ = false;
    }

    IV_SetLabel_OK(ui->IV_Pause_Label, iv_pause_field_ok_);

    return;
}

void MainWindow::on_IV_Pause_Field_textChanged()
{
    IV_Check_All_Fields_OK();

    return;
}

void MainWindow::on_IV_LoadParameters_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), parsdirectory_, tr("Parameter files (*.par)"));

    if(!(filename == NULL))
    {



        IV_LoadParameters(filename);
    }
    return;
}

void MainWindow::IV_LoadParameters(QString filename)
{
    QFile parameterfile;
    parameterfile.setFileName(filename);
    parameterfile.open(QIODevice::ReadOnly);

    QTextStream parameterfile_stream;
    parameterfile_stream.setDevice(&parameterfile);

    QString placeholder;

    ////////////
    //SweepCount
    ////////////

    parameterfile_stream >> placeholder;
    parameterfile_stream >> placeholder;

    ui->IV_SweepsCount_Field->setPlainText(placeholder);

    ////////////
    //Cycle
    ////////////

    parameterfile_stream >> placeholder;
    parameterfile_stream >> placeholder;
    if(placeholder == "1")
    {
        ui->IV_Cycle->setChecked(true);
    }
    else
    {
        ui->IV_Cycle->setChecked(false);
    }

    //////////////
    //StartVoltage
    //////////////

    parameterfile_stream >> placeholder;
    parameterfile_stream >> placeholder;
    ui->IV_StartVoltage_Field->setPlainText(placeholder);

    ////////////
    //EndVoltage
    ////////////

    parameterfile_stream >> placeholder;
    parameterfile_stream >> placeholder;
    ui->IV_EndVoltage_Field->setPlainText(placeholder);

    //////////////////
    //VoltageIncrement
    //////////////////

    parameterfile_stream >> placeholder;
    parameterfile_stream >> placeholder;
    ui->IV_VoltageIncrement_Field->setPlainText(placeholder);

    ////////////
    //Pause
    ////////////

    parameterfile_stream >> placeholder;
    parameterfile_stream >> placeholder;

    //BUG HERE
    //ui->IV_Pause_Field->setPlainText(placeholder);

    return;
}



void MainWindow::on_IV_SaveParameters_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Open file"), parsdirectory_, tr("Parameter files (*.par)"));

    if(!(filename == NULL))
    {
        IV_SaveParameters(filename);
    }

    return;
}

void MainWindow::IV_SaveParameters(QString filename)
{
    QFile parameterfile;
    parameterfile.setFileName(filename);
    parameterfile.open(QIODevice::ReadWrite);

    QTextStream parameterfile_stream;
    parameterfile_stream.setDevice(&parameterfile);

    ////////////
    //SweepCount
    ////////////
    parameterfile_stream << "#SweepCount\n";
    parameterfile_stream << ui->IV_SweepsCount_Field->toPlainText();

    ////////////
    //Cycle
    ////////////
    parameterfile_stream << "\n#Cycle\n";
    if(ui->IV_Cycle->isChecked())
    {
        parameterfile_stream << "1\n";
    }
    else
    {
        parameterfile_stream << "0\n";
    }

    //////////////
    //StartVoltage
    //////////////
    parameterfile_stream << "#StartVoltage\n";
    parameterfile_stream << ui->IV_StartVoltage_Field->toPlainText();

    ////////////
    //EndVoltage
    ////////////
    parameterfile_stream << "\n#EndVoltage\n";
    parameterfile_stream << ui->IV_EndVoltage_Field->toPlainText();

    //////////////////
    //VoltageIncrement
    //////////////////
    parameterfile_stream << "\nVoltageIncrement\n";
    parameterfile_stream << ui->IV_VoltageIncrement_Field->toPlainText();

    ////////////
    //Pause
    ////////////
    parameterfile_stream << "\n#Pause\n";
    parameterfile_stream << ui->IV_Pause_Field->toPlainText();

    return;

}
