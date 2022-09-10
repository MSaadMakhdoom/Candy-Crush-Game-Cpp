#pragma once
class Game_Menu
{
public:
	bool Game_Pause = false;

	static void Game_First_Menu();
	
	void Start_Display();
	


	static void Game_Pause_Menu();
	static void howtoplay();
	
	static void Win_Message();
	
	void Display_Pause_Menu();
	
	void Display_Intruction();
	
	void Display_Win_Message();
	
};

