#include "Game_Menu.h"

#include "util.h"


void Game_Menu::Game_First_Menu()
{
	glClearColor(0.21f, 0.21f, 0.21f, 0.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	DrawString(280, 550, "Game Menu", colors[SKY_BLUE]);

	DrawString(100, 500, "C++ OOPS Project", colors[DARK_GRAY]);

	DrawString(250, 450, "Lets play to Enjoy the Game", colors[DARK_GRAY]);




	DrawString(300, 250, "Play", colors[SKY_BLUE]);

	DrawString(300, 200, "Exist", colors[SKY_BLUE]);


	glutSwapBuffers();
}


void Game_Menu::Start_Display()
{
	glutDisplayFunc(Game_First_Menu);
}


void Game_Menu::Game_Pause_Menu()
{
	glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawString(250, 540, "Game Paused", colors[MISTY_ROSE]);
	DrawString(270, 250, "Resume", colors[MISTY_ROSE]);

	glutSwapBuffers();
}


void Game_Menu::howtoplay()
{
	glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawString(100, 500, "GOOD LUCK!", colors[MISTY_ROSE]);

	DrawString(100, 400, "Use your left mouse button to drag and drop different gems", colors[MISTY_ROSE]);
	DrawString(100, 350, "Match 3 or more gems of the same type to score points", colors[MISTY_ROSE]);
	DrawString(100, 300, "Matching more than 3 gems ", colors[MISTY_ROSE]);

	DrawString(270, 250, "Resume", colors[MISTY_ROSE]);

	glutSwapBuffers();
}


void Game_Menu::Win_Message()
{
	glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i <= 10; i++)
	{
		if (i == 0 || i == 10)
		{
			DrawString(100, 500, "Congratulations! You Win", colors[LIGHT_SKY_BLUE]);
			Sleep(100);
		}
		if (i == 1 || i == 9) {
			DrawString(100, 500, "Congratulations! You Win", colors[DARK_OLIVE_GREEN]);
			Sleep(100);
		}
		if (i == 2 || i == 8)
		{
			DrawString(100, 500, "Congratulations! You Win", colors[DARK_KHAKI]);
			Sleep(100);
		}
		if (i == 3 || i == 7)
		{
			DrawString(100, 500, "Congratulations! You Win", colors[LIGHT_GOLDEN_ROD_YELLOW]);
			Sleep(100);
		}
		if (i == 4 || i == 6)
		{
			DrawString(100, 500, "Congratulations! You Win", colors[DARK_SLATE_GRAY]);
			Sleep(100);
		}
		if (i == 5 || i == 0)
		{
			DrawString(100, 500, "Congratulations! You Win", colors[LIGHT_GREEN]);
			Sleep(100);
		}
	}
	DrawString(100, 500, "Congratulations! You Win", colors[PURPLE]);

	DrawString(300, 200, "Exist", colors[SKY_BLUE]);

	DrawString(270, 250, "Resume", colors[MISTY_ROSE]);




	glutSwapBuffers();
}




void Game_Menu::Display_Pause_Menu()
{
	glutDisplayFunc(Game_Pause_Menu);
}




void Game_Menu::Display_Intruction()
{

	glutDisplayFunc(howtoplay);
}


void Game_Menu::Display_Win_Message()
{

	glutDisplayFunc(Win_Message);
}




