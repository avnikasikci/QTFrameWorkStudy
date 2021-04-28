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


void Dialog::on_btn_ps_clicked()
{
   //Parent Sınıf kullanarak
    Dialog2 *dialog=new Dialog2(this);
    dialog->show();
}

void Dialog::on_btn_nps_clicked()
{
    // Parent sınıf kullanmadan
    Dialog2 *dialog=new Dialog2();
    dialog->show();
}

void Dialog::on_btn_pe_clicked()
{
    //Parent Sınıf kullanarak
     Dialog2 *dialog=new Dialog2(this);
     dialog->exec();
}

void Dialog::on_btn_npe_clicked()
{
    //Parent Sınıf kullanarak
     Dialog2 *dialog=new Dialog2(this);
     dialog->exec();
}

void Dialog::on_btnResimSec_clicked()
{
   ResimSec2 *dlgRes=new ResimSec2(this);
   dlgRes->exec();
   // listeden secilen resmin path'ini oku ve test edit'a yaz.
   ui->textEdit->setText(dlgRes->selected);
   ui->btnResimSec->setIcon(QIcon(dlgRes->selected));
}
