#pragma once
#include "domain.h"
class repository
{
	domain current;
	int n;
	int m;
	int** v;
public:
	repository(int n,int m,domain current);
	repository();
	~repository();
	void add(domain d);
	domain getCurrent();
	int** getAll();
	int getNRepo();
	int getMRepo();
};

