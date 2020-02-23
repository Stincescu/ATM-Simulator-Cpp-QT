#ifndef FUNDSTRANSFERPAGE_H
#define FUNDSTRANSFERPAGE_H

#include <QWidget>
#include <ReceiptPage.h>

namespace Ui {
class FundsTransferPage;
}

class FundsTransferPage : public QWidget
{
    Q_OBJECT

public:
    explicit FundsTransferPage(QWidget *parent = nullptr);

    void SetTypeAmountPageUI();

    void SetTypeIBANPageUI();

    void SetConfirmPageUI();

    void SetReceiptPageUI();

     void Allocate(long &,long &);

    ~FundsTransferPage();

private slots:
    void amountNumPressed();
    void iBANNumPressed();

    void on_ValButtonnCancel_clicked();

    void on_ValButtonnClear_clicked();

    void on_ValButtonnOk_clicked();

    void on_ValButtonCancel_clicked();

    void on_ValButtonClear_clicked();

    void on_ValButtonOk_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::FundsTransferPage *ui;
    ReceiptPage receiptPage;

signals:
    void CancelClicked();
    void DataForReceipt(long &,long &, QString &);

};

#endif // FUNDSTRANSFERPAGE_H
