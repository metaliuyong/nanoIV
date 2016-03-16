#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

#include "typeconversions.h"
#include "session.h"
#include "currentsampleprotocol.h"
#include "ivprotocol.h"



void MainWindow::EnableNeutralButton(QPushButton* button)
{
    button->setEnabled(true);
    button->setStyleSheet(neutralbutton_released_ss_);
    return;
}

void MainWindow::DisableNeutralButton(QPushButton* button)
{
    button->setEnabled(false);
    button->setStyleSheet(neutralbutton_pressed_ss_);
    return;
}

void MainWindow::EnableGreenButton(QPushButton* button)
{
    button->setEnabled(true);
    button->setStyleSheet(greenbutton_released_ss_);
    return;
}

void MainWindow::DisableGreenButton(QPushButton* button)
{
    button->setEnabled(false);
    button->setStyleSheet(greenbutton_pressed_ss_);
    return;
}

void MainWindow::EnableYellowButton(QPushButton* button)
{
    button->setEnabled(true);
    button->setStyleSheet(yellowbutton_released_ss_);
    return;
}

void MainWindow::DisableYellowButton(QPushButton* button)
{
    button->setEnabled(false);
    button->setStyleSheet(yellowbutton_pressed_ss_);
    return;
}

void MainWindow::EnableRedButton(QPushButton* button)
{
    button->setEnabled(true);
    button->setStyleSheet(redbutton_released_ss_);
    return;
}

void MainWindow::DisableRedButton(QPushButton* button)
{
    button->setEnabled(false);
    button->setStyleSheet(redbutton_pressed_ss_);
    return;
}

void MainWindow::Enable_AddToSweepQueue_Button()
{
    EnableNeutralButton(ui->IV_AddToSweepQueue);
    return;
}
