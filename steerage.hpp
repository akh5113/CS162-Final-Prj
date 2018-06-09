/*********************************************************************
** Program Name: steerage.hpp
** Author: Anne Harris
** Date: 06/02/17
** Description: defines the steerage class which is a child of the
** space class. includes the memeber function prototypes. The 
** steerage represents the back of the ship
*********************************************************************/

#ifndef STEERAGE_HPP
#define STEERAGE_HPP

#include<iostream>
#include<vector>
#include"space.hpp"

class Steerage : public Space
{
public:
	Steerage();
	~Steerage();
	int getMenu();
	void displayMessage();
	char roomActions();
	bool getItem();
};

#endif
