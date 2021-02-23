#include "IdiotEnemyCell.h"


IdiotEnemyCell::IdiotEnemyCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\IDIOTGHOSTCELL.jpg";
}
IdiotEnemyCell::IdiotEnemyCell(Cell * old) : Cell(old->getRow(), old->getCol()) {


	ImagePath = "images\\Cells\\IDIOTGHOSTCELL.jpg";

}


IdiotEnemyCell::~IdiotEnemyCell(void)
{
}

bool IdiotEnemyCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}

