#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButtonConnDb_clicked();

    void on_pushButtonUserSave_clicked();

    void on_pushButtonUserGetAll_clicked();

private:
    Ui::Dialog *ui;
    QSqlQueryModel *model;
    QSqlDatabase sqlitedb=QSqlDatabase::addDatabase("QSQLITE");
};
#endif // DIALOG_H
