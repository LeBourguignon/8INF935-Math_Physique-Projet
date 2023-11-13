#ifndef __GENERATEUR_FORCE_H__
#define __GENERATEUR_FORCE_H__

#include "../CorpsRigide.h"

class GenerateurForce
{
public:
    virtual void actualiserForce(CorpsRigide* corps) = 0;
};

#endif