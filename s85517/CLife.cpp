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
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int count = 0;
			if (i > 0 && j > 0 && grid[i - 1][j - 1].isAlive()) {
				count++;
			}
			if (i > 0 && grid[i - 1][j].isAlive()) {
				count++;
			}
			if (i > 0 && j < cols - 1 && grid[i - 1][j + 1].isAlive()) {
				count++;
			}
			if (j > 0 && grid[i][j - 1].isAlive()) {
				count++;
			}
			if (j < cols - 1 && grid[i][j + 1].isAlive()) {
				count++;
			}
			if (i < rows - 1 && j > 0 && grid[i + 1][j - 1].isAlive()) {
				count++;
			}
			if (i < rows - 1 && grid[i + 1][j].isAlive()) {
				count++;
			}
			if (i < rows - 1 && j < cols - 1 && grid[i + 1][j + 1].isAlive()) {
				count++;
			}
			grid[i][j].setneighborcount(count);
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j].getneighborcount() < 2 || grid[i][j].getneighborcount() > 3) {
				grid[i][j].setAlive(false);
			}
			else if (grid[i][j].getneighborcount() == 3) {
				grid[i][j].setAlive(true);
			}
		}
	}
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