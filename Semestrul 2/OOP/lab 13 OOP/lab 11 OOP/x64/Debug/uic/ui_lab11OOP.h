/********************************************************************************
** Form generated from reading UI file 'lab11OOP.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB11OOP_H
#define UI_LAB11OOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab11OOPClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lab11OOPClass)
    {
        if (lab11OOPClass->objectName().isEmpty())
            lab11OOPClass->setObjectName("lab11OOPClass");
        lab11OOPClass->resize(600, 400);
        menuBar = new QMenuBar(lab11OOPClass);
        menuBar->setObjectName("menuBar");
        lab11OOPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lab11OOPClass);
        mainToolBar->setObjectName("mainToolBar");
        lab11OOPClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(lab11OOPClass);
        centralWidget->setObjectName("centralWidget");
        lab11OOPClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lab11OOPClass);
        statusBar->setObjectName("statusBar");
        lab11OOPClass->setStatusBar(statusBar);

        retranslateUi(lab11OOPClass);

        QMetaObject::connectSlotsByName(lab11OOPClass);
    } // setupUi

    void retranslateUi(QMainWindow *lab11OOPClass)
    {
        lab11OOPClass->setWindowTitle(QCoreApplication::translate("lab11OOPClass", "lab11OOP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lab11OOPClass: public Ui_lab11OOPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB11OOP_H
