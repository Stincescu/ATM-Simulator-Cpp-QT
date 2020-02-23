QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Implement/ATMSimulator.cpp \
    Implement/CheckBalancePage.cpp \
    Implement/DepositPage.cpp \
    Implement/FundsTransferPage.cpp \
    Implement/Main.cpp \
    Implement/OptionsPage.cpp \
    Implement/ReceiptPage.cpp \
    Implement/TypeAmountPage.cpp \
    Implement/TypePinPage.cpp \
    Implement/WithdrawalPage.cpp \


HEADERS += \
    ATMSimulator.h \
    CheckBalancePage.h \
    DepositPage.h \
    FundsTransferPage.h \
    OptionsPage.h \
    ReceiptPage.h \
    TypeAmountPage.h \
    TypePinPage.h \
    WithdrawalPage.h

FORMS += \
    UI/ATMSimulator.ui \
    UI/CheckBalancePage.ui \
    UI/DepositPage.ui \
    UI/FundsTransferPage.ui \
    UI/OptionsPage.ui \
    UI/ReceiptPage.ui \
    UI/TypeAmountPage.ui \
    UI/TypePinPage.ui \
    UI/WithdrawalPage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
