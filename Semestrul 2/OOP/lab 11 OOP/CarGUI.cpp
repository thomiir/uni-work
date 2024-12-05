
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QHeaderView>
#include <qformlayout.h>
#include <QtWidgets/QWidget>
#include <QCheckBox>
#include <QStandardItemModel>
#include <qwindow.h>
#include "CarGUI.h"
#include "car.h"
#include "exception.h"
#include <map>
using namespace std;
void CarGUI::initGUI()
{
	//main layout
	QHBoxLayout* lyMain = new QHBoxLayout{};
	this->setLayout(lyMain);

	//left part
	QWidget* left = new QWidget;
	QVBoxLayout* lyleft = new QVBoxLayout;
	left->setLayout(lyleft);

	// schimba pe lista de masini de spalat
	QWidget* form0 = new QWidget;
	QFormLayout* lyform0 = new QFormLayout;
	form0->setLayout(lyform0);
	butonLista = new QPushButton("Schimba pe meniul de spalat");
	lyform0->addWidget(butonLista);
	lyleft->addWidget(form0);

	//add
	QWidget* form1 = new QWidget;
	QFormLayout* lyform1 = new QFormLayout;
	form1->setLayout(lyform1);
	addLicensePlate = new QLineEdit;
	addProducer = new QLineEdit;
	addModel = new QLineEdit;
	addType = new QLineEdit;
	lyform1->addRow(labelLPAdd, addLicensePlate);
	lyform1->addRow(labelPAdd, addProducer);
	lyform1->addRow(labelMAdd, addModel);
	lyform1->addRow(labelTAdd, addType);
	buttonAdd = new QPushButton("Adauga masina");
	lyform1->addWidget(buttonAdd);
	lyleft->addWidget(form1);

	//sterge
	QWidget* form2 = new QWidget;
	QFormLayout* lyForm2 = new QFormLayout;
	form2->setLayout(lyForm2);

	deleteLP = new QLineEdit;
	lyForm2->addRow(labelDelete, deleteLP);
	buttonRemove = new QPushButton("Sterge masina");
	lyForm2->addWidget(buttonRemove);
	lyleft->addWidget(form2);

	//modifica
	QWidget* form3 = new QWidget;
	QFormLayout* lyForm3 = new QFormLayout;
	form3->setLayout(lyForm3);

	modifyLicensePlate = new QLineEdit;
	modifyProducer = new QLineEdit;
	modifyModel = new QLineEdit;
	modifyType = new QLineEdit;
	lyForm3->addRow(labelLPModify, modifyLicensePlate);
	lyForm3->addRow(labelPModify, modifyProducer);
	lyForm3->addRow(labelMModify, modifyModel);
	lyForm3->addRow(labelTModify, modifyType);
	buttonModify = new QPushButton("Modifica masina");
	lyForm3->addWidget(buttonModify);
	lyleft->addWidget(form3);

	//sortare
	QWidget* form4 = new QWidget;
	QVBoxLayout* lyv4 = new QVBoxLayout;
	QWidget* lyh4 = new QWidget;
	QHBoxLayout* lyForm4 = new QHBoxLayout;
	QWidget* lyhord4 = new QWidget;
	QHBoxLayout* lyord4 = new QHBoxLayout;
	lyhord4->setLayout(lyord4);
	lyord4->addWidget(descLabel);
	lyord4->addWidget(desc);
	form4->setLayout(lyv4);
	lyh4->setLayout(lyForm4);
	buttonSortByLicensePlate = new QPushButton("Sortare dupa nr inmatriculare");
	buttonSortByType = new QPushButton("Sortare dupa tip");
	buttonSortByProdModel = new QPushButton("Sortare dupa produs si model");
	lyv4->addWidget(sortLabel);
	lyv4->addWidget(lyhord4);
	lyForm4->addWidget(buttonSortByLicensePlate);
	lyForm4->addWidget(buttonSortByType);
	lyForm4->addWidget(buttonSortByProdModel);
	lyv4->addWidget(lyh4);
	lyleft->addWidget(form4);

	//filtrare
	QWidget* form5 = new QWidget;
	QFormLayout* lyform5 = new QFormLayout;
	form5->setLayout(lyform5);
	filterByType = new QLineEdit();
	buttonFilterByType = new QPushButton("Filtreaza dupa tip");
	filterByProducer = new QLineEdit();
	buttonFilterByProducer = new QPushButton("Filtreaza dupa producator");
	lyform5->addRow(labelTFilter, filterByType);
	lyform5->addWidget(buttonFilterByType);
	lyform5->addRow(labelPFilter, filterByProducer);
	lyform5->addWidget(buttonFilterByProducer);
	lyleft->addWidget(form5);

	// butonul pentru generarea raportului
	butonGenerateReport = new QPushButton("Genereaza raport");
	lyleft->addWidget(butonGenerateReport);

	
	QWidget* right = new QWidget;
	QVBoxLayout* lyright = new QVBoxLayout;
	right->setLayout(lyright);

	int m = 10;
	int n = 4;
	table = new QTableWidget(m,n);
	QStringList HeaderList;
	HeaderList << "Nr inmatriculare" << "Producator" << "Model" << "Tip";
	table->setHorizontalHeaderLabels(HeaderList);
	lyright->addWidget(table);

	undo = new QPushButton("UNDO");
	lyright->addWidget(undo);


	map report = service.report();
	if (report["ALTELE"] > 0)
	{
		btnAltele = new QPushButton("Nr Altele");
		lyright->addWidget(btnAltele);
	}
	if (report["SPORT"] > 0)
	{
		btnSport = new QPushButton("Nr Sport");
		lyright->addWidget(btnSport);
	}
	if (report["SUV"] > 0)
	{
		btnSuv = new QPushButton("Nr Suv");
		lyright->addWidget(btnSuv);
	}
	if (report["MINI"] > 0)
	{
		btnMini = new QPushButton("Nr Mini");
		lyright->addWidget(btnMini);
	}

	lyMain->addWidget(left);
	lyMain->addWidget(right);
}

