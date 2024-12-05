#include "rochie.h"
#include <assert.h>

void testDomain()
{
	Rochie r{ 1, "denum", "marime", 500, "true" };
	assert(r.get_cod() == 1);
	assert(r.get_denumire() == "denum");
	assert(r.get_marime() == "marime");
	assert(r.get_pret() == 500);
	assert(r.get_disponibilitate() == "true");

	r.set_disponibilitate("false");
	assert(r.get_disponibilitate() == "false");
}