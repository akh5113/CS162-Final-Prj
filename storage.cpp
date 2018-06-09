/*********************************************************************
** Program Name: storage.cpp
** Author: Anne Harris
** Date: 06/02/17
** Description: contains the function definitions for the storage
** class
*********************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include"storage.hpp"
#include"space.hpp"
#include"hallway.hpp"

/*********************************************************************
** Description: default constructor for the storage class
** Parameters: none
** Returns: none
*********************************************************************/
Storage::Storage()
{
	spaceName = "STORAGE ROOM";
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
std::string Storage::getName()
{
	return spaceName;
}

/*********************************************************************
** Description: calls the menu for the storage room that gives the user
** the option to check the room or go back to the hallway
** Parameters: none
** Returns: integer representing the users choice
*********************************************************************/
int Storage::getMenu()
{
	int action;
	std::cout << "-----STORAGE ROOM-----" << std::endl;
	std::cout << "Select an option" << std::endl;
	std::cout << "1. Check behind door" << std::endl;
	std::cout << "2. Check in the closet" << std::endl;
	std::cout << "3. Go back to the hallway" << std::endl;
	std::cout << "4. Quit" << std::endl;
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
		if (action < 1 || action > 4)
		{
			std::cout << "Out of range, enter a number between " << 1 << " and " << 4 << std::endl;
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
** Description: displays the initial message for the storage class
** Parameters: none
** Returns: void
*********************************************************************/
void Storage::displayMessage()
{
	std::cout << "In the " << spaceName << "..." << std::endl;
	std::cout << "This seems like a good place to look for something" << std::endl;
	std::cout << "that will help you float" << std::endl;
	std::cout << std::endl;
}

/*********************************************************************
** Description: simulates getting the raft, sets the variable to true
** and returns the apporpriate bool of true or false
** Parameters:
** Returns:
*********************************************************************/
bool Storage::getItem()
{
	//sets has raft to true
	if (itemAcquired == true)
	{
		hasRaft = true;
		return true;
	}
	else
	{
		return false;
	}

}

/*********************************************************************
** Description: simulates moving around the room in the storage class
** it calls the menu for the storage class and then based off of that
** response it displays a message, calls a function or moves room
** Parameters: none
** Returns: character representing the next room to go into
*********************************************************************/
char Storage::roomActions()
{
	itemAcquired = false;
	waterLevel = 0;

	if (hasLight == false)
	{
		std::cout << "In the STORAGE room... " << std::endl;
		std::cout << "You can't see in the storage room because the lights" << std::endl;
		std::cout << "are out, you should find a light first" << std::endl;

		//incease water level
		waterLevel++;

		//temp = new Hallway;
		return 'H';
	}
	else
	{
		int choice = getMenu();
		do 
		{
			if (choice == 1) //behind door
			{
				std::cout << "YIKES! A big rat ran out and scared you so you" << std::endl;
				std::cout << "fell and lost a lot of time, you get up and keep going!" << std::endl;
				std::cout << std::endl;

				//incease water level
				waterLevel+= 10;
				std::cout << "WATER RISING - water level + 10" << std::endl;

				choice = getMenu();
			}
			else if (choice == 2) //in closet
			{
				if (hasRaft == false)
				{
					std::cout << "You're excited! You found a raft which is a key to" << std::endl;
					std::cout << "getting off the ship in one peice" << std::endl;
					itemAcquired = true;
					/*
					if (hasRaft == false)
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
					std::cout << "You already have a raft and can't fit another in" << std::endl;
					std::cout << "your backpack. You tried to stuff it in but wasted time" << std::endl;
					std::cout << "while water rose" << std::endl;
					std::cout << "WATER RISING - water level + 5" << std::endl;
					std::cout << std::endl;
				}

				//call menu
				choice = getMenu();
			}
			else if (choice == 3) //return to hallway
			{
				std::cout << ".... leaving " << spaceName << "....." << std::endl;
				std::cout << std::endl;

				//incease water level
				waterLevel++;

				return 'H';
			}
			
		} while (choice != 4);
		if (choice == 4)
		{
			//quit
			waterLevel = 9999;
			return 'H';
		}
	}

}

/*********************************************************************
** Description: destructor for the storage class
** Parameters: none
** Returns: none
*********************************************************************/
Storage::~Storage()
{
	/*
	delete forward;
	delete back;
	delete right;
	delete left;
	*/
}