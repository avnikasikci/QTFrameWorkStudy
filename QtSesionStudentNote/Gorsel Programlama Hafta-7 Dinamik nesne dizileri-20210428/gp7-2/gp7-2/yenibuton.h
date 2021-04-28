#ifndef YENIBUTON_H
#define YENIBUTON_H

#include <QPushButton>
#include <QObject>
#include <QWidget>

class yeniButon : public QPushButton
{
    Q_OBJECT
public:
    explicit yeniButon(QWidget *parent = 0);
    bool tiklandimi;

signals:


public slots:
    void tikla();

};

#endif // YENIBUTON_H
