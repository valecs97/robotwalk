#pragma once
#include "repository.h"

class controller
{
	repository* repo;
public:
	controller(repository* repo);
	~controller();
	void moveRobot(int n , int m);
	domain getCurrentController();
	char* showCleanedTitle();
	char* showPercentageCleaned(int* l,int* r);
};

