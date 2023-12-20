#include "GenerateurContactCorpsRigide.h"

GenerateurContactCorpsRigide::GenerateurContactCorpsRigide(CorpsRigide* corpsRigides[2], const double& restitution)
    : GenerateurContactCorpsRigide(corpsRigides[0], corpsRigides[1], restitution)
{
}

GenerateurContactCorpsRigide::GenerateurContactCorpsRigide(CorpsRigide* corpsRigide0, CorpsRigide* corpsRigide1, const double& restitution)
    : restitution(restitution)
{
    this->corpsRigides[0] = corpsRigide0;
    this->corpsRigides[1] = corpsRigide1;
}

void GenerateurContactCorpsRigide::ajouterContact(Contacts& contacts, unsigned int limit)
{
	if (contacts.size() < limit)
	{
        std::vector<Vecteur3D> sommetsCorpsRigide0(this->corpsRigides[0]->forme.vertices);
        std::vector<Vecteur3D> sommetsCorpsRigide1(this->corpsRigides[1]->forme.vertices);

        for (auto& sommet : sommetsCorpsRigide0)
        {
            sommet = this->corpsRigides[0]->transformMatrix * sommet;
        }
        for (auto& sommet : sommetsCorpsRigide1)
        {
            sommet = this->corpsRigides[1]->transformMatrix * sommet;
        }

        std::vector<Vecteur3D> outIntersectionPoints;

        if (this->isCollision(sommetsCorpsRigide0, sommetsCorpsRigide1, outIntersectionPoints))
        {
            Vecteur3D pointContact;
            for (auto& outIntersectionPoint : outIntersectionPoints)
            {
                pointContact = pointContact + outIntersectionPoint;
            }

            pointContact = pointContact / outIntersectionPoints.size(); // pointContact



            Vecteur3D rayVector = this->corpsRigides[1]->position - this->corpsRigides[0]->position; // 0 -> 1

            Vecteur3D outIntersectionPoint0(DBL_MAX / 2, DBL_MAX / 2, DBL_MAX / 2), outIntersectionPoint1(DBL_MAX / 2, DBL_MAX / 2, DBL_MAX / 2);

            std::array<Vecteur3D, 3> outIntersectionTriangle0, outIntersectionTriangle1;

            for (auto& indice0 : this->corpsRigides[0]->forme.indices) // 0
            {
                std::array<Vecteur3D, 3> triangle0({ sommetsCorpsRigide0[indice0[0]], sommetsCorpsRigide0[indice0[1]], sommetsCorpsRigide0[indice0[2]] });

                Vecteur3D outIntersectionPoint;

                if (RayIntersectsTriangle(pointContact - (rayVector * 0.1f), rayVector * 2.0f, triangle0, outIntersectionPoint))
                {
                    if ((outIntersectionPoint - pointContact).norme() < (outIntersectionPoint0 - pointContact).norme())
                    {
                        outIntersectionPoint0 = outIntersectionPoint;

                        outIntersectionTriangle0[0] = triangle0[0];
                        outIntersectionTriangle0[1] = triangle0[1];
                        outIntersectionTriangle0[2] = triangle0[2];
                    }
                }
            }

            for (auto& indice1 : this->corpsRigides[1]->forme.indices) // 1
            {
                std::array<Vecteur3D, 3> triangle1({ sommetsCorpsRigide1[indice1[0]], sommetsCorpsRigide1[indice1[1]], sommetsCorpsRigide1[indice1[2]] });

                Vecteur3D outIntersectionPoint;

                if (RayIntersectsTriangle(pointContact + (rayVector * 0.1f), -rayVector * 2, triangle1, outIntersectionPoint))
                {
                    if ((outIntersectionPoint - pointContact).norme() < (outIntersectionPoint1 - pointContact).norme())
                    {
                        outIntersectionPoint1 = outIntersectionPoint;

                        outIntersectionTriangle1[0] = triangle1[0];
                        outIntersectionTriangle1[1] = triangle1[1];
                        outIntersectionTriangle1[2] = triangle1[2];
                    }
                }
            }          

            double centering0 = std::min({
                (outIntersectionTriangle0[0] - outIntersectionPoint0).norme(), 
                (outIntersectionTriangle0[1] - outIntersectionPoint0).norme(), 
                (outIntersectionTriangle0[2] - outIntersectionPoint0).norme() 
                });

            double centering1 = std::min({
                (outIntersectionTriangle1[0] - outIntersectionPoint1).norme(),
                (outIntersectionTriangle1[1] - outIntersectionPoint1).norme(),
                (outIntersectionTriangle1[2] - outIntersectionPoint1).norme()
                });

            Vecteur3D normalContact; // normalContact
            
            if (centering0 > centering1)
            {
                Vecteur3D u = outIntersectionTriangle0[1] - outIntersectionTriangle0[0];
                Vecteur3D v = outIntersectionTriangle0[2] - outIntersectionTriangle0[0];

                normalContact = (u % v).direction();
            }
            else
            {
                Vecteur3D u = outIntersectionTriangle1[1] - outIntersectionTriangle1[0];
                Vecteur3D v = outIntersectionTriangle1[2] - outIntersectionTriangle1[0];

                normalContact = (u % v).direction();
            }

            if (normalContact * (pointContact - this->corpsRigides[0]->position) > 0.0f)
                normalContact = -normalContact;

            double penetration = (outIntersectionPoint1 - outIntersectionPoint0).norme(); // penetration

            contacts.push_back(new Contact(DonneeContact(this->corpsRigides, this->restitution, penetration, pointContact, normalContact.direction())));
        }
	}
}