void CarGUI::reloadList(const std::vector<Car> carList)
{
	table->clearContents();
	table->setRowCount(int(carList.size()));

	int n = 0;
	for (auto& car : carList)
	{
		table->setItem(n, 0, new QTableWidgetItem(QString::fromStdString(car.getLicensePlate())));
		table->setItem(n, 1, new QTableWidgetItem(QString::fromStdString(car.getProducer())));
		table->setItem(n, 2, new QTableWidgetItem(QString::fromStdString(car.getModel())));
		table->setItem(n, 3, new QTableWidgetItem(QString::fromStdString(car.getType())));
		n++;
	}
}

void CarGUI::reloadWashList(const std::vector<Car> carList)
{
	/*
	windowTable->clearContents();
	windowTable->setRowCount(int(carList.size()));

	int n = 0;
	for (auto& car : carList)
	{
		windowTable->setItem(n, 0, new QTableWidgetItem(QString::fromStdString(car.getLicensePlate())));
		windowTable->setItem(n, 1, new QTableWidgetItem(QString::fromStdString(car.getProducer())));
		windowTable->setItem(n, 2, new QTableWidgetItem(QString::fromStdString(car.getModel())));
		windowTable->setItem(n, 3, new QTableWidgetItem(QString::fromStdString(car.getType())));
		n++;
	}
	*/
	windowList->clear();
	for (const auto& car : carList)
	{
		QString itemText = 
		QString::fromStdString(car.getLicensePlate()) + " | " +
		QString::fromStdString(car.getProducer()) + " | " +
		QString::fromStdString(car.getModel()) + " | " +
		QString::fromStdString(car.getType());
		QListWidgetItem* item = new QListWidgetItem(itemText);
		windowList->addItem(item);
	}
}

