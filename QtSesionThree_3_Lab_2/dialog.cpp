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

int Number,Noun1Int,Noun2Int;
int ds=0;//tahmin edilme saysısı
QString Noun1Str,Noun2Str;



void Dialog::on_btnGuessInsertNumber_clicked()
{
    srand(time(0));
    ui->btnGuess->setVisible(true);

    Noun1Str=ui->lineEditNoun1->text();
    Noun2Str=ui->lineEditNoun2->text();
    Noun1Int=Noun1Str.toInt();
    Noun2Int=Noun2Str.toInt();
    Number= rand() % (Noun2Int - Noun1Int)+Noun1Int;
    QString infoStart="Tahmin Edilecek Sayı "+QString::number(Number);
    qDebug() << infoStart;
    ui->textBrowserResult->setText(infoStart);

}

void Dialog::on_btnGuess_clicked()
{
    srand(time(0));
    ui->btnGuess->setAutoRepeat(true);
     int guessNumber= rand() % (Noun2Int - Noun1Int)+Noun1Int;
     ds++;
     QString infoStart="Tahmin Edilecek Sayı="+QString::number(Number)+"<br/> "+"Tahmin Edilen Sayi="+" "+QString::number(guessNumber)+"<br/> ";
     QString dsToString=QString::number(ds); // iki no c++ func kullanmak istiyorum demek.
     if(Number != guessNumber){
         ui->textBrowserResult->setText(infoStart+" "+"Doğru Tahmin Edilemedi.<br/> Deneme Sayisi: "+dsToString);
     }else{
         ui->textBrowserResult->setText(infoStart+" "+"Tebrikler! Doğru Tahmin Edildi.<br/> Deneme Sayisi: "+dsToString);
         ui->btnGuess->setVisible(false);
     }

}
