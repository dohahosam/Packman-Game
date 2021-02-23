#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (you can add more if needed)
{
	//  Possible action

	LOAD,	// Load game file
	SAVE,	// Save game to a file
	START,	// Start the game
	EMPTYCELL,
	ENEMYCELL,
	GOALCELL,
	OBSTACLECELL,
	LIVECELL,
	IDIOTGHOSTCELL,
	NURSECELL,
	COINCEll,
	PAUSE,	//Pause the game
	EXIT,	// Exit Application

	//  Player move direction 
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	NO_MOVE,

	EMPTY,				// a click inside empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// a click inside Grid Area
	STATUS 				// a click inside StatusBar Area


};

#endif