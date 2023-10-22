#include "GenerateursContactParticule.h"

void GenerateursContactParticule::ajouterContact(ContactParticules& contacts, unsigned int limit)
{
	for (auto generateurContact : *this) {
		generateurContact->ajouterContact(contacts, limit);
	}
}
