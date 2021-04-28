#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->scrollArea);

    //https://doc.qt.io/archives/qt-4.8/qstyle.html
    ui->actionAc->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionUzaklastir->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowBack));
    ui->actionYakinlastir->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowDown));

    m_lblResim=new QLabel(this);
    ui->scrollArea->setWidget(m_lblResim);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionYakinlastir_triggered()
{
    int w = m_lblResim->width();
    int h  = m_lblResim->height();

    w += 10;
    h += 10;

    m_lblResim->resize(w,h);
    m_lblResim->setPixmap(m_resim.scaled(w,h));
}

void MainWindow::on_actionUzaklastir_triggered()
{
    int w = m_lblResim->width();
    int h  = m_lblResim->height();

    w -= 10;
    h -= 10;

    m_lblResim->resize(w,h);
    m_lblResim->setPixmap(m_resim.scaled(w,h));
}

void MainWindow::on_actionAc_triggered()
{
    m_yol=QFileDialog::getOpenFileName(this,"DosyaAc",QString(),"All Files(*.*);;JPG(*.jpg);;PNG(*.png)");
    if (m_yol.isEmpty()) return;
    if (!m_resim.load(m_yol))
    {
        QMessageBox::critical(this,"Hata","Dosya Acilamıyor");

    }
    m_lblResim->setPixmap(m_resim);
}
