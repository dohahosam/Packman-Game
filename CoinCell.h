#pragma once
#include "cell.h"
class CoinCell :
	public Cell
{
public:
	CoinCell(int row, int col);
	CoinCell(Cell * old);

	virtual ~CoinCell();

	virtual bool ActOn(Player* p);
};

