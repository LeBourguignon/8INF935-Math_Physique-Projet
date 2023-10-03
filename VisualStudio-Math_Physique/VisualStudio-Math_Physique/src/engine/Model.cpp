#include "Model.h"

Model::Model()
{

}

void Model::addParticule(Particule* particule, float ttl)
{
	particules.push_back(particule);
	ttls.push_back(ttl);
}

void Model::actualiser(float deltaTime)
{
	for (int i = particules.size() - 1; i >= 0; i--)
	{
		ttls[i] -= deltaTime;
		if (ttls[i] < 0.0f)
		{
			Particule* particule = particules[i];
			ttls.erase(ttls.begin() + i);
			particules.erase(particules.begin() + i);
			delete particule;
		}
		else
		{
			particules[i]->integration(deltaTime);
		}
	}
}

std::vector<Particule*>& Model::getParticules()
{
	return particules;
}

Model::~Model()
{
	particules.~vector();
	ttls.~vector();
}
