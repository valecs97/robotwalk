#pragma once
#include "controller.h"
#include "domain.h"
#include "repository.h"

class tests
{
public:
	tests();
	~tests();
	void testAll();
	void testMove(domain current, repository* repo, controller* ctrl);
	void testPercentage(controller* ctrl);
};

