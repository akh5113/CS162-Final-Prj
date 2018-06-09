/*********************************************************************
** Program Name: deck.cpp
** Author: Anne Harris
** Date: 06/02/17
** Description: contains the function definitions for the deck
** class
*********************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include"space.hpp"
#include"deck.hpp"
#include"hallway.hpp"

/*********************************************************************
** Description: default constructor for the deck class
** Parameters: none
** Returns: none
*********************************************************************/
Deck::Deck()
{
	spaceName = "BOW DECK";
	//initiate all pointers to null
	forward = NULL;
	back = NULL;
	right = NULL;
	left = NULL;

	//initiate all items to false
	hasRaft = false;
	hasNote = false;
	hasLight = false;
	telegramSent = false;
}


/*********************************************************************
** Description: returns the name of the room
** Parameters: none
** Returns: string representing room name
*********************************************************************/
std::string Deck::getName()
{
	return spaceName;
}

/*********************************************************************
** Description: calls the menu for the deck class that gives the user
** options depending on what items they have
** Parameters: none
** Returns: integer representing the choice
*********************************************************************/
int Deck::getMenu()
{
	int action;
	std::cout << "-----FRONT DECK-----" << std::endl;
	std::cout << "Select an option" << std::endl;
	std::cout << "1. Open raft and get of the boat!" << std::endl;
	std::cout << "2. Go back to the hallway" << std::endl;
	std::cout << "3. Quit and go down with the ship" << std::endl;
	//get action
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
		if (action < 1 || action > 3)
		{
			std::cout << "Out of range, enter a number between " << 1 << " and " << 3 << std::endl;
			std::cin >> action;
		}
		else
		{
			iValid = 0;
		}
	}

	return action;
}

/*********************************************************************
** Description: displays the message for the deck class
** Parameters: none
** Returns: none
*********************************************************************/
void Deck::displayMessage()
{
	std::cout << "In the " << spaceName << "..." << std::endl;
	std::cout << "It's cold and windy on the deck! I hope you came prepared" << std::endl;
	std::cout << "too make you way off the boat!" << std::endl;
} 


/*********************************************************************
** Description: simulates adding an item
** Parameters: none
** Returns: boolean representing if an item was acquired
*********************************************************************/
bool Deck::getItem()
{
	//std::cout << "No item to add" << std::endl;
	return false;
	/*
	if (itemAcquired == true)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
}

/*********************************************************************
** Description: simulates moving around the deck room. calls the 
** appropriate functions for the room after the menu funcion
** returns the users choice
** Parameters: none
** Returns: character representing the next room to go to
*********************************************************************/
char Deck::roomActions()
{
	itemAcquired = false;
	waterLevel = 0;
	int choice;
	if (telegramSent == false && hasRaft == false)
	{
		std::cout << "You came to the deck but you realized you are totally" << std::endl;
		std::cout << "unprepared! It is a good idea to find something that floats" << std::endl;
		std::cout << "and tell someone where to find you." << std::endl;
		std::cout << std::endl;


		//increase water level
		waterLevel++;

		return 'H';
	}
	else if (telegramSent == false && hasRaft == true)
	{
		std::cout << "You may have a way to get off the boat, but no one will" << std::endl;
		std::cout << "know where you are! You might want to go back.. " << std::endl;
		std::cout << std::endl;

		//increase water level
		waterLevel++;

		return 'H';
	}
	else if (telegramSent == true && hasRaft == false)
	{
		std::cout << "People know where you are which is a good start, but you" << std::endl;
		std::cout << "still have no way to get off the sinking ship! Hope you" << std::endl;
		std::cout << "go back and find something.." << std::endl;
		std::cout << std::endl;

		//increase water level
		waterLevel++;

		return 'H';
	}
	else if (telegramSent == true && hasRaft == true)
	{
		std::cout << "You have a raft and alerted help of your location, looks" << std::endl;
		std::cout << "like you are ready to make your way into the ocean" << std::endl;
		std::cout << std::endl;

		//call menu
		choice = getMenu();
		do
		{
			if (choice == 1) //open raft
			{
				std::cout << "You've opend your raft and gotten off the boat!" << std::endl;

				waterLevel = 555;

				return 'D';

			}
			else if (choice == 2) //return to hallway
			{
				std::cout << ".... leaving " << spaceName << "....." << std::endl;
				//increase water level
				waterLevel++;

				return 'H';
			}
			
		} while (choice != 3);
		if (choice == 3)
		{
			//quit game
			waterLevel = 9999;
			return false;
		}
	}
}

/*********************************************************************
** Description: destructor for the deck class
** Parameters: none
** Returns: none
*********************************************************************/
Deck::~Deck()
{
	/*
	delete forward;
	delete back;
	delete right;
	delete left;
	*/
}