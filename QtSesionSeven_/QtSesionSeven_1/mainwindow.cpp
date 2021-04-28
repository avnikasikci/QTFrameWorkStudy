#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTimer"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *isTimer=new QTimer(this);
    connect(isTimer,SIGNAL(timeout()),this,SLOT(_ChangeButton()));
    isTimer->start(500);//her 500 ms tekrar et...

}

MainWindow::~MainWindow()
{
    delete ui;
}
int _Temp=0;
void MainWindow::mousePressEvent(QMouseEvent *event)
{
   //Create Object button
    newbutton *button = new newbutton();
    button->setGeometry(event->x(),event->y(),100,50);
    button->show();
    buttons.push_back(button);
    //button->setText(QString::number(_Temp)+"Button");
    button->setText(QString::number(buttons.size())+"Button");
    _Temp++;

    ui->statusbar->showMessage("X Cordinant: "+QString::number(event->x())+"  Y Cordinant: " +QString::number(event->y())+ " ");
}

void MainWindow::_ChangeButton()
{
    int buttonSize=buttons.size();
    for(int i=0;i<buttonSize;++i){
        if(buttons[i]->isButtonClicked){

        }
    }
}
