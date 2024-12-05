#include "window.h"
#include <qboxlayout.h>

void Window::initializeaza()
{
	QHBoxLayout* mainLy = new QHBoxLayout;
	setLayout(mainLy);
	close = new QPushButton("closed");
	open = new QPushButton("open");
	inprogress = new QPushButton("inprogress");
	
	tabel = new QTableWidget();
	mainLy->addWidget(tabel);
	mainLy->addWidget(close);
	mainLy->addWidget(open);
	mainLy->addWidget(inprogress);
}

void Window::reincarca()
{
	vector<Task> taskuri;
	for (auto& t : ui->service.sorteaza_stare())
		if (t.get_stare() == stare)
			taskuri.push_back(t);

	tabel->clearContents();
	tabel->setRowCount(taskuri.size());
	tabel->setColumnCount(4);
	int n = 0;
	for (auto p : taskuri)
	{
		tabel->setItem(n, 0, new QTableWidgetItem(QString::number(p.get_id())));
		tabel->setItem(n, 1, new QTableWidgetItem(QString::fromStdString(p.get_descriere())));
		tabel->setItem(n, 2, new QTableWidgetItem(QString::fromStdString(p.get_programatori())));
		tabel->setItem(n, 3, new QTableWidgetItem(QString::fromStdString(p.get_stare())));
		n++;
	}
}

void Window::conecteaza()
{
	connect(close, &QPushButton::clicked, [&]()
		{
			int id = tabel->selectionModel()->selectedRows()[0].data().toInt();
			ui->service.modifica_task(id, "closed");
			ui->update();
			update();
			notifica();
		});
	connect(inprogress, &QPushButton::clicked, [&]()
		{
			int id = tabel->selectionModel()->selectedRows()[0].data().toInt();
			ui->service.modifica_task(id, "inprogress");
			ui->update();
			update();
			notifica();
		});
	connect(open, &QPushButton::clicked, [&]()
		{
			int id = tabel->selectionModel()->selectedRows()[0].data().toInt();
			ui->service.modifica_task(id, "open");
			ui->update();
			update();
			notifica();
		});
}

void Window::update()
{
	reincarca();
}