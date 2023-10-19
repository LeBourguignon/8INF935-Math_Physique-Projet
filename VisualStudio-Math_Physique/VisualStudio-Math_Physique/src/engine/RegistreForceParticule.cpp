#include "RegistreForceParticule.h"

RegistreForceParticule::RegistreForceParticule()
{
    this->registre = Registre();
}

void RegistreForceParticule::ajouterForceParticule(Particule *particule, GenerateurForceParticule *generateur)
{
    struct EntreeForceParticule e = {particule, generateur};
    this->registre.push_back(e);
}

void RegistreForceParticule::actualiserForce(float duration)
{
    for (int i=0; i<this->registre.size(); i+=1){
        this->registre[i].generateurForce->actualiserForce(this->registre[i].particule, duration);
    }
}