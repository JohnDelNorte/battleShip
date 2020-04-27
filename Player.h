#ifndef PLY_H
#define PLY_H


#include<string>
#include<fstream>
#include"Ship.h"
#include"Cruiser.h"
#include"BattleShip.h"
#include"Sub.h"
#include"Destroyer.h"
#include"Frigate.h"
#include"Coord.h"
using namespace std;
class Player
{
	
	public:
	void show();
	void changeFile();
	void placeShips();

	Player();//default
	int getLifeCount(){return totalLife;}
	bool isGoodCoord(Coord& c,char choice, int size);
	void setFirst(bool b);
	bool getFirst(){return first;}
	
	bool checkShot(Coord shot);
	void updateGrid(char hOrM,int r, int c);


	
	
	
	private:
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
	
	char   board [10][10];
	char enBoard [10][10];

	Ship* ships[5]{s0,s1,s2,s3,s4};
	
	int totalLife;
	bool first;
	

};
#endif