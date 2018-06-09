/*********************************************************************
** Program Name: hallway.cpp
** Author: Anne Harris
** Date: 06/02/17
** Description: contains the function definitions for the hallway
** class
*********************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include"space.hpp"
#include"hallway.hpp"
#include"steerage.hpp"
#include"storage.hpp"
#include"captains.hpp"
#include"deck.hpp"

/*********************************************************************
** Description: constructor for the hallway class
** Parameters: none
** Returns: none
*********************************************************************/
Hallway::Hallway()
{
	spaceName = "HALLWAY";

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
std::string Hallway::getName()
{
	return spaceName;
}

/*********************************************************************
** Description: calls the menu for the hallway class, gives the user
** the options to go to any of the other rooms in the ship or pick
** up the notebook in the hallway
** Parameters: none
** Returns: integer representing choice
*********************************************************************/
int Hallway::getMenu()
{
	int action;
	std::cout << "-----HALLWAY-----" << std::endl;
	std::cout << "Select an option" << std::endl;
	std::cout << "1. Check the notebook in the hallway" << std::endl;
	std::cout << "2. Go back to steerage" << std::endl;
	std::cout << "3. Go right to storage room" << std::endl;
	std::cout << "4. Go left to captains room" << std::endl;
	std::cout << "5. Go forward to deck" << std::endl;
	std::cout << "6. Quit" << std::endl;
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
		if (action < 1 || action > 6)
		{
			std::cout << "Out of range, enter a number between " << 1 << " and " << 6 << std::endl;
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
** Description: displays the message for the hallway class depending
** on what items the user has so far
** Parameters: none
** Returns: void
*********************************************************************/
void Hallway::displayMessage()
{
	if (hasLight == false)
	{
		std::cout << "In the " << spaceName << "..." << std::endl;
		std::cout << "You can't see in the hallway because the lights are out" << std::endl;
		std::cout << "you should find a light first" << std::endl;
	}
	else if (hasRaft == false && telegramSent == false)
	{
		std::cout << "In the " << spaceName << "..." << std::endl;
		std::cout << "You can see the way to the deck ahead of you but" << std::endl;
		std::cout << "you don't have a life raft and you haven't told any" << std::endl;
		std::cout << "rescuers where you are, might be wise to look around first" << std::endl;
		std::cout << std::endl;
	}
	else if (hasRaft == false && telegramSent == true)
	{
		std::cout << "In the " << spaceName << "..." << std::endl;
		std::cout << "You've alereted rescures to your posistion, but you" << std::endl;
		std::cout << "still don't have a way off the boat, I'd keep looking around" << std::endl;
		std::cout << std::endl;
	}
	else if (hasRaft == true && telegramSent == true)
	{
		std::cout << "In the " << spaceName << "..." << std::endl;
		std::cout << "Quickly! The water is rising! Get to the deck!" << std::endl;
		std::cout << std::endl;
	}
}

/*********************************************************************
** Description:
** Parameters:
** Returns:
*********************************************************************/
bool Hallway::getItem()
{
	if (itemAcquired == true)
	{
		hasLight = true;
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
** Description: simulates the actions for the hallway space. calls the 
** menu for the hallway class and then based on what that returns it 
** displays a message or calls another hallway class function
** Parameters: none
** Returns: character representing the next room to enter
*********************************************************************/
char Hallway::roomActions()
{
	//set item acquired to false
	itemAcquired = false;
	//reset room water level to 0
	waterLevel = 0;
	if (hasLight == false)
	{
		std::cout << "The water rushes you back to your room" << std::endl;
		std::cout << std::endl;
		//increase water level 
		waterLevel++;
		//temp = new Steerage;
		return 'S';
	}
	else
	{
		//call menu
		int choice = getMenu();

		do
		{
			if (choice == 1) //check notebook
			{
				if (hasNote == false)
				{
					std::cout << "You found a very important notebook, it conatins a" << std::endl;
					std::cout << "essages to the Captain about the fate of the sinking" << std::endl;
					std::cout << "ship. You hold onto it incase you might need it later" << std::endl;
					std::cout << std::endl;
					itemAcquired = true;
					/*
					if (hasNote == false)
					{
						itemAcquired = true;
					}
					else
					{
						itemAcquired = false;
					}
					*/
					//incease water level
					waterLevel++;
				}
				else
				{
					std::cout << "You already took the imporant parts out of the notebook" << std::endl;
					std::cout << "You wasted time and the water has risen" << std::endl;
					std::cout << "WATER RISING - water level + 5" << std::endl;
					waterLevel += 5;
				}

				//call menu
				choice = getMenu();
			}
			else if (choice == 2) //steerage
			{
				std::cout << ".... leaving " << spaceName << "....." << std::endl;
				std::cout << std::endl;

				//incease water level
				waterLevel++;

				//temp = new Steerage;
				return 'S';
			}
			else if (choice == 3) //storage
			{
				std::cout << ".... leaving " << spaceName << "....." << std::endl;
				std::cout << std::endl;

				//incease water level
				waterLevel++;

				//temp = new Storage;
				return 'O';
			}
			else if (choice == 4) //captains
			{
				std::cout << ".... leaving " << spaceName << "....." << std::endl;
				std::cout << std::endl;

				//incease water level
				waterLevel++;

				//temp = new Captains;
				return 'C';
			}
			else if (choice == 5) //deck
			{
				std::cout << ".... leaving " << spaceName << "....." << std::endl;
				std::cout << std::endl;

				//incease water level
				waterLevel++;

				//temp = new Deck;
				return 'D';
			}

		} while (choice != 6);
		if (choice == 6)
		{
			//quit game
			waterLevel = 9999;
			//temp = new Steerage;
			return 'S';
		}
	}
}

/*********************************************************************
** Description: destructor for the hallway class
** Parameters: none
** Returns: none
*********************************************************************/
Hallway::~Hallway()
{

}