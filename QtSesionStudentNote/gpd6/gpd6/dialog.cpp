#include "dialog.h"
#include "ui_dialog.h"
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include "QPushButton"
#include "QIcon"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPushButton *btnAccept=new QPushButton(QIcon(":dialog/images/accept.png"),"Accept",this);
    QPushButton *btnReject=new QPushButton("Reject",this);
    btnReject->setIcon(QIcon(":dialog/images/cancel.png"));
    ui->buttonBox->addButton(btnAccept,QDialogButtonBox::ButtonRole::AcceptRole);
    ui->buttonBox->addButton(btnReject,QDialogButtonBox::ButtonRole::RejectRole);

    connect(btnAccept,&QPushButton::clicked,this,&Dialog::kaydet);




}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnYeni_clicked()
{
    ui->txtMetin->clear();
}

void Dialog::on_btnOku_clicked()
{
   oku();
}

void Dialog::on_btnKaydet_clicked()
{
    kaydet();
}

void Dialog::kaydet()
{
    QFile file("metin.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"HATA",file.errorString());
        return;
    }
    QTextStream stream(&file);
    stream << ui->txtMetin->toPlainText();
    file.close();
    m_saved=true;
    QMessageBox::information(this,"Bilgi","Metin Kaydedildi");

}

void Dialog::oku()
{
   QFile file("metin.txt");
   if (!file.exists())
   {
       return;
   }
   if (!file.open(QIODevice::ReadOnly))
   {
       QMessageBox::critical(this,"HATA",file.errorString());
       return;
   }
   QTextStream stream(&file);
   ui->txtMetin->setPlainText(stream.readAll());
   file.close();

}

void Dialog::on_txtMetin_textChanged()
{
   m_saved=false;
}

void Dialog::closeEvent(QCloseEvent *event)
{
    if (!m_saved) {
        QMessageBox::StandardButton btn=QMessageBox::question(this,"Kayıt Edilsin mi?","Metin Kutusunun icerigi değişmiştir. Kaydetmek ister misiniz?");
        if (btn==QMessageBox::StandardButton::Yes)
            kaydet();
    }
    event->accept();
}
