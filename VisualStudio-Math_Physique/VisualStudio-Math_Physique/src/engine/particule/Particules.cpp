#include "Particules.h"

void Particules::actualiser(double duration)
{
	for (auto particule : *this)
	{
		particule->actualiser(duration);
	}
}
