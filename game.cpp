
#include "util.h"

#include <iostream>

#include<string>

#include<cmath> 

#include"Game_Manager.h"

#include"Game_Menu.h"

#include"Player_data.h"

using namespace std;


Game_Manager grid[8][8];


class Game_board
{
public:
	bool _inital = true;
	int intia_X,final_X;
	int intial_Y,final_Y;
	int _Row, _Column;
	bool run = false;
	static int Point;
	static int level_Point;
	static int level_no;
	
	static void Playing_Display_of_game()
	{
		glClearColor(0.18f, 0.18f, 0.18f, 0.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		

		static Playerdata p;


		DrawString(5, 570, "Progress ", colors[SKY_BLUE]);

		for (int i = 0; i < Point; i++)
		{
			DrawSquare(105 + i, 565, 20, colors[TEAL]);
		}


		DrawString(545, 530, "Player Name ", colors[DEEP_SKY_BLUE]);

		DrawString(545, 500, Num3Str(p.getname()), colors[SKY_BLUE]);

		DrawString(545, 470, "Game level " + Num2Str(level_no), colors[SKY_BLUE]);

		DrawString(545, 430, "Player Points", colors[DEEP_SKY_BLUE]);

		DrawString(590, 400, Num2Str(Point), colors[SKY_BLUE]);

		DrawString(545, 375, "Target " , colors[DEEP_SKY_BLUE]);
		DrawString(620, 375,  Num2Str(level_Point), colors[SKY_BLUE]);
		DrawString(545, 340, "Point to win " , colors[DEEP_SKY_BLUE]);
		DrawString(545, 300, "level " + Num2Str(level_no), colors[DEEP_SKY_BLUE]);

	
		
		if (Point > level_Point ||Point == level_Point)
		{
			level_Point += 100;
			level_no++;
			for (int i = 0; i < 5; i++)
			{
				DrawString(545, 270, "Congratulation", colors[SKY_BLUE+i+100]);
				DrawString(545, 230, "You Win level " + Num2Str(level_no - 1) + " Win ", colors[SKY_BLUE]);
			}
		}
		else
		{
			DrawString(545, 230, "Level " + Num2Str(level_no - 1) + " Win ", colors[SKY_BLUE]);
		}
		


		if (level_no == 3)
		{
			Game_Menu g;
			g.Display_Win_Message();
			
		}



		DrawString(545, 200, "Clicked option", colors[DARK_BLUE]);


		DrawString(545, 150, "Game Pause", colors[DARK_BLUE]);

		DrawString(550, 100, "How to play", colors[DARK_BLUE]);


		DrawString(550, 50, "Exist Game", colors[TOMATO]);


		DrawLine(5, 10, 800, 10, 5, colors[BLUE]);
		DrawLine(20, 10, 20, 555, 5, colors[BLUE]);

		DrawLine(5, 555, 800, 555, 5, colors[BLUE]);
		DrawLine(540, 10, 540, 555, 5, colors[BLUE]);

		for (int i = 0, x = 50; i < 8; i++, x += 60)
		{
			for (int j = 0, y = 50; j < 8; j++, y += 60)
			{
				if (grid[i][j].Get_Shape_Id() == 'a')
				{
					DrawCircle(x + 20, y + 20, 20, colors[YELLOW]);

				}
				else if (grid[i][j].Get_Shape_Id() == 'b')
				{
					DrawSquare(x, y, 40, colors[MEDIUM_PURPLE]);

				}
				else if (grid[i][j].Get_Shape_Id() == 'c')
				{
					DrawRoundRect(x, y, 40, 40, colors[DARK_OLIVE_GREEN], 30);

				}
				else if (grid[i][j].Get_Shape_Id() == 'd')
				{

					DrawTriangle(x, y, x + 40, y, x + 20, y + 40, colors[DARK_BLUE]);

				}
				else if (grid[i][j].Get_Shape_Id() == 'e')
				{

					DrawTriangle(x, y, x + 40, y, x + 20, y + 40, colors[RED]);

				}
				else if (grid[i][j].Get_Shape_Id() == 'f')
				{

					DrawTriangle(x, y, x + 40, y, x + 20, y + 40, colors[GREEN]);

				}
			}

		}
		glutSwapBuffers();

	}

	void Display_pause()
	{

		glutDisplayFunc(Playing_Display_of_game);
	}
	//This function checks if any neighbour is eligible to be swapped.

	bool point_move(vector<int>& tmp)
	{
		static int score;

		int x, y;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				x = i;
				y = j;
				// Check Horizontal
				if (x < 8 - 2 && grid[x][y].display_Shape_Id() == grid[x + 1][y].display_Shape_Id() && grid[x][y].display_Shape_Id() == grid[x + 2][y].display_Shape_Id())
				{
					score += 5;

					tmp[0] = x;
					tmp[1] = x + 1;
					tmp[2] = x + 2;
					tmp[3] = y;
					tmp[4] = y;
					tmp[5] = y;
					return true;
				}
				else if (x < 8 - 1 && x>0 && grid[x][y].display_Shape_Id() == grid[x + 1][y].display_Shape_Id() && grid[x][y].display_Shape_Id() == grid[x - 1][y].display_Shape_Id())
				{

					score += 5;
					tmp[0] = x - 1;
					tmp[1] = x;
					tmp[2] = x + 1;
					tmp[3] = y;
					tmp[4] = y;
					tmp[5] = y;
					return true;
				}
				else if (x > 1 && grid[x][y].display_Shape_Id() == grid[x - 1][y].display_Shape_Id() && grid[x][y].display_Shape_Id() == grid[x - 2][y].display_Shape_Id())
				{
					score += 5;
					tmp[0] = x - 2;
					tmp[1] = x - 1;
					tmp[2] = x;
					tmp[3] = y;
					tmp[4] = y;
					tmp[5] = y;
					return true;
				}
				// Check Vertical
				else if (y < 8 - 2 && grid[x][y].display_Shape_Id() == grid[x][y + 1].display_Shape_Id() && grid[x][y].display_Shape_Id() == grid[x][y + 2].display_Shape_Id())
				{

					score += 5;
					tmp[0] = x;
					tmp[1] = x;
					tmp[2] = x;
					tmp[3] = y;
					tmp[4] = y + 1;
					tmp[5] = y + 2;
					return true;
				}
				else if (y < 8 - 1 && y > 0 && grid[x][y].display_Shape_Id() == grid[x][y + 1].display_Shape_Id() && grid[x][y].display_Shape_Id() == grid[x][y - 1].display_Shape_Id())
				{
					score += 5;
					tmp[0] = x;
					tmp[1] = x;
					tmp[2] = x;
					tmp[3] = y - 1;
					tmp[4] = y;
					tmp[5] = y + 1;
					return true;
				}
				else if (y > 1 && grid[x][y].display_Shape_Id() == grid[x][y - 1].display_Shape_Id() && grid[x][y].display_Shape_Id() == grid[x][y - 2].display_Shape_Id())
				{

					score += 5;
					tmp[0] = x;
					tmp[1] = x;
					tmp[2] = x;
					tmp[3] = y - 2;
					tmp[4] = y - 1;
					tmp[5] = y;
					return true;
				}

			}
		}
		Point = score;
		static Playerdata p;

