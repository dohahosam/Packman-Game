#pragma once

#include "Cell.h"
#include "GUI.h"
class Grid;

class Player 
{
	int lives;    // number of lives (initially 4)
	float health; // player's health percentage (initially 100% -> full health)
	float score;  // player's score (initially 0)
	Cell PositionCell;

public:

	Player(Cell pos); // Constructor
	
	void setPosition(Cell);
	void Move(Grid* pGrid, ActionType MoveAction); // Moves the Player in a specific direction if possible


	//// Added by Mousa
	virtual void SaveP();
};

