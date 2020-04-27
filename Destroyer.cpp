#include"Destroyer.h"

void Destroyer::rotate()
{
	std::cout<<"Destroyer has been rotated"<<std::endl;
}

Destroyer::Destroyer()
{
	this->setArmor(4);
	this->setSymbol('D');
}
Destroyer::~Destroyer()
{
	//std::cout<<"Destroyer has been destroyed"<<std::endl;
}