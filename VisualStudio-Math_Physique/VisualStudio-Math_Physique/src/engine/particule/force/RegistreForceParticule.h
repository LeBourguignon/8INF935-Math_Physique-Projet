#ifndef __REGISTRE_FORCE_PARTICULE_H__
#define __REGISTRE_FORCE_PARTICULE_H__

#include <vector>
#include "GenerateurForceParticule.h"

struct ForceParticule {
    Particule* particule;
    GenerateurForceParticule* generateurForce;
};

using RegistreParticule = std::vector<ForceParticule>;

class RegistreForceParticule
{
private:
    RegistreParticule registre;

public:
    RegistreForceParticule();

    void ajouterForceParticule(Particule* particule, GenerateurForceParticule* generateur);
    void actualiserForce(float duration);

    void deleteForce();
};

#endif