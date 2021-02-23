#pragma once
#include "cell.h"
class GoalCell :
	public Cell
{
public:
	GoalCell(int row, int col);
	GoalCell(Cell * old);

	virtual ~GoalCell();

	virtual bool ActOn(Player* p);
};

