#include "NurseCell.h"


NurseCell::NurseCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\NURSECELL.jpg";
}
NurseCell::NurseCell(Cell * old) : Cell(old->getRow(), old->getCol()) {


	ImagePath = "images\\Cells\\NURSECELL.jpg";

}


NurseCell::~NurseCell(void)
{
}

bool NurseCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}

