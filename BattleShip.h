#ifndef BSHIP_H
#define BSHIP_H


#include"Ship.h"

class BattleShip: public Ship
{
	public:
	virtual void rotate() override;
	virtual std::string getName() override{return "BattleShip";}
	~BattleShip();
	BattleShip();

	
	
	private:

};
#endif
