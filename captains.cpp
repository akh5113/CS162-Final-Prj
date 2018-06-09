/*********************************************************************
** Program Name: captains.cpp
** Author: Anne Harris
** Date: 06/02/17
** Description: contains the function definitions for the captains
** class
*********************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include"captains.hpp"
#include"space.hpp"
#include"hallway.hpp"

/*********************************************************************
** Description: default constructor for the captains class
** Parameters: none
** Returns: none
*********************************************************************/
Captains::Captains()
{
	spaceName = "CAPTAIN'S ROOM";
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
std::string Captains::getName()
{
	return spaceName;
}

/*********************************************************************
** Description: calls the menu for the captains room that gives the 
** user the option to check the room or leave to go back to the hallway
** Parameters: none
** Returns: integer representing the users choice
*********************************************************************/
int Captains::getMenu()
{
	int action;
	std::cout << "-----CAPTAINS ROOM-----" << std::endl;
	std::cout << "Select an option" << std::endl;
	std::cout << "1. Send a telegram" << std::endl;
	std::cout << "2. Check the captains storage room" << std::endl;
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
** Description: displays the initial message for the captains class
** Parameters: none
** Returns: void
*********************************************************************/
void Captains::displayMessage()
{
	std::cout << "In the " << spaceName << "..." << std::endl;
	std::cout << "The captain doesn't trust a lot of people, I hope you" << std::endl;
	std::cout << "have something to show him" << std::endl;
	std::cout << std::endl;

}

/*********************************************************************
** Description: simulates sending the telegram, sets the variable to 
** true and sets the variable to true and returns the appropraite 
** boolean true or false
** Parameters: none
** Returns: boolean representing if the item was acquired
*********************************************************************/
bool Captains::getItem()
{
	//sets telegram to true
	if (itemAcquired == true)
	{
		telegramSent = true;
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
** Description: simulates moving around the room. calls the menu for 
** the captains class and then based on what that returns this function
** displays the appropraite message and calls the appropriate functions
** Parameters: none
** Returns: character representing the next room to go to
*********************************************************************/
char Captains::roomActions()
{
	itemAcquired = false;
	waterLevel = 0;
	if (hasLight== false)
	{
		std::cout << "You can't see in the captains room because the lights" << std::endl;
		std::cout << "are out, you should find a light first" << std::endl;
		std::cout << std::endl;

		//increase water level
		waterLevel++;
		
		//temp = new Hallway;
		return 'H';
	}
	else if (hasNote == false)
	{
		std::cout << "You got to the captains room, but he doesn't trust you" << std::endl;
		std::cout << "he says to come back when you have some information" << std::endl;
		std::cout << std::endl;

		//increase water level
		waterLevel++;

		//temp = new Hallway;
		return 'H';
	}
	else if(hasNote == true)
	{
		std::cout << "The captain trusts you because you had the note!" << std::endl;
		std::cout << "He want's to help you however he can, take a look around." << std::endl;

		//call menu
		int choice = getMenu();
		//temp = new Hallway;
		do
		{
			if (choice == 1) //sent telegram
			{
				if (telegramSent == false)
				{
					std::cout << "You've been able to get word out of the sinking" << std::endl;
					std::cout << "ships location. Now if you have a raft the rescue" << std::endl;
					std::cout << "team will be able to find you!" << std::endl;
					std::cout << std::endl;
					itemAcquired = true;
					//collectItem();
					/*
					if (telegramSent == false)
					{
						itemAcquired = true;
					}
					else
					{
						itemAcquired = false;
					}
					*/
					//increase water level
					waterLevel++;
				}
				else
				{
					std::cout << "You've already sent one telegram, sending another" << std::endl;
					std::cout << "won't help you any more. The water is getting higher.." << std::endl;
					std::cout << "WATER RISING - water level + 5" << std::endl;
					std::cout << std::endl;
				}
				//call menu
				choice = getMenu();
			}
			else if (choice == 2) //captains sotrage room
			{
				std::cout << "You open the captains storage door and a rush of" << std::endl;
				std::cout << "water comes through, you get knocked down and take" << std::endl;
				std::cout << "a while to get up, you've lost some time" << std::endl;
				std::cout << std::endl;

				//increase water level
				waterLevel += 15;
				std::cout << "WATER RISING - Water Level + 15" << std::endl;
				std::cout << std::endl;

				choice = getMenu();
			}
			else if (choice == 3) //hallway
			{
				std::cout << ".... leaving " << spaceName << "....." << std::endl;
				std::cout << std::endl;
				//increase water level
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
** Description: destructor for the captains class
** Parameters: none
** Returns: none
*********************************************************************/
Captains::~Captains()
{
	/*
	delete forward;
	delete back;
	delete right;
	delete left;
	*/
}