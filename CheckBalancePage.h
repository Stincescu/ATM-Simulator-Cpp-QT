#ifndef CHECKBALANCEPAGE_H
#define CHECKBALANCEPAGE_H

#include <QWidget>
#include <ReceiptPage.h>


namespace Ui {
class CheckBalancePage;
}

class CheckBalancePage : public QWidget
{
    Q_OBJECT

public:
    explicit CheckBalancePage(QWidget *parent = nullptr);
    void SetCheckBalancePageUI();
    ~CheckBalancePage();

private slots:
    void on_btnReceipt_clicked();

private:
    Ui::CheckBalancePage *ui;
    ReceiptPage receiptPage;

signals:
    void DataForReceipt(long &, long &, QString &);

};

#endif // CHECKBALANCEPAGE_H
