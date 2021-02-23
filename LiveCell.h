#pragma once
#include "cell.h"
class LiveCell :
	public Cell
{
public:
	LiveCell(int row, int col);
	LiveCell(Cell * old);

	virtual ~LiveCell();

	virtual bool ActOn(Player* p);
};

