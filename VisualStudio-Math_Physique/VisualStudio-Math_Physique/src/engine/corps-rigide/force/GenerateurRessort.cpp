#include "GenerateurRessort.h"

GenerateurRessort::GenerateurRessort(Vecteur3D attache, CorpsRigide* autreCorps, Vecteur3D autreCorpsAttache, double k, double l0)
    : attache(attache), autreCorps(autreCorps), autreCorpsAttache(autreCorpsAttache), k(k), l0(l0)
{
}

void GenerateurRessort::actualiserForce(CorpsRigide* corps)
{
    Matrix34 mat1 = corps->getTransformMatrix();
    Matrix34 mat2 = this->autreCorps->getTransformMatrix();
    Vecteur3D attache1 = mat1 * this->attache;
    Vecteur3D attache2 = mat2 * this->autreCorpsAttache;
    Vecteur3D distance = attache2 - attache1;
    Vecteur3D force = distance.direction() * (-this->k * (distance.norme() - this->l0));
    corps->ajouterForcePositionRelative(force, this->attache);
}