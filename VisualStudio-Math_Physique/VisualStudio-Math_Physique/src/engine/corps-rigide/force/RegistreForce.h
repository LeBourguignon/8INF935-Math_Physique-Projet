#ifndef __REGISTRE_FORCE_H__
#define __REGISTRE_FORCE_H__

#include <vector>
#include "GenerateurForce.h"

struct Force {
    CorpsRigide* corps;
    GenerateurForce* generateurForce;
};

using Registre = std::vector<Force>;

class RegistreForce
{
private:
    Registre registre;

public:
    RegistreForce();

    void ajouterForce(CorpsRigide* corps, GenerateurForce* generateur);
    void actualiserForce(float duration);

    void deleteForce();
};

#endif