#include"BattleShip.h"

void BattleShip::rotate()
{
	std::cout<<"BattleShip has been rotated"<<std::endl;
}

BattleShip::BattleShip()
{
	this->setArmor(5);
	this->setSymbol('B');
}
BattleShip::~BattleShip()
{
	//std::cout<<"BattleShip has been destroyed"<<std::endl;
}