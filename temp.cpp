void Grid::place()
{
	for(Ship *s:ships)//for each ship
	{
		int firstGrid,secondGrid;                                       //inputs for the 1st coordinate
		int size=s->getArmor();  										//get how many squares it takes up
		char choice;
		bool flag=true;
		Coord coords[size];      										//create an array of that size. 
		//cout<<size<<endl;
		do
		{
			flag=true;
			cout<<"specify start coordinate for: " <<s->getName()<<endl;
			cin>>firstGrid>>secondGrid;                                     //get the starting coordinate for the current ship. 
			coords[0].setX(firstGrid);                                      //set x
			coords[0].setY(secondGrid);                                     //set y
			cout<<"Which orientation, verticle or horizontal? (v\\h): ";
			cin>>choice;
			isGoodCoord(startCoord);
			if(firstGrid>9 || firstGrid<0 ||secondGrid>9 || secondGrid<0 || board[firstGrid][secondGrid]!=freeSquare)
			{
				cout<<"invalid coordinate"<<endl;
				flag=false;
			}
			if(flag)
			{			
				cout<<"Which orientation, verticle or horizontal? (v\\h): ";
				cin>>choice;
				
				//horizontal orientation	
				if(choice=='h')
				{
					if(secondGrid+size>10)
						flag=false;
					for(int i=1; i<size && flag; i++)
					{
						if(board[firstGrid][secondGrid+i]==freeSquare)
						{
							coords[i].setX(firstGrid);
							coords[i].setY(secondGrid+i);
						}
						else 
						{
							flag=false;
							cout<<"overlapping"<<endl;
						}
					}
				}
				//veritcal orientation
				else if(choice=='v')
				{
					if(firstGrid+size>10)
						flag=false;
					for(int i=1; i<size && flag; i++)
					{
						if(board[firstGrid+i][secondGrid]==freeSquare)
						{
							coords[i].setX(firstGrid+i);
							coords[i].setY(secondGrid);
						}
						else
						{
							flag=false;
							cout<<"overlapping"<<endl;
						}
					}
				}
				else
					cout<<"bad entry"<<endl;
			}
	
		}while( (choice!='v' && choice!='h') || !flag);
		
		
		
		
		
		
		
		
		
		
		
		
		for(int i=0; i<size; i++)                                              //put the coords on the map
			{
				board[coords[i].getX()][coords[i].getY()]=s->getCharacter();           //before you place the ship, check if it is within bounds and not overlapping. 
			}
		
		
		
		changeFile();