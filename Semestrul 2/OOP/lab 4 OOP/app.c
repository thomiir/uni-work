#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "tests.h"
#include "ui.h"


int main()
{
	runAllTests();
	run();
	_CrtDumpMemoryLeaks();
}