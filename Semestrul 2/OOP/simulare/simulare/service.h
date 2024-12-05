#pragma once
#include "rochie.h"
#include "repo.h"
#include <algorithm>
#include <vector>
using namespace std;

class Service
{
private:
	// repository-ul curent
	Repo& repo;

public:
	// constructorul clasei Service
	Service(Repo& _repo) : repo{ _repo } {};

	// getter pentru lista curenta de rochii
	vector<Rochie> getList()
	{
		return repo.getList();
	}

	// sortam lista dupa marime
	vector<Rochie> sortMarime()
	{
		vector<Rochie> list = getList();
		sort(list.begin(), list.end(), [](Rochie r1, Rochie r2)
			{
				return r1.get_marime() < r2.get_marime();
			});
		return list;
	}

	// sortam lista dupa pret
	vector<Rochie> sortPret()
	{
		vector<Rochie> list = getList();
		sort(list.begin(), list.end(), [](Rochie r1, Rochie r2)
			{
				return r1.get_pret() < r2.get_pret();
			});
		return list;
	}

	// inchiriem o rochie
	int inchiriaza(int pos)
	{
		vector<Rochie> list = getList();
		if (list.at(pos).get_disponibilitate() == "false")
			return -1;
		else
			list.at(0).set_disponibilitate("false");
		return 0;
	}
};

// teste pentru clasa Service
void testService();