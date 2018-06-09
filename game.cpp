/*********************************************************************
** Program Name: game.cpp
** Author: Anne Harris
** Date: 06/02/17
** Description: contains the function definitions for the class game
** the functions put the game in action and go throught the different
** spaces of the ship
*********************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include"menu.hpp"
#include"game.hpp"
#include"space.hpp"
#include"steerage.hpp"
#include"storage.hpp"
#include"deck.hpp"
#include"captains.hpp"
#include"hallway.hpp"

/*********************************************************************
** Description: Default constructor for game class, sets water level
** to 1 and initiates all the spaces to a new space with parameters
** and sets all the items to false
** Parameters: none
** Returns: none
*********************************************************************/
Game::Game()
{
	gameOver = false;
	waterLevel = 1;
	steerageSpace = new Steerage();
	hallwaySpace = new Hallway();
	storageSpace = new Storage();
	captainsSpace = new Captains();
	deckSpace = new Deck();
	itemAcquired1 = false;
	hasRaft1 = false;
	hasNote1 = false;
	hasLight1 = false;
	telegramSent1 = false;
}

/*********************************************************************
** Description: Sets up the pointers for all spaces to what they should
** be by calling the individual set pointer functions
** Parameters: none
** Returns: void
*********************************************************************/
void Game::setSpacePointers()
{
	//steerage space only need to set forward
	steerageSpace->setForward('S', hallwaySpace);

	//hallway space need to set all 4
	hallwaySpace->setForward('H', deckSpace);
	hallwaySpace->setBack('H', steerageSpace);
	hallwaySpace->setLeft('H', captainsSpace);
	hallwaySpace->setRight('H', storageSpace);

	//storage space need to set left
	storageSpace->setLeft('O', hallwaySpace);

	//captains space need to set right
	captainsSpace->setRight('C', hallwaySpace);

	//deck space need to set back
	deckSpace->setBack('D', hallwaySpace);
}


/*********************************************************************
** Description: starts the game by setting the current space to the
** steerage space, then while the water level is less than 100 it 
** will call the current spaces room actions, get any items and 
** print the items collected
** Parameters: none
** Returns: integer represting the game being over
*********************************************************************/
int Game::startGame()
{
	//set pointers
	setSpacePointers();

	//set starting postition to steerage
	setCurrentSpace(steerageSpace);

	while (waterLevel < 100) //ship has not sunk
	{
		//clear stream
		clearScreen();

		//print water level
		std::cout << "WATER LEVEL: " << waterLevel << std::endl;
		std::cout << std::endl;
		//print backpack
		printItems();

		//display intro message and menu
		currentSpace->displayMessage();
		
		//call room actions which will display menu and 
		//perform activities
		tempSpace = currentSpace->roomActions();

		//add any items
		backpackItem = currentSpace->getItem();
		addItem(backpackItem);

		//increase water level
		if (currentSpace->getWaterLevel() == 555)
		{
			waterLevel = 555;
		}
		else
		{
			waterLevel = waterLevel + (currentSpace->getWaterLevel());
		}

		//set new current space
		if (tempSpace == 'H')
		{
			setCurrentSpace(hallwaySpace);
		}
		else if (tempSpace == 'S')
		{
			setCurrentSpace(steerageSpace);
		}
		else if (tempSpace == 'O')
		{
			setCurrentSpace(storageSpace);
		}
		else if (tempSpace == 'C')
		{
			setCurrentSpace(captainsSpace);
		}
		else if (tempSpace == 'D')
		{
			setCurrentSpace(deckSpace);
		}

		//press enter to continue
		if (waterLevel != 555)
		{
			std::cout << "Press <enter> to continue" << std::endl;
			std::cin.ignore();
		}
	}
	if (waterLevel == 555)
	{
		std::cout << std::endl;
		std::cout << "**********************" << std::endl;
		std::cout << "**You win the game!!**" << std::endl;
		std::cout << "**********************" << std::endl;
		std::cout << std::endl;

		//remove items from backpack
		while (!backpack.empty())
		{
			for (int i = 0; i < backpack.size(); i++)
			{
				backpack.pop_back();
			}
		}

		//end game
		return -1;
	}
	else if (waterLevel >= 100)
	{
		std::cout << "You went down with the ship, you lose the game" << std::endl;
		std::cout << std::endl;
		return -1;
	}
}

/*********************************************************************
** Description: add the item from the appropriate room to the item
** vector and set the boolian value for each room to be true
** Parameters: bool representing if the item should be added
** Returns: void
*********************************************************************/
void Game::addItem(bool boolIn)
{
	if (boolIn == true)
	{
		if (currentSpace == steerageSpace)
		{
			backpack.push_back("Flashlight");
			hasLight1 = true;
			std::cout << "**Flashlight added to your backpack**" << std::endl;
			std::cout << std::endl;

			hallwaySpace->setLight();
			storageSpace->setLight();
			captainsSpace->setLight();
			deckSpace->setLight();
		}
		else if (currentSpace == hallwaySpace)
		{
			backpack.push_back("Notebook");
			hasNote1 = true;
			std::cout << "**Notebook added to your backpack**" << std::endl;
			std::cout << std::endl;

			steerageSpace->setNote();
			storageSpace->setNote();
			captainsSpace->setNote();
			deckSpace->setNote();
		}
		else if (currentSpace == storageSpace)
		{
			backpack.push_back("LifeRaft");
			hasRaft1 = true;
			std::cout << "**LifeRaft added to your backpack**" << std::endl;
			std::cout << std::endl;

			steerageSpace->setRaft();
			hallwaySpace->setRaft();
			captainsSpace->setRaft();
			deckSpace->setRaft();
		}
		else if (currentSpace == captainsSpace)
		{
			backpack.push_back("Telegram");
			telegramSent1 = true;
			std::cout << "**Telegram added to your backpack**" << std::endl;
			std::cout << std::endl;

			steerageSpace->setTelegram();
			hallwaySpace->setTelegram();
			storageSpace->setTelegram();
			deckSpace->setTelegram();
		}
		else if (currentSpace == deckSpace)
		{
			backpack.push_back("Life");
			std::cout << "** You saved yourself!**" << std::endl;
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "No items to add on the deck" << std::endl;
	}
}

/*********************************************************************
** Description: sets the current space pointer to be what the space
** varaible that was passed in is
** Parameters: pointer to a space
** Returns: void
*********************************************************************/
void Game::setCurrentSpace(Space* spaceIn)
{
	currentSpace = spaceIn;
}

/*********************************************************************
** Description: prints the items in the players backpack vector
** Parameters: none
** Returns: void
*********************************************************************/
void Game::printItems()
{
	//print items
	if (backpack.empty())
	{
		std::cout << "You have no items in your backpack" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Items in your backpack: ";
		for (int i = 0; i < backpack.size(); i++)
		{
			std::cout << backpack.at(i) << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

/*********************************************************************
** Description: Destructor for the game class that deletes all of the 
** spaces and deletes any items in the items vector
** Parameters: none
** Returns: none
*********************************************************************/
Game::~Game()
{
	//delete pointers
	delete steerageSpace;
	delete hallwaySpace;
	delete storageSpace;
	delete captainsSpace;
	delete deckSpace;

}
