#include "tests.h"
#include <crtdbg.h>
#include "console.h"
int main()
{
	tests* t = new tests();
	t->testAll();
	delete t;

	console* con = new console();
	con->run();

	delete con;

	_CrtDumpMemoryLeaks();
	return 0;
}