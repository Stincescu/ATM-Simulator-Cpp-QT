#include "CheckBalancePage.h"
#include "ui_CheckBalancePage.h"
#include <QDebug>


static long g_Amount=0;
static long g_BankDeposit=7502515;


CheckBalancePage::CheckBalancePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckBalancePage)
{
    ui->setupUi(this);
    SetCheckBalancePageUI();
    ui->stackedWidget->insertWidget(2,&receiptPage);
    connect(this, SIGNAL(DataForReceipt(long &, long &, QString &)),&receiptPage, SLOT(DataFromCheckBalance(long &, long &, QString &)));
}

CheckBalancePage::~CheckBalancePage()
{
    delete ui;
}
void CheckBalancePage::SetCheckBalancePageUI()
{
    ui->lblText->setText("Your transaction has been successfully completed");
    ui->lblText->setStyleSheet("QLabel {color: #FB8122; font-size:25px;}");

    ui->btnReceipt->setText("Print Receipt");
    ui->btnReceipt->setStyleSheet("QPushButton {color:#FB8122; font-size:15px; background-color:E8EAE3}");

}
void CheckBalancePage::on_btnReceipt_clicked()
{
    QString str="CheckBalance";
    emit DataForReceipt(g_Amount,g_BankDeposit,str);
    ui->stackedWidget->setCurrentIndex(2);
}

