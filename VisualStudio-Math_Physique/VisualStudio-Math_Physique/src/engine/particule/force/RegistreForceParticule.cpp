#include "RegistreForceParticule.h"

RegistreForceParticule::RegistreForceParticule()
{
    this->registre = Registre();
}

void RegistreForceParticule::ajouterForceParticule(Particule *particule, GenerateurForceParticule *generateur)
{
    struct ForceParticule forceParticule = {particule, generateur};
    this->registre.push_back(forceParticule);
}

void RegistreForceParticule::actualiserForce(float duration)
{
    for (auto& forceParticule: this->registre)
    {
        forceParticule.generateurForce->actualiserForce(forceParticule.particule, duration);
    }
}

void RegistreForceParticule::deleteForce()
{
    for (auto& forceParticule : this->registre)
    {
        delete forceParticule.generateurForce;
    }
    this->~RegistreForceParticule();
}