		p.Set_current_Point(Point);

		

		p.Point_Write();


		return false;
	}



	void load_grid()
	{


		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				grid[i][j].final_Shape_Grid(i, j);
		}
		// Remove any Matches
		vector<int>tmp(6, 0); // Store coordinates

		while (point_move(tmp))
		{
			update_grid(tmp);
		}


	}
	bool valid_move(int x0, int y0, int x1, int y1)
	{
		// Check if move is valid
		if ((x0 + 1 == x1 && y0 == y1) || (x0 - 1 == x1 && y0 == y1) || (x0 == x1 && y0 + 1 == y1) || (x0 == x1 && y0 - 1 == y1))
		{
			swap(grid[x0][y0], grid[x1][y1]);
			return true;
		}
		else
			return false;
	}
	void update_grid(vector<int>& pos)
	{

		if (pos[0] == pos[2]) // Horizontal Match, Row is Constant
		{
			int j = pos[0];
			while (j > 0)
			{
				grid[j][pos[3]] = grid[j - 1][pos[3]];
				grid[j][pos[4]] = grid[j - 1][pos[4]];
				grid[j][pos[5]] = grid[j - 1][pos[5]];
				j--;
			}
			grid[0][pos[3]].final_Shape_Grid(0, pos[3]);
			grid[0][pos[4]].final_Shape_Grid(0, pos[4]);
			grid[0][pos[5]].final_Shape_Grid(0, pos[5]);

		}
		else // Vertical Match , Column is constant
		{
			int column = pos[3];
			int j = pos[2];
			while (j > 2)
			{
				grid[j][column] = grid[j - 3][column];
				j--;
			}
			grid[0][column].final_Shape_Grid(0, column);
			grid[1][column].final_Shape_Grid(1, column);
			grid[2][column].final_Shape_Grid(2, column);
		}
	}
	
	void GameLoop(int _i, int _j, int i, int j)
	{


		vector<int>tmp(6, 0);


		bool isvalid = valid_move(_i, _j, i, j);
		if (isvalid)
		{

			while (point_move(tmp))
			{

				glutPostRedisplay();
				glutDisplayFunc(Playing_Display_of_game);
				// A Match is Made

				update_grid(tmp);      // Update Grid with new Elements

			}
		}

	}


};
int Game_board::Point = 0;
int Game_board::level_Point = 0;
int Game_board::level_no = 1;


void SetCanvasSize(int width, int height)
{
	
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();
	
	glOrtho(0, width, 0, height, -1, 1); 
	
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
}




