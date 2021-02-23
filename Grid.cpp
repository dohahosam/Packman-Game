#include "Grid.h"
#include "ObstacleCell.h"
#include "EnemyCell.h"
#include "GoalCell.h"
#include "NurseCell.h"
#include "IdiotEnemyCell.h"
#include "LiveCell.h"
#include "CoinCell.h"
#include "Player.h"
#include "EmptyCell.h"
#include "PlayerCell.h"
 

Grid::Grid() 
{
	// initializes all the GameObject pointer of the List to NULL
	for (int i = 0; i < NumRowCells; i++)
	{
		for (int j = 0; j < NumColumnCells; j++)		{
			
			GameCells[i][j] = new EmptyCell(i,j);	//start with all cells as empty cells
		}
	}
	pGUI = new GUI;
	
	DrawAllCells();
	
	 
}



/////////////////////////////////////////////////////////////////////////////////////////////
// Moves the entered position in the passed direction if possible
// updates currentCell if move takes place
// Note: It returns bool indicating if a move occured or not
bool Grid::MoveIfPossible(Cell* pCurrentCell, ActionType dir) 
{
	
	//Calculate the row and col of the cell to move to
	//First initialize them as current row and col
	int playerOldRow = pCurrentCell->getRow();
	int playerOldCol = pCurrentCell->getCol();

	int TargetRow = playerOldRow;
	int TargetCol = playerOldCol ; 

	
	switch(dir)
	{
	case MOVE_UP:
		TargetRow--;
		break;
	case MOVE_DOWN:
		TargetRow++;
		break;
	case MOVE_LEFT:
		TargetCol--;
		break;
	case MOVE_RIGHT:
		TargetCol++;;
		break;
	}

	if( !IsValidCell(TargetRow, TargetCol))
		return false;

	//get the target cell
	Cell *pTargetCell = GameCells[TargetRow][TargetCol];

	if(!pTargetCell->ActOn(player))	//The target cell is an obstacle ==> no action should be taken
		return false;

	//The target cell is not an obstacle and has acted on the player
	//The player position should be updated to the target cell
	
	//Player should be moved to the target cell

	//1-delete the target cell and make it point to the PlayerCell
	setCell(TargetRow,TargetCol, pCurrentCell);

	//2- update player position
	pCurrentCell->SetRow(TargetRow);
	pCurrentCell->SetCol(TargetCol);

	//3- Convert the old player position to an Empty cell
	GameCells[playerOldRow][playerOldCol] = new EmptyCell(playerOldRow,playerOldCol);

	//4- Redraw both cells
	pGUI->DrawCell(GameCells[TargetRow][TargetCol]);
	pGUI->DrawCell(GameCells[playerOldRow][playerOldCol]);

	return true;
}

void Grid::DrawAllCells() const	
{
	// Draw Empty Grid
	pGUI->ClearGridArea();

	// Draw all the GameObject of the Grid
	for (int i = 0; i < NumRowCells; i++)
		for (int j = 0; j < NumColumnCells; j++)
			pGUI->DrawCell(GameCells[i][j]);
}

void Grid::setCell(int row, int col, Cell* pCell)
{	
	if(GameCells[row][col])
		delete GameCells[row][col];	//if cell ptr is not null, delete it first
	
	GameCells[row][col] = pCell;

}
// trial
void Grid::setCell(Cell* old, Cell* pCell)
{
	int row = old->getRow();
	int col = old-> getCol();
	if (GameCells[row][col])
		delete GameCells[row][col];	//if cell ptr is not null, delete it first
	GameCells[row][col] = pCell;

}

GUI * Grid::getGUI() const
{
	return pGUI;
}
///////////////////////////////////////////////////////////////////
//				Action-related functions
///////////////////////////////////////////////////////////////////

