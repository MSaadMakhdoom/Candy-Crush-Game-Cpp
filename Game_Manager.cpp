#include "Game_Manager.h"
#include <cstddef>
#include <stdlib.h>
#include "CImg.h"
#include "util.h"



Game_Manager::Game_Manager()
{
	Random_no = 0;
	X_Coordinate = 0;
	Y_Coordinate = 0;
	Shape_Id = NULL;
}
void Game_Manager::Set_Random_no(int n)
{
	Random_no = n;
}

int Game_Manager::Get_random_no()
{
	return Random_no;
}

void Game_Manager::Set_xcoordinate(int n)
{
	X_Coordinate = n;
}

int Game_Manager::Get_xcoordinate()
{
	return X_Coordinate;
}

void Game_Manager::Set_ycoordinate(int n)
{
	Y_Coordinate = n;
}

int Game_Manager::Get_ycoordinate()
{
	return Y_Coordinate;
}

void Game_Manager::Set_shape_Id(char a)
{
	Shape_Id = a;
}

char Game_Manager::Get_Shape_Id()
{
	return Shape_Id;
}

int Game_Manager::generate_random_no()
{

	int temp = 0;
	//srand(time(NULL));
	temp = (1 + (rand() % 6));

	Set_Random_no(temp);

	return temp;
}

void Game_Manager::final_Shape_Grid(int x, int y)
{
	Random_no = generate_random_no();
	this->X_Coordinate = x;
	this->Y_Coordinate = y;
	if (Random_no == 1)
	{
		DrawCircle(x + 20, y + 20, 20, colors[YELLOW]);

		Shape_Id = 'a';

		Y_Coordinate += 20;
	}
	else if (Random_no == 2)
	{
		DrawSquare(x, y, 40, colors[MEDIUM_PURPLE]);

		Shape_Id = 'b';


	}
	else if (Random_no == 3)
	{
		DrawRoundRect(x, y, 40, 40, colors[DARK_OLIVE_GREEN], 30);
		Shape_Id = 'c';
	}

	else if (Random_no == 4)
	{
		DrawTriangle(x, y, x + 40, y, x + 20, y + 40, colors[DARK_BLUE]);
		Shape_Id = 'd';
	}
	else if (Random_no == 5)
	{
		DrawTriangle(x, y, x + 40, y, x + 20, y + 40, colors[RED]);
		Shape_Id = 'e';
	}
	else if (Random_no == 6)
	{
		DrawTriangle(x, y, x + 40, y, x + 20, y + 40, colors[GREEN]);
		Shape_Id = 'f';
	}
}

void Game_Manager::Get_coordinate()
{
	cout << "X coordinate :" << X_Coordinate << "\t" << "Y coordinate :" << Y_Coordinate << endl;
}

char Game_Manager::display_Shape_Id()
{
	return Shape_Id;
}
