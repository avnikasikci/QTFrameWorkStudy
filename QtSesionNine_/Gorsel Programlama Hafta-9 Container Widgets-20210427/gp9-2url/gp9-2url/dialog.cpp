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

void Dialog::itemDoubleClicked(QListWidgetItem *item)
{
   QString url = item->data(Qt::ItemDataRole::UserRole).toString();
   QDesktopServices::openUrl(QUrl(url));
}

void Dialog::init()
{
    // Sayfaları temizleyelim
    while(ui->toolBox->count()>0)
    {
        ui->toolBox->removeItem(0);

    }
    // Sayfaları ekleyelim
    addCategory("Egitim");
    addCategory("Arama Motorları");
    addCategory("Sosyal Medya");

    addEducation();
    addSearch();
    addSocial();



}

void Dialog::addCategory(QString name)
{
    QListWidget * list = new QListWidget(this);
    ui->toolBox->addItem(list,QIcon(":/files/resimler/Globe-icon.png"),name);
    connect(list,&QListWidget::itemDoubleClicked,this,&Dialog::itemDoubleClicked);
}

void Dialog::addLink(QListWidget *list, QString name, QString url)
{
    QListWidgetItem *itm=new QListWidgetItem(QIcon(":/files/resimler/page2.png"),name);
    itm->setData(Qt::ItemDataRole::UserRole,url);
    list->addItem(itm);
}

void Dialog::addEducation()
{
   QListWidget *list = qobject_cast<QListWidget*>(ui->toolBox->widget(0));
   if (!list){
       qWarning() << "Egitim ile ilgili linklerin listesi bulunamadı";
       return;
   }

   addLink(list,"Erbakan Uni","http://www.erbakan.edu.tr");
}


void Dialog::addSocial()
{
    QListWidget *list = qobject_cast<QListWidget*>(ui->toolBox->widget(1));

    if(!list)
    {
        qWarning() << "Could not find Social List!";
        return;
    }

    addLink(list,"Facebook", "http://www.facebook.com");
    addLink(list,"YouTube", "http://www.youtube.com");

}

void Dialog::addSearch()
{
    QListWidget *list = qobject_cast<QListWidget*>(ui->toolBox->widget(2));

    if(!list)
    {
        qWarning() << "Could not find Search List!";
        return;
    }

    addLink(list,"Google", "http://www.google.com");
    addLink(list,"Yahoo", "http://www.yahoo.com");

}

