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
    void on_btnClear_clicked();

    void on_btnList_clicked();

    void on_btnShowChilderenChose_clicked();

    QString get_chosen(QObject* obj);

    void on_checkBoxGear_stateChanged(int arg1);

    void on_checkBoxFuel_stateChanged(int arg1);

    void on_checkBoxAge_stateChanged(int arg1);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
