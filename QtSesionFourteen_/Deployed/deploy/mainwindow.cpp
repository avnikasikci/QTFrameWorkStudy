#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonShowMsg_clicked()
{
 QString inputMsg= ui->lineEditMsg->text();
 if(!inputMsg.isEmpty()){
     QMessageBox::information(this,"Information",inputMsg,"Ok");

 }else{
     ui->lineEditMsg->setFocus();//is empty mesgae localation textbox
     QMessageBox::information(this,"Warning","Please input message","Ok");
 }
}
