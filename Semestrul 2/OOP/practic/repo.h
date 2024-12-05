#pragma once
#include "domain.h"
#include <fstream>

class Repo
{
	// vectorul de taskuri
	vector<Task> taskuri;
	// numele fisierului
	string fileName;
	// incarcam din fisier
	void load();
	// descarcam in fisier
	void store();
public:
	// constructorul clasei Repo
	Repo(string f) : fileName{ f } { load(); }
	// getter pentru lista de taskuri
	vector<Task>& get_taskuri() { return taskuri; }
	// adaugam un task
	void adauga_task(const Task& t);
	// modificam un task
	void modifica_task(int poz, string s);
	// stergem ultimul task
	void sterge_task() { taskuri.pop_back(); store(); }
};
// teste pentru Repo
void testRepo();