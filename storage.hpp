/*********************************************************************
** Program Name: storage.hpp
** Author: Anne Harris
** Date: 06/02/17
** Description: defines the storage class which is a child of the
** space class. includes the memeber function prototypes. The 
** storage space represents the space on the right of the hallway
** which has the raft
*********************************************************************/

#ifndef STORAGE_HPP
#define STORAGE_HPP

#include<iostream>
#include"space.hpp"

class Storage : public Space
{
private:

public:
	Storage();
	~Storage();
	std::string getName();
	int getMenu();
	void displayMessage();
	char roomActions();
	bool getItem();
};

#endif 
