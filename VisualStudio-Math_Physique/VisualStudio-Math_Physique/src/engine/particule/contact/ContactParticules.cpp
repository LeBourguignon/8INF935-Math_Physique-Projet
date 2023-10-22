#include "ContactParticules.h"

void ContactParticules::resoudre(float duration)
{
	for (auto contactParticule : *this)
	{
		contactParticule->resoudre(duration);
	}
}
