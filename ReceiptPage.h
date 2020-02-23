#ifndef RECEIPTPAGE_H
#define RECEIPTPAGE_H

#include <QWidget>

namespace Ui {
class ReceiptPage;
}

class ReceiptPage : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiptPage(QWidget *parent = nullptr);
    ~ReceiptPage();
    void SetReceiptPageUI();
    void SetReceiptPageUILabelValues();

private:
    Ui::ReceiptPage *ui;


public slots:
    void DataFromCheckBalance(long &,long &, QString &);
    void DataFromDeposit(long &,long &,QString &);
    void DataFromFundsTransfer(long &, long &, QString &);
    void DataFromWithdrawal(long &, long &, QString &);
    void DataFromWithdrawalCustom(long &, long &, QString &);
};

#endif // RECEIPTPAGE_H
