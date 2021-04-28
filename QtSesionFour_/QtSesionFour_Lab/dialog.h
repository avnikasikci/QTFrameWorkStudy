#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_radioButtonLicense_clicked();

    void on_radioButtonPostgraduate_clicked();

    void on_pushButtonInfoPrint_clicked();

    void on_pushButtonCheckGradation_clicked();

    void on_pushButtonStudentStatusPrint_clicked();

    bool CheckMezuniyet();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