void CarGUI::connectSignalSlots()
{
	QObject::connect(btnSuv, &QPushButton::clicked, [&]()
		{
			map report = service.report();
			QMessageBox::information(this, "Info", QString::number(report["SUV"]));
		});
	QObject::connect(btnMini, &QPushButton::clicked, [&]() 
		{
			map report = service.report();
			QMessageBox::information(this, "Info", QString::number(report["MINI"]));
		});
	QObject::connect(btnSport, &QPushButton::clicked, [&]()
		{
			map report = service.report();
			QMessageBox::information(this, "Info", QString::number(report["SPORT"]));
		}
		);
	QObject::connect(btnAltele, &QPushButton::clicked, [&]()
		{
			map report = service.report();
			QMessageBox::information(this, "Info", QString::number(report["ALTELE"]));
		});
	QObject::connect(buttonAdd, &QPushButton::clicked, this, &CarGUI::addGUI);
	QObject::connect(buttonRemove, &QPushButton::clicked, this, &CarGUI::removeGUI);
	QObject::connect(buttonModify, &QPushButton::clicked, this, &CarGUI::modifyGUI);
	QObject::connect(buttonSortByLicensePlate, &QPushButton::clicked, this, &CarGUI::sortByLicensePlateGUI);
	QObject::connect(buttonSortByType, &QPushButton::clicked, this, &CarGUI::sortByTypeGUI);
	QObject::connect(buttonSortByProdModel, &QPushButton::clicked, this, &CarGUI::sortByProdModelGUI);
	QObject::connect(desc, &QCheckBox::stateChanged, this, &CarGUI::sortOrderChanged);
	QObject::connect(buttonFilterByType, &QPushButton::clicked, [&]() 
		{
			string type = this->filterByType->text().toStdString();
			filterByType->clear();
			this->reloadList(service.filterByType(type));
		});
	QObject::connect(buttonFilterByProducer, &QPushButton::clicked, [&]() 
		{
			string prod = this->filterByProducer->text().toStdString();
			filterByProducer->clear();
			this->reloadList(service.filterByProd(prod));
		});
	QObject::connect(undo, &QPushButton::clicked, this, &CarGUI::undoGUI);
	QObject::connect(butonLista, &QPushButton::clicked, [&]()
		{
			window->show();
		});
	QObject::connect(butonAddWash, &QPushButton::clicked, this, &CarGUI::addWashGUI);
	QObject::connect(butonEmptyWash, &QPushButton::clicked, [&]() 
		{
			this->service.emptyWash();
			this->reloadWashList(this->service.getWashList());
			QMessageBox::information(this, "Info", QString::fromStdString("Lista a fost golita cu succes!"));
		});
	QObject::connect(butonAcasa, &QPushButton::clicked, [&]()
		{
			window->hide();
			this->show();
		});
	QObject::connect(butonPopulateWash, &QPushButton::clicked, this, &CarGUI::generateWashGUI);
	QObject::connect(butonExportHTMLWash, &QPushButton::clicked, [&]() 
		{
			try
			{
				string file = exportWash->text().toStdString();
				file = file + ".html";
				this->service.exportHTML(file);
				exportWash->clear();
				QMessageBox::warning(this, "Info", QString::fromStdString("Lista a fost exportata cu succes!"));
			}
			catch (const InvalidFileError& err)
			{
				QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
			}
		});
	QObject::connect(butonExportCSVWash, &QPushButton::clicked, [&]()
		{
			try
			{
				string file = exportWash->text().toStdString();
				file = file + ".csv";
				this->service.exportCSV(file);
				exportWash->clear();
				QMessageBox::warning(this, "Info", QString::fromStdString("Lista a fost exportata cu succes!"));
			}
			catch (const InvalidFileError& err)
			{
				QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
			}
		});
	QObject::connect(butonGenerateReport, &QPushButton::clicked, [&]() 
		{
			map report = this->service.report();
			string carstring;
			carstring = "Exista urmatoarele masini: \nALTELE " + to_string(report["ALTELE"]) + "\nMINI " +
				to_string(report["MINI"]) + "\nSPORT " + to_string(report["SPORT"]) + "\nSUV " + 
				to_string(report["SUV"]);
			QMessageBox::warning(this, "Info", QString::fromStdString(carstring));
		});
}

void CarGUI::addWashGUI()
{
	try
	{
		string lic = addLicensePlateWash->text().toStdString();
		addLicensePlateWash->clear();
		this->service.addWash(lic);
		this->reloadWashList(this->service.getWashList());
		QMessageBox::information(this, "Info", QString::fromStdString("Masina a fost adaugata cu succes!"));
	}
	catch (const InvalidLicensePlate& err)
	{
		QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
	}
	catch (const InexistentCarError& err)
	{
		QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
	}
}

void CarGUI::generateWashGUI()
{
	try
	{
		int nr = populateWash->text().toInt();
		populateWash->clear();
		this->service.populateWash(nr);
		this->reloadWashList(this->service.getWashList());
		QMessageBox::information(this, "Info", QString::fromStdString("Masinile au fost adaugate cu succes!"));
	}
	catch (const InvalidGenerateNumber& err)
	{
		QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
	}
}

void CarGUI::addGUI()
{
	try 
	{
		string lic = addLicensePlate->text().toStdString();
		addLicensePlate->clear();
		string prod = addProducer->text().toStdString();
		addProducer->clear();
		string model = addModel->text().toStdString();
		addModel->clear();
		string tip = addType->text().toStdString();
		addType->clear();
		this->service.addCar(lic, prod, model, tip);
		this->reloadList(this->service.getCarList());
		QMessageBox::information(this, "Info", QString::fromStdString("Masina a fost adaugata cu succes!"));

	}
	catch (const ExistentCarError& err)
	{
		QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
	}
	catch (const InvalidCarError& err)
	{
		QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
	}
}

void CarGUI::removeGUI()
{
	try 
	{
		string denum = deleteLP->text().toStdString();
		deleteLP->clear();
		this->service.removeCar(denum);
		this->reloadList(service.getCarList());

		QMessageBox::information(this, "Info", QString::fromStdString("Masina stearsa cu succes!"));
	}

	catch (const InvalidCarError& err)
	{
		QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
	}

	catch (const InexistentCarError& err)
	{
		QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
	}
}