bool GenerateurContactCorpsRigide::isCollision(const std::vector<Vecteur3D>& sommetsCorpsRigide0, const std::vector<Vecteur3D>& sommetsCorpsRigide1, std::vector<Vecteur3D>& outIntersectionPoints)
{
    bool isCollision = false;

    for (auto& indice0 : this->corpsRigides[0]->forme.indices)
    {
        std::array<Vecteur3D, 3> triangle0({ sommetsCorpsRigide0[indice0[0]], sommetsCorpsRigide0[indice0[1]], sommetsCorpsRigide0[indice0[2]] });

        for (auto& indice1 : this->corpsRigides[1]->forme.indices)
        {
            std::array<Vecteur3D, 3> triangle1({ sommetsCorpsRigide1[indice1[0]], sommetsCorpsRigide1[indice1[1]], sommetsCorpsRigide1[indice1[2]] });

            for (int i = 0; i < 3; i++)
            {
                Vecteur3D rayOrigin, rayVector, outIntersectionPoint;

                rayOrigin = {
                    triangle0[i].x,
                    triangle0[i].y,
                    triangle0[i].z
                };

                rayVector = {
                    triangle0[(i + 1) % 3].x - triangle0[i].x,
                    triangle0[(i + 1) % 3].y - triangle0[i].y,
                    triangle0[(i + 1) % 3].z - triangle0[i].z
                };

                if (RayIntersectsTriangle(rayOrigin, rayVector, triangle1, outIntersectionPoint))
                {
                    isCollision = true;
                    outIntersectionPoints.push_back(outIntersectionPoint);
                }
                    

                rayOrigin = {
                    triangle1[i].x,
                    triangle1[i].y,
                    triangle1[i].z
                };

                rayVector = {
                    triangle1[(i + 1) % 3].x - triangle1[i].x,
                    triangle1[(i + 1) % 3].y - triangle1[i].y,
                    triangle1[(i + 1) % 3].z - triangle1[i].z
                };

                if (RayIntersectsTriangle(rayOrigin, rayVector, triangle0, outIntersectionPoint))
                {
                    isCollision = true;
                    outIntersectionPoints.push_back(outIntersectionPoint);
                }
            }
        }
    }
    return isCollision;
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