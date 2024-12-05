#include "rochie.h"
#include "repo.h"
#include <assert.h>

void testRepo()
{
	Repo repo{ "test.txt" };
	vector<Rochie> list = repo.getList();
	assert(list.size() == 10);

}