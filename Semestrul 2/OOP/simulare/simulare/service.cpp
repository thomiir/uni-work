#include "rochie.h"
#include "repo.h"
#include "service.h"
#include <assert.h>
void testService()
{
	Repo repo{ "test.txt" };
	Service service{ repo };
	vector<Rochie> list = service.getList();
	list = service.sortMarime();
	assert(list.at(0).get_marime() == "marime1");

	list = service.sortPret();
	assert(list.at(0).get_pret() == 100);

	assert(service.inchiriaza(1) == -1);
	assert(service.inchiriaza(0) == 0);
}