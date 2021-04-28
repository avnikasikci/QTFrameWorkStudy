#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    QMdiSubWindow *editor=newDocument();
    editor->setWindowTitle("New File");

}

void MainWindow::on_actionOpen_triggered()
{
    QString path=QFileDialog::getOpenFileName(this,"Open a file");
    QFile my_file(path);
    if(!my_file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"Error!",my_file.errorString());
        return;
    }
    QTextStream stream(&my_file);

    QMdiSubWindow *window=newDocument();

    window->setWindowTitle(path);

    QPlainTextEdit *editor=qobject_cast<QPlainTextEdit*>(window->widget());

    editor->setPlainText(stream.readAll());
    my_file.close();

}

void MainWindow::on_actionSave_triggered()
{
    QMdiSubWindow *window=ui->mdiArea->currentSubWindow();
    if(!window) return;

    QString path=window->windowTitle();
    QFile my_file(path);

    if(!my_file.exists())
    {
        on_actionSave_As_triggered();
        return;

    }

    if(!my_file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error!",my_file.errorString());
        return;
    }
    QTextStream stream(&my_file);

    QPlainTextEdit *editor=qobject_cast<QPlainTextEdit*>(window->widget());
    stream << editor->toPlainText();
    my_file.close();
    window->setWindowTitle(path);
    ui->statusbar->showMessage("Saved",1000);

}

void MainWindow::on_actionSave_As_triggered()
{
    QMdiSubWindow *window=ui->mdiArea->currentSubWindow();
    if(!window) return;

    QString path=QFileDialog::getSaveFileName(this,"Save File");
    if(path.isEmpty()) return;


    QFile my_file(path);
    if(!my_file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error!",my_file.errorString());
        return;
    }
    QTextStream stream(&my_file);

    QPlainTextEdit *editor=qobject_cast<QPlainTextEdit*>(window->widget());
    stream << editor->toPlainText();
    my_file.close();

    window->setWindowTitle(path);
    ui->statusbar->showMessage("Saved",1000);

}

void MainWindow::on_actionClose_triggered()
{
    this->close();

}

void MainWindow::on_actionCopy_triggered()
{
    QMdiSubWindow *window=ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor=qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->copy();

}

void MainWindow::on_actionCut_triggered()
{
    QMdiSubWindow *window=ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor=qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->cut();

}

void MainWindow::on_actionPaste_triggered()
{
    QMdiSubWindow *window=ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor=qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->paste();

}

void MainWindow::on_actionSelect_All_triggered()
{
    QMdiSubWindow *window=ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor=qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->selectAll();

}

void MainWindow::on_actionNext_triggered()
{
    ui->mdiArea->activateNextSubWindow();

}

void MainWindow::on_actionPrevious_triggered()
{
    ui->mdiArea->activatePreviousSubWindow();

}

void MainWindow::on_actionCanvas_triggered()
{
    ui->mdiArea->cascadeSubWindows();

}

void MainWindow::on_actionTile_triggered()
{
    ui->mdiArea->tileSubWindows();

}

void MainWindow::on_actionClose_2_triggered()
{
    ui->mdiArea->closeActiveSubWindow();

}

void MainWindow::on_actionClose_All_triggered()
{
    ui->mdiArea->closeAllSubWindows();

}
QMdiSubWindow *MainWindow::newDocument()
{
    QMdiSubWindow *window=new QMdiSubWindow(this);
    QPlainTextEdit *editor=new QPlainTextEdit(window);

    window->setWidget(editor);
    window->setAttribute(Qt::WA_DeleteOnClose);

    ui->mdiArea->addSubWindow(window);
    window->show();

    return window;

}














