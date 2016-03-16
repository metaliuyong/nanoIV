#include "overwritefiledialogue.h"
#include "ui_overwritefiledialogue.h"
#include <iostream>

OverwriteFileDialogue::OverwriteFileDialogue(QWidget *parent, QString filename, bool* overwrite) :
    QDialog(parent),
    overwrite_(overwrite),
    ui(new Ui::OverwriteFileDialogue)
{

    ui->setupUi(this);

    this->setWindowTitle("Overwrite file");

    ui->Label->setText("Overwrite " + filename + "?");

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


    ui->Yes->setStyleSheet(greenbutton_released_ss_);
    ui->No->setStyleSheet(redbutton_released_ss_);
}

OverwriteFileDialogue::~OverwriteFileDialogue()
{
    delete ui;
}



void OverwriteFileDialogue::on_Yes_clicked()
{
    *overwrite_ = true;
    this->close();
    return;
}



void OverwriteFileDialogue::on_Yes_pressed()
{
    ui->Yes->setStyleSheet(greenbutton_pressed_ss_);
    return;
}

void OverwriteFileDialogue::on_Yes_released()
{
    ui->Yes->setStyleSheet(greenbutton_released_ss_);
    return;
}

void OverwriteFileDialogue::on_No_clicked()
{
    *overwrite_ = false;
    this->close();
    return;
}

void OverwriteFileDialogue::on_No_pressed()
{
    ui->No->setStyleSheet(redbutton_pressed_ss_);
    return;
}

void OverwriteFileDialogue::on_No_released()
{
    ui->No->setStyleSheet(redbutton_released_ss_);
    return;
}


