/*********************************************************************
** Program Name: deck.hpp
** Author: Anne Harris
** Date: 06/02/17
** Description: defines the deck class which is a child of the
** space class. includes the memeber function prototypes. The 
** deck class. The deck represents the front of the ship
*********************************************************************/

#ifndef DECK_HPP
#define DECK_HPP

#include<iostream>
#include<vector>
#include"space.hpp"

class Deck : public Space
{
public:
	Deck();
	~Deck();
	std::string getName();
	int getMenu();
	void displayMessage();
	char roomActions();
	bool getItem();
};

#endif 


