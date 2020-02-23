#include "WithdrawalPage.h"
#include "ui_WithdrawalPage.h"
#include <QPushButton>
#include <QDebug>

static long g_BankDeposit=7502515;
static long g_Amount=0;

WithdrawalPage::WithdrawalPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WithdrawalPage)
{
    ui->setupUi(this);
    SetWithdrawalPageUI();
    ui->stackedWidget->insertWidget(2,&receiptPage);
    ui->stackedWidget->insertWidget(3,&typeAmountPage);

    connect(&typeAmountPage, SIGNAL(CancelClicked()),this, SLOT(moveWithdrawal()));
    connect(this, SIGNAL(DataForReceipt(long &, long &, QString &)),&receiptPage, SLOT(DataFromWithdrawal(long &, long &, QString &)));
}

WithdrawalPage::~WithdrawalPage()
{
    delete ui;
}
void WithdrawalPage::SetWithdrawalPageUI()
{

   ui->lblWithdrTransaction->setText("Withdrawal Transaction");
   ui->lblWithdrTransaction->setStyleSheet("QLabel {font: Dosis;color: #FB8122; font-size:30px;}");

}
void WithdrawalPage::on_btn10_clicked()
{
    g_Amount=10;
    QString str="Withdrawal 10";
    g_BankDeposit-=g_Amount;
    emit DataForReceipt(g_Amount,g_BankDeposit,str);

    ui->stackedWidget->setCurrentIndex(2);   //CATRE RECEIPT
}


void WithdrawalPage::on_btn50_clicked()
{
    g_Amount=50;
    QString str="Withdrawal 50";
    g_BankDeposit-=g_Amount;
    emit DataForReceipt(g_Amount,g_BankDeposit,str);

     ui->stackedWidget->setCurrentIndex(2);
}

void WithdrawalPage::on_btn100_clicked()
{
    g_Amount=100;
    QString str="Withdrawal 100";
    g_BankDeposit-=g_Amount;
    emit DataForReceipt(g_Amount,g_BankDeposit,str);
    ui->stackedWidget->setCurrentIndex(2);

}

void WithdrawalPage::on_btn500_clicked()
{
    g_Amount=500;
    QString str="Withdrawal 500";
    g_BankDeposit-=g_Amount;
    emit DataForReceipt(g_Amount,g_BankDeposit,str);
    ui->stackedWidget->setCurrentIndex(2);
}

void WithdrawalPage::on_btn1000_clicked()
{
    g_Amount=1000;
    QString str="Withdrawal 1000";
    g_BankDeposit-=g_Amount;
    emit DataForReceipt(g_Amount,g_BankDeposit,str);
    ui->stackedWidget->setCurrentIndex(2);
}

void WithdrawalPage::on_btnOther_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void WithdrawalPage::on_btnCancel_clicked()
{
    emit CancelClicked();
}

void WithdrawalPage::moveWithdrawal()
{
    ui->stackedWidget->setCurrentIndex(0);
}






























