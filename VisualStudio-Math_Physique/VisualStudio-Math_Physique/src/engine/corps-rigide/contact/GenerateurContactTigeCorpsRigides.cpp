#include "GenerateurContactTigeCorpsRigides.h"

GenerateurContactTigeCorpsRigides::GenerateurContactTigeCorpsRigides(CorpsRigide* corpsRigides[2], Vecteur3D localAttache[2], double longueur)
	: GenerateurContactLienCorpsRigides(corpsRigides, localAttache), longueur(longueur)
{
}

void GenerateurContactTigeCorpsRigides::ajouterContact(Contacts& contacts, unsigned int limit)
{
	Vecteur3D attache0 = corpsRigides[0]->transformMatrix * localAttache[0];
	Vecteur3D attache1 = corpsRigides[1]->transformMatrix * localAttache[1];
	Vecteur3D distance = attache1 - attache0;
	double longueurActuelle = distance.norme();

	if (contacts.size() < limit && longueurActuelle != longueur)
	{
		if (longueurActuelle > longueur) {
			contacts.push_back(new Contact(DonneeContact(corpsRigides, 1, longueurActuelle - longueur, (attache0 + attache1) / 2, distance.direction())));
		}
		else {
			contacts.push_back(new Contact(DonneeContact(corpsRigides, 1, longueur - longueurActuelle, (attache0 + attache1) / 2, -distance.direction())));
		}
	}
}
