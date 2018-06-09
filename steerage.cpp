/*********************************************************************
** Program Name: steerage.cpp
** Author: Anne Harris
** Date: 06/02/17
** Description: contains the function definitions for the steerage
** class
*********************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include"space.hpp"
#include"steerage.hpp"
#include"hallway.hpp"
#include"menu.hpp"

/*********************************************************************
** Description: default constructor for the steerage class
** Parameters: none
** Returns: none
*********************************************************************/
Steerage::Steerage()
{
	spaceName = "STEERAGE ROOM";
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
** Description: calls the menu for the steerage class, it gives the user
** the options of where to look for a light, to leave the room or quit
** Parameters: none
** Returns: integer representing menu choice
*********************************************************************/
int Steerage::getMenu()
{
	int action;
	std::cout << "-----STEERAGE ROOM-----" << std::endl;
	std::cout << "Select an option" << std::endl;
	std::cout << "1. Search under your bed" << std::endl;
	std::cout << "2. Search in the drawer" << std::endl;
	std::cout << "3. Go to hallway" << std::endl;
	std::cout << "4. Accept your fate and quit" << std::endl;
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
** Description: displays the message for the room, if the user doesn't 
** have a flashlight they won't be able to "enter" the room
** Parameters: none
** Returns: void
*********************************************************************/
void Steerage::displayMessage()
{
	if (hasLight == false)
	{
		//display inital message
		std::cout << "In the " << spaceName << "..." << std::endl;
		std::cout << "You are unlucky enough to have a ticket in steerage" << std::endl;
		std::cout << "You have a long way to go before getting to the deck" << std::endl;
		std::cout << "It's pretty dark in here, better find a light.." << std::endl;
		std::cout << std::endl;
	}
	else if(hasLight == true)
	{
		std::cout << "In the " << spaceName << "..." << std::endl;
		std::cout << "It should be easier to find your way now!" << std::endl;
		std::cout << "Better get on your way..." << std::endl;
		std::cout << std::endl;
	}
}

/*********************************************************************
** Description: sets the light to true and then sets item acquired to
** true and will return true or false
** Parameters: none
** Returns: boolean representing if the item was acquired
*********************************************************************/
bool Steerage::getItem()
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
** Description: calls the rooms menu function and the performs the 
** appropriate action
** Parameters: none
** Returns: char representing the next space to go to
*********************************************************************/
char Steerage::roomActions()
{
	itemAcquired = false;
	waterLevel = 0;
	//call menu
	int choice = getMenu();
	do
	{
		if (choice == 1) //under the bed
		{
			int choice2, choice3;
			std::cout << "There is a hole under your bed, you can choose to swim " << std::endl;
			std::cout << "into it if you are so brave" << std::endl;
			std::cout << std::endl;
			choice2 = menu2();
			if (choice2 == 1)
			{
				std::cout << "A shark has bit you and spit you back out!" << std::endl;
				std::cout << "Would you like to stop to fix your wound?" << std::endl;
				std::cout << std::endl;
				choice3 = menu3();
				if (choice3 == 1)
				{
					std::cout << "Good thinking, had you not you could have" << std::endl;
					std::cout << "wasted a lot of time" << std::endl;
					std::cout << std::endl;
				}
				else if (choice3 == 2)
				{
					std::cout << "You're so wounded you passed out and ALOT of" << std::endl;
					std::cout << "water has risen, hope you feel better!" << std::endl;
					std::cout << "WATER RISING - water level + 25" << std::endl;
					std::cout << std::endl;
					waterLevel += 25;
				}
				waterLevel++;
			}
			else if (choice2 == 2)
			{
				std::cout << "Hope there isn't something you needed in there" << std::endl;
				std::cout << std::endl;
				waterLevel++;
			}
			//increase water level
			waterLevel++;
			//call menu
			choice = getMenu();
		}
		else if (choice == 2) //in the drawer
		{
			if (hasLight == false)
			{
				std::cout << "You're in luck! There's a flashlight in the drawer" << std::endl;
				std::cout << "You add it to your backpack and are feeling hopeful" << std::endl;
				std::cout << std::endl;
				itemAcquired = true;
			
				//increase water level
				waterLevel++;
			}
			else
			{
				std::cout << "The drawer is empty becuase you already grabbed the" << std::endl;
				std::cout << "flashlight, you wasted time coming back here" << std::endl;
				std::cout << "WATER RISING - water level + 5" << std::endl;
				std::cout << std::endl;
				//increase water level
				waterLevel += 5;
			}
		
			//call menu
			choice = getMenu();
		}
		else if (choice == 3) //go to hallway
		{
			//increase waterLevel
			waterLevel++;
			//return hallway space
			std::cout << ".... leaving " << spaceName << "....." << std::endl;
			std::cout << std::endl;
			return 'H';
		}
		
	} while (choice != 4); //quit
	if (choice == 4)
	{
		//end game
		waterLevel = 9999;
		return 'H';
	}
}

/*********************************************************************
** Description: Destructor for the steerage class
** Parameters: none
** Returns: none
*********************************************************************/
Steerage::~Steerage()
{
	/*
	delete forward;
	delete back;
	delete right;
	delete left;
	*/
}
