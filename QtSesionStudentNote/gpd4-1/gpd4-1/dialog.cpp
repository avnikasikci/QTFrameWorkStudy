#include "dialog.h"
#include "ui_dialog.h"
#include "QString"
#include "QDebug"
#include "QObjectList"
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


void Dialog::on_btnTemizle_clicked()
{
    QList<QString> my_list;
    my_list <<"kitap " <<"defter"<<"kalem";
    foreach (QString my_str, my_list) {
        qDebug() << my_str;

    }
    reject();
}

void Dialog::on_btnListele_clicked()
{
    QString secimler;
    QObjectList boxes = this->children();
    foreach(QObject* obj,boxes){
        if(obj->inherits("QCheckBox"))
        {
            QCheckBox* box_ptr=qobject_cast<QCheckBox*>(obj);
            if (box_ptr->isChecked()) secimler+=box_ptr->text() +"\r\n";
        }
    }

    ui->plainTextEdit->appendPlainText(secimler);
}

void Dialog::on_btnAltSecenek_clicked()
{
   QString vites = secimAl(ui->grpVites);
   QString yakit = secimAl(ui->groupBox); /* yakıt group box'i*/

   QString alt_secimler="Vites :" + vites+ "\r\n"+"Yakıt :" + yakit+ "\r\n";

   QMessageBox::information(this,"SECIMLERINIZ",alt_secimler);
}

QString Dialog::secimAl(QObject* obj)
{
    QString deger = "Hiçbiri";

    QList<QRadioButton*> lst = obj->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);

    foreach(QRadioButton* rdo,lst){
        if (rdo->isChecked()){
            deger = rdo->text();
            break;
        }
    }
    return deger;
}
