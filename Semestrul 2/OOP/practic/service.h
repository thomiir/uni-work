#pragma once
#include "repo.h"

class Service
{
	// repository-ul curent
	Repo& repo;
public:
	// constructorul clasei service
	Service(Repo& r) : repo{ r } {};
	// getter pentru taskuri
	vector<Task>& get_taskuri() { return repo.get_taskuri(); }
	// adaugam un task
	void adauga_task(int i, string d, string p, string s);
	// cautam dupa programator
	vector<Task> cauta_programator(string p);
	// sortam dupa stare
	vector<Task> sorteaza_stare();
	// modificam un task
	void modifica_task(int id, string s);
	// stergem un task
	void sterge_task() { repo.sterge_task(); }
};
// teste pentru service
void testService();