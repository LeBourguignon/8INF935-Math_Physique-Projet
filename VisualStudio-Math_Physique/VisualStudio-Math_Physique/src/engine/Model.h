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
	// Initilisation du model
	Model();

	// Ajout d'une particule et de son temps de vie dans le model
	void addParticule(Particule* particule, float ttl);
	// Actualisation du model d'un dt
	void actualiser(float deltaTime);

	// Liste des particules du model
	std::vector<Particule*>& getParticules();

	// Desctruction du model
	~Model();
};

#endif