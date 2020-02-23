#include "TypePinPage.h"
#include "ui_TypePinPage.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>

static int g_PIN=0;

TypePinPage::TypePinPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TypePinPage)
{

    ui->setupUi(this);
    SetTypePinPageUI();
    ui->stackedWidget->insertWidget(2,&optionsPage);

}
void TypePinPage::SetTypePinPageUI()
{
    ui->LEDisplay->setText(QString::number(g_PIN));
    ui->LEDisplay->setStyleSheet("QLineEdit { color:#FB8122; font-size:15px;}");
    ui->lblTypePin->setText("Please type your PIN");
    ui->lblTypePin->setStyleSheet("QLabel {color: #FB8122; font-size:30px;}");

    QPushButton *numButtons[10];
    for(int i=0;i<10;i++)
    {
        QString buttonName ="button" + QString::number(i);
        numButtons[i]=TypePinPage::findChild<QPushButton *>(buttonName);

        connect(numButtons[i],SIGNAL(clicked()),this,SLOT(numPressed()));
    }
}
void TypePinPage::numPressed()
{
    QPushButton *button=(QPushButton *)sender();
    QString butVal=button->text();
    QString displayVal=ui->LEDisplay->text();
    QString newVal=displayVal+butVal;
    int NewPin=newVal.toInt();
    if(NewPin<9999)
    {
         ui->LEDisplay->setText(QString::number(NewPin));
    }

}

TypePinPage::~TypePinPage()
{
    delete ui;
}

void TypePinPage::on_buttonCancel_clicked()
{
    emit CancelClicked();
    QString displayVal=ui->LEDisplay->text();
    int NewPin=displayVal.toInt()*0;
    ui->LEDisplay->setText(QString::number(NewPin));
}

void TypePinPage::on_buttonClear_clicked()
{
    QString displayVal=ui->LEDisplay->text();
    int NewPin=displayVal.toInt()/10;
    if(NewPin<9999)
    {
         ui->LEDisplay->setText(QString::number(NewPin));
    }
}

void TypePinPage::on_buttonOk_clicked()
{
    QString displayVal=ui->LEDisplay->text();
    int NewPin=displayVal.toInt();
    if(NewPin==1525)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        QMessageBox::critical(this,tr("ATMSimulator"),tr("Wrong PIN!"));
    }
}
