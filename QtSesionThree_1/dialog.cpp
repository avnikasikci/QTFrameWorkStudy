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


void Dialog::on_btnSend_clicked()
{
    //kendi sahip olduğumuz nesneyi ref ediyoruz this diyerek qmain windowsa ref et
    //2. param title yaz
    //3. Param Messegi yaz diyor. yazıdğı texti alcaz
    //4. param butonuların ismi //Okeyi tamam yap örnek
    QMessageBox::information(this,"Hosgeldiniz...","Merhaba "+ui->txtInputText->text(),"Tamam");
}
