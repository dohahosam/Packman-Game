#pragma once
#include "cell.h"
class IdiotEnemyCell :
	public Cell
{
public:
	IdiotEnemyCell(int row, int col);
	IdiotEnemyCell(Cell * old);

	virtual ~IdiotEnemyCell();

	virtual bool ActOn(Player* p);
};

