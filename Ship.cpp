#include"Ship.h"

void Ship::rotate()
{
	std::cout<<"the ship was rotated"<<std::endl;
}

Ship::~Ship()
{
	
}
std::string Ship::getName()
{
	return "name";
}
void Ship::damage()
{
	(armor>0)?armor--:armor;
	if(armor==0)
	{
		sunk=true;
	}
}