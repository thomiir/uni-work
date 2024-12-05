#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Observer
{
	public:
		// metoda virtuala de actualizare
		virtual void update() = 0;
};

class Observable
{
	private:
		// vectorul de observere
		vector<Observer*> observers;

	public:
		// adaugam un observer
		void addObserver(Observer* obs)
		{
			observers.push_back(obs);
		}

		// stergem un observer
		void removeObserver(Observer* obs)
		{
			observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
		}

		// notificam atunci cand s-a produs o schimbare
		void notify()
		{
			for (auto obs : observers)
				obs->update();
		}
};		

