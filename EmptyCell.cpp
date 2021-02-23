#include "EmptyCell.h"


EmptyCell::EmptyCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\EmptyCell.jpg";
}
EmptyCell::EmptyCell(Cell * old) : Cell((old!=NULL)?old->getRow():-1, (old != NULL) ? old->getCol():-1) {


	ImagePath = "images\\Cells\\EmptyCell.jpg";

}


EmptyCell::~EmptyCell(void)
{
}

bool EmptyCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}

