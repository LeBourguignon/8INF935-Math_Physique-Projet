#include "LienParticule.h"

float LienParticule::longueurActuelle() const
{
	return (particules[0]->position - particules[1]->position).norme();
}
