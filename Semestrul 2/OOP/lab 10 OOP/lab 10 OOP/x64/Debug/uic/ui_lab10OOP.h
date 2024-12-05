/********************************************************************************
** Form generated from reading UI file 'lab10OOP.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB10OOP_H
#define UI_LAB10OOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab10OOPClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lab10OOPClass)
    {
        if (lab10OOPClass->objectName().isEmpty())
            lab10OOPClass->setObjectName("lab10OOPClass");
        lab10OOPClass->resize(600, 400);
        menuBar = new QMenuBar(lab10OOPClass);
        menuBar->setObjectName("menuBar");
        lab10OOPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lab10OOPClass);
        mainToolBar->setObjectName("mainToolBar");
        lab10OOPClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(lab10OOPClass);
        centralWidget->setObjectName("centralWidget");
        lab10OOPClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lab10OOPClass);
        statusBar->setObjectName("statusBar");
        lab10OOPClass->setStatusBar(statusBar);

        retranslateUi(lab10OOPClass);

        QMetaObject::connectSlotsByName(lab10OOPClass);
    } // setupUi

    void retranslateUi(QMainWindow *lab10OOPClass)
    {
        lab10OOPClass->setWindowTitle(QCoreApplication::translate("lab10OOPClass", "lab10OOP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lab10OOPClass: public Ui_lab10OOPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB10OOP_H
