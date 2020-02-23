#include "DepositPage.h"
#include "ui_DepositPage.h"
#include <QDebug>

static int g_TypedValue=0;
static long g_BankDeposit=7502515;


DepositPage::DepositPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepositPage)
{
    ui->setupUi(this);
    SetDepositPageUI();
    ui->stackedWidget->insertWidget(2,&receiptPage);
    connect(this, SIGNAL(DataForReceipt(long &, long &, QString &)),&receiptPage, SLOT(DataFromDeposit(long &, long &, QString &)));

}

DepositPage::~DepositPage()
{
    delete ui;
}
void DepositPage::SetDepositPageUI()
{
    ui->LEDisplay->setText(QString::number(g_TypedValue));
    ui->LEDisplay->setStyleSheet("QLineEdit {color:#FB8122; font-size:15px;}");
    ui->lblTypeAmount->setText("Please type the exact amount");
    ui->lblTypeAmount->setStyleSheet("QLabel {color: #FB8122; font-size:30px;}");

    QPushButton *numButtons[10];
    for(int i=0;i<10;i++)
    {
        QString buttonName ="ValButton" + QString::number(i);
        numButtons[i]=DepositPage::findChild<QPushButton *>(buttonName);

        connect(numButtons[i],SIGNAL(clicked()),this,SLOT(amountNumPressed()));
    }

}
void DepositPage::amountNumPressed()
{
    QPushButton *button=(QPushButton *)sender();
    QString butVal=button->text();
    QString displayVal=ui->LEDisplay->text();
    QString newVal=displayVal+butVal;
    long NewTypedValue=newVal.toLong();
    ui->LEDisplay->setText(QString::number(NewTypedValue));
}
void DepositPage::on_ValButtonCancel_clicked()
{
    emit CancelClicked();
    QString displayVal=ui->LEDisplay->text();
    long NewTypedValue=displayVal.toLong()*0;
    ui->LEDisplay->setText(QString::number(NewTypedValue));
}

void DepositPage::on_ValButtonClear_clicked()
{
    QString displayVal=ui->LEDisplay->text();
    long NewTypedValue=displayVal.toLong()/10;
    ui->LEDisplay->setText(QString::number(NewTypedValue));
}

void DepositPage::on_ValButtonOk_clicked()
{
    QString displayVal=ui->LEDisplay->text();
    long NewTypedValue=displayVal.toLong();
    QString str="Deposit";
    g_BankDeposit+=NewTypedValue;
    emit DataForReceipt(NewTypedValue,g_BankDeposit,str);
    ui->stackedWidget->setCurrentIndex(2);
}

void DepositPage::moveBackToOptions()
{
    ui->stackedWidget->setCurrentIndex(0);
}

