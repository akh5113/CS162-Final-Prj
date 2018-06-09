/*********************************************************************
** Program Name: FinalPrjMain.cpp
** Author: Anne Harris
** Date: 06/02/17
** Description: The main function explains the game to the user and 
** calls teh initial menu to start the game. Sets up a game variable
** and quits the game when it's done. 
*********************************************************************/

#include<iostream>
#include<string>
#include"menu.hpp"
#include"game.hpp"
#include"space.hpp"

int main()
{
	//greet the user & explain game
	std::cout << "You have been enjoying your time on an ocean liner " << std::endl;
	std::cout << "crusing from coast to coast, but you've just been" << std::endl;
	std::cout << "awaken by a sudden jolt, the lights go out and there" << std::endl;
	std::cout << "is a rush of water! You must find a life raft, tell " << std::endl;
	std::cout << "someone your location, and make it to the deck of the ship" << std::endl;
	std::cout << "to survive. Hurry! If the water level reaches 100 you will" << std::endl;
	std::cout << "go down with the ship! Good luck...." << std::endl;
	std::cout << std::endl;

	//display the menu
	int choice1 = initialMenu();
	//start game
	if (choice1 == 1)
	{
		//clear screen
		clearScreen();

		//initialize game
		Game shipGame;
		int endGame;

		//start the game
		endGame = shipGame.startGame();

		//call menu
		choice1 = initialMenu();
		
	}
	//quit
	else
	{
		return 0;
	}
	return 0;
}