ActionType Grid::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pGUI->GetUserAction( ); 
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void Grid::ExecuteAction(ActionType ActType) 
{
	
	// According to Action Type, create the corresponding action object	
	switch (ActType)
	{
	case LOAD:
		// Call Load function to load game from a file
		break;

	case SAVE:
		// Call Save function to Save current game to a file
		break;

	case START:	//start game 
		pGUI->setInterfaceMode(MODE_GAME);
		break;

	case PAUSE:	//pause game
		pGUI->setInterfaceMode(MODE_MENU);
		break;
	case  EMPTYCELL: {pGUI->PrintMessage("Please Click on the Cell you Want to be Empty Cell");
	
		Cell* tryCell = new Cell(getClickedCell());
			
			if (!(tryCell-> getCol()==-1)) {
				EmptyCell *oCell = new EmptyCell(tryCell); // create new cell of selected type
				setCell(oCell, oCell); // change the required cell and deleteing the old one
				pGUI->DrawCell(oCell); // draw the new cell
				}
			
	}
		break;
	case ENEMYCELL:
	
	{pGUI->PrintMessage("Please Click on the Cell you Want to be Enemy Cell");
	Cell* tryCell = new Cell(getClickedCell());

	if (!(tryCell->getCol() == -1)) {
		EnemyCell *oCell = new EnemyCell(tryCell); // create new cell of selected type
		setCell(oCell, oCell); // change the required cell and deleteing the old one
		pGUI->DrawCell(oCell); // draw the new cell
	}
	} 
		break;
	case   GOALCELL: {pGUI->PrintMessage("Please Click on the Cell you Want to be Goal Cell");
		Cell* tryCell = new Cell(getClickedCell());

		if (!(tryCell->getCol() == -1)) {
			GoalCell *oCell = new GoalCell(tryCell); // create new cell of selected type
			setCell(oCell, oCell); // change the required cell and deleteing the old one
			pGUI->DrawCell(oCell); // draw the new cell
		}
	}  break;
	case 	  OBSTACLECELL:
	{
	
	pGUI->PrintMessage("Please Click on the Cell you Want to be Obstacle Cell");
	
	Cell* tryCell = new Cell(getClickedCell());

	if (!(tryCell->getCol() == -1)) {
		ObstacleCell *oCell = new ObstacleCell(tryCell); // create new cell of selected type
		setCell(oCell, oCell); // change the required cell and deleteing the old one
		pGUI->DrawCell(oCell); // draw the new cell
	}
	}
		break;
	case   LIVECELL: {

		pGUI->PrintMessage("Please Click on the Cell you Want to be Live Cell");

		Cell* tryCell = new Cell(getClickedCell());

		if (!(tryCell->getCol() == -1)) {
			LiveCell *oCell = new LiveCell(tryCell); // create new cell of selected type
			setCell(oCell, oCell); // change the required cell and deleteing the old one
			pGUI->DrawCell(oCell); // draw the new cell
		}
	} break;
	case   IDIOTGHOSTCELL: {

		pGUI->PrintMessage("Please Click on the Cell you Want to be Idiot-Enemy Cell");

		Cell* tryCell = new Cell(getClickedCell());

		if (!(tryCell->getCol() == -1)) {
			IdiotEnemyCell *oCell = new IdiotEnemyCell(tryCell); // create new cell of selected type
			setCell(oCell, oCell); // change the required cell and deleteing the old one
			pGUI->DrawCell(oCell); // draw the new cell
		}
	} break;
	case   NURSECELL: {
		pGUI->PrintMessage("Please Click on the Cell you Want to be Nurse Cell"); 
		Cell* tryCell = new Cell(getClickedCell());

		if (!(tryCell->getCol() == -1)) {
			NurseCell *oCell = new NurseCell(tryCell); // create new cell of selected type
			setCell(oCell, oCell); // change the required cell and deleteing the old one
			pGUI->DrawCell(oCell); // draw the new cell
		}
	}break;
	case   COINCEll: {

		pGUI->PrintMessage("Please Click on the Cell you Want to be Coin Cell");

		Cell* tryCell = new Cell(getClickedCell());

		if (!(tryCell->getCol() == -1)) {
			CoinCell *oCell = new CoinCell(tryCell); // create new cell of selected type
			setCell(oCell, oCell); // change the required cell and deleteing the old one
			pGUI->DrawCell(oCell); // draw the new cell
		}
	} break;
	///TODO: Add a case for EACH Action type DONE TILL NOW
	case MOVE_UP:
	case MOVE_DOWN:
	case MOVE_RIGHT:
	case MOVE_LEFT:
		player->Move(this,ActType);
		break;		

	case STATUS:	// a click on the status bar ==> no action
		return;
	}

}


	Cell* Grid::getClickedCell() {
		int x = -1, y = -1;
		 int r = -1; int c = -1;

		pGUI->GetPointClicked(x, y, true);   // true to wait see the function in GUI.cpp
		if (y >= ToolBarHeight && y < (WindowHeight - StatusBarHeight))
		{
			c = x / GridCellWidth; // columns from x 
			r = (y- ToolBarHeight) / GridCellWidth; // note that cells are squares   
			pGUI->PrintMessage("A valid Cell was selected");
			return GameCells[r][c];			   // extra : check it is not player cell
		}
		else {
			pGUI->PrintMessage("No valid Cell was selected");
			return NULL;
		}
			
	}


Grid::~Grid()
{
	delete pGUI;
}

//////////////////////////////////////////////////////////////////////////////////


// Runs the application

void Grid::RunApp()
{
	
	 
	int Startrow = 7, Startcol=12;	
	PlayerCell* pCell = new PlayerCell(Startrow, Startcol);
	setCell(Startrow, Startcol, pCell);
	player = new Player(*pCell);
	pGUI->DrawCell(pCell);
	
	while (1)
	{
		ActionType act = GetUserAction();
		if(act == EXIT)
			return;
		
		ExecuteAction(act);
		 
 		Sleep(100);
	}

}

////////////////////////////////////////////////////////////////////////////////////
bool Grid::IsValidCell(int row, int col) const
{
	return (row >= 0 && row < NumRowCells) 
			&& (col >=0 && col < NumColumnCells);
}
