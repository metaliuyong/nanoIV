#ifndef OVERWRITEFILEDIALOGUE_H
#define OVERWRITEFILEDIALOGUE_H

#include <QDialog>

namespace Ui {
class OverwriteFileDialogue;
}

class OverwriteFileDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit OverwriteFileDialogue(QWidget *parent = 0, QString filename = "", bool* overwrite = 0);
    ~OverwriteFileDialogue();

private slots:
    void on_Yes_clicked();

    void on_No_clicked();

    void on_Yes_pressed();

    void on_Yes_released();

    void on_No_released();

    void on_No_pressed();

private:
    Ui::OverwriteFileDialogue *ui;

    QString greenbutton_pressed_ss_;
    QString greenbutton_released_ss_;

    QString redbutton_pressed_ss_;
    QString redbutton_released_ss_;

    bool* overwrite_;
};

#endif // OVERWRITEFILEDIALOGUE_H
