#include "Particules.h"

void Particules::actualiser(double duration)
{
	for (auto particule : *this)
	{
		particule->actualiser(duration);
	}
}

void Particules::deleteParticules()
{
	for (auto particule : *this)
	{
		delete particule;
	}
	this->~Particules();
}
