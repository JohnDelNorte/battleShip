#ifndef CRU_H
#define CRU_H


#include"Ship.h"
#include"Coord.h"

class Cruiser: public Ship
{
public:
virtual void rotate() override;
virtual std::string getName() override{return "Cruiser";}
~Cruiser();
Cruiser();


private:

};

#endif
