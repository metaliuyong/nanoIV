#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>

#include "typeconversions.h"
#include "session.h"
#include "currentsampleprotocol.h"
#include "ivprotocol.h"
#include "ivsweepaverage.h"
#include <vector>

#include "ptime.cpp"

#include "OverwriteFileDialogue.h"


void MainWindow::on_IV_SaveAllSweeps_clicked()
{

    std::vector<IVSweep*> sortedsweeplist;

    sortedsweeplist = SortSweepList(ivprotocol_->sweeplist());

    std::vector< std::vector<std::string> > savematrix;

    for(int i = 0; i < sortedsweeplist.size(); i++)
    {
        std::cerr << "i = " << i << ", " << sortedsweeplist[i]->startvoltage() << "\n";
    }

    int no_rows = 0;
    int no_cols = 0;
    IVSweep* sweep;
    IVSweep* comparesweep;
    std::cerr << "before" << "\n";
    for(int i = 0; i < sortedsweeplist.size(); i++)
    {

        sweep = sortedsweeplist[i];

        if(i != 0)
        {
            if(sweep->totalvoltages() > sortedsweeplist[i-1]->totalvoltages())
            {
                no_rows = sweep->totalvoltages();
            }
        }
        else
        {
            no_rows = sweep->totalvoltages();
        }

        no_cols = no_cols + 1;
        if( i == 0)
        {
            comparesweep = NULL;
        }
        else
        {
            comparesweep = sortedsweeplist[i - 1];
        }
        if(!(IVProtocol::CheckMatchingParameters(sweep, comparesweep)))
        {

            std::cerr << "no matching parameters!\n";
            //std::cerr << sweep->startvoltage() << "  " << sweep->endvoltage() << "  " << sweep->voltageincrement() << "\n";
            //std::cerr << comparesweep->startvoltage() << "  " << comparesweep->endvoltage() << "  " << comparesweep->voltageincrement() << "\n";
            no_cols = no_cols + 2;
        }
    }


    std::cerr << "after" << "\n";
    std::cerr << "cols = " << no_cols << "\n";
    std::cerr << "rows = " << no_rows << "\n";

    savematrix.resize( no_rows + 1, std::vector<std::string>(no_cols, ""));

    IVSweep* previoussweep;
    IVSweep* currentsweep;

    int currentcolumn = 0;

    int multicounter = 0;





    for(unsigned int i = 0; i < sortedsweeplist.size(); i++)
    {

        if(i == 0)
        {
            previoussweep = NULL;
        }
        else
        {
            previoussweep = sortedsweeplist[i - 1];
        }

        currentsweep = sortedsweeplist[i];


        if(!IVProtocol::CheckMatchingParameters(previoussweep, currentsweep)) //start new sweep type
        {

            multicounter = 0;
            if(!(i==0))
            {

                savematrix[0][currentcolumn] = "average";

                for(int j = 0; j < previoussweep->parentaverage()->totalvoltages(); j++)
                {

                    savematrix[j + 1][currentcolumn] = DoubleToStringScientific(previoussweep->parentaverage()->yaverage()[j]);

                }
                currentcolumn = currentcolumn + 1;
            }

            savematrix[0][currentcolumn] = "voltage";
            for(int j = 0; j < currentsweep->totalvoltages(); j++)
            {
                savematrix[j + 1][currentcolumn] = DoubleToString(currentsweep->x()[j]);
            }

            currentcolumn = currentcolumn + 1;

        }



        savematrix[0][currentcolumn] = DirectionToString(currentsweep->direction()) + ", " + FloatToString(currentsweep->pausetime());

        for(int j = 0; j < currentsweep->totalvoltages(); j++)
        {
            savematrix[j+1][currentcolumn] = DoubleToStringScientific(currentsweep->y()[j]);
        }

        currentcolumn = currentcolumn + 1;
        multicounter = multicounter + 1;
    }

    if(currentsweep->parentaverage()->save() == true && sortedsweeplist.size() > 1)
    {

        savematrix[0][currentcolumn] = "average";
        for(int j = 0; j < previoussweep->parentaverage()->totalvoltages(); j++)
        {
            savematrix[j + 1][currentcolumn] = DoubleToStringScientific(previoussweep->parentaverage()->yaverage()[j]);
        }
        currentcolumn = currentcolumn + 1;
    }



    std::cerr << "printing save matrix...\n";
    PrintSaveMatrix(savematrix);
    return;

}

