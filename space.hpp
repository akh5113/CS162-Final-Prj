/************************************************************************
** Program Name: space.hpp
** Author: Anne Harris
** Date: 06/02/17
** Description: Defines the class space which is the abstract parent
** class for all of the spaces in the ship. It defines the four pointers
** and the boolean values
************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include<iostream>
#include<vector>
#include<string>

class Space
{
protected:
	Space *forward;
	Space *back;
	Space *right;
	Space *left;
	bool itemAcquired;
	bool hasRaft;
	bool hasNote;
	bool hasLight;
	bool telegramSent;
	Space *temp;
	int waterLevel;
	std::string spaceName;

public:
	Space();
	virtual ~Space();
	void setForward(char, Space*);
	void setBack(char, Space*);
	void setRight(char, Space*);
	void setLeft(char, Space*);
	virtual int getMenu() = 0;
	virtual void displayMessage() = 0;
	virtual char roomActions() = 0;
	virtual bool getItem() = 0;
	std::string getName();
	int getWaterLevel();
	void setLight();
	void setRaft();
	void setNote();
	void setTelegram();

};

#endif 
