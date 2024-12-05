#pragma once
#include "ui.h"
#include "observer.h"

// definim clasa Window, pentru cele trei ferestre de taskuri
class Window : public QWidget, public Observer, public Observable
{
	friend class UI;
	// retinem un pointer catre clasa UI
	UI* ui;
	// starea taskurilor din fereastra
	string stare;
	// cele trei butoane pentru open, close, inprogress
	QPushButton* close;
	QPushButton* open;
	QPushButton* inprogress;
	// tabelul de taskuri
	QTableWidget* tabel;
	// initializam interfata grafica
	void initializeaza();
	// reincarcam tabelul
	void reincarca();
	// conectam butoanele
	void conecteaza();
	// suprascriem metoda update din clasa Observer
	void update() override;

public:
	// constructorul clasei Window
	Window(UI* _ui, string s) : ui{ _ui }, stare{ s } 
	{
		initializeaza();
		reincarca();
		conecteaza();
	};
};