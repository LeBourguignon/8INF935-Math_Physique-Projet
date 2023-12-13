#include "Cuboide.h"

Cuboide::Cuboide()
	: Cuboide(Vecteur3D(), 0)
{
}

Cuboide::Cuboide(Vecteur3D dimension, double masse)
	: Cuboide(dimension, masse, Vecteur3D(), Quaternion())
{
}

Cuboide::Cuboide(Vecteur3D dimension, double masse, Vecteur3D position, Quaternion orientation)
	: Cuboide(dimension, masse, position, orientation, Vecteur3D(), Vecteur3D())
{
}

Cuboide::Cuboide(Vecteur3D dimension, double masse, Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire)
	: CorpsRigide(getForme(dimension), masse, getTenseurInertie(dimension, masse), position, orientation, velocite, velociteAngulaire), dimension(dimension)
{
}

Forme Cuboide::getForme(Vecteur3D dimension)
{
	double dx = dimension.x / 2;
	double dy = dimension.y / 2;
	double dz = dimension.z / 2;

	std::vector<Vecteur3D> vertices({
		Vecteur3D(-dx,-dy, dz),
		Vecteur3D(-dx,-dy,-dz),
		Vecteur3D( dx,-dy,-dz),
		Vecteur3D( dx,-dy, dz),
		Vecteur3D(-dx, dy, dz),
		Vecteur3D(-dx, dy,-dz),
		Vecteur3D( dx, dy,-dz),
		Vecteur3D( dx, dy, dz)
		});

	std::vector<std::array<int, 3>> indices({
		{0, 1, 2},
		{0, 2, 3},
		{0, 4, 7},
		{0, 7, 3},
		{3, 7, 6},
		{3, 6, 2},
		{2, 6, 5},
		{2, 5, 1},
		{1, 5, 4},
		{1, 4, 0},
		{4, 5, 6},
		{4, 6, 7}
		});

	return Forme(vertices, indices);
}

Matrix33 Cuboide::getTenseurInertie(Vecteur3D dimension, double masse)
{
	return Matrix33(std::array<std::array<double, 3>, 3>({
		{(1.0 / 12.0) * masse * (dimension.y * dimension.y + dimension.z * dimension.z), 0, 0},
		{0, (1.0 / 12.0) * masse * (dimension.x * dimension.x + dimension.z * dimension.z), 0},
		{0, 0, (1.0 / 12.0) * masse * (dimension.y * dimension.y + dimension.x * dimension.x)}
	}));
}
