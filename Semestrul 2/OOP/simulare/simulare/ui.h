#pragma once
#include "rochie.h"
#include "service.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qstring.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qmessagebox.h>
class GUI : public QWidget
{
private:
	// service-ul curent
	Service& service;

	// lista de rochii
	QListWidget* list = new QListWidget;

	// butoanele pentru sortari
	QPushButton* sortMarime = new QPushButton("Sorteaza dupa marime");
	QPushButton* sortPret = new QPushButton("Sorteaza dupa pret");
	QPushButton* nesortat = new QPushButton("Nesortat");

	// butonul pentru inchiriere
	QPushButton* inchiriaza = new QPushButton("Inchiriaza rochie");

	// reincarcarea listei de rochii
	void reload(vector<Rochie> _list)
	{
		list->clear();
		for (auto r : _list)
		{
			QString str = 
				QString::fromStdString(r.get_denumire()) + " | " +
				QString::fromStdString(r.get_marime()) + " | " +
				QString::number(r.get_pret());
			QListWidgetItem* item = new QListWidgetItem(str);
			list->addItem(item);
			
		}
	}

	// conectam butoanele
	void connectSignalSlots()
	{
		QPushButton::connect(sortMarime, &QPushButton::clicked, [&]()
			{
				reload(service.sortMarime());
			});

		QPushButton::connect(sortPret, &QPushButton::clicked, [&]()
			{
				reload(service.sortPret());
			});

		QPushButton::connect(nesortat, &QPushButton::clicked, [&]()
			{
				reload(service.getList());
			});

		QPushButton::connect(inchiriaza, &QPushButton::clicked, [&]()
			{
				for (int i = 0; i < list->count();i++)
					if (list->item(i)->isSelected())
						if (service.inchiriaza(i) == -1)
							QMessageBox::information(this, "info", "indisponibil");
						else
							QMessageBox::information(this, "info", "rochia a fost inchiriata cu succes");
			});


	}

	// initializam interfata grafica
	void initGUI()
	{
		QWidget* main = new QWidget;
		QHBoxLayout* mainLy = new QHBoxLayout;
		//setLayout(mainLy);

		// stanga
		QWidget* left = new QWidget;
		QVBoxLayout* leftLy = new QVBoxLayout;
		leftLy->addWidget(list);
		left->setLayout(leftLy);

		// dreapta
		QWidget* right = new QWidget;
		QVBoxLayout* rightLy = new QVBoxLayout;
		rightLy->addWidget(sortMarime);
		rightLy->addWidget(sortPret);
		rightLy->addWidget(nesortat);
		rightLy->addWidget(inchiriaza);
		right->setLayout(rightLy);

		mainLy->addWidget(left);
		mainLy->addWidget(right);
		setLayout(mainLy);

	}

public:
	// constructorul clasei GUI
	GUI(Service& _service) : service{ _service }
	{
		reload(service.getList());
		connectSignalSlots();
		initGUI();
	}
};