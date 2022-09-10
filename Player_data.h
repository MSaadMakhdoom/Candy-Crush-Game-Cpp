#pragma once

#include<iostream>
using namespace std;

class Playerdata
{
private:
	int currentscore;


	string name;
public:


	void setname(string a);
	
	string getname();
	

	void File_Write();
	
	void Set_current_Point(int a);
	
	int Get_current_Point();
	

	void Point_Write();
	
};
