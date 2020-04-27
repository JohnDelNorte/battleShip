#include"Sub.h"

void Sub::rotate()
{
	std::cout<<"Sub has been rotated"<<std::endl;
}

Sub::Sub()
{
	this->setArmor(3);
	this->setSymbol('S');
}
Sub::~Sub()
{
	//std::cout<<"Sub has been destroyed"<<std::endl;
}