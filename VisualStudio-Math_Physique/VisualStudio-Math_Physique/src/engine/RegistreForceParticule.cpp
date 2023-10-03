#include <vector>
#include "RegistreForceParticule.h"
#include "Particule.h"

RegistreForceParticule::RegistreForceParticule(){
    this->registre = Registre();
}

void RegistreForceParticule::ajouterEntree(Particule *p, GenerateurForceParticule *g){
    struct EntreeForceParticule e = {p, g};
    this->registre.push_back(e);
}

void RegistreForceParticule::actualiserForce(float duration){}