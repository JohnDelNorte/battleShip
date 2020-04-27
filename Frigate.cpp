#include"Frigate.h"


void Frigate::rotate()
{
	std::cout<<"cruiser has been rotated"<<std::endl;
}
Frigate::Frigate()
{
	this->setArmor(2);
	this->setSymbol('F');
}
Frigate::~Frigate()
{
	//std::cout<<"Cruiser has been destroyed"<<std::endl;
}