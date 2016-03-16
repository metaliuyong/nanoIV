#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>

#include "typeconversions.h"
#include "session.h"
#include "currentsampleprotocol.h"
#include "ivprotocol.h"
#include "ivsweepaverage.h"


void MainWindow::IV_UpdateProgress(int sweepnumber)
{
    IV_UpdateProgressLabel();
    IV_UpdateProgressHighlights(sweepnumber);

    return;
}

void MainWindow::IV_UpdateProgressLabel()
{
    QString progresslabel;

    int finishedsweeps = 0;
    int totalsweeps = ivprotocol_->sweeplist().size();

    for(int i = 0; i < totalsweeps; i++)
    {
        if(ivprotocol_->sweeplist()[i]->finished() == true)
        {
            finishedsweeps++;

        }
    }

    progresslabel = "Progress: " + QString::number(finishedsweeps) + "/" + QString::number(totalsweeps);

    ui->IV_Progress_Label->setText(progresslabel);

    return;
}

void MainWindow::IV_UpdateProgressHighlights(int sweepnumber)
{
    for(int i = 0; i < ui->IV_SweepTable->rowCount(); i++)
    {
        if(i < sweepnumber)
        {
            for(int j = 0; j < ui->IV_SweepTable->columnCount(); j++)
            {
                ui->IV_SweepTable->item(i, j)->setBackground(QColor(31, 218, 154));
            }
        }
        else if(i == sweepnumber)
        {

            for(int j = 0; j < ui->IV_SweepTable->columnCount(); j++)
            {
                ui->IV_SweepTable->item(i, j)->setBackground(QColor(233, 188, 27));

            }
        }
        else
        {
            for(int j = 0; j < ui->IV_SweepTable->columnCount(); j++)
            {
                ui->IV_SweepTable->item(i, j)->setBackground(QColor(238, 75, 62));
            }
        }
    }

    return;

}

void MainWindow::on_IV_AddToSweepQueue_clicked()
{
    unsigned int sweepscount = QStringToUInt(ui->IV_SweepsCount_Field->toPlainText());
    float startvoltage = QStringToFloat(ui->IV_StartVoltage_Field->toPlainText());
    float endvoltage = QStringToFloat(ui->IV_EndVoltage_Field->toPlainText());
    float voltageincrement = QStringToFloat(ui->IV_VoltageIncrement_Field->toPlainText());
    float pausetime = QStringToFloat(ui->IV_Pause_Field->toPlainText());
    bool cycle = ui->IV_Cycle->isChecked();


    for(unsigned int i = 0; i < sweepscount; i++)
    {
        ivprotocol_->AddSweepToSweepList(startvoltage, endvoltage, voltageincrement, pausetime);

        if(cycle == true)
        {

            ivprotocol_->AddSweepToSweepList(endvoltage, startvoltage, voltageincrement, pausetime);

        }
    }

    return;
}



