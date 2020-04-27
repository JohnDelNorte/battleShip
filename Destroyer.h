#ifndef DES_H
#define DES_H


#include"Ship.h"

class Destroyer: public Ship
{
	public:
	virtual void rotate() override;
	virtual std::string getName() override{return "Destroyer";}
	~Destroyer();
	Destroyer();

	
	
	private:
};
#endif