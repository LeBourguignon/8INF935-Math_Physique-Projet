#include "GenerateurContactParticuleNaive.h"

GenerateurContactParticuleNaive::GenerateurContactParticuleNaive(double radius)
    : GenerateurContactParticuleNaive(particules, radius)
{
}

GenerateurContactParticuleNaive::GenerateurContactParticuleNaive(Particules& particules, double radius)
	: particules(particules), radius(radius)
{
}

void GenerateurContactParticuleNaive::ajouterParticule(Particule* particule)
{
    particules.push_back(particule);
}

void GenerateurContactParticuleNaive::ajouterContact(ContactParticules& contacts, unsigned int limit)
{
    for (int i = 0; i < particules.size() && contacts.size() < limit; ++i) {
        for (int j = i + 1; j < particules.size() && contacts.size() < limit; ++j) {
            Vecteur3D distance = particules[i]->position - particules[j]->position;
            if (distance.norme() <= (2 * radius))
            {
                Particule* particuleArray[2] = { particules[i], particules[j] };
                float penetration = 2 * radius - distance.norme();
                contacts.push_back(new ContactParticule(particuleArray, 0.5f, penetration, distance.direction()));
            }
        }
    }
}