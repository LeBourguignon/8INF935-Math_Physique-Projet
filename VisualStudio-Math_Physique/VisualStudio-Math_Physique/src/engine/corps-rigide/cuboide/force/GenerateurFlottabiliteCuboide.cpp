#include "GenerateurFlottabiliteCuboide.h"

#include <vector>

GenerateurFlottabiliteCuboide::GenerateurFlottabiliteCuboide(double niveauLiquide, double densiteLiquide)
    : niveauLiquide(niveauLiquide), densiteLiquide(densiteLiquide)
{
}

void GenerateurFlottabiliteCuboide::actualiserForce(CorpsRigide* corps)
{
    Cuboide* cuboide = dynamic_cast<Cuboide*>(corps);

    if (cuboide)
    {
        std::vector<Vecteur3D> sommets(cuboide->forme.vertices);
        Matrix33 rotation(corps->orientation);
        double ySommetMax = std::numeric_limits<double>::min(), ySommetMin = std::numeric_limits<double>::max();

        for (Vecteur3D& sommet : sommets) 
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
        double volumeObjet = cuboide->dimension.x * cuboide->dimension.y * cuboide->dimension.z;

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
}
