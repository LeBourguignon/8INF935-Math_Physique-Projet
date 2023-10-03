#ifndef __REGISTRE_FORCE_PARTICULE_H__
#define __REGISTRE_FORCE_PARTICULE_H__

#include <vector>
#include "Particule.h"
#include "GenerateurForceParticule.h"

class RegistreForceParticule{
private:
    struct EntreeForceParticule{
        Particule *particule;
        GenerateurForceParticule *generateurForce;
    };
    using Registre = std::vector<EntreeForceParticule>;
    Registre registre;
public:
    RegistreForceParticule();
    void ajouterEntree(Particule*, GenerateurForceParticule*);
    void actualiserForce(float);
};

#endif