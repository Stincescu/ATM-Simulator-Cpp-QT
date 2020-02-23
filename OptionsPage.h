#ifndef OPTIONSPAGE_H
#define OPTIONSPAGE_H

#include <QWidget>
#include <WithdrawalPage.h>
#include <FundsTransferPage.h>
#include <DepositPage.h>
#include <CheckBalancePage.h>


namespace Ui {
class OptionsPage;
}

class OptionsPage : public QWidget
{
    Q_OBJECT

public:
    explicit OptionsPage(QWidget *parent = nullptr);
    void SetOptionsPageUI();
    ~OptionsPage();
private slots:
    void on_buttonExit_clicked();

    void on_buttonWithdrawal_clicked();

    void on_buttonDeposit_clicked();

    void on_buttonBalance_clicked();

    void on_buttonTransfer_clicked();

    void moveBackToOptions();

private:
    Ui::OptionsPage *ui;
    WithdrawalPage withdrawalPage;
    FundsTransferPage fundsTransferPage;
    DepositPage depositPage;
    CheckBalancePage balancePage;

};

#endif // OPTIONSPAGE_H
