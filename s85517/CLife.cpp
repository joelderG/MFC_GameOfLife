#include "pch.h"
#include "CLife.h"

CLife::CLife(int r, int c) : rows(r), cols(c) {
	grid = new CCell * [rows];
	for (int i = 0; i < rows; i++) {
		grid[i] = new CCell[cols];
	}
}

CLife::~CLife() {
	for (int i = 0; i < rows; i++) {
		delete[] grid[i];
	}
	delete[] grid;
}

int CLife::getRows() const {
	return rows;
}

int CLife::getCols() const {
	return cols;
}

CCell& CLife::getCell(int x, int y) {
	return grid[x][y];
}

void CLife::setcell(int x, int y, bool state) {
	grid[x][y].setAlive(state);
}

void CLife::loadstartstates(const std::string& filename) {
	
}

void CLife::run() {

}

void CLife::randomstartstate(double percentage) {
	for(int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			if (rand() % 100 < percentage) {
				grid[i][j].setAlive(true);
			}
			else {
				grid[i][j].setAlive(false);
			}
		}
}