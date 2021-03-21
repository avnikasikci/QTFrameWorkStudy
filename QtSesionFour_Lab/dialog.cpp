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


void Dialog::on_radioButtonLicense_clicked()
{
    //class ve zorunlu dersler lisans enable false olcak
  ui->groupBoxClasses->setEnabled(true);
  ui->groupBoxLisansZorunluDersler->setEnabled(true);
  //ui->groupBoxEducation->setEnabled(true); //Eğitim

  ui->groupBoxStatus->setEnabled(false);//durum
  ui->groupBoxLisansustuZorunluDersler->setEnabled(false);//durum


}

void Dialog::on_radioButtonPostgraduate_clicked()
{
    ui->groupBoxClasses->setEnabled(false);
    ui->groupBoxLisansZorunluDersler->setEnabled(false);
   // ui->groupBoxEducation->setEnabled(true); //Eğitim

    ui->groupBoxStatus->setEnabled(true);//durum
    ui->groupBoxLisansustuZorunluDersler->setEnabled(true);//durum
}

void Dialog::on_pushButtonInfoPrint_clicked() // ad soyad eğitim bilgilerini yazdır...
{
    /*3 erişim var qtobje listesi ile qtradio obje listesi ile bide bu ayşe hoca 2 si gösterdi labda biz suan bu func görüyoruz.*/
    QString name,surname,episode,EdicationTxt;
    name=ui->lineEditName->text();
    surname=ui->lineEditSurName->text();
    episode=ui->lineEditEpisode->text();
    //1.yontem burada groupbox içine erişmediğimiz için radio buttonu alamadık
    EdicationTxt="";

    QObjectList objlist=this->children();
    foreach(QObject* obj ,objlist)
    {
    if(obj->inherits("QRadioButton"))    //QRadibutton miras almış mı ?
    {
        QRadioButton* rd=qobject_cast<QRadioButton*>(obj);
        if(rd->isChecked()){
            EdicationTxt=rd->text();

        }
    }

    }
    /*1.Yontem*/
    /*2 yöntem.*/
    EdicationTxt="";

    QObject* objGrp=ui->groupBoxEducation;
    QList<QRadioButton*> qRadioList=objGrp->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);//sadece radio buttonları bul
    foreach(QRadioButton* rd,qRadioList){
        if(rd->isChecked()){
            EdicationTxt=rd->text();

        }
    }
    /*2 yöntem.*/
    /*3 yöntem.*/
    EdicationTxt="";
    if(ui->radioButtonLicense->isChecked()){
        EdicationTxt=ui->radioButtonLicense->text();

    }
    if(ui->radioButtonPostgraduate->isChecked()){
        EdicationTxt=ui->radioButtonPostgraduate->text();
    }

    /*3 yöntem.*/

    QMessageBox::information(this,"Ogrenci Bilgileri","Ad:"+name+"\n"+"Soyad:"+surname+"\n"+"Bolum:"+episode+"\n"+"Seviye:"+EdicationTxt);



}

void Dialog::on_pushButtonCheckGradation_clicked()
{
    /*Öğrenci Lisans ize tüm zorunlu dersleri aldıysa mezun olabilir okey */
    QString name,surname,episode,EdicationTxt;
    name=ui->lineEditName->text();
    surname=ui->lineEditSurName->text();
    episode=ui->lineEditEpisode->text();
    //1.yontem burada groupbox içine erişmediğimiz için radio buttonu alamadık
    if(ui->radioButtonLicense->isChecked()){
        EdicationTxt=ui->radioButtonLicense->text();

    }
    if(ui->radioButtonPostgraduate->isChecked()){
        EdicationTxt=ui->radioButtonPostgraduate->text();
    }

if(CheckMezuniyet()){
    if(EdicationTxt=="Lisans")
        QMessageBox::information(this,"Ogrenci Mezuniyet Bildileri","Ogrenci Lisanstan Mezun Olabilir.\n Ad:"+name+"\n"+"Soyad:"+surname+"\n"+"Bolum:"+episode+"\n"+"Seviye:"+EdicationTxt,"Tamam");
    if(EdicationTxt=="LisansÜstü")
        QMessageBox::information(this,"Ogrenci Mezuniyet Bildileri","Ogrenci LisansÜstü Mezun Olabilir.\n Ad:"+name+"\n"+"Soyad:"+surname+"\n"+"Bolum:"+episode+"\n"+"Seviye:"+EdicationTxt,"Tamam");


}else{
    if(EdicationTxt=="Lisans")
        QMessageBox::information(this,"Ogrenci Mezuniyet Bildileri","Ogrenci Lisanstan Mezun Olamaz.\n Ad:"+name+"\n"+"Soyad:"+surname+"\n"+"Bolum:"+episode+"\n"+"Seviye:"+EdicationTxt,"Tamam");
    if(EdicationTxt=="LisansÜstü")
        QMessageBox::information(this,"Ogrenci Mezuniyet Bildileri","Ogrenci LisansÜstü Mezun Olamaz.\n Ad:"+name+"\n"+"Soyad:"+surname+"\n"+"Bolum:"+episode+"\n"+"Seviye:"+EdicationTxt,"Tamam");

}

//    QMessageBox::information(this,"Ogrenci Bilgileri","Ad:"+name+"\n"+"Soyad:"+surname+"\n"+"Bolum:"+episode+"\n"+"Seviye:"+EdicationTxt);

}

