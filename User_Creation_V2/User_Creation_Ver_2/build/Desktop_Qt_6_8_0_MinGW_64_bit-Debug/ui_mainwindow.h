/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *Enter_Username;
    QPlainTextEdit *User_Name;
    QLineEdit *Enter_Password;
    QPlainTextEdit *PassWord;
    QPushButton *Login;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("MainWidow\n"
"{\n"
"background -color:rgb(255, 234, 199);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Enter_Username = new QLineEdit(centralwidget);
        Enter_Username->setObjectName("Enter_Username");
        Enter_Username->setGeometry(QRect(190, 110, 113, 20));
        User_Name = new QPlainTextEdit(centralwidget);
        User_Name->setObjectName("User_Name");
        User_Name->setGeometry(QRect(70, 110, 104, 21));
        Enter_Password = new QLineEdit(centralwidget);
        Enter_Password->setObjectName("Enter_Password");
        Enter_Password->setGeometry(QRect(190, 150, 113, 20));
        PassWord = new QPlainTextEdit(centralwidget);
        PassWord->setObjectName("PassWord");
        PassWord->setGeometry(QRect(70, 150, 104, 21));
        Login = new QPushButton(centralwidget);
        Login->setObjectName("Login");
        Login->setGeometry(QRect(150, 190, 80, 18));
        Login->setAutoFillBackground(false);
        Login->setStyleSheet(QString::fromUtf8("QPushBUtton\n"
"{ 	background-color :red;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        User_Name->setPlainText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        PassWord->setPlainText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        Login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
