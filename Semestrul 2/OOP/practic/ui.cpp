#include "ui.h"
#include <qboxlayout.h>
#include <qlabel.h>
#include <qmessagebox.h>

void UI::initializeaza()
{
	adaugaObs(this);
	tabel = new QTableWidget;
	QHBoxLayout* mainLy = new QHBoxLayout;
	setLayout(mainLy);
	mainLy->addWidget(tabel);

	_id = new QTextEdit();
	_desc = new QTextEdit();
	_prog = new QTextEdit();
	_stare = new QTextEdit();
	QLabel* id = new QLabel("Introduceti id-ul taskului");
	QLabel* desc = new QLabel("Introduceti descrierea taskului");
	QLabel* prog = new QLabel("Introduceti programatorii");
	QLabel* stare = new QLabel("Introduceti starea");
	adauga = new QPushButton("Adauga task");

	QVBoxLayout* dreaptaLy = new QVBoxLayout;
	QWidget* dreapta = new QWidget;
	dreapta->setLayout(dreaptaLy);
	dreaptaLy->addWidget(id);
	dreaptaLy->addWidget(_id);
	dreaptaLy->addWidget(desc);
	dreaptaLy->addWidget(_desc);
	dreaptaLy->addWidget(prog);
	dreaptaLy->addWidget(_prog);
	dreaptaLy->addWidget(stare);
	dreaptaLy->addWidget(_stare);
	dreaptaLy->addWidget(adauga);


	QLabel* filter = new QLabel("Filtreaza dupa numele programatorului");
	_filter = new QTextEdit();
	dreaptaLy->addWidget(filter);
	dreaptaLy->addWidget(_filter);
	mainLy->addWidget(dreapta);

	Window* open = new Window{ this, "open" };
	open->show();
	Window* closed = new Window{ this, "closed" };
	closed->show();
	Window* inprog = new Window{ this, "inprogress" };
	inprog->show();
	ferestre.push_back(open);
	ferestre.push_back(closed);
	ferestre.push_back(inprog);

}

void UI::reincarca(const vector<Task>& v)
{
	tabel->clearContents();
	tabel->setRowCount(v.size());
	tabel->setColumnCount(4);
	int n = 0;
	for (auto p : v)
	{
		tabel->setItem(n, 0, new QTableWidgetItem(QString::number(p.get_id())));
		tabel->setItem(n, 1, new QTableWidgetItem(QString::fromStdString(p.get_descriere())));
		tabel->setItem(n, 2, new QTableWidgetItem(QString::fromStdString(p.get_programatori())));
		tabel->setItem(n, 3, new QTableWidgetItem(QString::fromStdString(p.get_stare())));
		n++;
	}
}

void UI::conecteaza()
{
	connect(adauga, &QPushButton::clicked, [&]()
		{
			int id = _id->toPlainText().toInt();
			string desc = _desc->toPlainText().toStdString();
			string prog = _prog->toPlainText().toStdString();
			string stare = _stare->toPlainText().toStdString();
			try
			{
				service.adauga_task(id, desc, prog, stare);
				reincarca(service.sorteaza_stare());
				QMessageBox::information(this, "Info", "Task adaugat cu succes!");
				_id->clear();
				_desc->clear();
				_prog->clear();
				_stare->clear();
				notifica();
				update();
			}
			catch (const string& e)
			{
				QMessageBox::warning(this, "Eroare", QString::fromStdString(e));
			}
		});
	connect(_filter, &QTextEdit::textChanged, [&]()
		{
			string p = _filter->toPlainText().toStdString();
			if (p.size())
			{
				vector<Task> v = service.cauta_programator(p);
				sort(v.begin(), v.end(), [](Task& t1, Task& t2)
					{
						return t1.get_stare() < t2.get_stare();
					});
				reincarca(v);
			}
//				reincarca(service.cauta_programator(p));
			else 
				reincarca(service.sorteaza_stare());

		});
}

void UI::update()
{
	for (auto& f : ferestre)
		f->update();
	reincarca(service.sorteaza_stare());
}