#ifndef ATMSIMULATOR_H
#define ATMSIMULATOR_H

#include <QMainWindow>
#include <TypePinPage.h>



QT_BEGIN_NAMESPACE
namespace Ui { class ATMSimulator; }
QT_END_NAMESPACE

class ATMSimulator : public QMainWindow
{
    Q_OBJECT

public:
    ATMSimulator(QWidget *parent = nullptr);
    ~ATMSimulator();
    void SetWelcomePageUI();

private slots:
    void on_btnCard_clicked();
    void moveHome();


private:
    Ui::ATMSimulator *ui;
    TypePinPage pinPage;



};
#endif //ATMSIMULATOR_H
