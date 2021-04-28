#ifndef RESIMSEC2_H
#define RESIMSEC2_H

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QListWidgetItem>

namespace Ui {
class ResimSec2;
}

class ResimSec2 : public QDialog
{
    Q_OBJECT

public:
    explicit ResimSec2(QWidget *parent = nullptr);
    ~ResimSec2();
    QString selected;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ResimSec2 *ui;
    void init();
};

#endif // RESIMSEC2_H
