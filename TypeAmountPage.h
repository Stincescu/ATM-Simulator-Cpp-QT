#ifndef TYPEAMOUNTPAGE_H
#define TYPEAMOUNTPAGE_H

#include <QWidget>
#include <ReceiptPage.h>

namespace Ui {
class TypeAmountPage;
}

class TypeAmountPage : public QWidget
{
    Q_OBJECT

public:
    explicit TypeAmountPage(QWidget *parent = nullptr);
    void SetTypeAmountPageUI();
    ~TypeAmountPage();

private slots:
    void amountNumPressed();

    void on_ValButtonClear_clicked();

    void on_ValButtonCancel_clicked();

    void on_ValButtonOk_clicked();

private:
    Ui::TypeAmountPage *ui;
    ReceiptPage receiptPage;

signals:
    void CancelClicked();
    void DataForReceipt(long &, long &, QString &);

};

#endif // TYPEAMOUNTPAGE_H
