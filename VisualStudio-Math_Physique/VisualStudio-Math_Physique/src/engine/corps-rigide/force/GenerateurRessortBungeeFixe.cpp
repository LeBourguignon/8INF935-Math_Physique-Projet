#include "GenerateurRessortBungeeFixe.h"

GenerateurRessortBungeeFixe::GenerateurRessortBungeeFixe(Vecteur3D attacheLocale, Vecteur3D autreAttache, double k, double l0)
    : attacheLocale(attacheLocale), autreAttache(autreAttache), k(k), l0(l0)
{
}

void GenerateurRessortBungeeFixe::actualiserForce(CorpsRigide* corps)
{
    Matrix34 mat1 = corps->transformMatrix;
    Vecteur3D attache1 = mat1 * this->attacheLocale;
    Vecteur3D attache2 = autreAttache;
    Vecteur3D distance = attache1 - attache2;
    if (distance.norme() > this->l0) {
        Vecteur3D force = distance.direction() * (-this->k * (distance.norme() - this->l0));
        corps->ajouterForcePositionRelative(force, this->attacheLocale);
    }
}