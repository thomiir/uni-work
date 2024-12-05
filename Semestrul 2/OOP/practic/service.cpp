#include "service.h"
#include <qdebug.h>
#include <algorithm>
using namespace std;

vector<Task> Service::sorteaza_stare()
{
	vector<Task> taskuri = repo.get_taskuri();
	sort(taskuri.begin(), taskuri.end(), [](Task& t1, Task& t2) 
		{
			return t1.get_stare() < t2.get_stare();
		});
	return taskuri;
}

void Service::adauga_task(int i, string d, string p, string s)
{
	string erori = {};
	for (auto& t : repo.get_taskuri())
		if (t.get_id() == i)
			erori.append("Id invalid!");
	if (d.size() == 0)
		erori.append("Descriere invalida!");
	int nr = 0;
	for (auto c : p)
		if (c == ',') nr++;
	if (nr > 3 || p.size() == 0)
		erori.append("Numar programatori incorect!");
	if (s != "open" && s != "inprogress" && s != "closed")
		erori.append("Stare incorecta!");
	if (erori.size() > 0)
		throw erori;
	repo.adauga_task(Task{ i,d,p,s });
}

vector<Task> Service::cauta_programator(string p)
{
	vector<Task> taskuri;
	for (auto& t : repo.get_taskuri())
	{
		string prog = t.get_programatori();
		for (int i = 0; i < prog.size();i++)
		{
			int ok = 1;
			for (int j = 0; j < p.size();j++)
				if (prog[i + j] != p[j])
				{
					ok = 0;
					break;
				}
			if (ok == 1)
			{
				taskuri.push_back(t);
				break;
			}
		}
	}
	return taskuri;
}

void Service::modifica_task(int id, string s)
{
	for (int i = 0; i < repo.get_taskuri().size();i++)
		if (repo.get_taskuri()[i].get_id() == id)
			repo.modifica_task(i, s);
}

void testService()
{
	Repo repo{ "test.txt" };
	Service service{ repo };
	service.adauga_task(1, "d", "p", "closed");
	service.adauga_task(2, "d", "p", "closed");
	assert(service.get_taskuri().size() == 2);
	service.sorteaza_stare();
	assert(service.get_taskuri()[0].get_stare() == "closed");
	service.modifica_task(1, "open");
	assert(service.get_taskuri()[0].get_stare() == "open");
	vector<Task> taskuri = service.cauta_programator("p");
	assert(taskuri.size() == 2);
	vector<Task> taskuri2 = service.cauta_programator("prog");
	assert(taskuri2.size() == 0);
	try
	{
		service.adauga_task(1, "", "p1,p2,p3,p4,p5", "stare");
	}
	catch (...)
	{
		assert(true);
	}
	service.sterge_task();
	service.sterge_task();
	
}