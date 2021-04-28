#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButtonMake_clicked()
{
    ui->lblShow->setEnabled(true);
    QString LineType,InputColor,Line;
    int LineSize;
    //LineType=ui->comboBoxLineType->currentText();
    LineType=ui->fontComboBox->currentText();
    LineSize=ui->spinBoxLineSize->value();
    InputColor=ui->comboBoxLineColor->currentText();
    Line=ui->lineEditInput->text();
    ui->lblShow->setText(Line);
    //Style Settings
    QFont myFont(LineType,LineSize); // two parameters sett one line type second line size
    myFont.setBold(ui->checkBoxBold->isChecked());
    myFont.setItalic(ui->checkBoxItalic->isChecked());
    QPalette myColor;
    myColor.setColor(QPalette::WindowText,ui->comboBoxLineColor->currentText()); // Eğer butonu değiştirceğin zaman bunu button secicek
    ui->lblShow->setFont(myFont);
    ui->lblShow->setPalette(myColor);

}
