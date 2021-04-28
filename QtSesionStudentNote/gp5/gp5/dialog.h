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
    void on_btnHatirla_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);




    void on_btnTamam_clicked();

    void on_btnIptal_clicked();

    void on_btnTemizle_clicked();

    void on_btnSil_clicked();

    void on_btnDemirbasEkle_clicked();

private:
    Ui::Dialog *ui;
    void baslarken();
    void yukle_demirbas();
    void yukle();
    void kaydet();

};
#endif // DIALOG_H
