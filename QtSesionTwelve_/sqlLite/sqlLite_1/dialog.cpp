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


void Dialog::on_pushButtonConnDb_clicked()
{
    sqlitedb.setDatabaseName("D:/Programs/DB.Browser.for.SQLite-3.12.2-win64/DB Browser for SQLite/Database/gpd12Db.db");
    if (!sqlitedb.open())
    {
        QMessageBox::information(this,"Error","Not Connection Database");
    }
    else
    {
        QMessageBox::information(this,"State","Connect Database Success");
    }
}

void Dialog::on_pushButtonUserSave_clicked()
{
    if (!sqlitedb.open())
    {
        QMessageBox::information(this,"Error","Before connect database!!!");
    }
    else
    {

        // SQL query clausework
        QSqlQuery qry;
        qry.prepare("INSERT INTO user values (?,?)");
        qry.addBindValue(ui->lineEditUserName->text());
        qry.addBindValue(ui->lineEditUserSurname->text());
        if (qry.exec())
            QMessageBox::information(this,"state","Saved");
        else
        {
           qDebug() << qry.lastError();
        }
    }
}

void Dialog::on_pushButtonUserGetAll_clicked()
{
    QSqlQuery query;
    model=new QSqlQueryModel();
    if (query.exec("select * from user"))
    {
        model->setQuery(query);
        ui->tableViewUser->setModel(model);

    }
    else
        qDebug() << query.lastError();
}
