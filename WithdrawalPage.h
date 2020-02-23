#ifndef WITHDRAWALPAGE_H
#define WITHDRAWALPAGE_H

#include <QWidget>
#include <ReceiptPage.h>
#include <TypeAmountPage.h>

namespace Ui {
class WithdrawalPage;
}

class WithdrawalPage : public QWidget
{
    Q_OBJECT

public:
    explicit WithdrawalPage(QWidget *parent = nullptr);

    void SetWithdrawalPageUI();
    ~WithdrawalPage();


private slots:
    void on_btn10_clicked();

    void on_btn50_clicked();

    void on_btn100_clicked();

    void on_btn500_clicked();

    void on_btn1000_clicked();

    void on_btnOther_clicked();

    void on_btnCancel_clicked();

    void moveWithdrawal();



private:
    Ui::WithdrawalPage *ui;
    ReceiptPage receiptPage;
    TypeAmountPage typeAmountPage;

signals:
    void CancelClicked();
    void DataForReceipt(long &, long &, QString &);


};

#endif // WITHDRAWALPAGE_H
