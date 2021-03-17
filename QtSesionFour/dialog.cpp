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
    ui->grpGear->hide();//form load edilirken hide edilmesi gereken groupboxları code belirliyorum
    ui->grpfuel->hide();
    ui->grpAge->hide();
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
    //Form Nesnelerini Temizle tek tek yapmadan tüm form elementlerini nasıl temizleyebiliriz araştırılacak...
    /*
    QObjectList AllObjectList=this->children();
    foreach(QObject _ChildObj , AllObjectList){

    }
*/
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
 QString gear=get_chosen(ui->grpGear);
 QString fuel=get_chosen(ui->grpfuel);
 QString age=get_chosen(ui->grpAge);

 QString _childerenChosen="Vites:"+gear+"\r\n"+" Yakit :"+fuel+"\r\n Yaş :"+age+"\r\n";

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

void Dialog::on_checkBoxGear_stateChanged(int arg1)
{
//Check active arg1 = 2 deactive arg1=0;
    ui->checkBoxGear->isChecked() ?  ui->grpGear->show():ui->grpGear->hide();

}

void Dialog::on_checkBoxFuel_stateChanged(int arg1)
{
ui->checkBoxFuel->isChecked() ?  ui->grpfuel->show():ui->grpfuel->hide();
}

void Dialog::on_checkBoxAge_stateChanged(int arg1)
{
    ui->checkBoxAge->isChecked() ?  ui->grpAge->show():ui->grpAge->hide();

}
