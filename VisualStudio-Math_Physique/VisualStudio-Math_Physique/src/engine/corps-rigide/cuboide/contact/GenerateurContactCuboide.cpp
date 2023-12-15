#include "GenerateurContactCuboide.h"

GenerateurContactCuboide::GenerateurContactCuboide(Cuboide* cuboides[2])
{
	this->cuboides[0] = cuboides[0];
	this->cuboides[1] = cuboides[1];
}

void GenerateurContactCuboide::ajouterContact(Contacts& contacts, unsigned int limit)
{
    if (contacts.size() < limit)
    {
        if (isCollision())
        {
            contacts.push_back(new Contact(getDonneeContact()));
        }
    }
}

bool GenerateurContactCuboide::isCollision()
{
    Vecteur3D distance(
        std::abs(cuboides[0]->position.x - cuboides[1]->position.x),
        std::abs(cuboides[0]->position.y - cuboides[1]->position.y),
        std::abs(cuboides[0]->position.z - cuboides[1]->position.z)
    );

    Vecteur3D sumDemiDimension(
        cuboides[0]->dimension.x + cuboides[1]->dimension.x,
        cuboides[0]->dimension.y + cuboides[1]->dimension.y,
        cuboides[0]->dimension.z + cuboides[1]->dimension.z
    );

    return distance.x < sumDemiDimension.x &&
        distance.y < sumDemiDimension.y &&
        distance.z < sumDemiDimension.z;
}

DonneeContact GenerateurContactCuboide::getDonneeContact()
{
    Vecteur3D contactNormal;
    float penetration = 0.0f;

    Vecteur3D distance = cuboides[1]->position - cuboides[0]->position;

    Vecteur3D halfSize0 = cuboides[0]->dimension / 2, halfSize1 = cuboides[1]->dimension / 2;

    Vecteur3D overlap({ 
        std::abs(distance.x) - (halfSize0.x + halfSize1.x),
        std::abs(distance.y) - (halfSize0.y + halfSize1.y),
        std::abs(distance.z) - (halfSize0.z + halfSize1.z) }
    );

    if (overlap.x < overlap.y && overlap.x < overlap.z) {
        contactNormal = Vecteur3D(std::copysign(1.0f, distance.x), 0.0f, 0.0f);
        penetration = (halfSize0.x + halfSize1.x) - std::abs(distance.x);
    }
    else if (overlap.y < overlap.z) {
        contactNormal = Vecteur3D(0.0f, std::copysign(1.0f, distance.y), 0.0f);
        penetration = (halfSize0.y + halfSize1.y) - std::abs(distance.y);
    }
    else {
        contactNormal = Vecteur3D(0.0f, 0.0f, std::copysign(1.0f, distance.z));
        penetration = (halfSize0.z + halfSize1.z) - std::abs(distance.z);
    }

    penetration = penetration > 0 ? penetration : 0;

    Vecteur3D contactPoint = (cuboides[1]->position + cuboides[0]->position) * 0.5f;

    CorpsRigide* corpsRigides[2] = { cuboides[0], cuboides[1] };

    return DonneeContact(corpsRigides, 0.5f, penetration, contactPoint, contactNormal);
}