void MainWindow::on_IV_SaveSelectedSweeps_clicked()
{
    std::vector<IVSweep*> sortedsweeplist;
    std::vector<IVSweep*> tempsweeplist;

    for(unsigned int i = 0; i < ivprotocol_->sweeplist().size(); i++)
    {
        if(ivprotocol_->sweeplist()[i]->save() == true)
        {
            tempsweeplist.push_back(ivprotocol_->sweeplist()[i]);
        }
    }

    sortedsweeplist = SortSweepList(tempsweeplist);

    std::vector< std::vector<std::string> > savematrix;

    IVSweep* sweep;
    IVSweep* comparesweep;
    int no_rows = 0;
    int no_cols = 0;

    for(int i = 0; i < ivprotocol_->sweeplist().size(); i++)
    {

        sweep = ivprotocol_->sweeplist()[i];
        if(sweep->save() == true)
        {
            if(i != 0)
            {
                if(sweep->totalvoltages() > ivprotocol_->sweeplist()[i-1]->totalvoltages())
                {
                    no_rows = sweep->totalvoltages();
                }
            }
            else
            {
                no_rows = sweep->totalvoltages();
            }

            no_cols = no_cols + 1;
            for(int j = 0; j < i; j++)
            {
                comparesweep = ivprotocol_->sweeplist()[j];
                if(!(sweep->startvoltage() == comparesweep->startvoltage() &&
                     sweep->endvoltage() == comparesweep->endvoltage()))
                {
                    no_cols = no_cols + 1;
                }
            }
        }
    }


    savematrix.resize( no_rows + 1, std::vector<std::string>(no_cols, ""));

    IVSweep* previoussweep;
    IVSweep* currentsweep;

    int currentcolumn = 0;

    int multicounter = 0;

    for(unsigned int i = 0; i < sortedsweeplist.size(); i++)
    {

        if(currentcolumn == 0)
        {
            previoussweep = NULL;
        }
        else
        {
            previoussweep = sortedsweeplist[i - 1];
        }




        currentsweep = sortedsweeplist[i];


        if(!IVProtocol::CheckMatchingParameters(previoussweep, currentsweep)) //start new sweep type
        {

            multicounter = 0;

            if(!(currentcolumn==0))
            {
                if(previoussweep->parentaverage()->save() == true)
                {
                    std::cerr << "adding an average\n";
                    savematrix[0][currentcolumn] = "average";
                    for(int j = 0; j < previoussweep->parentaverage()->totalvoltages(); j++)
                    {
                        savematrix[j + 1][currentcolumn] = DoubleToStringScientific(previoussweep->parentaverage()->yaverage()[j]);
                    }
                    currentcolumn = currentcolumn + 1;
                }
            }



            savematrix[0][currentcolumn] = "voltage";
            for(int j = 0; j < currentsweep->totalvoltages(); j++)
            {
                savematrix[j + 1][currentcolumn] = DoubleToString(currentsweep->x()[j]);
            }

            currentcolumn = currentcolumn + 1;


        }



        savematrix[0][currentcolumn] = DirectionToString(currentsweep->direction()) + ", " + FloatToString(currentsweep->pausetime());

        for(int j = 0; j < currentsweep->totalvoltages(); j++)
        {
            savematrix[j+1][currentcolumn] = DoubleToStringScientific(currentsweep->y()[j]);
        }

        currentcolumn = currentcolumn + 1;
        multicounter = multicounter + 1;
    }

    if(currentsweep->parentaverage()->save() == true)
    {
        savematrix[0][currentcolumn] = "average";
        for(int j = 0; j < previoussweep->parentaverage()->totalvoltages(); j++)
        {
            savematrix[j + 1][currentcolumn] = DoubleToStringScientific(previoussweep->parentaverage()->yaverage()[j]);
        }
        currentcolumn = currentcolumn + 1;
    }



    PrintSaveMatrix(savematrix);
    return;
}

