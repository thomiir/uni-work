#pragma once
#include <string>
#include <vector>
using namespace std;

class Task
{
	// campurile clasei Task
	int id;
	string descriere;
	string programatori;
	string stare;
public:
	// constructorul clasei Task
	Task(int i, string d, string p, string s) : id{ i }, descriere{ d }, programatori{ p }, stare{ s } {};
	// getter pentru id-ul unui task
	int get_id() { return id; }
	// getter pentru descrierea unui task
	string get_descriere() { return descriere; }
	// getter pentru programatorii unui task
	string get_programatori() { return programatori; }
	// getter pentru starea unui task
	string get_stare() { return stare; }
	// setter pentru starea unui task
	void set_stare(string s) { stare = s; }
};
// teste pentru Domain
void testDomain();