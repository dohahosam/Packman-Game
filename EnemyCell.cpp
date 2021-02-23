#include "EnemyCell.h"


EnemyCell::EnemyCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\ENEMYCELL.jpg";
}
EnemyCell::EnemyCell(Cell * old) : Cell(old->getRow(), old->getCol()) {


	ImagePath = "images\\Cells\\ENEMYCELL.jpg";

}


EnemyCell::~EnemyCell(void)
{
}

bool EnemyCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}

