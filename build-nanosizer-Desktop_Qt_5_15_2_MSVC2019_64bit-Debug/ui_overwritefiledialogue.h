/********************************************************************************
** Form generated from reading UI file 'overwritefiledialogue.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERWRITEFILEDIALOGUE_H
#define UI_OVERWRITEFILEDIALOGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_OverwriteFileDialogue
{
public:
    QLabel *Label;
    QPushButton *Yes;
    QPushButton *No;

    void setupUi(QDialog *OverwriteFileDialogue)
    {
        if (OverwriteFileDialogue->objectName().isEmpty())
            OverwriteFileDialogue->setObjectName(QString::fromUtf8("OverwriteFileDialogue"));
        OverwriteFileDialogue->resize(400, 300);
        OverwriteFileDialogue->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 246, 232);"));
        Label = new QLabel(OverwriteFileDialogue);
        Label->setObjectName(QString::fromUtf8("Label"));
        Label->setGeometry(QRect(10, 10, 371, 171));
        Yes = new QPushButton(OverwriteFileDialogue);
        Yes->setObjectName(QString::fromUtf8("Yes"));
        Yes->setGeometry(QRect(60, 190, 75, 71));
        No = new QPushButton(OverwriteFileDialogue);
        No->setObjectName(QString::fromUtf8("No"));
        No->setGeometry(QRect(260, 190, 75, 71));

        retranslateUi(OverwriteFileDialogue);

        QMetaObject::connectSlotsByName(OverwriteFileDialogue);
    } // setupUi

    void retranslateUi(QDialog *OverwriteFileDialogue)
    {
        OverwriteFileDialogue->setWindowTitle(QCoreApplication::translate("OverwriteFileDialogue", "Dialog", nullptr));
        Label->setText(QString());
        Yes->setText(QCoreApplication::translate("OverwriteFileDialogue", "Yes", nullptr));
        No->setText(QCoreApplication::translate("OverwriteFileDialogue", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OverwriteFileDialogue: public Ui_OverwriteFileDialogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERWRITEFILEDIALOGUE_H
