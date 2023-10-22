#include "ContactParticules.h"

void ContactParticules::resoudre(float duration)
{
	for (auto contactParticule : *this)
	{
		contactParticule->resoudre(duration);
	}
}

void ContactParticules::deleteContactParticules()
{
	for (auto contactParticule : *this)
	{
		delete contactParticule;
	}
	this->~ContactParticules();
}