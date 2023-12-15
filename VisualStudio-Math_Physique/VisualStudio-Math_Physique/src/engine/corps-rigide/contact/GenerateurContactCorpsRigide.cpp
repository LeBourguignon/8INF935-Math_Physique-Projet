#include "GenerateurContactCorpsRigide.h"

GenerateurContactCorpsRigide::GenerateurContactCorpsRigide(CorpsRigide* corpsRigides[2])
{
	this->corpsRigides[0] = corpsRigides[0];
	this->corpsRigides[1] = corpsRigides[1];
}

void GenerateurContactCorpsRigide::ajouterContact(Contacts& contacts, unsigned int limit)
{
	if (contacts.size() < limit)
	{
        if (isCollision())
        {
            // TODO :
            // Calculer penetration, pointContact, normalContact;
            // Ajouter le contact : contacts.push_back(new Contact())
        }
	}
}

bool GenerateurContactCorpsRigide::isCollision()
{
    if ((corpsRigides[0]->forme.minRayon + corpsRigides[1]->forme.minRayon) < (corpsRigides[0]->position - corpsRigides[1]->position).norme())
        return true;


    
    std::vector<Vecteur3D> sommetsCorpsRigide0(this->corpsRigides[0]->forme.vertices);
    for (auto& sommet : sommetsCorpsRigide0)
    {
        sommet = this->corpsRigides[0]->transformMatrix * sommet;
    }

    std::vector<Vecteur3D> sommetsCorpsRigide1(this->corpsRigides[1]->forme.vertices);
    for (auto& sommet : sommetsCorpsRigide1)
    {
        sommet = this->corpsRigides[1]->transformMatrix * sommet;
    }



    for (auto& indice0 : this->corpsRigides[0]->forme.indices)
    {
        std::array<Vecteur3D, 3> triangle0({ sommetsCorpsRigide0[indice0[0]], sommetsCorpsRigide0[indice0[1]], sommetsCorpsRigide0[indice0[2]] });

        for (auto& indice1 : this->corpsRigides[1]->forme.indices)
        {
            std::array<Vecteur3D, 3> triangle1({ sommetsCorpsRigide1[indice1[0]], sommetsCorpsRigide1[indice1[1]], sommetsCorpsRigide1[indice1[2]] });

            for (int i = 0; i < 3; i++)
            {
                Vecteur3D rayOrigin = {
                    triangle0[i].x,
                    triangle0[i].y,
                    triangle0[i].z
                };

                Vecteur3D rayVector = {
                    triangle0[(i + 1) % 3].x - triangle0[i].x,
                    triangle0[(i + 1) % 3].y - triangle0[i].y,
                    triangle0[(i + 1) % 3].z - triangle0[i].z
                };

                Vecteur3D outIntersectionPoint;
                if (RayIntersectsTriangle(rayOrigin, rayVector, triangle1, outIntersectionPoint))
                    return true;

                Vecteur3D rayOrigin = {
                    triangle1[i].x,
                    triangle1[i].y,
                    triangle1[i].z
                };

                Vecteur3D rayVector = {
                    triangle1[(i + 1) % 3].x - triangle1[i].x,
                    triangle1[(i + 1) % 3].y - triangle1[i].y,
                    triangle1[(i + 1) % 3].z - triangle1[i].z
                };

                Vecteur3D outIntersectionPoint;
                if (RayIntersectsTriangle(rayOrigin, rayVector, triangle0, outIntersectionPoint))
                    return true;
            }
        }
    }



    return false;
}



bool RayIntersectsTriangle(Vecteur3D rayOrigin, Vecteur3D rayVector, std::array<Vecteur3D, 3>& inTriangle, Vecteur3D& outIntersectionPoint)
{
    const float EPSILON = 0.0000001;
    Vecteur3D vertex0 = inTriangle[0];
    Vecteur3D vertex1 = inTriangle[1];
    Vecteur3D vertex2 = inTriangle[2];
    Vecteur3D edge1, edge2, h, s, q;
    float a, f, u, v;
    edge1 = vertex1 - vertex0;
    edge2 = vertex2 - vertex0;
    h = rayVector % edge2;
    a = edge1 * h;
    if (a > -EPSILON && a < EPSILON)
        return false;    // Le rayon est parallèle au triangle.

    f = 1.0 / a;
    s = rayOrigin - vertex0;
    u = f * (s * h);
    if (u < 0.0 || u > 1.0)
        return false;
    q = s % edge1;
    v = f * (rayVector * q);
    if (v < 0.0 || u + v > 1.0)
        return false;

    // On calcule t pour savoir ou le point d'intersection se situe sur la ligne.
    float t = f * (edge2 * q);
    if (t > EPSILON) // Intersection avec le rayon
    {
        outIntersectionPoint = rayOrigin + rayVector * t;
        return true;
    }
    else // On a bien une intersection de droite, mais pas de rayon.
        return false;
}