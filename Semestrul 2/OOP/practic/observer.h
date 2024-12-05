#pragma once
#include <vector>
using namespace std;

// definim clasa abstracta Observer
class Observer
{
public:
	virtual void update() = 0;
};

// definim clasa Observable
class Observable : public Observer
{
	// vectorul de observeri
	vector<Observer*> obs;
public:
	// adaugam un observer
	void adaugaObs(Observer* o) { obs.push_back(o); }
	// stergem un observer
	void stergeObs() { obs.pop_back(); }
	// notificam atunci cand s-a produs o schimbare
	void notifica()
	{
		for (auto& o : obs)
			o->update();
	}
};