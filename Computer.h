#ifndef COM_H
#define COM_H

#include<fstream>
#include<string>
#include"Coord.h"
#include"BattleShip.h"
#include"Sub.h"
#include"Frigate.h"
#include"Cruiser.h"
#include"Destroyer.h"
using namespace std;
class Computer
{

public:
void placeShips();//computer will place its ships randomly;
void printGrid();//for diagnostic. 
int getLifeCount(){return totalLife;}
int getRand();


Coord shoot();
bool checkShot(int r, int c);
char tellShot(int r, int c);
bool lost();

private:


	bool first;
	BattleShip b;
	Cruiser    c;
	Frigate    f;
	Sub        s;
	Destroyer  d;
	char freeSquare='.';
	char hit='X';
	char miss='0';
	
	Ship *s0=&b;
	Ship *s1=&c;
	Ship *s2=&f;
	Ship *s3=&s;
	Ship *s4=&d;
	
	char   cBoard [10][10];
	char   pBoard [10][10];
	Ship* ships[5]{s0,s1,s2,s3,s4};
	
	int totalLife;
	bool isGoodCoord(Coord &c,char orientation, int shipSize);
};
#endif