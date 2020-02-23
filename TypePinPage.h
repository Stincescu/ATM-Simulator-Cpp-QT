#ifndef TYPEPINPAGE_H
#define TYPEPINPAGE_H

#include <QWidget>
#include <OptionsPage.h>

namespace Ui {
class TypePinPage;
}

class TypePinPage : public QWidget
{
    Q_OBJECT

public:
    explicit TypePinPage(QWidget *parent = nullptr);
    void SetTypePinPageUI();

    ~TypePinPage();

private slots:

    void numPressed();
    void on_buttonCancel_clicked();

    void on_buttonClear_clicked();

    void on_buttonOk_clicked();

private:
    Ui::TypePinPage *ui;
    OptionsPage optionsPage;

signals:
    void CancelClicked();

};

#endif // TYPEPINPAGE_H
