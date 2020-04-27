#include"Computer.h"
using namespace std;


void Computer::placeShips()
{
	totalLife=s0->getArmor()+s1->getArmor()+s2->getArmor()+s3->getArmor()+s4->getArmor(); 
	for(int i=0; i<10; i++)             //the board is initialized. 
		for(int j=0; j<10; j++)
			cBoard[i][j]=freeSquare;
	for(Ship *s:ships)                 //place each ship randomly, ensuring a good placement. 
	{
		char orientation;
		int size=s->getArmor();
		Coord cr;

		do
		{
		orientation=(getRand()%2==0)?'h':'v';
		cr.setX(getRand());
		cr.setY(getRand());
		//cout<<cr.getX()<<' '<<cr.getY()<<' '<<"orientation: "<<orientation<<" validCoord? "<<isGoodCoord(cr,orientation,size);
		//getline(cin,input);
		}while(!(isGoodCoord(cr,orientation,size)));
		
	switch(orientation)
		{
			case 'h':
				for(int i=0; i<size; i++)                                             //put the coords on the map
					cBoard[cr.getX()][cr.getY()+i]=s->getCharacter();

			break;
			default:
				for(int i=0; i<size; i++)                                             
					cBoard[cr.getX()+i][cr.getY()]=s->getCharacter();  

		}
	}
		printGrid();//output to the file. 

}
int Computer::getRand()
{
return(system("RandomNumberExecutable.exe"));

}


bool Computer::isGoodCoord(Coord& cr, char orientation, int size)
{
	bool flag=true;
	if(cr.getX()>9 || cr.getX()<0 ||cr.getY()>9 || cr.getY()<0 || cBoard[cr.getX()][cr.getY()]!=freeSquare)
	{
		//cout<<"in the first if, bad condition, flag is false"<<endl;
		//printGrid();
		flag=false;
	}
	if(flag)
	{
		switch(orientation)
		{
			case 'h': //horizontal was chosen
				if(cr.getY()+size>10)
					flag=false;
				for(int i=1; i<size && flag; i++)
						if(cBoard[cr.getX()][cr.getY()+i]!=freeSquare)
							flag=false;
			break;
			default://vertical was chosen
				if(cr.getX()+size>10)
					flag=false;
				for(int i=1; i<size && flag; i++)
						if(cBoard[cr.getX()+i][cr.getY()]!=freeSquare)
							flag=false;
		}
	}
	return flag;
}
void Computer::printGrid()
{
	fstream fout;
	string line;
	fout.open("oppGrid.txt",ios::out);
	if(fout)
	{
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
			{
				fout<<cBoard[i][j]<<' ';
				//cout<<cBoard[i][j]<<' ';
			}
			fout<<'\n';
			//cout<<'\n';
			
		}
		fout.close();
	}
	else
		cout<<"fileError."<<endl;
	
}


//the computer will send a shot to player, the player
//object will process the coordinate and update its own total. 
bool Computer::checkShot(int r, int c)
{
	cout<<"the thing at that square is: "<<cBoard[r][c]<<endl;
return ( (cBoard[r][c]!=hit && cBoard[r][c]!=miss) && (!(r<0||r>9)) && (!(c<0||c>9))   );
}
char Computer::tellShot(int r, int c)
{
	char hitOrMiss;
	if(cBoard[r][c]=='B'||cBoard[r][c]=='F'||cBoard[r][c]=='C'||cBoard[r][c]=='S'||cBoard[r][c]=='D')
	{
		hitOrMiss=hit;
		cout<<"Hit!"<<endl;
		totalLife--;
		for(Ship *s:ships)
		{
			if(s->getCharacter()==cBoard[r][c])
			{
				s->damage();
				if(s->isSunk())
					std::cout<<"You sank opponent's "<<s->getName()<<"!"<<endl;
			}
		}
		cBoard[r][c]=hit;
	}
	else
	{
		hitOrMiss=miss;
		cout<<"Miss!"<<endl;
		cBoard[r][c]=miss;
	}
	return hitOrMiss;
}
Coord Computer::shoot()
{
	
	Coord shot(getRand(),getRand());
	return shot;
}
