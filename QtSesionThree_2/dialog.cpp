#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->btnConnect,&QPushButton::clicked,this,&Dialog::YazDbg);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_2_clicked()
{
    qDebug() << "Yaz db ile butona tıklanma zamanını yazdırcağız";
    YazDbg();
}

void Dialog::YazDbg()
{
    qInfo() <<"buton tıklanama zamanı :"<<QDateTime::currentDateTime().toString();
    accept();//penceri akapatır.
}


