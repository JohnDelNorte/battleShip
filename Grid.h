#ifndef GRI_H
#define GRI_H


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
class Grid
{
	
	public:
	void show();
	void changeFile();
	void place();
	Grid();//default
	int getTotalLife(){return totalLife;}
	bool isGoodCoord(Coord& c,char choice, int size);


	
	
	
	private:
	BattleShip b;
	Cruiser    c;
	Frigate    f;
	Sub        s;
	Destroyer  d;
	char freeSquare='.';
	char hit='!';
	char miss='0';
	
	Ship *s0=&b;
	Ship *s1=&c;
	Ship *s2=&f;
	Ship *s3=&s;
	Ship *s4=&d;
	
	char   board [10][10];
	char enBoard [10][10];
	char comCopy [10][10]; //only needs to be initialzed once. 
	Ship* ships[5]{s0,s1,s2,s3,s4};
	
	int totalLife;
	

};
#endif