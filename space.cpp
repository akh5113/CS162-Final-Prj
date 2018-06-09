/*********************************************************************
** Program Name: space.cpp
** Author: Anne Harris
** Date: 06/02/17
** Description: contains the function definitions for the class
** space
*********************************************************************/

#include<iostream>
#include<vector>
#include"space.hpp"

/*************************************************************************
** Description: Default constructor for the space class, sets all pointers
** to null and sets all items to false
** Parameters: none
** Returns: none
*************************************************************************/
Space::Space()
{
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
** Description: sets the forward pointer based on the character and 
** spaced passed in
** Parameters: character representing current room and space representing
** the next room
** Returns: void 
*********************************************************************/
void Space::setForward(char spaceIn, Space* nextIn)
{
	if (spaceIn == 'S') //steerage
	{
		forward = nextIn; 
	}
	else if (spaceIn == 'H') //hallway
	{
		forward = nextIn;
	}
	else if (spaceIn == 'O') //storage
	{
		forward = NULL;
	}
	else if (spaceIn == 'C') //captains
	{
		forward = NULL;
	}
	else if (spaceIn == 'D') //deck
	{
		forward = NULL;
	}
}

/*********************************************************************
** Description: sets the back pointer based on the character and
** spaced passed in
** Parameters: character representing current room and space representing
** the next room
** Returns: void
*********************************************************************/
void Space::setBack(char spaceIn, Space* nextIn)
{
	if (spaceIn == 'S') //steerage
	{
		back = NULL;
	}
	else if (spaceIn == 'H') //hallway
	{
		back = nextIn;
	}
	else if (spaceIn == 'O') //storage
	{
		back = NULL;
	}
	else if (spaceIn == 'C') //captains
	{
		back = NULL;
	}
	else if (spaceIn == 'D') //deck
	{
		back = nextIn;
	}
}

/*********************************************************************
** Description: sets the right pointer based on the character and
** spaced passed in
** Parameters: character representing current room and space representing
** the next room
** Returns: void
*********************************************************************/
void Space::setRight(char spaceIn, Space* nextIn)
{
	if (spaceIn == 'S') //steerage
	{
		right = NULL;
	}
	else if (spaceIn == 'H') //hallway
	{
		right = nextIn;
	}
	else if (spaceIn == 'O') //storage
	{
		right = NULL;
	}
	else if (spaceIn == 'C') //captains
	{
		right = nextIn;
	}
	else if (spaceIn == 'D') //deck
	{
		right = NULL;
	}
}

/*********************************************************************
** Description: sets the left pointer based on the character and
** spaced passed in
** Parameters: character representing current room and space representing
** the next room
** Returns: void
*********************************************************************/
void Space::setLeft(char spaceIn, Space* nextIn)
{
	if (spaceIn == 'S') //steerage
	{
		left = NULL;
	}
	else if (spaceIn == 'H') //hallway
	{
		left = nextIn;
	}
	else if (spaceIn == 'O') //storage
	{
		left = nextIn;
	}
	else if (spaceIn == 'C') //captains
	{
		left = NULL;
	}
	else if (spaceIn == 'D') //deck
	{
		left = NULL;
	}
}


/*********************************************************************
** Description: returns the water level from the current space
** Parameters: none
** Returns: integer representing the water level
*********************************************************************/
std::string Space::getName()
{
	return spaceName;
}

/*********************************************************************
** Description: returns the water level from the current space
** Parameters: none
** Returns: integer representing the water level
*********************************************************************/
int Space::getWaterLevel()
{
	return waterLevel;
}

/*********************************************************************
** Description: sets the light on variable to be true for all of the
** spaces
** Parameters: none
** Returns: void
*********************************************************************/
void Space::setLight()
{
	hasLight = true;
}

/*********************************************************************
** Description: sets the has raft variable to be true for all of the 
** spaces
** Parameters: none
** Returns: void
*********************************************************************/
void Space::setRaft()
{
	hasRaft = true;
}

/*********************************************************************
** Description: sets the has note variable to be true for all of the
** spaces
** Parameters: none
** Returns: void
*********************************************************************/
void Space::setNote()
{
	hasNote = true;
}

/*********************************************************************
** Description: sets the telegram sent variable to be true for all of 
** the spaces
** Parameters: none
** Returns: void
*********************************************************************/
void Space::setTelegram()
{
	telegramSent = true;
}

/*********************************************************************
** Description: Destructor for the space class that deletes all of
** the pointer variables
** Parameters: none
** Returns: none
*********************************************************************/
Space::~Space()
{
	
}
