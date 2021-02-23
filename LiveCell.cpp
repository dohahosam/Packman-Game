#include "LiveCell.h"


LiveCell::LiveCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\LIVECELL.jpg";
}
LiveCell::LiveCell(Cell * old) : Cell(old->getRow(), old->getCol()) {


	ImagePath = "images\\Cells\\LIVECELL.jpg";

}


LiveCell::~LiveCell(void)
{
}

bool LiveCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}

