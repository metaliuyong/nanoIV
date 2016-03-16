#ifndef OVERWRITEFILEDIALOG_H
#define OVERWRITEFILEDIALOG_H

//#include <QMainWindow>
#include <QDialog>
//#include <QPushButton>

namespace Ui {
class OverwriteFileDialog;
}

class OverwriteFileDialog: public QDialog
{
    Q_OBJECT

public:
    explicit OverwriteFileDialog(QWidget* parent = 0, QString filename = "");
    ~OverwriteFileDialog();

private:
    bool overwrite;

    Ui::OverwriteFileDialog *ui;


};

#endif // OVERWRITEFILEDIALOG_H
