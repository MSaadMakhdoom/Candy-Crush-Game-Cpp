#pragma once
class Game_Manager
{
private:

	int Random_no, X_Coordinate, Y_Coordinate;
	char Shape_Id;


public:

	Game_Manager();
	
	void Set_Random_no(int n);


	int Get_random_no();
	

	void Set_xcoordinate(int n);
	

	int Get_xcoordinate();
	

	void Set_ycoordinate(int n);


	int Get_ycoordinate();
	
	void Set_shape_Id(char a);
	

	char Get_Shape_Id();
	

	int generate_random_no();
	

	void final_Shape_Grid(int x, int y);


		void Get_coordinate();


		char display_Shape_Id();



};
