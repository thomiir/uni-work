#pragma once
#include <vector>
#include <string>
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QFormLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include "carService.h"
#include "observer.h"
#include <map>
using namespace std;

class CarGUI : public QWidget, public Observable, Observer
{
	private:
		// service-ul curent
		CarService& service;

		// comutare
		QPushButton* butonLista;

		// adaugare
		QPushButton* buttonAdd;
		QLabel* labelLPAdd = new QLabel("Numarul de inmatriculare al masinii: ");
		QLabel* labelPAdd = new QLabel("Producatorul masinii: ");
		QLabel* labelMAdd = new QLabel("Modelul masinii: ");
		QLabel* labelTAdd = new QLabel("Tipul masinii: ");
		QLineEdit *addLicensePlate, *addProducer, *addModel, *addType;

		// stergere
		QPushButton* buttonRemove;
		QLabel* labelDelete = new QLabel{ "Numarul de inmatriculare al masinii: " };
		QLineEdit* deleteLP;

		// modifica
		QPushButton* buttonModify;
		QLabel* labelLPModify = new QLabel("Numarul de inmatriculare al masinii: ");
		QLabel* labelPModify = new QLabel("Producatorul masinii: ");
		QLabel* labelMModify = new QLabel("Modelul masinii: ");
		QLabel* labelTModify = new QLabel("Tipul masinii: ");
		QLineEdit *modifyLicensePlate, *modifyProducer, *modifyModel, *modifyType;

		// sortare
		QLabel* descLabel = new QLabel("Descrescator:");
		QCheckBox* desc = new QCheckBox;
		QLabel* sortLabel = new QLabel("Sorteaza:");
		QPushButton *buttonSortByLicensePlate, *buttonSortByType, *buttonSortByProdModel;

		// filtrare
		QLabel* labelPFilter = new QLabel("Producatorul dupa care se filtreaza:");
		QLineEdit* filterByProducer, *filterByType;
		QLabel* labelTFilter = new QLabel("Tipul dupa care se filtreaza:");
		QPushButton *buttonFilterByProducer, *buttonFilterByType;

		QTableWidget* table;
		QListWidget* windowList;
		
		QWidget* window = new QWidget;

		// initializarea interfetei
		void initGUI();

		// legatura dintre butoane si actiuni
		void connectSignalSlots();

		// reincarcam lista dupa fiecare operatiune
		void update(const vector<Car> list);

		// undo
		QPushButton* undo;

		// butoane pentru tipuri
		QPushButton *btnAltele, *btnSuv, *btnMini, *btnSport;

		// variabila care retine modul in care sortam
		char mode = 'c';

		// adaugam o masina
		void addGUI();

		//stergem o masina
		void removeGUI();

		// modificam o masina
		void modifyGUI();

		//sortam dupa nr de inmatriculare
		void sortByLicensePlateGUI();

		// sortam dupa tip
		void sortByTypeGUI();

		// sortam dupa producator + model
		void sortByProdModelGUI();

		// schimbam mode daca s-a apasat butonul de descrescator
		void sortOrderChanged(int state);

		// undo
		void undoGUI();

		// butoanele pentru meniul de masini de spalat
		QPushButton *butonAddWash, *butonEmptyWash, *butonPopulateWash, *butonExportHTMLWash;
		QPushButton *butonGenerateReport, *butonExportCSVWash, *butonAcasa;

		// formulare
		QLineEdit *addLicensePlateWash, *populateWash, *exportWash;

		// labels
		QLabel *labelAddWash = new QLabel("Introduceti un numar de inmatriculare:");
		QLabel *labelPopulateWash = new QLabel("Introduceti un numar:");
		QLabel *labelExportWash = new QLabel("Introduceti numele fisierului:");

		// tabelul care retine lista de masini
		QTableWidget* windowTable;

		// adaugam o masina in lista de masini de spalat
		void addWashGUI();

		// populam lista de masini de spalat
		void generateWashGUI();

		// initializam fereastra pentru lista de spalat
		void initWashGUI();

		// reincarcam lista de masini de spalat
		void reloadWashList(vector<Car> carList);

	public:
		// constructorul clasei GUI
		CarGUI(CarService& cS) : service{ cS }
		{
			initGUI();
			initWashGUI();
			connectSignalSlots();
			reloadList(service.getCarList());
			reloadWashList(service.getWashList());
		}
};
