#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab10OOP.h"

class lab10OOP : public QMainWindow
{
    Q_OBJECT

public:
    lab10OOP(QWidget *parent = nullptr);
    ~lab10OOP();

private:
    Ui::lab10OOPClass ui;
};
