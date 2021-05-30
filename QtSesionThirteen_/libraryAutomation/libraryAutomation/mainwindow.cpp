#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setEnabled(false);
    sqlitedb.setDatabaseName("C:/Sqlite/DB.Browser.for.SQLite-3.12.2-win64/DB Browser for SQLite/database/DbLibrary.db");
    //C:\Sqlite\DB.Browser.for.SQLite-3.12.2-win64\DB Browser for SQLite\database
    if(!sqlitedb.open()){
        statusBar()->showMessage("Status:Can not connection database");
    }else{
        statusBar()->showMessage("Status:Success connect database");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonLogin_clicked()
{
    QSqlQuery query;
    query.prepare("select user_name from user where user_name = ? and user_password = ? ;");
    query.addBindValue(ui->lineEditUserName->text());
    query.addBindValue(ui->lineEditPwd->text());
    query.exec();

    int temp=0;
    while(query.next())
        temp++;
    if(temp==1){
        ui->tabWidget->setEnabled(true);
        ui->statusbar->showMessage("Status: Succes login...");
    }
    else{
        ui->statusbar->showMessage("Cannot find user");
        qDebug() << query.lastError();
        ui->tabWidget->setEnabled(false);


    }



}
