#pragma once
#include "cell.h"
class EmptyCell :
	public Cell
{
public:
	EmptyCell(int row, int col);
	EmptyCell(Cell * old);

	virtual ~EmptyCell();

	virtual bool ActOn(Player* p);
};

