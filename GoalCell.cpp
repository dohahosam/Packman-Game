#include "GoalCell.h"


GoalCell::GoalCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\GoalCell.jpg";
}
GoalCell::GoalCell(Cell * old) : Cell(old->getRow(), old->getCol()) {


	ImagePath = "images\\Cells\\GoalCell.jpg";

}


GoalCell::~GoalCell(void)
{
}

bool GoalCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}

