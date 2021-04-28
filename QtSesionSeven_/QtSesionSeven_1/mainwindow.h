#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <newbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent=0);
    //MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent*);

signals:

public slots:
    void _ChangeButton();

private:
    Ui::MainWindow *ui;
    QList<newbutton*> buttons2;
    QList<newbutton*> buttons;
};
#endif // MAINWINDOW_H
