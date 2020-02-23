#include "ATMSimulator.h"
#include "ui_ATMSimulator.h"
#include <QDebug>


ATMSimulator::ATMSimulator(QWidget *parent) : QMainWindow(parent), ui(new Ui::ATMSimulator)
{
    ui->setupUi(this);
    SetWelcomePageUI();
    ui->stackedWidget->insertWidget(1,&pinPage);

    connect(&pinPage, SIGNAL(CancelClicked()), this, SLOT(moveHome()));

}
void ATMSimulator::SetWelcomePageUI()
{
    this->setWindowTitle("ATMSimulator");
    ui->stackedWidget->setStyleSheet("QStackedWidget {background-color:#1D2228}");

    ui->lblWelcome->setText("Welcome to SS Bank");
    ui->lblWelcome->setStyleSheet("QLabel {color: #FB8122; font-size:40px;}");

    ui->lblInsert->setText("Please insert your card");
    ui->lblInsert->setStyleSheet("QLabel {color:#FB8122; font-size:30px}");

    ui->btnCard->setText("Card Inserted");
    ui->btnCard->setStyleSheet("QPushButton {color:#FB8122; font-size:15px; background-color:E8EAE3}");

}
ATMSimulator::~ATMSimulator()
{
    delete ui;
}


void ATMSimulator::on_btnCard_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}

void ATMSimulator::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}
