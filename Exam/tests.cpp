#include "tests.h"
#include <assert.h>
#include <string.h>

tests::tests()
{
}


tests::~tests()
{
}

void tests::testAll()
{
	domain current = domain(2, 2);
	repository* repo = new repository(5, 5, current);
	controller* ctrl = new controller(repo);
	testMove(current, repo, ctrl);
	testPercentage(ctrl);
	delete ctrl;
}

void tests::testMove(domain current, repository * repo, controller * ctrl)
{
	domain currentCtrl = ctrl->getCurrentController();
	assert(current.getM() == currentCtrl.getM());
	assert(current.getN() == currentCtrl.getN());
	ctrl->moveRobot(-1, 0);
	ctrl->moveRobot(-1, 0);
	try {
		ctrl->moveRobot(-1, 0);
		assert(false);
	}
	catch (int e)
	{
		assert(true);
	}
	ctrl->moveRobot(0, 1);
	ctrl->moveRobot(0, 1);
	try {
		ctrl->moveRobot(0, 1);
		assert(false);
	}
	catch (int e)
	{
		assert(true);
	}
}

void tests::testPercentage(controller * ctrl)
{
	int a, b;
	char* c = ctrl->showPercentageCleaned(&a, &b);
	assert(!strcmp(c, "Percentage in left000%\nPercentage in right033%\n"));
	delete[] c;
}
