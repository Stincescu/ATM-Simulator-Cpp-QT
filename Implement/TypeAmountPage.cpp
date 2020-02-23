#include "TypeAmountPage.h"
#include "ui_TypeAmountPage.h"
#include <QDebug>
#include <QMessageBox>

static int g_TypedValue=0;
static long g_BankDeposit=7502515;

TypeAmountPage::TypeAmountPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TypeAmountPage)
{
    ui->setupUi(this);
    SetTypeAmountPageUI();
    ui->stackedWidget->insertWidget(2,&receiptPage);
    connect(this, SIGNAL(DataForReceipt(long &, long &, QString &)),&receiptPage, SLOT(DataFromWithdrawalCustom(long &, long &, QString &)));
}

TypeAmountPage::~TypeAmountPage()
{
    delete ui;
}
void TypeAmountPage::SetTypeAmountPageUI()
{
    ui->LEDisplay_3->setText(QString::number(g_TypedValue));
    ui->LEDisplay_3->setStyleSheet("QLineEdit {color:#FB8122; font-size:15px;}");
    ui->lblTypeAmount->setText("Please type the exact amount");
    ui->lblTypeAmount->setStyleSheet("QLabel {color: #FB8122; font-size:30px;}");

    QPushButton *numButtons[10];
    for(int i=0;i<10;i++)
    {
        QString buttonName ="ValButton" + QString::number(i);
        numButtons[i]=TypeAmountPage::findChild<QPushButton *>(buttonName);

        connect(numButtons[i],SIGNAL(clicked()),this,SLOT(amountNumPressed()));
    }
}
void TypeAmountPage::amountNumPressed()
{
    QPushButton *button=(QPushButton *)sender();
    QString butVal=button->text();
    QString displayVal=ui->LEDisplay_3->text();
    QString newVal=displayVal+butVal;
    long NewTypedValue=newVal.toLong();
    ui->LEDisplay_3->setText(QString::number(NewTypedValue));


}

void TypeAmountPage::on_ValButtonClear_clicked()
{
    QString displayVal=ui->LEDisplay_3->text();
    long NewTypedValue=displayVal.toLong()/10;
    ui->LEDisplay_3->setText(QString::number(NewTypedValue));

}

void TypeAmountPage::on_ValButtonCancel_clicked()
{
    emit CancelClicked();
    QString displayVal=ui->LEDisplay_3->text();
    long NewTypedValue=displayVal.toLong()*0;
    ui->LEDisplay_3->setText(QString::number(NewTypedValue));
}

void TypeAmountPage::on_ValButtonOk_clicked()
{
    QString displayVal=ui->LEDisplay_3->text();
    long NewTypedValue=displayVal.toLong();
    if(NewTypedValue<g_BankDeposit)
    {
        QString str="Withdrawal Custom";
        g_BankDeposit-=NewTypedValue;
        emit DataForReceipt(NewTypedValue,g_BankDeposit,str);
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        QMessageBox::critical(this,tr("ATMSimulator"),tr("The amount you typed is larger than the bank deposit!"));
    }
}
