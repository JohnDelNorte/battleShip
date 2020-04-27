#include"BattleShip.h"
#include"Cruiser.h"
#include"Sub.h"
#include"Frigate.h"
#include"Destroyer.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	BattleShip b;
	Sub        s;
	Cruiser    c;
	Destroyer  d;
	Frigate    f;
	
	vector<Ship *> ships;
	
	Ship* s0=&b;
	Ship* s1=&s;
	Ship* s2=&c;
	Ship* s3=&d;
	Ship* s4=&f;
	ships.push_back(s0);
	ships.push_back(s1);
	ships.push_back(s2);
	ships.push_back(s3);
	ships.push_back(s4);
	
	for(Ship *s:ships)
	{
		cout<<s->getName()<<" armor: "<<s->getArmor()<<" symbol: "<<s->getCharacter()<<endl;
	}
	
	b.damage();
	b.damage();
	b.damage();
	b.damage();
	b.damage();

	
	
	
	
	
	
	
	return 0;
}