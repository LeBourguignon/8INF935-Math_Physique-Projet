#include "GenerateurFlottabiliteCuboide.h"

#include <vector>

GenerateurFlottabiliteCuboide::GenerateurFlottabiliteCuboide(Vecteur3D dimensionCuboide, double niveauLiquide, double densiteLiquide)
	: dimensionCuboide(dimensionCuboide), niveauLiquide(niveauLiquide), densiteLiquide(densiteLiquide)
{
}

void GenerateurFlottabiliteCuboide::actualiserForce(CorpsRigide* corps)
{
    double dx = dimensionCuboide.x / 2;
    double dy = dimensionCuboide.y / 2;
    double dz = dimensionCuboide.z / 2;

    std::array<Vecteur3D, 8> sommets = {
        Vecteur3D( dx, dy, dz),
        Vecteur3D( dx, dy,-dz),
        Vecteur3D( dx,-dy, dz),
        Vecteur3D( dx,-dy,-dz),
        Vecteur3D(-dx, dy, dz),
        Vecteur3D(-dx, dy,-dz),
        Vecteur3D(-dx,-dy, dz),
        Vecteur3D(-dx,-dy,-dz)
    };

    Matrix33 rotation(corps->orientation);

    double ySommetMax = std::numeric_limits<double>::min(), ySommetMin = std::numeric_limits<double>::max();

    for (auto& sommet : sommets) 
    {
        sommet = rotation * sommet;

        if (sommet.y > ySommetMax)
        {
            ySommetMax = sommet.y;
        }

        if (sommet.y < ySommetMin)
        {
            ySommetMin = sommet.y;
        }
    }

    double hauteurObjet = ySommetMax - ySommetMin;
    double volumeObjet = dimensionCuboide.x * dimensionCuboide.y * dimensionCuboide.z;

    double d = -(corps->position.y - this->niveauLiquide - hauteurObjet) / (2 * hauteurObjet);
    Vecteur3D force = Vecteur3D();
    if (d <= 0)
    {
        force.y = 0;
    }
    else if (d >= 1)
    {
        force.y = volumeObjet * this->densiteLiquide;
    }
    else
    {
        force.y = d * volumeObjet * this->densiteLiquide;
    }

    corps->ajouterForce(force);
}
