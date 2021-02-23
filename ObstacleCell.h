#pragma once
#include "cell.h"
class ObstacleCell :
	public Cell
{
public:
	ObstacleCell(int row, int col);
	ObstacleCell(Cell * old);

	virtual ~ObstacleCell();

	virtual bool ActOn(Player* p);
};

