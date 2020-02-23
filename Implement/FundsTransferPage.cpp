#include "FundsTransferPage.h"
#include "ui_FundsTransferPage.h"
#include <QDebug>
#include <QMessageBox>

static int g_TypedValue=0;
static long g_BankDeposit=7502515;
static long g_IBAN=1;
static long g_Amount=0;

FundsTransferPage::FundsTransferPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FundsTransferPage)
{
    ui->setupUi(this);
    SetTypeIBANPageUI();
    SetTypeAmountPageUI();
    ui->stackedWidget->insertWidget(3,&receiptPage);
    connect(this, SIGNAL(DataForReceipt(long &, long &, QString &)),&receiptPage, SLOT(DataFromFundsTransfer(long &, long &, QString &)));

}

FundsTransferPage::~FundsTransferPage()
{
    delete ui;
}

//TypeIBANpage

void FundsTransferPage::SetTypeIBANPageUI()
{

    ui->LEDisplay->setText(QString::number(g_TypedValue));
    ui->LEDisplay->setStyleSheet("QLineEdit {color:#FB8122; font-size:15px;}");
    ui->lblTypeIBAN->setText("Please type the IBAN");
    ui->lblTypeIBAN->setStyleSheet("QLabel {color: #FB8122; font-size:30px;}");

    QPushButton *numButtons[10];
    for(int i=0;i<10;i++)
    {
        QString buttonName ="ValButton" + QString::number(i);
        numButtons[i]=FundsTransferPage::findChild<QPushButton *>(buttonName);

        connect(numButtons[i],SIGNAL(clicked()),this,SLOT(iBANNumPressed()));
    }
}
void FundsTransferPage::iBANNumPressed()
{
    QPushButton *button=(QPushButton *)sender();
    QString butVal=button->text();
    QString displayVal=ui->LEDisplay->text();
    QString newVal=displayVal+butVal;
    long NewTypedValue=newVal.toLong();
    ui->LEDisplay->setText(QString::number(NewTypedValue));
}

void FundsTransferPage::on_ValButtonCancel_clicked()
{
   emit CancelClicked();

    QString displayVal=ui->LEDisplay->text();
    long NewIBANValue=displayVal.toLong()*0;
    ui->LEDisplay->setText(QString::number(NewIBANValue));
}

void FundsTransferPage::on_ValButtonClear_clicked()
{
    QString displayVal=ui->LEDisplay->text();
    long NewIBANValue=displayVal.toLong()/10;
    ui->LEDisplay->setText(QString::number(NewIBANValue));
}

void FundsTransferPage::on_ValButtonOk_clicked()
{

    QString displayVal=ui->LEDisplay->text();
    long NewIBANValue=displayVal.toLong();
    if(QString::number(NewIBANValue).length()==9)
    {
        Allocate(g_IBAN,NewIBANValue);
        SetConfirmPageUI();

        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::critical(this,tr("ATMSimulator"),tr("The IBAN you typed does not exist"));
    }
}

//TypeAmountPage

void FundsTransferPage::SetTypeAmountPageUI()
{
    ui->LEDisplay_1->setText(QString::number(g_TypedValue));
    ui->LEDisplay_1->setStyleSheet("QLineEdit {color:#FB8122; font-size:15px;}");
    ui->lblTypeAmount->setText("Please type the exact amount you want to transfer");
    ui->lblTypeAmount->setStyleSheet("QLabel {color: #FB8122; font-size:20px;}");

    QPushButton *numButtons[10];
    for(int i=0;i<10;i++)
    {
        QString buttonName ="ValButtonn" + QString::number(i);
        numButtons[i]=FundsTransferPage::findChild<QPushButton *>(buttonName);

        connect(numButtons[i],SIGNAL(clicked()),this,SLOT(amountNumPressed()));
    }
}
void FundsTransferPage::amountNumPressed()
{
    QPushButton *button=(QPushButton *)sender();
    QString butVal=button->text();
    QString displayVal=ui->LEDisplay_1->text();
    QString newVal=displayVal+butVal;
    long NewTypedValue=newVal.toLong();
    ui->LEDisplay_1->setText(QString::number(NewTypedValue));

}

void FundsTransferPage::on_ValButtonnCancel_clicked()
{
    QString displayVal=ui->LEDisplay_1->text();
    long NewTypedValue=displayVal.toLong()*0;
    ui->LEDisplay_1->setText(QString::number(NewTypedValue));
     ui->stackedWidget->setCurrentIndex(0);
}
void FundsTransferPage::on_ValButtonnClear_clicked()
{
    QString displayVal=ui->LEDisplay_1->text();
    long NewTypedValue=displayVal.toLong()/10;
    ui->LEDisplay_1->setText(QString::number(NewTypedValue));
}

void FundsTransferPage::on_ValButtonnOk_clicked()
{
    QString displayVal=ui->LEDisplay_1->text();
    long NewTypedValue=displayVal.toLong();
    if(NewTypedValue<g_BankDeposit)
    {
         Allocate(g_Amount,NewTypedValue);
         SetConfirmPageUI();
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        QMessageBox::critical(this,tr("ATMSimulator"),tr("The amount you typed is larger than the bank deposit!"));
    }
}

//ConfirmPage

void FundsTransferPage::SetConfirmPageUI()
{
    ui->lblIBAN->setText("The IBAN you typed is:");
    ui->lblIBAN->setStyleSheet("QLabel {color: #FB8122; font-size:20px;}");
    QString s=QString::number(g_IBAN);
    ui->lblTypeIBANConfirm->setText(s);
    ui->lblTypeIBANConfirm->setStyleSheet("QLabel {color: #FB8122; font-size:20px;}");


    ui->lblMoney->setText("The AMOUNT you typed is:");
    ui->lblMoney->setStyleSheet("QLabel {color: #FB8122; font-size:20px;}");
    QString a=QString::number(g_Amount);
    ui->lblMoneyTyped->setText(a);
    ui->lblMoneyTyped->setStyleSheet("QLabel {color: #FB8122; font-size:20px;}");

}
void FundsTransferPage::Allocate(long &IBAN, long &NewIBANValue)
{
    IBAN=NewIBANValue;
}

void FundsTransferPage::on_buttonBox_accepted()
{
    QString str="Funds Transfer";
    g_BankDeposit-=g_Amount;
    emit DataForReceipt(g_Amount,g_BankDeposit,str);

    ui->stackedWidget->setCurrentIndex(3);
}

void FundsTransferPage::on_buttonBox_rejected()
{
    ui->stackedWidget->setCurrentIndex(1);
}
