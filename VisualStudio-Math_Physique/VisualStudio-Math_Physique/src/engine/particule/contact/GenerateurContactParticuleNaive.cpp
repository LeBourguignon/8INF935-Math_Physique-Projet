#include "GenerateurContactParticuleNaive.h"

GenerateurContactParticuleNaive::GenerateurContactParticuleNaive(float longueurArete)
    : particules(particules), longueurArete(longueurArete)
{
}

GenerateurContactParticuleNaive::GenerateurContactParticuleNaive(Particules& particules, float longueurArete)
	: particules(particules), longueurArete(longueurArete)
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
            if (std::abs(distance.x) <= longueurArete && std::abs(distance.y) <= longueurArete && std::abs(distance.z) <= longueurArete)
            {
                Particule* particuleArray[2] = { particules[i], particules[j] };
                float penetration = ((distance.direction() * longueurArete).norme() - distance.norme() + (distance.direction() * longueurArete - distance).norme()) / 2;
                contacts.push_back(new ContactParticule(particuleArray, 0.5f, penetration, distance.direction()));
            }
        }
    }
}
