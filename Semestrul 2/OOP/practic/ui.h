#pragma once
#include <qwidget.h>
#include <qtablewidget.h>
#include "service.h"
#include <qtextedit.h>
#include <qpushbutton.h>
#include "window.h"
#include "observer.h"

class UI : public QWidget, public Observable
{
	friend class Window;
	// service-ul curent
	Service& service;
	// tabelul de taskuri
	QTableWidget* tabel;
	// reincarcam tabelul de taskuri
	void reincarca(const vector<Task>& v);
	// initializam interfata
	void initializeaza();
	// conectam butoanele
	void conecteaza();
	// text field-urile pentru adaugare
	QTextEdit* _id;
	QTextEdit* _desc;
	QTextEdit* _prog;
	QTextEdit* _stare;
	// butonul de adaugare
	QPushButton* adauga;
	// text field-ul pentru filtrare
	QTextEdit* _filter;
	// ferestrele pentru open, closed, inprogress
	vector<Window*> ferestre;
	// suprascriem metoda update din observer
	void update() override;

public:
	// constructorul clasei UI
	UI(Service& s) : service{ s }
	{
		initializeaza();
		reincarca(service.sorteaza_stare());
		conecteaza();
	}
	// destructorul clasei UI - stergem observerul pus
	~UI()
	{
		stergeObs();
	}
};

