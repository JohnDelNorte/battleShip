
#ifndef SHIP_H
#define SHIP_H

#include<iostream>
#include<string>
#include<sstream>

class Ship
{
	public:
	virtual void rotate()=0;
	virtual std::string getName()=0;
	int getArmor(){return armor;}
	char getCharacter(){return symbol;}
	//void hit();
	virtual ~Ship();
	void damage();
	void setArmor(int a){armor=a;}
	void setSymbol(char c){symbol=c;}
	bool isSunk(){return sunk;}
	
	private:
	int armor;
	bool sunk=false;
	char symbol;


	
};
#endif