void CarGUI::modifyGUI()
{
	try 
	{
		string lic = modifyLicensePlate->text().toStdString();
		modifyLicensePlate->clear();
		string prod = modifyProducer->text().toStdString();
		modifyProducer->clear();
		string model = modifyModel->text().toStdString();
		modifyModel->clear();
		string tip = modifyType->text().toStdString();
		modifyType->clear();
		this->service.modifyCar(lic, lic, prod, model, tip);		
		this->reloadList(this->service.getCarList());
		QMessageBox::information(this, "Info", QString::fromStdString("Masina modificata cu succes!"));
	}
	catch (const InexistentCarError& err)
	{
		QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
	}
	catch (const InvalidCarError& err)
	{
		QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
	}
}

void CarGUI::sortByLicensePlateGUI()
{
	this->reloadList(service.sortByLicPlate(mode));
}

void CarGUI::sortByTypeGUI()
{
	this->reloadList(service.sortByType(mode));
}

void CarGUI::sortByProdModelGUI()
{
	this->reloadList(service.sortByProdModel(mode));
}

void CarGUI::sortOrderChanged(int state) 
{
	if (state == Qt::Checked)
	{
		mode = 'd';
	}
	else
		mode = 'c';
}

void CarGUI::undoGUI() 
{
	try 
	{
		service.undo();
		reloadList(service.getCarList());
		QMessageBox::information(this, "Info", QString::fromStdString("Undo realizat cu succes!"));
	}
	catch (const Error& err)
	{
		QMessageBox::warning(this, "Eroare", QString::fromStdString(err.getMessage()));
	}
}

void CarGUI::initWashGUI()
{
	
	//main layout
	QHBoxLayout* lyMain = new QHBoxLayout{};
	window->setLayout(lyMain);

	//left part
	QWidget* left = new QWidget;
	QVBoxLayout* lyleft = new QVBoxLayout;
	left->setLayout(lyleft);

	// schimba pe lista de masini de spalat
	QWidget* form0 = new QWidget;
	QFormLayout* lyform0 = new QFormLayout;
	form0->setLayout(lyform0);
	butonAcasa = new QPushButton("Schimba pe meniul principal");
	lyform0->addWidget(butonAcasa);
	lyleft->addWidget(form0);

	// adaugarea unei masini in lista de masini de spalat
	QWidget* form1 = new QWidget;
	QFormLayout* lyform1 = new QFormLayout;
	form1->setLayout(lyform1);
	addLicensePlateWash = new QLineEdit;
	lyform1->addRow(labelAddWash, addLicensePlateWash);
	butonAddWash = new QPushButton("Adauga masina");
	lyform1->addWidget(butonAddWash);
	lyleft->addWidget(form1);

	// popularea listei de masini de spalat
	QWidget* form2 = new QWidget;
	QFormLayout* lyform2 = new QFormLayout;
	form2->setLayout(lyform2);
	populateWash = new QLineEdit;
	lyform2->addRow(labelPopulateWash, populateWash);
	butonPopulateWash = new QPushButton("Genereaza masini");
	lyform2->addWidget(butonPopulateWash);
	lyleft->addWidget(form2);

	// golirea listei de masini de spalat
	butonEmptyWash = new QPushButton("Goleste lista de masini de spalat");
	lyleft->addWidget(butonEmptyWash);

	// exportarea listei de masini de spalat in fisier csv / html
	QWidget* form3 = new QWidget;
	QFormLayout* lyform3 = new QFormLayout;
	form3->setLayout(lyform3);
	exportWash = new QLineEdit;
	lyform3->addRow(labelExportWash, exportWash);
	butonExportCSVWash = new QPushButton("Exporta lista in fisier .csv");
	butonExportHTMLWash = new QPushButton("Exporta lista in fisier .html");
	lyform3->addWidget(butonExportCSVWash);
	lyform3->addWidget(butonExportHTMLWash);
	lyleft->addWidget(form3);


	// lista curenta de masini
	
	QWidget* right = new QWidget;
	QHBoxLayout* lyright = new QHBoxLayout;
	right->setLayout(lyright);
	/*
	int m = 10;
	int n = 4;
	windowTable = new QTableWidget(m, n);
	QStringList HeaderList;
	HeaderList << "Nr inmatriculare" << "Producator" << "Model" << "Tip";
	windowTable->setHorizontalHeaderLabels(HeaderList);
	lyright->addWidget(windowTable);
	*/
	//QList 
	
	
	//QWidget* right = new QWidget;
	//QHBoxLayout* lyright = new QHBoxLayout;
	//right->setLayout(lyright);

	windowList = new QListWidget;
	lyright->addWidget(windowList);

	lyMain->addWidget(left);
	lyMain->addWidget(right);
}