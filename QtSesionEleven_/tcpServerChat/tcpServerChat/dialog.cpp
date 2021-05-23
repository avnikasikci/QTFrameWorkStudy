#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // Derste yasadığımız sorunun sebebi, init() fonskiyonunu yapıcı fonksiyon içinden çağırmamamız.
    // Yani fonksiyonu yazdık ancak dialog form oluştururken çağırmadığımız için çalışmadı ve butonlar oluşmadı.

    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{
   btnBack=new QPushButton("Geri",this);
   btnNext= new QPushButton("ileri",this);
   // hangi nesne, hangi sinyali ürettiğinde(SİGNAL), hangi nesne , sinyali nasıl kabul edecek(SLOT)

   ui->buttonBox->addButton(btnBack,QDialogButtonBox::ButtonRole::ActionRole);
   ui->buttonBox->addButton(btnNext,QDialogButtonBox::ButtonRole::ActionRole);

   connect(btnBack,&QPushButton::clicked,this,&Dialog::back);
   connect(btnNext,&QPushButton::clicked,this,&Dialog::next);
   connect(&server,&Server::changed,this,&Dialog::changed);

   enableButtons();


}

void Dialog::on_btnStart_clicked()
{
    quint16 port=static_cast<quint16>(ui->spinBoxPort->value());
    server.setMessage(ui->txtMessageInput->text()+"\r\n");

    if (!server.listen(QHostAddress::Any,port))
    {
        QMessageBox::critical(this,"Hata",server.errorString());
        return;
    }
    ui->lblStatusInfo->setText("Sunucu Dinliyor");
    enableButtons();
}

void Dialog::on_btnStop_clicked()
{
    server.close();
    ui->lblStatusInfo->setText("Sunucu Kapandı");
    enableButtons();


}

void Dialog::next()
{
    int i=ui->stackedWidget->currentIndex();
    i++;
    if (i>=ui->stackedWidget->count()) i=ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(i);
    enableButtons();

}

void Dialog::back()
{
    int i=ui->stackedWidget->currentIndex();
    i--;
    if (i<0) i=0;
    ui->stackedWidget->setCurrentIndex(i);
    enableButtons();

}

void Dialog::changed()
{
   ui->lblStatusInfo->setText(QString("Su an %0 kullanıcı baglıdır.gelen datalar: "+server.message()).arg(server.count()));
   ui->textEditServerMsg->setText(QString("Gelen Datalar "+server.Readmessage()));
}



void Dialog::enableButtons()
{
   ui->btnStartAction->setEnabled(!server.isListening());
   ui->btnStopAction->setEnabled(server.isListening());

   if (ui->stackedWidget->count()<=1)
   {
       btnNext->setEnabled(false);
       btnBack->setEnabled(false);
       return;


   }
   if (ui->stackedWidget->currentIndex()==0)
   {
       btnNext->setEnabled(true);
       btnBack->setEnabled(false);
       return;

    }
   if(ui->stackedWidget->currentIndex()>=ui->stackedWidget->count()-1)
   {
       btnNext->setEnabled(false);
       btnBack->setEnabled(true);
       return;

   }
}



void Dialog::on_btnStartAction_clicked()
{
    quint16 port=static_cast<quint16>(ui->spinBoxPort->value());
    server.setMessage(ui->txtMessageInput->text()+"\r\n");

    if (!server.listen(QHostAddress::Any,port))
    {
        QMessageBox::critical(this,"Hata",server.errorString());
        return;
    }
    ui->lblStatusInfo->setText("Sunucu Dinliyor");
    enableButtons();

}

void Dialog::on_btnStopAction_clicked()
{
    server.close();
    ui->lblStatusInfo->setText("Sunucu Kapandı");
    enableButtons();
}
