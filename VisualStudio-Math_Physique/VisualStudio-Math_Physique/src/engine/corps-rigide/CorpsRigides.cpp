#include "CorpsRigides.h"

void CorpsRigides::actualiser(double duration)
{
	for (auto corpsRigide : *this)
	{
		corpsRigide->actualiser(duration);
	}
}

void CorpsRigides::deleteCorpsRigides()
{
	for (auto corpsRigide : *this)
	{
		delete corpsRigide;
	}
	this->~CorpsRigides();
}