std::vector<IVSweep*> MainWindow::SortSweepList(std::vector<IVSweep*>& sweeplist)
{
    std::vector<IVSweep*> sortedsweeplist;
    IVSweep* tempsweep;

    for(unsigned int i = 0; i < sweeplist.size(); i++)
    {
        tempsweep = sweeplist[i];
        sortedsweeplist.push_back(tempsweep);
    }


    int moves = 1;

    while(moves != 0) //bubble sort start
    {
        moves = 0;
        for(unsigned int i = 0; i < sortedsweeplist.size() - 1; i++)
        {
            /*if(sortedsweeplist[i]->startvoltage() > sortedsweeplist[i+1]->startvoltage())
            {
                moves = moves + 1;
                tempsweep = sortedsweeplist[i];
                sortedsweeplist[i] = sortedsweeplist[i + 1];
                sortedsweeplist[i + 1] = tempsweep;
            }*/

            if(sortedsweeplist[i]->direction() == forward && sortedsweeplist[i+1]->direction() == forward)
            {
                if(sortedsweeplist[i]->startvoltage() > sortedsweeplist[i+1]->startvoltage())
                {
                                moves = moves + 1;
                                tempsweep = sortedsweeplist[i];
                                sortedsweeplist[i] = sortedsweeplist[i + 1];
                                sortedsweeplist[i + 1] = tempsweep;
                }
            }

            else if(sortedsweeplist[i]->direction() == forward && sortedsweeplist[i+1]->direction() == reverse)
            {
                if(sortedsweeplist[i]->startvoltage() > sortedsweeplist[i+1]->endvoltage())
                {
                                moves = moves + 1;
                                tempsweep = sortedsweeplist[i];
                                sortedsweeplist[i] = sortedsweeplist[i + 1];
                                sortedsweeplist[i + 1] = tempsweep;
                }
            }

            else if(sortedsweeplist[i]->direction() == reverse && sortedsweeplist[i+1]->direction() == forward)
            {
                if(sortedsweeplist[i]->endvoltage() >= sortedsweeplist[i+1]->startvoltage())
                {
                    moves = moves + 1;
                    tempsweep = sortedsweeplist[i];
                    sortedsweeplist[i] = sortedsweeplist[i+1];
                    sortedsweeplist[i+1] = tempsweep;
                }
            }

            else if(sortedsweeplist[i]->direction() == reverse && sortedsweeplist[i+1]->direction() == reverse)
            {
                if(sortedsweeplist[i]->endvoltage() > sortedsweeplist[i+1]->endvoltage())
                {
                    moves = moves + 1;
                    tempsweep = sortedsweeplist[i];
                    sortedsweeplist[i] = sortedsweeplist[i+1];
                    sortedsweeplist[i+1] = tempsweep;
                }
            }


        }
    }

    while(moves != 0)
    {
        moves = 0;
        for(unsigned int i = 0; i < sortedsweeplist.size() - 1; i++)
        {

            if(sortedsweeplist[i]->direction() == forward && sortedsweeplist[i+1]->direction() == forward)
            {
                if(sortedsweeplist[i]->endvoltage() > sortedsweeplist[i+1]->endvoltage())
                {
                    if(!EpsilonEqual(sortedsweeplist[i]->startvoltage(), sortedsweeplist[i+1]->startvoltage()))
                    {
                        moves = moves + 1;
                        tempsweep = sortedsweeplist[i];
                        sortedsweeplist[i] = sortedsweeplist[i + 1];
                        sortedsweeplist[i + 1] = tempsweep;

                    }
                }
            }

            else if(sortedsweeplist[i]->direction() == forward && sortedsweeplist[i+1]->direction() == reverse)
            {
                if(sortedsweeplist[i]->endvoltage() > sortedsweeplist[i+1]->startvoltage())
                {
                    if(!EpsilonEqual(sortedsweeplist[i]->startvoltage(), sortedsweeplist[i+1]->endvoltage()))
                    {
                        moves = moves + 1;
                        tempsweep = sortedsweeplist[i];
                        sortedsweeplist[i] = sortedsweeplist[i + 1];
                        sortedsweeplist[i + 1] = tempsweep;

                    }
                }
            }

            else if(sortedsweeplist[i]->direction() == reverse && sortedsweeplist[i+1]->direction() == forward)
            {
                if(sortedsweeplist[i]->startvoltage() >= sortedsweeplist[i+1]->endvoltage())
                {
                    if(!EpsilonEqual(sortedsweeplist[i]->endvoltage(), sortedsweeplist[i+1]->startvoltage()))
                    {
                        moves = moves + 1;
                        tempsweep = sortedsweeplist[i];
                        sortedsweeplist[i] = sortedsweeplist[i + 1];
                        sortedsweeplist[i + 1] = tempsweep;

                    }
                }
            }

            else if(sortedsweeplist[i]->direction() == reverse && sortedsweeplist[i+1]->direction() == reverse)
            {
                if(sortedsweeplist[i]->startvoltage() > sortedsweeplist[i+1]->startvoltage())
                {
                    if(!EpsilonEqual(sortedsweeplist[i]->endvoltage(), sortedsweeplist[i+1]->endvoltage()))
                    {
                        moves = moves + 1;
                        tempsweep = sortedsweeplist[i];
                        sortedsweeplist[i] = sortedsweeplist[i + 1];
                        sortedsweeplist[i + 1] = tempsweep;

                    }
                }
            }









        }


    }

    moves = 1;

    while(moves != 0)
    {
        moves = 0;
        for(unsigned int i = 0; i < sortedsweeplist.size() - 1; i++)
        {
            if(sortedsweeplist[i]->voltageincrement() > sortedsweeplist[i+1]->voltageincrement())
            {
                if(!EpsilonEqual(sortedsweeplist[i]->endvoltage(), sortedsweeplist[i+1]->startvoltage()))
                {
                    if(!EpsilonEqual(sortedsweeplist[i]->startvoltage(), sortedsweeplist[i+1]->startvoltage()))
                    {
                        moves = moves + 1;
                        tempsweep = sortedsweeplist[i];
                        sortedsweeplist[i] = sortedsweeplist[i + 1];
                        sortedsweeplist[i + 1] = tempsweep;

                    }
                }
            }
        }
    }

    moves = 1;
    while(moves != 0)
    {
        moves = 0;
        for(unsigned int i = 0; i < sortedsweeplist.size() - 1; i++)
        {
            if(sortedsweeplist[i]->direction() == reverse && sortedsweeplist[i+1]->direction() == forward)
            if(sortedsweeplist[i]->startvoltage() != sortedsweeplist[i+1]->startvoltage())
            {
                if(sortedsweeplist[i]->endvoltage() != sortedsweeplist[i+1]->endvoltage())
                {
                    if(sortedsweeplist[i]->voltageincrement() != sortedsweeplist[i+1]->voltageincrement())
                    {
                        moves = moves + 1;
                        tempsweep = sortedsweeplist[i];
                        sortedsweeplist[i] = sortedsweeplist[i + 1];
                        sortedsweeplist[i + 1] = tempsweep;
                    }

                }
            }
        }
    }

    return sortedsweeplist;
}

