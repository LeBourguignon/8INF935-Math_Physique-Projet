#include "Cuboide.h"

Cuboide::Cuboide(Vecteur3D size)
	: Cuboide(Vecteur3D(), Quaternion(), Vecteur3D(), Vecteur3D(), 0, size)
{
}

Cuboide::Cuboide(Vecteur3D position, Quaternion orientation, double masse, Vecteur3D size)
	: Cuboide(position, orientation, Vecteur3D(), Vecteur3D(), masse, size)
{
}

Cuboide::Cuboide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, double masse, Vecteur3D size)
	: CorpsRigide(position, orientation, velocite, velociteAngulaire, masse), size(size)
{
}
