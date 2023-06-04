#pragma once
#include <iostream>
#include "CCell.h"

class CLife
{
public:
	CLife(int r, int c);
	~CLife();
	int getRows() const;
	int getCols() const;
	CCell& getCell(int x, int y);
	void setcell(int x, int y, bool state);
	void loadstartstates(const std::string& filename);
	void run();
	void randomstartstate(double percentage);
private:
	CCell** grid;
	int rows, cols;
};

