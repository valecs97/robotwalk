#include "repository.h"



repository::repository(int n, int m, domain current)
{
	if (n % 2 == 0 || m % 2 == 0)
		throw 1;
	this->n = n;
	this->m = m;
	this->current = current;
	v = new int*[n+1];
	for (int i = 0; i < n; i++) {
		v[i] = new int[m + 1];
		for (int j = 0; j < m; j++)
			v[i][j] = 0;
	}
	v[current.getN()][current.getM()] = 1;
}

repository::repository()
{
	n = -1;
	m = -1;
}


repository::~repository()
{
	for (int i = 0; i < n; i++)
		delete[] v[i];
	delete[] v;
}

/*
Function that sets a tile to walked

d - domain (the tile to be set)
*/

void repository::add(domain d)
{
	int a = d.getN();
	int b = d.getM();
	if (a >= n || b >= m)
		throw 1;
	if (a < 0 || b < 0)
		throw 1;
	if (v[a][b] != 0)
		throw 2;
	v[a][b] = 1;
	current = domain(a, b);
}

domain repository::getCurrent()
{
	return current;
}

int ** repository::getAll()
{
	return v;
}

int repository::getNRepo()
{
	return n;
}

int repository::getMRepo()
{
	return m;
}
