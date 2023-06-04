#include "pch.h"
#include "CCell.h"

CCell::CCell(bool initState) : state(initState), countneighbor(0) {}

bool CCell::isAlive() const{
	return state;
}

void CCell::setAlive(bool cstate) {
	state = cstate;
}

int CCell::getneighborcount() const {
	return countneighbor;
}

void CCell::setneighborcount(int count) {
	countneighbor = count;
}