#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->listWidgetGamer1->setDisabled(true);
    ui->listWidgetGamer2->setDisabled(true);

}

Dialog::~Dialog()
{
    delete ui;
}

int Number,MinNumber=0,MaxNumber=1000,InputNumber,GuessNumber;
int ds=0;//tahmin edilme saysısı
QString Noun1Str,Noun2Str;

void Dialog::on_pushButtonGeneratedNumber_clicked()
{
    srand(time(0));
    InputNumber=ui->spinBoxLimitValue->value();

    GuessNumber= rand() % (InputNumber - MinNumber)+MinNumber;
    QString infoStart="Tahmin Edilecek Sayı "+QString::number(GuessNumber);
    //qDebug() << infoStart;
    ui->label_GeneratedNumber->setText(QString::number(GuessNumber));
}

void Dialog::on_spinBoxLimitValue_valueChanged(int arg1)
{
    QString _Opsiyon=arg1>=10?QString::number(arg1): "...";
    ui->labelInfoStartGamer->
            setText("0 ile "+ _Opsiyon +" sayıları arasında sayı tahmin oyunu başlıyor.");
}

void Dialog::on_radioButtonSingleGamer_clicked()
{
    bool IsCheckedSingle=ui->radioButtonSingleGamer->isChecked();
    bool IsCheckedMulti=ui->radioButtonTwoGamer->isChecked();
    ui->listWidgetGamer1->setDisabled(!IsCheckedSingle);
    ui->listWidgetGamer2->setDisabled(!IsCheckedMulti);

}



void Dialog::on_radioButtonTwoGamer_clicked()
{
    bool IsCheckedMulti=ui->radioButtonTwoGamer->isChecked();
    //ui->listWidgetGamer1->setDisabled(IsCheckedMulti);
    ui->listWidgetGamer2->setDisabled(!IsCheckedMulti);

}

void Dialog::on_pushButtonRunGame_clicked()
{
    int _GuessGamer1=1;
    int _GuessGamer2=1;

    bool _IsActiveGamer1=ui->listWidgetGamer1->isEnabled();
    bool _IsActiveGamer2=ui->listWidgetGamer2->isEnabled();

    srand(time(0));
    int guessNumber1= rand() % (InputNumber - MinNumber)+MinNumber;


    if(_IsActiveGamer1){

do {
        _GuessGamer1++;
        guessNumber1= rand() % (InputNumber - MinNumber)+MinNumber;
        QString _InputValue=QString::number(guessNumber1);
        ui->listWidgetGamer1->addItem(_InputValue);
        srand(time(0));
        //QuestGamer1.append( guessNumber1);
    }
    while (guessNumber1 !=GuessNumber);

    ui->listWidgetGamer1->addItem("Deneme Sayısı:"+QString::number(_GuessGamer1));

 }
    srand(time(0));

    int guessNumber2= rand() % (InputNumber - MinNumber)+MinNumber;

    if(_IsActiveGamer2){

do {
        _GuessGamer2++;
        srand(time(0));
        guessNumber2= rand() % (InputNumber - MinNumber)+MinNumber;
        QString _InputValue=QString::number(guessNumber2);
        ui->listWidgetGamer1->addItem(_InputValue);
       // QuestGamer1.append( guessNumber2);
       // if(guessNumber2 == GuessNumber){break;}

    }
    while (guessNumber2 !=GuessNumber);
    ui->listWidgetGamer2->addItem("Deneme Sayısı:"+QString::number(_GuessGamer2));
 }


  /* foreach(int _Number1,QuestGamer1){
   QString _InputValue=QString::number(_Number1);
   ui->listWidgetGamer1->addItem(_InputValue);
   }
   foreach(int _Number2,QuestGamer2){
   QString _InputValue=QString::number(_Number2);
   ui->listWidgetGamer2->addItem(_InputValue);
   }*/






}
