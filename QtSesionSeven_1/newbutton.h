#ifndef NEWBUTTON_H
#define NEWBUTTON_H

#include <QPushButton>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class newbutton : public QPushButton
{
    bool isButtonClicked;
public:
    newbutton(/*bool isButtonClicked)*/);

public slots:
    void clickManuel();




};
#endif // NEWBUTTON_H
