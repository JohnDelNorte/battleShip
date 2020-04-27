#ifndef SUB_H
#define SUB_H


#include"Ship.h"

class Sub: public Ship
{
	public:
	virtual void rotate() override;
	virtual std::string getName() override{return "Sub";}
	~Sub();
	Sub();

	
	
	private:

};
#endif