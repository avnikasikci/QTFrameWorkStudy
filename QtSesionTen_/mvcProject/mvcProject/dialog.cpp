#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{

    dirModel.setRootPath(QDir::currentPath());
    dirModel.setFilter(QDir::Filter::Drives | QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);

    //i model set view
    ui->treeView->setModel(&dirModel);
    // hide colomn
    for (int i=1;i<dirModel.columnCount() ;i++ ) {
        ui->treeView->hideColumn(i);

    }

    fileModel.setRootPath(dirModel.rootPath());
    fileModel.setFilter(QDir::Filter::Files);
    // file model, görüntüye(list view) set edelim
    ui->listView->setModel(&fileModel);


}
void Dialog::on_treeView_activated(const QModelIndex &index)
{
    QString path = dirModel.filePath(index);
    qDebug() << path;
    fileModel.setFilter(QDir::Filter::Files);
    ui->listView->setRootIndex(fileModel.setRootPath(path));
}