void MainWindow::IV_AddSweepToSweepTable(const IVSweep& ivsweep)
{

    unsigned int rownumber = ivprotocol_->sweeplist().size() - 1;

    ui->IV_SweepTable->insertRow(rownumber);



    QTableWidgetItem* plotcheckbox = new QTableWidgetItem();
    plotcheckbox->setCheckState(Qt::Checked);

    QTableWidgetItem* averagecheckbox = new QTableWidgetItem();
    averagecheckbox->setCheckState(Qt::Checked);

    QTableWidgetItem* savecheckbox = new QTableWidgetItem();
    savecheckbox->setCheckState(Qt::Checked);

    QTableWidgetItem* erasebutton = new QTableWidgetItem();
    erasebutton->setCheckState(Qt::Unchecked);


    ui->IV_SweepTable->setItem(rownumber, 0, plotcheckbox);
    ui->IV_SweepTable->setItem(rownumber, 1, averagecheckbox);
    ui->IV_SweepTable->setItem(rownumber, 2, savecheckbox);
    ui->IV_SweepTable->setItem(rownumber, 8, erasebutton);

    for(int i = 0; i < 5; i++)
    {
        ui->IV_SweepTable->setItem(rownumber, 3 + i, new QTableWidgetItem());
    }

    QString startvoltage_qstring = QString::number(ivsweep.startvoltage());

    QString endvoltage_qstring = QString::number(ivsweep.endvoltage());

    QString voltageincrement_qstring = QString::number(ivsweep.voltageincrement());

    QString direction_qstring;

    if(ivsweep.direction() == forward)
    {
        direction_qstring = "F";
    }

    else
    {
        direction_qstring = "R";
    }

    QString pause_qstring = QString::number(ivsweep.pausetime());

    ui->IV_SweepTable->item(rownumber, 3)->setText(startvoltage_qstring);
    ui->IV_SweepTable->item(rownumber, 4)->setText(endvoltage_qstring);
    ui->IV_SweepTable->item(rownumber, 5)->setText(voltageincrement_qstring);
    ui->IV_SweepTable->item(rownumber, 6)->setText(direction_qstring);
    ui->IV_SweepTable->item(rownumber, 7)->setText(pause_qstring);

    return;
}



void MainWindow::IV_DeleteSweepFromSweepTable(unsigned int sweepnumber)
{

    ui->IV_SweepTable->removeRow(sweepnumber);

    return;
}



void MainWindow::IV_SweepTableChanged(QTableWidgetItem* item)
{


    IVSweep* ivsweep = ivprotocol_->sweeplist()[item->row()];
    if(item->column() == 0) //show plot
    {
        if(item->checkState() == Qt::Checked)
        {
            ivprotocol_->plot()->ShowGraph(ivsweep->parentgraph(), true);
        }
        else
        {
            ivprotocol_->plot()->ShowGraph(ivsweep->parentgraph(), false);
        }
    }

    else if(item->column() == 1) //include in average
    {
        if(item->checkState() == Qt::Checked)
        {
            ivsweep->SetIncludeInAverage(true);
        }
        else
        {
            ivsweep->SetIncludeInAverage(false);
        }

        ivsweep->parentaverage()->UpdateAverage();
        ivprotocol_->plot()->UpdateAveragePlot(ivsweep->parentaverage()->parentgraph(), ivsweep->parentaverage()->xaverage(), ivsweep->parentaverage()->yaverage());
    }

    else if(item->column() == 2) //save
    {
        if(item->checkState() == Qt::Checked)
        {
            ivsweep->SetSave(true);
        }
        else
        {
            ivsweep->SetSave(false);
        }
    }

    else if(item->column() == 8) //delete sweep
    {

        if(ivprotocol_->started())
        {
            item->setCheckState(Qt::Unchecked);
        }
        else
        {
            if(item->checkState() == Qt::Checked)
            {
                ivprotocol_->DeleteSweep(item->row());
            }
        }
    }

    return;
}

void MainWindow::IV_AddSweepAverageToSweepAverageTable(IVSweepAverage& ivsweepaverage)
{
    unsigned int rownumber = ivprotocol_->sweepaveragelist().size() - 1;

    ui->IV_SweepAverageTable->insertRow(rownumber);

    QTableWidgetItem* plotcheckbox = new QTableWidgetItem();
    plotcheckbox->setCheckState(Qt::Unchecked);

    QTableWidgetItem* savecheckbox = new QTableWidgetItem();
    savecheckbox->setCheckState(Qt::Checked);



    ui->IV_SweepAverageTable->setItem(rownumber, 0, plotcheckbox);
    ui->IV_SweepAverageTable->setItem(rownumber, 1, savecheckbox);


    for(int i = 0; i < 4; i++)
    {
        ui->IV_SweepAverageTable->setItem(rownumber, 2 + i, new QTableWidgetItem());
    }

    QString startvoltage_qstring = QString::number(ivsweepaverage.startvoltage());

    QString endvoltage_qstring = QString::number(ivsweepaverage.endvoltage());

    QString voltageincrement_qstring = QString::number(ivsweepaverage.voltageincrement());

    QString direction_qstring;

    if(ivsweepaverage.direction() == forward)
    {
        direction_qstring = "F";
    }

    else
    {
        direction_qstring = "R";
    }


    ui->IV_SweepAverageTable->item(rownumber, 2)->setText(startvoltage_qstring);
    ui->IV_SweepAverageTable->item(rownumber, 3)->setText(endvoltage_qstring);
    ui->IV_SweepAverageTable->item(rownumber, 4)->setText(voltageincrement_qstring);
    ui->IV_SweepAverageTable->item(rownumber, 5)->setText(direction_qstring);

    return;
}

