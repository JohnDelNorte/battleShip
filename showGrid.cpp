#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{	
	while(true)
	{
	fstream fout("myGrid.txt",ios::in);
	string line;
	if(fout)
	{
		while(getline(fout,line))
		{
			cout<<line<<endl;
		}
		fout.close();
		system("cls");
	}
	else
		cout<<"file error"<<endl;
	}
}