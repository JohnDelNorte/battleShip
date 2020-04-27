#ifndef FRI_H
#define FRI_H

#include"Ship.h"
class Frigate : public Ship
{
public:
	virtual void rotate() override;
	virtual std::string getName() override{return "Frigate";}
	~Frigate();
	Frigate();


private:


};
#endif