void GameDisplay()
{

	glClearColor(0.4f, 0.4f, 0.4f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);



	DrawString(50, 570, "Practice  Mode ", colors[SKY_BLUE]);
   
	DrawLine(5, 10, 695, 10, 5, colors[BLUE]);    
	DrawLine(20, 10, 20, 555, 5, colors[BLUE]);
	DrawLine(5, 555, 695, 555, 5, colors[BLUE]);
    DrawLine(540, 10,540, 555, 5, colors[BLUE]);


	for (int i = 0, x = 50; i < 8; i++, x += 60)
	{
		for (int j = 0, y = 50; j < 8; j++, y += 60)
		{
			grid[i][j].final_Shape_Grid(x, y);       
		}
	}

	
	glutSwapBuffers();
}





void NonPrintableKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	}
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	}
	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	 //glutPostRedisplay();
}


void PrintableKeys(unsigned char key, int x, int y)
{
	if (key == 27/* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
	{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	if (key == 121) {
		glutPostRedisplay();
		glutDisplayFunc(GameDisplay);

	}
}

void Timer(int m)
{
	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}



void MousePressedAndMoved(int x, int y) 
{
	//cout << "\nMouse Key x :"<<x << "\t" <<"Mouse Key y :"<< y << endl;

}

void MouseMoved(int x, int y)
{
	//cout << "\nMouse moved x :" << x << "\t" << "Mouse moved y :" << y << endl;
}




void MouseClicked(int button, int state, int x, int y) 
{
	static Game_board d;
	static Game_Menu p;

	if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && p.Game_Pause == false && (x >= 550 && x <= 660 && y >= 430 && y <= 450)) 
	{
		p.Game_Pause = true;
		glutPostRedisplay();
		p.Display_Pause_Menu();
	}
	if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && p.Game_Pause == false && (x >= 550 && x <= 660 && y >= 460 && y <= 500))
	{
		p.Game_Pause = true;
		glutPostRedisplay();
		p.Display_Intruction();
	}

	if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && p.Game_Pause == true && (x >= 270 && x <= 340 && y >= 320 && y <= 350))
	{
		p.Game_Pause = false;
		glutPostRedisplay();
		d.Display_pause();
	}
	


	if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && p.Game_Pause == false && (x >= 550 && x <= 660 && y >= 540 && y <= 550))
	{
		exit(1);
	}


	if (button == GLUT_LEFT_BUTTON) 
	{

		if (d._inital == true)
		{
			if (state == GLUT_DOWN && (x >= 300 && x <= 370)&& (y >= 330 && y <= 365))
			{
				glutPostRedisplay();

				glutDisplayFunc(GameDisplay);
			}

			if (state == GLUT_DOWN && (x >= 300 && x <= 360)&& (y >= 380 && y <= 400)) 
			{
				exit(1);
			}
			d._inital = false;
		}

	}
	else if (button == GLUT_RIGHT_BUTTON) 
	{
		cout << "Right Button Pressed" << endl;

	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
		d.intia_X = x;
		d.intial_Y = y;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
	{
		d.final_X = x;
		d.final_Y = y;


		int Previous_i = (d.intia_X - 60) / 60;
		int Privious_j = (600 - d.intial_Y - 60) / 60;

		

		int Next_i = (d.final_X - 60) / 60;
		int Next_j = (600 - d.final_Y - 60) / 60;
		
		d._Row = Next_i;
		d._Column = Next_j;

		if (((Next_i >= 0 && Next_i < 8) && (Next_j >= 0 && Next_j < 8))&& ((Next_i == Previous_i && Next_j == Privious_j + 1)|| (Next_i == Previous_i && Next_j == Privious_j - 1)|| (Next_i == Previous_i + 1 && Next_j == Privious_j)|| (Next_i == Previous_i - 1 && Next_j == Privious_j))) 
		{
			d.GameLoop(Previous_i, Privious_j, Next_i, Next_j);

		}
		

	}

}

int main(int argc, char* argv[]) 
{
	string name; 
	int width = 700, height = 600;

	cout << "Enter player name: ";
	cin >> name;
	Playerdata p; 
	
	 p.setname(name); 
	 p.File_Write();
	 Num3Str(name);

	

	
	 InitRandomizer(); 
	
	 glutInit(&argc, argv);
	
	 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	
	 glutInitWindowPosition(50, 50); 
	
	 glutInitWindowSize(width, height); 
	
	 glutCreateWindow("Candy Crash Game "); 
	
	
	 SetCanvasSize(width, height); 
	
	Game_Menu a; 
	
	a.Start_Display();
	Game_board d;
	d.Playing_Display_of_game();
	
	glutSpecialFunc(NonPrintableKeys);
	glutKeyboardFunc(PrintableKeys);
	glutTimerFunc(1000.0, Timer, 0);

	
	glutMouseFunc(MouseClicked);
	
	glutPassiveMotionFunc(MouseMoved);
	
	glutMotionFunc(MousePressedAndMoved);

	
	glutMainLoop();

	return 1;
}


