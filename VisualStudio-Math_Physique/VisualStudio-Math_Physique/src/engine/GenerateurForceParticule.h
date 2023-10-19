#ifndef __GENERATEUR_FORCE_PARTICULE_H__
#define __GENERATEUR_FORCE_PARTICULE_H__

#include "Particule.h"

class GenerateurForceParticule
{
public:
    virtual void actualiserForce(Particule* particule, float duration) = 0;
};

#endif