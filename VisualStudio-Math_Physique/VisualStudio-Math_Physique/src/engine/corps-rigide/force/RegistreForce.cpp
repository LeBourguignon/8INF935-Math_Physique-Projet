#include "RegistreForce.h"

RegistreForce::RegistreForce()
{
    this->registre = Registre();
}

void RegistreForce::ajouterForce(CorpsRigide *corps, GenerateurForce *generateur)
{
    struct Force force = {corps, generateur};
    this->registre.push_back(force);
}

void RegistreForce::actualiserForce()
{
    for (auto& force: this->registre)
    {
        force.generateurForce->actualiserForce(force.corps);
    }
}

void RegistreForce::deleteForce()
{
    for (auto& force : this->registre)
    {
        delete force.generateurForce;
    }
    this->~RegistreForce();
}
