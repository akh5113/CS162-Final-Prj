/*********************************************************************
** Program Name: game.hpp
** Author: Anne Harris
** Date: 06/02/17
** Description: Declares the game class by setting up the class member
** variables and the class member functions
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include<iostream>
#include<vector>
#include"space.hpp"
#include"steerage.hpp"
#include"storage.hpp"
#include"deck.hpp"
#include"captains.hpp"
#include"hallway.hpp"

class Game
{
private:
	bool gameOver;
	int waterLevel;
	bool backpackItem;
	bool itemAcquired1;
	bool hasRaft1;
	bool hasNote1;
	bool hasLight1;
	bool telegramSent1;
	char tempSpace;
	Space* currentSpace;
	Steerage* steerageSpace;
	Storage* storageSpace;
	Deck* deckSpace;
	Captains* captainsSpace;
	Hallway* hallwaySpace;

	std::vector<std::string> backpack;

public:
	Game();
	~Game();
	void setSpacePointers();
	void setCurrentSpace(Space*);
	int startGame();
	void addItem(bool);
	void printItems();
};
#endif 