void MainWindow::IV_DeleteSweepAverageFromSweepAverageTable(IVSweepAverage* ivsweepaverage)
{
    QString sweep_startvoltage_qstring = QString::number(ivsweepaverage->startvoltage());
    QString sweep_endvoltage_qstring = QString::number(ivsweepaverage->endvoltage());
    QString sweep_voltageincrement_qstring = QString::number(ivsweepaverage->voltageincrement());
    QString sweep_direction_qstring;
    if(ivsweepaverage->direction() == forward)
    {
        sweep_direction_qstring = "F";
    }
    else
    {
        sweep_direction_qstring = "R";
    }


    for(int i = 0; i < ui->IV_SweepAverageTable->rowCount(); i++)
    {
        if(sweep_startvoltage_qstring == ui->IV_SweepAverageTable->item(i, 2)->text())
        {
            if(sweep_endvoltage_qstring == ui->IV_SweepAverageTable->item(i, 3)->text())
            {
                if(sweep_voltageincrement_qstring == ui->IV_SweepAverageTable->item(i, 4)->text())
                {
                    if(sweep_direction_qstring == ui->IV_SweepAverageTable->item(i, 5)->text())
                    {
                        ui->IV_SweepAverageTable->removeRow(i);
                    }
                }
            }
        }
    }
    return;
}

void MainWindow::IV_SweepAverageTableChanged(QTableWidgetItem *item)
{
    IVSweepAverage* ivsweepaverage = ivprotocol_->sweepaveragelist()[item->row()];

    if(item->column() == 0)
    {
        if(item->checkState() == Qt::Checked)
        {
            ivprotocol_->plot()->ShowGraph(ivsweepaverage->parentgraph(), true);
        }
        else
        {
            ivprotocol_->plot()->ShowGraph(ivsweepaverage->parentgraph(), false);
        }
    }

    else if(item->column() == 1)
    {
        if(item->checkState() == Qt::Checked)
        {
            ivsweepaverage->SetSave(true);
        }
        else
        {
            ivsweepaverage->SetSave(false);
        }
    }

    return;
}

void MainWindow::on_IV_Autoscale_clicked()
{
    if(ui->IV_Autoscale->checkState() == Qt::Checked)
    {
        ivprotocol_->plot()->SetAutoscaleX(true);
        ivprotocol_->plot()->SetAutoscaleY(true);
    }

    else
    {
        ivprotocol_->plot()->SetAutoscaleX(false);
        ivprotocol_->plot()->SetAutoscaleY(false);
    }


    return;
}

void MainWindow::on_IV_ZoomOutX_clicked()
{
    ivprotocol_->plot()->ZoomOutX();
    return;
}

void MainWindow::on_IV_ZoomInX_clicked()
{
    ivprotocol_->plot()->ZoomInX();
    return;
}


void MainWindow::on_IV_ZoomOutY_clicked()
{
    ivprotocol_->plot()->ZoomOutY();
    return;
}

void MainWindow::on_IV_ZoomInY_clicked()
{
    ivprotocol_->plot()->ZoomInY();
    return;
}



