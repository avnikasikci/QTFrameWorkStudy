#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

   ui->setupUi(this);
   sozlesmeYukle();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::sozlesmeYukle()
{
    QFile file(":/sozlesme/metinFile/sozlesme.txt");
    if (!file.exists())
    {
        QMessageBox::critical(this,"Dosya Bulunamadı","sozleme metnine ulasılamadı");
        return;
    }
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"HATA",file.errorString());
        return;
    }
    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();

}


void Dialog::on_pushButton_clicked()
{

}
