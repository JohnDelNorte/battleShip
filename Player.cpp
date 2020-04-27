#include<fstream>
#include<string>
#include<iostream>
#include<iomanip>
#include<chrono>
#include<thread>
#include<sstream>
#include"Player.h"
using namespace std;

Player::Player()
{
	totalLife=s0->getArmor()+s1->getArmor()+s2->getArmor()+s3->getArmor()+s4->getArmor(); 

	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++)
		{
			board[i][j]=freeSquare;
			enBoard[i][j]=freeSquare;
		}
		changeFile();
}
void Player::changeFile()
{

	//pause for some time
	this_thread::sleep_for(chrono::seconds(2));
	system("cls");

	fstream fout("myGrid.txt",ios::out);
	if(fout)
	{
		fout<<"  0 1 2 3 4 5 6 7 8 9 "<<setfill(' ')<<setw(40)<<"0 1 2 3 4 5 6 7 8 9 "<<endl;
		cout<<"  0 1 2 3 4 5 6 7 8 9 "<<setfill(' ')<<setw(40)<<"0 1 2 3 4 5 6 7 8 9 "<<endl;
		for(int i=0; i<10; i++)
		{
			//fout<<static_cast<char>(65+i)<<' ';
			//cout<<static_cast<char>(65+i)<<' ';
			fout<<i<<' ';
			cout<<i<<' ';
			for(int j=0; j<10; j++)
			{
				fout<<board[i][j]<<' ';
				cout<<board[i][j]<<' ';
			}
			fout<<setfill(' ')<<setw(21);
			cout<<setfill(' ')<<setw(21);
			//cout<<static_cast<char>(65+i)<<' ';
			for(int j=0; j<10; j++)
			{
				fout<<enBoard[i][j]<<' ';
				cout<<enBoard[i][j]<<' ';
			}
			fout<<'\n';
			cout<<'\n';
		}
		fout.close();
	}
	else
		cout<<"file error"<<endl;

}
void Player::placeShips()
{
	for(Ship *s:ships)                                                      //for each ship
	{
		int firstGrid,secondGrid;                                           //inputs for the 1st coordinate
		int size=s->getArmor();  										    //get how many squares it takes up
		char choice;
		char bad;
		bool flag=true;

		stringstream ss;
		Coord startCoord;      										        //create an array of that size. 
		do
		{
			string input;
			cout<<"specify start coordinate for: " <<s->getName()<<endl;
			getline(cin,input);											//get the starting coordinate for the current ship. 
			ss<<input;
			ss>>firstGrid>>secondGrid;
			startCoord.setX(firstGrid);                                      //set x
			startCoord.setY(secondGrid);                                     //set y
			cout<<"Which orientation, verticle or horizontal? (v\\h): ";
			ss.clear();
			input.clear();
			getline(cin, input);
			ss<<input;
			ss>>choice;
			//cout<<startCoord.getX()<<' '<<startCoord.getY()<<' '<<choice<<' '<<size<<endl;
			//cout<<isGoodCoord(startCoord,choice,size);
		}while(!(isGoodCoord(startCoord,choice,size)));		                 //after this i know the chosen configuration was good. 

		switch(choice)
		{
			case 'h':
				for(int i=0; i<size; i++)                                             //put the coords on the map
					board[startCoord.getX()][startCoord.getY()+i]=s->getCharacter();

			break;
			default:
				for(int i=0; i<size; i++)                                             
					board[startCoord.getX()+i][startCoord.getY()]=s->getCharacter();  

		}
		//cout<<"end of switch"<<endl;
		changeFile();
	}
}

bool Player::isGoodCoord(Coord& c, char choice, int size)
{
	bool flag=true;
	if(c.getX()>9 || c.getX()<0 ||c.getY()>9 || c.getY()<0 || board[c.getX()][c.getY()]!=freeSquare)
		flag=false;
	if(flag)
	{
		switch(choice)
		{
			case 'h': //horizontal was chosen
				if(c.getY()+size>10)
					flag=false;
				for(int i=1; i<size && flag; i++)
						if(board[c.getX()][c.getY()+i]!=freeSquare)
							flag=false;
			break;
			default://vertical was chosen
				if(c.getX()+size>10)
					flag=false;
				for(int i=1; i<size && flag; i++)
						if(board[c.getX()+i][c.getY()]!=freeSquare)
							flag=false;
		}
	}
	return flag;
}


void Player::setFirst(bool b)
{
	first=b;
}

bool Player::checkShot(Coord shot)
{
	int r=shot.getX();
	int c=shot.getY();
	bool flag=false;
	if(board[r][c]!=hit && board[r][c]!=miss)
	{
		if(board[r][c]==freeSquare)
		{
			cout<<"computer missed"<<endl;
			board[r][c]=miss;
			flag=true;
			
		}
		else
		{
			cout<<"computer hit!"<<endl;
		for(Ship *s:ships)
		{
			if(s->getCharacter()==board[r][c])
			{
				s->damage();
				if(s->isSunk())
					std::cout<<"The enemy sank your "<<s->getName()<<"!"<<endl;
			}
		}
			board[r][c]=hit;
			totalLife--;
			flag=true;
		}
	}
	if(flag)
		changeFile();
	return flag;
	
}
void Player::updateGrid(char hOrM, int r, int c)
{
	//cout<<"hi from updateGrid"<<endl;

	enBoard[r][c]=hOrM;
	changeFile();
}