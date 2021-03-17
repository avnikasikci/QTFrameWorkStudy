#include "dialog.h"
#include "ui_dialog.h"
#include "QString" // harf duyarlı .h kütüphanesi değil bu
#include "QtDebug"
#include "QObject"
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


void Dialog::on_btnClear_clicked()
{
    //burayı headerada koydu önemli burası interfaceler dialog.h tutuluyor.

    QList<QString> my_list;
    my_list << "kitap"<<"defter"<<"kalem";
    foreach(QString my_str,my_list) // Listedeki her bir eleman 2 paremetre istiyor burada variable ve container
    {
        qDebug()<< my_str;
    }

    reject();

}

void Dialog::on_btnList_clicked() //Secimleri bir str de tutcaz ekrana bascaz
{
    QString chosens;
    QObjectList checkboxes=this->children();
    foreach(QObject* obj,checkboxes){ // Her adres 4 bit int unsigned idir.
        // adresini tutacaz adres tutmak pointer tutmak demektir.direk pointer tutuyoruz da nesneyi tutmuyoruz cünkü verimli olmaz
        // nesneyi verirsek nesnenin sahip olduğu alan kadar yer ayırır bu sebeple pointer tutarız.

        //simdi 7 adet elemanın içindeki checkboxesları alıcaz
        if(obj->inherits("QCheckBox")){
            //QCheckbox tipinde bir değişikeni refere edicek bir adres gelicek
            QCheckBox* checkbox_ptr=qobject_cast<QCheckBox*>(obj);  // bu adresin cast ediceyoruz eğer label verirsen buraya patlatır.
            if(checkbox_ptr->isChecked()) chosens +=checkbox_ptr->text()+"\r\n";

        }//qcheckbox check

    } //Foreach
    ui->plainTextEdit->appendPlainText(chosens);

}

void Dialog::on_btnShowChilderenChose_clicked()
{
 QString vites=get_chosen(ui->grpVites);
 QString yakit=get_chosen(ui->grpYakit);
 QString _childerenChosen="Vites:"+vites+"\r\n"+" Yakit :"+yakit+"\r\n";
 QMessageBox::information(this,"Secimleriniz",_childerenChosen);
}

QString Dialog::get_chosen(QObject* obj)
{
    //sag tık refocter localation belirlediğinde bu func otomatik oluşturulur.
    QString value="Hiçbiri";
    QList<QRadioButton*> lst= obj->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly); // Eğer istersen q string içine ismini verebilirsin.
            //find direct childeren direk o container cocuklarını bul..
    foreach(QRadioButton* rdoObject,lst){
        if(rdoObject->isChecked()){
               value=rdoObject->text()+"\r\n"; // aynı anda birden fazla radio olmaz o yüzden + konulmaz bulursa bitir bekleme
               break;
        }
    }
    return value;
}


















