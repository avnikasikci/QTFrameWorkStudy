#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
 //   connect(ui->btnExit,&QPushButton::clicked,this,&QDialog::reject);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnExit_clicked()
{
   QDialog::reject(); // Çıkığ yapılsın
}

void Dialog::on_btnCalcature_clicked()
{
    QString studentName,LessionName,VizeNote,FinalNote;
    studentName=ui->lineEditStudentName->text();
    LessionName=ui->lineEditLessionName->text();
    VizeNote=ui->lineEditVizeNote->text();
    FinalNote=ui->lineEditFinalNote->text();
    int vn,fn,passgrade;
    vn=VizeNote.toUInt();
    fn=FinalNote.toInt();
    passgrade=(vn*0.4)+(fn*0.6);
    if(passgrade >=60){
        ui->textBrowserResult->setText(studentName + " isimli öğrenci "+ LessionName +" "+"adlı dersten geçti...");
    }else{
        ui->textBrowserResult->setText(studentName + " isimli öğrenci "+ LessionName +" "+"adlı dersten kaldı...");
    }



}