void MainWindow::PrintSaveMatrix(std::vector<std::vector <std::string>> savematrix)
{
    QFile savefile;
    savefile.setFileName(ui->IV_SavePath_Field->toPlainText());
    savefile.open(QIODevice::ReadWrite);
    bool save = true;

    QTextStream savefile_stream;
    savefile_stream.setDevice(&savefile);

    if(!CheckStreamEmpty(&savefile_stream))
    {
        save = CreateOverwriteFileDialogue(ui->IV_SavePath_Field->toPlainText());

    }

    if(save == true)
    {
        savefile.resize(0);
        std::string placeholder;
        QString qplaceholder;

        time_t t = time(0);   // get time now
        struct tm * now = localtime( &t );

        //savefile_stream << QString::number(now->tm_mon + 1) << "-" << QString::number(now->tm_mday) << "-" << QString::number(now->tm_year + 1900) << "\t";

        //std::cerr << CurrentDateTime();
        QString currentdatetime = QString::fromUtf8(CurrentDateTime().c_str());
        savefile_stream << currentdatetime << "\n";
        //std::cerr << "CURRENT DATE TIME = " << currentdatetime.toStdStr() << "\n";

        //std::cerr << "current date time = " << CurrentDateTime();



        for(int i = 0; i < savematrix.size(); i++)
        {
            for(int j = 0; j < savematrix[i].size(); j++)
            {

                placeholder = savematrix[i][j];
                qplaceholder = QString::fromUtf8(placeholder.c_str());
                savefile_stream << qplaceholder;
                savefile_stream << "\t";
            }
            savefile_stream << "\n";
        }
    }
    return;
}

bool MainWindow::CheckStreamEmpty(QTextStream* stream)
{
    bool isempty;
    QString streamcontents = stream->readAll();

    if(streamcontents != "")
    {
        isempty = false;
    }
    else
    {
        isempty = true;
    }

    stream->seek(0);

    return isempty;
}



bool MainWindow::CreateOverwriteFileDialogue(QString filename)
{
    bool overwrite;
    OverwriteFileDialogue* overwritefiledialogue = new OverwriteFileDialogue(this, filename, &overwrite);
    overwritefiledialogue->setModal(true);
    overwritefiledialogue->exec();

    return overwrite;
}

void MainWindow::on_IV_SetSavePath_clicked()
{

    QString filename = QFileDialog::getSaveFileName(this, tr("Open file"), savedirectory_, tr("IV save files (*.txt)"));

    if(!(filename == NULL))
    {
        ui->IV_SavePath_Field->setPlainText(filename);
    }

    return;
}
