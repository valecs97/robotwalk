#include "domain.h"



domain::domain(int n,int m)
{
	this->n = n;
	this->m = m;
}

domain::domain()
{
	n = -1;
	m = -1;
}


domain::~domain()
{
}

int domain::getM()
{
	return m;
}

int domain::getN()
{
	return n;
}

void domain::setM(int i)
{
	m = i;
}

void domain::setN(int i)
{
	n = i;
}
