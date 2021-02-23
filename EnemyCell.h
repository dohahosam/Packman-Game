#pragma once
#include "cell.h"
class EnemyCell :
	public Cell
{
public:
	EnemyCell(int row, int col);
	EnemyCell(Cell * old);

	virtual ~EnemyCell();

	virtual bool ActOn(Player* p);
};