void Dialog::on_pushButtonStudentStatusPrint_clicked()
{
    /*Ogrencinin Genel Bilgilerini Yazdır*/
    QString name,surname,episode,EdicationTxt,MsgBoxInfo;
    name=ui->lineEditName->text();
    surname=ui->lineEditSurName->text();
    episode=ui->lineEditEpisode->text();
    if(ui->radioButtonLicense->isChecked()){
        EdicationTxt=ui->radioButtonLicense->text();

    }
    if(ui->radioButtonPostgraduate->isChecked()){
        EdicationTxt=ui->radioButtonPostgraduate->text();
    }
    bool CheckMezuniyetParam=CheckMezuniyet();
    if(CheckMezuniyetParam){
        if(EdicationTxt=="Lisans"){
            MsgBoxInfo="Ogrenci Lisanstan Mezun Olabilir.\n ";
        }
        if(EdicationTxt=="LisansÜstü"){
            MsgBoxInfo="Ogrenci LisansÜstü Mezun Olabilir.\n ";

        }

    }else{
        if(EdicationTxt=="Lisans"){
            MsgBoxInfo="Ogrenci Lisanstan Mezun Olamaz.\n ";
        }
        if(EdicationTxt=="LisansÜstü"){
            MsgBoxInfo="Ogrenci LisansÜstü Mezun Olamaz.\n ";

        }
    }

    QMessageBox::information(this,"Ogrenci Mezuniyet Bildileri",MsgBoxInfo+"Ad:"+name+"\n"+"Soyad:"+surname+"\n"+"Bolum:"+episode+"\n"+"Seviye:"+EdicationTxt,"Tamam");


}

bool Dialog::CheckMezuniyet()
{
    bool returnValue=false;
    if(ui->radioButtonLicense->isChecked()){
        if(ui->radioButtonClass4->isChecked()
                && ui->checkBoxAiit->isChecked()
                && ui->checkBoxIsg->isChecked()
                && ui->checkBoxTd->isChecked()  )
        {
           // QMessageBox::information(this,"Ogrenci Mezuniyet Bildileri","Ogrenci Lisanstan Mezun Olabilir.\n Ad:"+name+"\n"+"Soyad:"+surname+"\n"+"Bolum:"+episode+"\n"+"Seviye:"+EdicationTxt,"Tamam");
            returnValue= true;
        }else{
           // QMessageBox::information(this,"Ogrenci Mezuniyet Bildileri","Ogrenci Lisanstan Mezun Olamaz.\n Ad:"+name+"\n"+"Soyad:"+surname+"\n"+"Bolum:"+episode+"\n"+"Seviye:"+EdicationTxt,"Tamam");
            returnValue= false;

        }
    }
    if(ui->radioButtonPostgraduate->isChecked()){
        if(ui->radioButtonTez->isChecked()
                && ui->checkBoxSecmeliDers->isChecked()
                && ui->checkBoxSeminer->isChecked()
                && ui->checkBoxTez->isChecked())
        {
            //QMessageBox::information(this,"Ogrenci Mezuniyet Bildileri","Ogrenci LisansUstü Mezun Olabilir.\n Ad:"+name+"\n"+"Soyad:"+surname+"\n"+"Bolum:"+episode+"\n"+"Seviye:"+EdicationTxt,"Tamam");
            returnValue= true;
        }
        else{
            //QMessageBox::information(this,"Ogrenci Mezuniyet Bildileri","Ogrenci LisansUstü Mezun Olamaz.\n Ad:"+name+"\n"+"Soyad:"+surname+"\n"+"Bolum:"+episode+"\n"+"Seviye:"+EdicationTxt,"Tamam");
            returnValue= false;
        }
    }
    return returnValue;
}
