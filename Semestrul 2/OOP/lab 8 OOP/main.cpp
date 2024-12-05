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

		CarRepo carRepo;
		CarRepo washRepo;
		CarService carService{ carRepo };
		WashService washService{ carService };
		CarConsole console{ carService, washService };
		console.start(); 
	}
	_CrtDumpMemoryLeaks();
	
}