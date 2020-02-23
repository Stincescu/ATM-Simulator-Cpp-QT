#include "ReceiptPage.h"
#include "ui_ReceiptPage.h"
#include <CheckBalancePage.h>
#include <QDebug>
#include <QDate>
#include <QTime>

ReceiptPage::ReceiptPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReceiptPage)
{
    ui->setupUi(this);
    SetReceiptPageUI();
    SetReceiptPageUILabelValues();


}
void ReceiptPage::SetReceiptPageUI()
{
    ui->lblTitle->setText("ATM Transaction Record");
    ui->lblTitle->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:25px;}");

    ui->lblDate->setText("Date:");
    ui->lblDate->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblTime->setText("Time:");
    ui->lblTime->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblLocation->setText("Location:");
    ui->lblLocation->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblCardNum->setText("Card Numb:");
    ui->lblCardNum->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblTransaction->setText("Transaction:");
    ui->lblTransaction->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->llblAmount->setText("Amount:");
    ui->llblAmount->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblBalance->setText("Balance:");
    ui->lblBalance->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

}

void ReceiptPage::SetReceiptPageUILabelValues()
{
    QDate date= QDate::currentDate();
    QString dates=date.toString();
    ui->lblDateValue->setText(dates);
    ui->lblDateValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    QTime time= QTime::currentTime();
    QString times=time.toString();
    ui->lblTimeValue->setText(times);
    ui->lblTimeValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblLocationValue->setText("Romania");
    ui->lblLocationValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblCardNumValue->setText("**** **** **** 1525");
    ui->lblCardNumValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

}

ReceiptPage::~ReceiptPage()
{
    delete ui;
}
void ReceiptPage::DataFromCheckBalance(long &Amount,long &BankDeposit,QString &str)
{

    QString Amounts = QString::number(Amount);
    ui->lblAmountValue->setText(Amounts);
    ui->lblAmountValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    QString BankAmount = QString::number(BankDeposit);
    ui->lblAvailableBalance->setText(BankAmount);
    ui->lblAvailableBalance->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblTransactionValue->setText(str);
    ui->lblTransactionValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");


}
void ReceiptPage::DataFromDeposit(long &Amount, long &BankDeposit, QString &str)
{
    QString Amounts = QString::number(Amount);
    ui->lblAmountValue->setText(Amounts);
    ui->lblAmountValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    QString BankAmount = QString::number(BankDeposit);
    ui->lblAvailableBalance->setText(BankAmount);
    ui->lblAvailableBalance->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblTransactionValue->setText(str);
    ui->lblTransactionValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

}
void ReceiptPage::DataFromFundsTransfer(long &Amount, long &BankDeposit, QString &str)
{
    QString Amounts = QString::number(Amount);
    ui->lblAmountValue->setText(Amounts);
    ui->lblAmountValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    QString BankAmount = QString::number(BankDeposit);
    ui->lblAvailableBalance->setText(BankAmount);
    ui->lblAvailableBalance->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblTransactionValue->setText(str);
    ui->lblTransactionValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");
}

void ReceiptPage::DataFromWithdrawal(long &Amount, long &BankDeposit, QString &str)
{
    QString Amounts = QString::number(Amount);
    ui->lblAmountValue->setText(Amounts);
    ui->lblAmountValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    QString BankAmount = QString::number(BankDeposit);
    ui->lblAvailableBalance->setText(BankAmount);
    ui->lblAvailableBalance->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblTransactionValue->setText(str);
    ui->lblTransactionValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");
}

void ReceiptPage::DataFromWithdrawalCustom(long &Amount, long &BankDeposit, QString &str)
{
    QString Amounts = QString::number(Amount);
    ui->lblAmountValue->setText(Amounts);
    ui->lblAmountValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    QString BankAmount = QString::number(BankDeposit);
    ui->lblAvailableBalance->setText(BankAmount);
    ui->lblAvailableBalance->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");

    ui->lblTransactionValue->setText(str);
    ui->lblTransactionValue->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:15px;}");
}
