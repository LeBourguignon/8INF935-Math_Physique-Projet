#ifndef __CUBOIDE_H__
#define __CUBOIDE_H__

#include "../CorpsRigide.h"

class Cuboide : public CorpsRigide
{
public:
	Vecteur3D dimension;

	Cuboide();
	Cuboide(Vecteur3D dimension, double masse);
	Cuboide(Vecteur3D dimension, double masse, Vecteur3D position, Quaternion orientation);
	Cuboide(Vecteur3D dimension, double masse, Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire);

	Forme getForme(Vecteur3D dimension);
	Matrix33 getTenseurInertie(Vecteur3D dimension, double masse);
};

#endif