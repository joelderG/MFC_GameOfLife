#pragma once

class CCell
{
public:
	CCell(bool initState = false);
	bool isAlive() const;
	void setAlive(bool fstate); // fstate = function state
	int getneighborcount() const;
	void setneighborcount(int count);
private:
	bool state;
	int countneighbor;
};

