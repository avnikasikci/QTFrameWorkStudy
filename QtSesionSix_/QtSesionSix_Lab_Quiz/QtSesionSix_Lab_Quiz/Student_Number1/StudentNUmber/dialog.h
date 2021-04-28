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
    void on_pushButtonGeneratedNumber_clicked();

    void on_spinBoxLimitValue_valueChanged(int arg1);

    void on_radioButtonSingleGamer_clicked();

    void on_radioButtonTwoGamer_clicked();

    void on_pushButtonRunGame_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
