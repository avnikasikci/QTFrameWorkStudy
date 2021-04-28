#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnCheckable_clicked()
{
 //Debug bir mesaj göndersin
    qDebug()<<"Tiklandi mi : "<<ui->btnCheckable->isChecked();
}

void Dialog::on_btnAuthRepeat_clicked()
{
//buna basılı tuttuğunuz sürece o click işlemi devam edicek.Basılı olduğu sürece debuga basılı duruyor diye yazalım..
    qInfo() << "Buton Basılı Durumda";
}

void Dialog::on_btnCheckableIsActive_clicked()
{
//buuton secilimi değilmi onu anlıcaz
    QString mesaj;

    mesaj=(ui->btnCheckable->isChecked()) ? "evet tıklandı" :"hayır tanımlanmadı";
    if(ui->btnCheckable->isChecked()){
        mesaj="Evet Tıklandi...";
    }else{
        mesaj="hayır tıklanmadı...";
    }
    QMessageBox::information(this,"Durum",mesaj);
}

void Dialog::on_btnAuthRepeatChange_clicked()
{
//auto reapatı değiştircez
    bool durum=!ui->btnAuthRepeat->autoRepeat();
    ui->btnAuthRepeat->setAutoRepeat(durum);
    qDebug()<<"Buton Auto buton Durumu:" <<ui->btnAuthRepeat->autoRepeat();

}

void Dialog::on_btnDefault_clicked()
{
// buarada default ve autodefault aktif ise entera bastığında bu butonna basılır olur.
//tab oto bu buttonda ama sen bir daha tab bastığında tab order değişir.
    QMessageBox::information(this,"Default Button Durumu","Klavyeye basarak tıklandı.");

}

void Dialog::on_btnDefaultChange_clicked()
{

}
