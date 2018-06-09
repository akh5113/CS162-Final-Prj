/*********************************************************************
** Program Name: hallway.hpp
** Author: Anne Harris
** Date: 06/02/17
** Description: defines the hallway class which is a child of the
** space class. includes the memeber function prototypes. The 
** hallway represents the middle of the ship that connects all of the
** spaces together
*********************************************************************/

#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include<iostream>
#include<string>
#include<vector>
#include"space.hpp"

class Hallway : public Space
{
private:
	std::string note;
public:
	Hallway();
	~Hallway();
	std::string getName();
	int getMenu();
	void displayMessage();
	char roomActions();
	bool getItem();

};

#endif 
