/*********************************************************************
** Program Name: menu.cpp
** Author: Anne Harris
** Date: 06/02/17
** Description: Includes the function definitions for three menus and
** also a function definition to clear the screen
*********************************************************************/

#include<iostream>
#include<string>
#include"menu.hpp"

/**********************************************************
** Desciption: Displays the menu for the user to decide if
** they want to start game or quit, then validates the input
** Input: none
** Returns: integer represeting choice
**********************************************************/
int initialMenu()
{
	int action;
	std::cout << "-------------- Menu --------------" << std::endl;
	std::cout << "Select an option" << std::endl;
	std::cout << "1. Start the game" << std::endl;
	std::cout << "2. Quit" << std::endl;
	std::cin >> action;
	//validate integer
	bool iValid = 1;
	while (iValid == 1)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Not a valid integer, enter again." << std::endl;
			std::cin >> action;
		}
		else
		{
			iValid = 0;
		}
	}
	//validate in range
	iValid = 1;
	while (iValid == 1)
	{
		if (action < 1 || action > 2)
		{
			std::cout << "Out of range, enter a number between " << 1 << " and " << 2 << std::endl;
			std::cin >> action;
		}
		else
		{
			iValid = 0;
		}
	}

	return action;
}

/**********************************************************
** Desciption: Displays a menu of two options for the user
** simulating if they were to swim through a hole or stay
** in the room
** Input: none
** Returns: integer representing choice
**********************************************************/
int menu2()
{
	int action;
	std::cout << "-------------- Menu --------------" << std::endl;
	std::cout << "1. Swim through" << std::endl;
	std::cout << "2. Stay in the steerage room" << std::endl;
	std::cin >> action;
	//validate integer
	bool iValid = 1;
	while (iValid == 1)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Not a valid integer, enter again." << std::endl;
			std::cin >> action;
		}
		else
		{
			iValid = 0;
		}
	}
	//validate in range
	iValid = 1;
	while (iValid == 1)
	{
		if (action < 1 || action > 2)
		{
			std::cout << "Out of range, enter a number between " << 1 << " and " << 2 << std::endl;
			std::cin >> action;
		}
		else
		{
			iValid = 0;
		}
	}

	return action;
}

/****************************************************************
** Desciption: Displays a menu for the user to decide if they 
** want to simulate fixing a wound or not
** Input: none
** Returns: integer representing choice
******************************************************************/
int menu3()
{
	int action;
	std::cout << "-------------- Menu --------------" << std::endl;
	std::cout << "1. Yes, let me fix my wound" << std::endl;
	std::cout << "2. No, I will tough it out" << std::endl;
	std::cin >> action;
	//validate integer
	bool iValid = 1;
	while (iValid == 1)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Not a valid integer, enter again." << std::endl;
			std::cin >> action;
		}
		else
		{
			iValid = 0;
		}
	}
	//validate in range
	iValid = 1;
	while (iValid == 1)
	{
		if (action < 1 || action > 2)
		{
			std::cout << "Out of range, enter a number between " << 1 << " and " << 2 << std::endl;
			std::cin >> action;
		}
		else
		{
			iValid = 0;
		}
	}

	return action;
}

/**********************************************************
** Desciption: Clears the screen of any other text
** Source: http://www.cplusplus.com/forum/articles/10515/
** Input: none
** Returns: void
**********************************************************/
void clearScreen()
{
	std::cout << std::string(100, '\n');
}
