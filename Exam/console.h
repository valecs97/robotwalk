#pragma once
#include "controller.h"
#include <iostream>
#include "domain.h"


class console
{
	controller* ctrl;
private:
	void createMatrix();
public:
	void run();
	void printCurrentPosition();
	void moveRobotConsole(int n, int m);
	void printCleanedTiles();
	void showPercentage();
	console();
	~console();
};

