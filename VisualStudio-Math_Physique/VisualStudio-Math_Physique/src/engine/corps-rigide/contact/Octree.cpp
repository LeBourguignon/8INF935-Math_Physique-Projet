#include "Octree.h"

bool Octree::CR_Into_Zone(Node zone, CorpsRigide cr)	
// Si le corps rigide est dans la zone, alors il faut le mettre dans la liste de possession de la branche/zone
{	
	bool result;
	if( result = test_CR_Into_Zone(zone, cr) )
		{ set_CR_Into_Zone_Liste(zone, cr); }
	return result;
}

bool Octree::test_CR_Into_Zone(Node zone, CorpsRigide cr)
// Calcul de vérification du corps rigide dans la zone
{
	return false;
}

void Octree::set_CR_Into_Zone_Liste(Node zone, CorpsRigide cr)
// Place le corps rigide dans la liste de possession de la branche/zone et vérifie si on a dépassé le nombre de corps rigide de la zone
{
	zone.liste_Corp_Rigide.push_back(cr);
	if (test_nb_CR(zone, cr)) {
		


	}
}

bool Octree::test_nb_CR(Node zone, CorpsRigide cr)
{
	return false;
}
