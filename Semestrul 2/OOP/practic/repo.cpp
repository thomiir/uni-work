#include "repo.h"
#include <cassert>
#include <iostream>
using namespace std;

void Repo::load()
{
	ifstream in(fileName);
	int id;
	taskuri = {};
	string descriere, stare, prog;
	while (in >> id >> descriere >> prog >> stare)
		taskuri.push_back(Task{ id,descriere, prog, stare });
	in.close();
}

void Repo :: store()
{
	ofstream out(fileName);
	for (auto& t : taskuri)
		out << t.get_id() << ' ' << t.get_descriere() << ' ' << t.get_programatori() << ' ' << t.get_stare() << endl;
	out.close();
}

void Repo::adauga_task(const Task& t)
{
	taskuri.push_back(t);
	store();
}

void Repo::modifica_task(int poz, string s)
{
	taskuri[poz].set_stare(s);
	store();
}

void testRepo()
{
	Repo repo{ "test.txt" };
	Task t{ 1, "desc", "prog", "closed" };
	repo.adauga_task(t);
	vector<Task> taskuri = repo.get_taskuri();
	assert(repo.get_taskuri().size() == 1);
	repo.modifica_task(0, "open");
	assert(repo.get_taskuri()[0].get_stare() == "open");
	t.set_stare("open");
	repo.sterge_task();
	assert(repo.get_taskuri().size() == 0);
}