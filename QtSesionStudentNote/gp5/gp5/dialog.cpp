#include "dialog.h"
#include "ui_dialog.h"
#include "QSettings"
#include "QMessageBox"
#include "QDebug"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    yukle();
    baslarken();
    yukle_demirbas();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::baslarken()
{
    ui->cmbDemirbas->setEditable("True");
 }

void Dialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString yazi="Sectiginiz Renk..:";
    ui->lblSecim->setText(yazi+" "+arg1);
    this->setStyleSheet("background-color: "+arg1);
}

void Dialog::on_btnHatirla_clicked()
{
    QSettings settings("NeuGorsel", "gp5");
    settings.setValue("ayarlar", ui->cmbRenk->currentIndex());

    QMessageBox::information(this,"Kaydedildi",QString::number(ui->cmbRenk->currentIndex()));

}

void Dialog::yukle()
{
    QSettings settings("NeuGorsel", "gp5");
    QVariant value = settings.value("ayarlar",0);

    int index = value.toInt();
    qDebug() << value << index;

    if(index < ui->cmbRenk->count())
    {
        ui->cmbRenk->setCurrentIndex(index);
    }
    else
    {
        ui->cmbRenk->setCurrentIndex(0);
    }

}


void Dialog::yukle_demirbas()
{
    QSettings settings("NeuGorsel","gp5d");


    ui->cmbDemirbas->setCurrentText(settings.value("text","").toString());

    qDebug() << "fonk_yukle_demirbas" << settings.value("text","").toString();

    int combosize = settings.beginReadArray("combo");
    for (int i = 0;i < combosize; i++)
    {
        settings.setArrayIndex(i);
        ui->cmbDemirbas->addItem(settings.value("item","").toString());
    }
    settings.endArray();

    int listsize = settings.beginReadArray("list");
    for (int i = 0;i < listsize; i++)
    {
        settings.setArrayIndex(i);
        ui->listDemirbas->addItem(settings.value("item","").toString());
    }
    settings.endArray();
}





void Dialog::kaydet()
{
    QSettings settings("NeuGorsel", "gp5");
    settings.clear();

    settings.setValue("text",ui->cmbDemirbas->currentText());

    settings.beginWriteArray("combo");
    for(int i = 0; i < ui->cmbDemirbas->count(); i++)
    {
        settings.setArrayIndex(i);
        settings.setValue("item", ui->cmbDemirbas->itemText(i));
    }
    settings.endArray();

    settings.beginWriteArray("list");
    for(int i = 0; i < ui->listDemirbas->count(); i++)
    {
        settings.setArrayIndex(i);
        settings.setValue("item", ui->listDemirbas->item(i)->text());
    }
    settings.endArray();

}




void Dialog::on_btnTamam_clicked()
{
        kaydet();
        accept();
        return;
}

void Dialog::on_btnIptal_clicked()
{
    reject();
    return;
}

void Dialog::on_btnTemizle_clicked()
{
    ui->cmbDemirbas->clear();
    ui->listDemirbas->clear();
    return;
}

void Dialog::on_btnSil_clicked()
{
    QList<QListWidgetItem*> items = ui->listDemirbas->selectedItems();
    foreach (QListWidgetItem* item, items)
    {
        ui->listDemirbas->removeItemWidget(item);
        delete item;
    }
}
void Dialog::on_btnDemirbasEkle_clicked()
{
    if(ui->cmbDemirbas->findText(ui->cmbDemirbas->currentText()) < 0)
    {
        ui->cmbDemirbas->addItem(ui->cmbDemirbas->currentText());
    }
    ui->listDemirbas->addItem(ui->cmbDemirbas->currentText());
}
