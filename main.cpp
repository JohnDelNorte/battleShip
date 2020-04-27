
#include"Player.h"
#include"Computer.h"
#include<string>
#include<sstream>
using namespace std;

int main()
{
	stringstream ss;
	int r,c;
	Player player1;
	Computer opponent;
	player1.placeShips();        //place ships in myGrid.txt
	opponent.placeShips();       //place ships in oppGrid.txt

	
	
	


	(opponent.getRand()%2==0)?player1.setFirst(true):player1.setFirst(false);
	cout<<((player1.getFirst())?"Player is first":"Computer is first")<<endl;
	
	do
	{
		//player shot


		do{
			r=c=0;
			string input;
			cout<<"enter coordinate to shoot: ";
			getline(cin,input);
			ss<<input;
			ss>>r>>c;
			ss.clear();
		}while(!(opponent.checkShot(r,c)));
		//the shot was a valid coordinate.
		player1.updateGrid(opponent.tellShot(r,c),r,c);
		
		while(!(player1.checkShot(opponent.shoot()))){}
		//shot is valid coordinate
		
		
		
		
		
		
		
		
	}while(player1.getLifeCount()!=0 && opponent.getLifeCount()!=0);
	
	cout<<((player1.getLifeCount()==0)?"computer wins":"player wins")<<endl;


}
//player has a grid
//grid has ships and coordinates
//ship has coordinates