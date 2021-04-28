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
    QPushButton *buttonAccept = new QPushButton(QIcon(":/dialog/icon/images/accept.png"),"Accept",this);
    QPushButton *buttonReject = new QPushButton("Reject",this);
    buttonReject->setIcon(QIcon(":/dialog/icon/images/cancel.png"));
    ui->buttonBox->addButton(buttonAccept,QDialogButtonBox::ButtonRole::AcceptRole);
    ui->buttonBox->addButton(buttonReject,QDialogButtonBox::ButtonRole::RejectRole);

    connect(buttonAccept,&QPushButton::clicked,this,&Dialog::save);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButtonNew_clicked()
{
    ui->plainTextEdit->clear();

}

void Dialog::on_pushButtonRead_clicked()
{
    read();
}

void Dialog::on_pushButtonSave_clicked()
{
    save();
}

void Dialog::save()// is msg txt file write
{
    QFile myfile("msg.txt"); // bunu ramden okursun hdd de kalmaz bu .
    /*if(myfile.open(QFile::WriteOnly))
       {


    }*/
    if(!myfile.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this,"Error","Error :"+myfile.errorString());
        return;
    }
    QTextStream stream(&myfile);
    stream << ui->plainTextEdit->toPlainText();
    myfile.close();
    isMsgSaved=true;
    QMessageBox::information(this,"Info","is message saved");
}

void Dialog::read()
{
    QFile myfile("msg.txt");
    if(!myfile.exists() || !myfile.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,"Error","Error File Not Found or not permission ReadOnly :"+myfile.errorString());
        return;
    }
   /* if(!myfile.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this,"Error","Error :"+myfile.errorString());
        return;
    }*/
    QTextStream stream(&myfile);
    ui->plainTextEdit->setPlainText(stream.readAll());
    myfile.close();
}

QPaintEngine *Dialog::paintEngine() const
{

}

void Dialog::closeEvent(QCloseEvent *event)
{
    if(!isMsgSaved){
        QMessageBox::StandardButton btn = QMessageBox::question(this,"Is a Text Save","all save edit line ? ");
        if(btn==QMessageBox::StandardButton::Yes){
            save();
        }
    }
    event->accept();

}

void Dialog::on_plainTextEdit_textChanged() // mesg not save
{
    isMsgSaved=false;
}
