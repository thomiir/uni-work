#include "TestExtins.h"
#include "TestScurt.h"
#include <crtdbg.h>
#include <iostream>
using namespace std;

int main() 
{
	testAll();
	testAllExtins();
	cout << "That's all!" << endl;
	_CrtDumpMemoryLeaks();
	return 0;
}
