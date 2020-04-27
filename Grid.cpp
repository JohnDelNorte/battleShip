#include<fstream>
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include"Grid.h"
using namespace std;

Grid::Grid()
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
void Grid::changeFile()
{
	fstream fout("myGrid.txt",ios::out);
	if(fout)
	{
		fout<<"  0 1 2 3 4 5 6 7 8 9 "<<setfill(' ')<<setw(40)<<"0 1 2 3 4 5 6 7 8 9 "<<endl;
		for(int i=0; i<10; i++)
		{
			//fout<<static_cast<char>(65+i)<<' ';
			fout<<i<<' ';
			for(int j=0; j<10; j++)
			{
				fout<<board[i][j]<<' ';
			}
			fout<<setfill(' ')<<setw(21);
			for(int j=0; j<10; j++)
				fout<<enBoard[i][j]<<' ';
			fout<<'\n';
		}
		fout.close();
	}
	else
		cout<<"file error"<<endl;
	show();
}
void Grid::place()
{
	for(Ship *s:ships)                                                      //for each ship
	{
		int firstGrid,secondGrid;                                           //inputs for the 1st coordinate
		int size=s->getArmor();  										    //get how many squares it takes up
		char choice;
		bool flag=true;
		Coord startCoord;      										        //create an array of that size. 
		do
		{
			cout<<"specify start coordinate for: " <<s->getName()<<endl;
			cin>>firstGrid>>secondGrid;                                      //get the starting coordinate for the current ship. 
			startCoord.setX(firstGrid);                                      //set x
			startCoord.setY(secondGrid);                                     //set y
			cout<<"Which orientation, verticle or horizontal? (v\\h): ";
			cin>>choice;
			cout<<isGoodCoord(startCoord,choice,size);
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
		changeFile();
	}
}
void Grid::show()
{
	system("cls");
	fstream fin("myGrid.txt",ios::in);
	string line;
	if(fin)
	{
		while(getline(fin,line))
		{
			cout<<line<<endl;
		}
		fin.close();
	}
	else
		cout<<"file error"<<endl;

}
bool Grid::isGoodCoord(Coord& c, char choice, int size)
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
