#include "controller.h"
#include <string.h>


controller::controller(repository* repo)
{
	this->repo = repo;
}


controller::~controller()
{
	delete repo;
}

/*
Function that moves the robot

input data:
n - integer (-1,0,1)
m - integer (-1,0,1)
*/

void controller::moveRobot(int n,int m)
{
	domain current = repo->getCurrent();
	n = n + current.getN();
	m = m + current.getM();
	current.setM(m);
	current.setN(n);
	repo->add(current);
}

domain controller::getCurrentController()
{
	return repo->getCurrent();
}

char * controller::showCleanedTitle()
{
	int** v = repo->getAll();
	int n = repo->getNRepo();
	int m = repo->getMRepo();
	char* c = new char[4096];
	bool found;
	strcpy(c, "Tiles:\n");
	char* aux = new char[2];
	aux[1] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 1)
			{
				found = true;
				strcat(c, "(");
				aux[0] = i + 48;
				strcat(c, aux);
				aux[0] = j + 48;
				strcat(c, ",");
				strcat(c, aux);
				strcat(c, ")");
				strcat(c,"\n");
			}
		}
	}
	if (found == false)
		strcpy(c, "No tiles cleaned");
	delete[] aux;
	return c;
}

/*
Function that shows the cleaned tiles

input data:
l - pointer to integer
r  - pointer to integer

output data:
c - array of chars to be printed
*/

char * controller::showPercentageCleaned(int* l,int *r)
{
	int** v = repo->getAll();
	int n = repo->getNRepo();
	int m = repo->getMRepo();
	char* c = new char[4096];
	strcpy(c, "Percentage in left");
	int total=0, occupied=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m/2; j++)
		{
			total++;
			if (v[i][j] == 1)
			{
				occupied++;
			}
		}
	}
	int perc = 0;
	float aa;
	aa = (float)occupied / total;
	aa = aa * 100;
	perc = (int)aa;
	*l = perc;
	char* aux = new char[4];
	aux[3] = 0;
	aux[0] = perc / 100 + 48;
	aux[1] = perc % 100 / 10 +48;
	aux[2] = perc % 10 + 48;
	strcat(c, aux);
	strcat(c, "%\n");
	strcat(c, "Percentage in right");
	total = 0, occupied = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = m/2; j < m; j++)
		{
			total++;
			if (v[i][j] == 1)
			{
				occupied++;
			}
		}
	}
	perc = 0;
	aa = (float)occupied / total;
	aa = aa * 100;
	perc = (int)aa;
	*r = perc;
	aux[3] = 0;
	aux[0] = perc / 100 + 48;
	aux[1] = perc % 100 / 10 + 48;
	aux[2] = perc % 10 + 48;
	strcat(c, aux);
	strcat(c, "%\n");
	delete[] aux;
	return c;
}
