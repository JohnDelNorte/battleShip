#ifndef CRD_H
#define CRD_H
class Coord
{
	public:
	void setX(int i){x=i;}
	void setY(int i){y=i;}
	int getX(){return x;}
	int getY(){return y;}
	Coord(int r=-1, int c=-1)
		:x(r),y(c)
	{
		
	}
	
	private:
	int x=-1;
	int y=-1;
};
#endif