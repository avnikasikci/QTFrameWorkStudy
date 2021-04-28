#include "resimsec2.h"
#include "ui_resimsec2.h"

ResimSec2::ResimSec2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResimSec2)
{
    ui->setupUi(this);
    init();
}

ResimSec2::~ResimSec2()
{
    delete ui;
}

void ResimSec2::on_buttonBox_accepted()
{
    selected=ui->listWidget->currentItem()->text();
    /*accept();*/
}

void ResimSec2::on_buttonBox_rejected()
{
    reject();
}

void ResimSec2::init()
{
    QDir root=QDir(":/file/images");
    QFileInfoList list=root.entryInfoList();
    foreach(QFileInfo fi,list)
    {
        QListWidgetItem *itm=new QListWidgetItem(ui->listWidget);
        itm->setText(fi.absoluteFilePath());
        itm->setIcon(QIcon(fi.absoluteFilePath()));
        ui->listWidget->addItem(itm);

    }

}
