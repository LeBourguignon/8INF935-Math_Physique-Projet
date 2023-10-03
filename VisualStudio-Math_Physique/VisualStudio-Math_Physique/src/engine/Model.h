#ifndef __MODEL_H__
#define __MODEL_H__

#include <vector>

#include "Particule.h"

class Model
{
private:
	std::vector<Particule*> particules;
	std::vector<float> ttls;

public:
	Model();

	void addParticule(Particule* particule, float ttl);
	void actualiser(float deltaTime);

	std::vector<Particule*>& getParticules();

	~Model();
};

#endif