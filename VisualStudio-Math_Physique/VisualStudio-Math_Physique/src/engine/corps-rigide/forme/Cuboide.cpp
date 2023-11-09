#include "Cuboide.h"

Cuboide::Cuboide(Vecteur3D dimension)
	: Cuboide(Vecteur3D(), Quaternion(), Vecteur3D(), Vecteur3D(), 0, dimension)
{
}

Cuboide::Cuboide(Vecteur3D position, Quaternion orientation, double masse, Vecteur3D dimension)
	: Cuboide(position, orientation, Vecteur3D(), Vecteur3D(), masse, dimension)
{
}

Cuboide::Cuboide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, double masse, Vecteur3D dimension)
	: CorpsRigide(position, orientation, velocite, velociteAngulaire, masse), dimension(dimension)
{
}
