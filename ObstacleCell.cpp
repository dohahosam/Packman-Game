#include "ObstacleCell.h"


ObstacleCell::ObstacleCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\ObstacleCell.jpg";
}
ObstacleCell:: ObstacleCell(Cell * old) :Cell(old->getRow(), old->getCol()) {


	ImagePath = "images\\Cells\\ObstacleCell.jpg";

}


ObstacleCell::~ObstacleCell(void)
{
}

bool ObstacleCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return false;
}

