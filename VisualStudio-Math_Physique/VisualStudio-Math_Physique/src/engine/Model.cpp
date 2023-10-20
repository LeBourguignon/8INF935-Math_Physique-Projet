#include "Model.h"

Model::Model()
{
}


void Model::ajouterTTLParticule(Particule* particule, float ttl)
{
	ttlParticules.push_back(TTLParticule(particule, ttl));
}

TTLParticules Model::getTTLParticules()
{
	return ttlParticules;
}


void Model::actualiser(float duration)
{
	// Phase 1
	for (int i = ttlParticules.size() - 1; i >= 0; i--)
	{
		ttlParticules[i].ttl -= duration;
		if (ttlParticules[i].ttl <= 0.0f)
		{
			Particule* particule = ttlParticules[i].particule;
			ttlParticules.erase(ttlParticules.begin() + i);
			delete particule;
		}
		else
		{
			ttlParticules[i].particule->actualiser(duration);
		}
	}

	// Phase 2
	// Générer les forces sur les particules
	// Intégration des particules
	// Génerer les contacts
	// Résoudre les contacts
}


Model::~Model()
{
	for (TTLParticule ttlParticule : ttlParticules)
	{
		delete ttlParticule.particule;
	}
	ttlParticules.~vector();
}
