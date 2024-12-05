#include "domain.h"
#include <cassert>

void testDomain()
{
	Task t{ 1,"descriere","prog1","open" };
	assert(t.get_id() == 1);
	assert(t.get_descriere() == "descriere");
	assert(t.get_programatori() == "prog1");
	assert(t.get_stare() == "open");
	t.set_stare("closed");
	assert(t.get_stare() == "closed");
}