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
	: Cuboide(position, orientation, velocite, velociteAngulaire, Vecteur3D(), Vecteur3D(), masse, dimension)
{
}

Cuboide::Cuboide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, Vecteur3D acceleration, Vecteur3D accelerationAngulaire, double masse, Vecteur3D dimension)
	: CorpsRigide(position, orientation, velocite, velociteAngulaire, acceleration, accelerationAngulaire, masse, getTenseurInertie(masse, dimension)), dimension(dimension)
{
}

Matrix33 Cuboide::getTenseurInertie(double masse, Vecteur3D dimension)
{
	return Matrix33(std::array<std::array<double, 3>, 3>({
		{(1.0 / 12.0) * masse * (dimension.y * dimension.y + dimension.z * dimension.z), 0, 0},
		{0, (1.0 / 12.0) * masse * (dimension.x * dimension.x + dimension.z * dimension.z), 0},
		{0, 0, (1.0 / 12.0) * masse * (dimension.y * dimension.y + dimension.x * dimension.x)}
	}));
}
