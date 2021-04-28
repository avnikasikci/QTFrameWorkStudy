#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QStyle>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>

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
    void on_actionYakinlastir_triggered();

    void on_actionUzaklastir_triggered();

    void on_actionAc_triggered();

private:
    Ui::MainWindow *ui;
    QLabel *m_lblResim;
    QString m_yol;
    QPixmap m_resim;

};
#endif // MAINWINDOW_H
