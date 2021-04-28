#include "dialog.h"
#include "ui_dialog.h"
#include "QMessageBox"

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


void Dialog::on_pushButton_clicked()
{
    int birthYear=ui->dateEditBirthDate->date().year();
    QDateTime currentNowDate=QDateTime::currentDateTime();
    //qDebug() << currentNowDate;
    int nowDateYear=currentNowDate.date().year();
    int userAge=nowDateYear -birthYear ;
    double userSize=ui->doubleSpinBox->value();
    double userKg=ui->spinBox->value();
    double vki=userKg/(userSize*userSize);
    if(userAge > 40){
    if(vki <18.5){
        QMessageBox::information(this,"Kullanicinin Vucut Kitle Indexi","<font color='#ff0000'> Zayif (Yaşa Dikkat Edilmeli) </font> ","Tamam");
    }
    else if(vki <21.9){
        QMessageBox::information(this,"Kullanicinin Vucut Kitle Indexi","<font color='#ff0000'> Normal Kilolu (Yaşa Dikkat Edilmeli) </font> ","Tamam");
    }
    else if(vki < 29.9)
        QMessageBox::information(this,"Kullanicinin Vucut Kitle Indexi","<font color='#ff0000'> Fazla Kilolu (Yaşa Dikkat Edilmeli) </font> ","Tamam");
    else
        QMessageBox::information(this,"Kullanicinin Vucut Kitle Indexi","<font color='#ff0000'> Obez</font> (Yaşa Dikkat Edilmeli) ","Tamam");
    }else{
    QMessageBox::information(this,"Kullanicinin Vucut Kitle Indexi","<font color='#ff0000'> Daha Cok Gençsin</font> ","Tamam");
    }

}
