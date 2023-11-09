#include "Cuboides.h"

void Cuboides::actualiser(double duration)
{
	for (auto cuboide : *this)
	{
		cuboide->actualiser(duration);
	}
}

void Cuboides::deleteCuboides()
{
	for (auto cuboide : *this)
	{
		delete cuboide;
	}
	this->~Cuboides();
}
