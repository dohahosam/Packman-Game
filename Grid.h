#pragma once

#include "GUI.h"
#include "DEFS.h"
#include "Cell.h"
class Player;	//forward class declaration

class Grid
{
	GUI * pGUI;   // a pointer to the the interface
	// the only poinet to it so far
	Cell*	GameCells[NumRowCells][NumColumnCells];	// Array of Pointers to Cell
	Player* player;

public:

	Grid();	  

	// ========== Action-Related Functions ==========

	ActionType GetUserAction() const; // Reads the input command from the user and returns the corresponding action type

	void ExecuteAction(ActionType) ;  // Creates an action of the passed actionType and executes it

	void setCell(int r, int c, Cell* pCell);	//updates cell r,c to hold the new pointer pCell
	void setCell(Cell* old, Cell* pCell); //trial

	
	bool MoveIfPossible(Cell * pCurrentCell, ActionType dir); // Moves the entered position in the passed direction if no obstacles
	                                                       // updates currentCell if move takes place
	                                                       // Note: It returns bool indicating if a move occured or not

	bool IsValidCell(int r, int c) const;

	void DrawAllCells() const; // Draws the Grid and All its GameObjects
	// new after 1st debug
	Cell* getClickedCell(); 

	GUI * getGUI() const;	// Gets a Pointer to the GUI

	~Grid();
	void RunApp();	//Runs the application
};

