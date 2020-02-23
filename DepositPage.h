#ifndef DEPOSITPAGE_H
#define DEPOSITPAGE_H

#include <QWidget>
#include <ReceiptPage.h>

namespace Ui {
class DepositPage;
}

class DepositPage : public QWidget
{
    Q_OBJECT

public:
    explicit DepositPage(QWidget *parent = nullptr);
    void SetDepositPageUI();
    ~DepositPage();

private:
    Ui::DepositPage *ui;
    ReceiptPage receiptPage;


signals:
    void CancelClicked();
    void DataForReceipt(long &, long &, QString &);

private slots:
    void amountNumPressed();

    void on_ValButtonCancel_clicked();

    void on_ValButtonClear_clicked();

    void on_ValButtonOk_clicked();

    void moveBackToOptions();
};

#endif // DEPOSITPAGE_H
