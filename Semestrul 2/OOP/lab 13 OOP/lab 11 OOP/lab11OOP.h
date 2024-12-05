#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab11OOP.h"

class lab11OOP : public QMainWindow
{
    Q_OBJECT

public:
    lab11OOP(QWidget *parent = nullptr);
    ~lab11OOP();

private:
    Ui::lab11OOPClass ui;
};
