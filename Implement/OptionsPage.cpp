#include "OptionsPage.h"
#include "ui_OptionsPage.h"
#include <QDebug>
using namespace std;

OptionsPage::OptionsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionsPage)
{
    ui->setupUi(this);
    SetOptionsPageUI();
    ui->stackedWidget->insertWidget(3,&withdrawalPage);
    ui->stackedWidget->insertWidget(6,&depositPage);
    ui->stackedWidget->insertWidget(7,&balancePage);
    ui->stackedWidget->insertWidget(8,&fundsTransferPage);

    connect(&withdrawalPage, SIGNAL(CancelClicked()),this, SLOT (moveBackToOptions()));
    connect(&depositPage,SIGNAL(CancelClicked()),this, SLOT(moveBackToOptions()));
    connect(&fundsTransferPage,SIGNAL(CancelClicked()),this,SLOT(moveBackToOptions()));


}

void OptionsPage::SetOptionsPageUI()
{
    ui->lblOptions->setText("Options Menu");
    ui->lblOptions->setStyleSheet("QLabel {color: #FB8122; font-size:30px;}");
}
OptionsPage::~OptionsPage()
{
    delete ui;
}

void OptionsPage::on_buttonExit_clicked()
{
    qApp->exit();
}

void OptionsPage::on_buttonWithdrawal_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void OptionsPage::on_buttonDeposit_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void OptionsPage::on_buttonBalance_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void OptionsPage::on_buttonTransfer_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void OptionsPage::moveBackToOptions()
{
    ui->stackedWidget->setCurrentIndex(0);
}

