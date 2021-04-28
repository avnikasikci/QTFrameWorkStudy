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
    void on_btnTemizle_clicked();

    void on_btnListele_clicked();

    void on_btnAltSecenek_clicked();

    QString secimAl(QObject* obj);
private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
