#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

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
    void on_btnSend_clicked(); // burayı interface olarak düşün bunun classını dialog.cpp de oluşturcam.

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
