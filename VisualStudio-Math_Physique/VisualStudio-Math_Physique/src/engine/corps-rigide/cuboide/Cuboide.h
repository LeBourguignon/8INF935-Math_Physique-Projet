#ifndef __CUBOIDE_H__
#define __CUBOIDE_H__

#include "../CorpsRigide.h"

class Cuboide : public CorpsRigide
{
public:
	Vecteur3D dimension;

	Cuboide(Vecteur3D dimension = Vecteur3D());
	Cuboide(Vecteur3D position, Quaternion orientation, double masse, Vecteur3D dimension = Vecteur3D());
	Cuboide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, double masse, Vecteur3D dimension = Vecteur3D());
	Cuboide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, Vecteur3D acceleration, Vecteur3D accelerationAngulaire, double masse, Vecteur3D dimension = Vecteur3D());

	Matrix33 getTenseurInertie(double masse, Vecteur3D dimension);
};

#endif