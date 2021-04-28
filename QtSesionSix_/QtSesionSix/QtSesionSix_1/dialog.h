#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButtonNew_clicked();

    void on_pushButtonRead_clicked();

    void on_pushButtonSave_clicked();

    void on_plainTextEdit_textChanged();

private:
    Ui::Dialog *ui;
    bool isMsgSaved; // we are defining variables, not functions
    void save();
    void read();

    // QPaintDevice interface
public:
    QPaintEngine *paintEngine() const override;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // DIALOG_H
