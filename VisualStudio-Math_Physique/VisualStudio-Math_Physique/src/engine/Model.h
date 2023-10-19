#ifndef __MODEL_H__
#define __MODEL_H__

#include <vector>

#include "Particule.h"

// Particule à temps de vie
struct TTLParticule {
	Particule* particule;
	float ttl;
};

// Liste de particules à temps de vie
using TTLParticules = std::vector<TTLParticule>;

// Model physique
class Model
{
private:
	TTLParticules ttlParticules;

public:
	// Initilisation du model
	Model();

	// Ajout d'une particule et de son temps de vie dans le model
	void ajouterTTLParticule(Particule* particule, float ttl);
	// Liste des particules du model
	TTLParticules getTTLParticules();

	// Actualisation du model d'un dt
	void actualiser(float duration);

	// Desctruction du model
	~Model();
};

#endif