#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionSelect_All_triggered();

    void on_actionSelect_None_triggered();

    void on_actionToolbar_Top_triggered();

    void on_actionToolbar_Bottom_triggered();

    void on_actionToolbar_Left_triggered();

    void on_actionToolbar_Right_triggered();

    void on_actionToolbar_Floatable_toggled(bool arg1);

    void on_actionToolbar_Movable_toggled(bool arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
