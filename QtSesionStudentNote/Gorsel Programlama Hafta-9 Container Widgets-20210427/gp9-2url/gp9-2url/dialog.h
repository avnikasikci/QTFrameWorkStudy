#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QUrl>
#include <QDebug>
#include <QDesktopServices>


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
    void itemDoubleClicked(QListWidgetItem *item);


private:
    Ui::Dialog *ui;
    void init();
    void addCategory(QString name);
    void addLink(QListWidget* list, QString name, QString url);
    void addEducation();
    void addSocial();
    void addSearch();
};
#endif // DIALOG_H
