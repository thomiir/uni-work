#include "carRepo.h"
#include "carService.h"
#include "carConsole.h"
#include "carValidator.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


int main()
{
	{
	testValidateCar();
	testDomain();
	testRepo();
	testService();

	carRepo repo;
	carService service{ repo };
	carConsole console{ service };
	console.start(); 
	}
	_CrtDumpMemoryLeaks();
	
}