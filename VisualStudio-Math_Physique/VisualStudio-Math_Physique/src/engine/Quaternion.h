#ifndef __QUATERNION_H__
#define __QUATERNION_H__

#include "Vecteur3D.h"

class Quaternion
{
public:
	double w, x, y, z;

	Quaternion();
	Quaternion(Vecteur3D vecteur, double angle);
	Quaternion(double w, double x, double y, double z);

	void normalise();

	Quaternion operator+(const Quaternion& other);
	Quaternion operator-(const Quaternion& other);
	Quaternion operator*(const Quaternion& other);

	Quaternion operator*(const Vecteur3D& vecteur);

	void rotationParVecteur(const Vecteur3D& vecteur);

	void actualisationParVelociteAngulaire(const Vecteur3D& rotation, float duration);
};

#endif