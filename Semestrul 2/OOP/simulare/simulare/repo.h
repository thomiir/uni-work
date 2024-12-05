#pragma once
#include "rochie.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Repo
{
private:
	// vectorul care retine rochiile
	vector<Rochie> list = {};

	// numele fisierului
	string file;

	// functia care incarca datele din fisier
	void load(string file)
	{
		ifstream in(file);
		string str;
		while (getline(in, str))
		{

			auto ss = stringstream(str);
			vector<string> arg;
			string a;
			while (getline(ss, a, ','))
				arg.push_back(a);
			list.push_back(Rochie{ stoi(arg[0]), arg[1], arg[2], stoi(arg[3]), arg[4] });
		}
	}
	

public:
	// constructorul clasei repo
	Repo(string _file) : file{ _file }
	{
		load(_file);
	}

	// getter pentru lista curenta de rochii
	vector<Rochie> getList()
	{
		return list;
	}
	
};

// teste pentru repository
void testRepo();
