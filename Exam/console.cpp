#include "console.h"



void console::createMatrix()
{
	int n, m,n1,m1;
	std::cout << "Please input your desired size for n :";
	std::cin >> n;
	std::cout << "Please input your desired size for m :";
	std::cin >> m;
	std::cout << "Please input starting position n :";
	std::cin >> n1;
	std::cout << "Please input starting position m :";
	std::cin >> m1;
	domain current = domain(n1, m1);
	try {
		repository* repo = new repository(n, m, current);
		ctrl = new controller(repo);
		system("cls");
	}
	catch (int e)
	{
		exit(1);
	}
}

void console::run()
{
	createMatrix();
	int cmd;
	while (true)
	{
		printCurrentPosition();
		std::cout << "Please input your desired operation :\n";
		std::cout << "1.Move up\n";
		std::cout << "2.Move down\n";
		std::cout << "3.Move left\n";
		std::cout << "4.Move right\n";
		std::cout << "5.Show cleaned tiles\n";
		std::cout << "6.Show percentage\n";
		std::cin >> cmd;
		switch (cmd)
		{
		case 1: moveRobotConsole(1, 0); break;
		case 2: moveRobotConsole(-1, 0); break;
		case 3: moveRobotConsole(0, -1); break;
		case 4: moveRobotConsole(0, 1); break;
		case 5: printCleanedTiles(); break;
		case 6: showPercentage(); break;
		default: std::cout << "Wrong button\n\n"; break;
		}
	}
}

void console::printCurrentPosition()
{
	domain current = ctrl->getCurrentController();
	std::cout << "Current position : " << current.getN() << " " << current.getM() << "\n\n";
}

void console::moveRobotConsole(int n, int m)
{
	system("cls");
	try
	{
		ctrl->moveRobot(n, m);
		std::cout << "The robot has moved\n";
	}
	catch (int e)
	{
		if (e==1)
			std::cout << "The robot has reached the wall\n";
		if (e == 2)
			std::cout << "The robot has already been there\n";
	}
}

void console::printCleanedTiles()
{
	system("cls");
	char* c = ctrl->showCleanedTitle();
	std::cout << c;
	delete[] c;
}

void console::showPercentage()
{
	system("cls");
	int l, r;
	char* c = ctrl->showPercentageCleaned(&l,&r);
	if (l == r)
		std::cout << "equal\n";
	else if (l > r)
		std::cout << "left bigger\n";
	else if (r > l)
		std::cout << "right bigger\n";
	std::cout << c;
	delete[] c;
}

console::console()
{
}


console::~console()
{
	delete ctrl;
}
