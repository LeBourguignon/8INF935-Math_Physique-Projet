#include "ContactParticule.h"

void ContactParticule::resoudreVelocite()
{
	Vecteur3D vs = contactNormal * getVelociteRelative();
	float k = (vs * contactNormal) * (restitution + 1.0f) / (this->particules[0]->inverseMasse + this->particules[1]->inverseMasse);

	this->particules[0]->velocite = this->particules[0]->velocite - (contactNormal * (k * this->particules[0]->inverseMasse));
	this->particules[1]->velocite = this->particules[1]->velocite + (contactNormal * (k * this->particules[1]->inverseMasse));
}

void ContactParticule::resoudreInterpenetration()
{
	this->particules[0]->position = this->particules[0]->position + (contactNormal * (penetration * this->particules[0]->inverseMasse / (this->particules[0]->inverseMasse + this->particules[1]->inverseMasse)));
	this->particules[1]->position = this->particules[1]->position + (contactNormal * (penetration * this->particules[1]->inverseMasse / (this->particules[0]->inverseMasse + this->particules[1]->inverseMasse)));
}

ContactParticule::ContactParticule(Particule* particules[2], float restitution, float penetration)
{
	this->particules[0] = particules[0];
	this->particules[1] = particules[1];

	this->restitution = restitution;
	this->penetration = penetration;

	this->contactNormal = (this->particules[0]->position - this->particules[1]->position).direction();

	if (this->particules[0]->inverseMasse == 0 && this->particules[1]->inverseMasse == 0) {
		std::cout << "Erreur : Collision entre deux particules à masse infini";
		// Je sais pas quoi faire dans ce cas... ça va faire boom!
	}
}

float ContactParticule::getVelociteRelative()
{
	return (this->particules[0]->velocite - this->particules[1]->velocite).norme();
}

void ContactParticule::resoudre(float duration)
{
	resoudreVelocite();
	resoudreInterpenetration();
}