/*********************************************************************
** Program Name: captains.hpp
** Author: Anne Harris
** Date: 06/02/17
** Description: defines the captains space class which is a child of the
** space class. includes the memeber function prototypes. The 
**  captains space represents the left of the ship that has the 
** telegrams
*********************************************************************/

#ifndef CAPTAINS_HPP
#define CAPTAINS_HPP

#include<iostream>
#include<vector>
#include"space.hpp"

class Captains : public Space
{
public:
	Captains();
	~Captains();
	std::string getName();
	int getMenu();
	void displayMessage();
	char roomActions();
	bool getItem();

};

#endif 

