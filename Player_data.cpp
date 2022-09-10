#include "Player_data.h"
#include<iostream>
#include <string>
#include <fstream>

using namespace std;

void Playerdata::setname(string a)
{
	this->name = a;
}

std::string Playerdata::getname()
{
	return name;
}

void Playerdata::File_Write()
{

	fstream file_write;
	file_write.open("Player_name.txt", ios::app);
	file_write << name;
	file_write.close();
}
void Playerdata::Set_current_Point(int a)
{
	currentscore = a;
}
int Playerdata::Get_current_Point()
{
	return currentscore;
}

void Playerdata::Point_Write()
{
	fstream file;
	file.open("currentScore.txt", ios::app);
	file << currentscore;
	file.close();
}