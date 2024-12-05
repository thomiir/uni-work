#include "carRepo.h"
#include "carService.h"
#include "carConsole.h"


int main()
{
	testDomain();
	testRepo();
	testService();
	
	
	carRepo repo;
	carService service{ repo };
	carConsole console{ service };
	console.start();
	
}