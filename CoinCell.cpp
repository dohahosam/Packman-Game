#include "CoinCell.h"


CoinCell::CoinCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\CoinCell.jpg";
}
CoinCell::CoinCell(Cell * old) : Cell(old->getRow(), old->getCol()) {


	ImagePath = "images\\Cells\\CoinCell.jpg";

}


CoinCell::~CoinCell(void)
{
}

bool CoinCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}

