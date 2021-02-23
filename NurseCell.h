#pragma once
#include "cell.h"
class NurseCell :
	public Cell
{
public:
	NurseCell(int row, int col);
	NurseCell(Cell * old);

	virtual ~NurseCell();

	virtual bool ActOn(Player* p);
};

