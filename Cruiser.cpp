#include"Cruiser.h"

void Cruiser::rotate()
{
	std::cout<<"cruiser has been rotated"<<std::endl;
}
Cruiser::Cruiser()
{
	this->setArmor(3);
	this->setSymbol('C');
}
Cruiser::~Cruiser()
{
	//std::cout<<"Cruiser has been destroyed"<<std::endl;
}