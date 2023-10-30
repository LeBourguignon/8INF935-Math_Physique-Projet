#ifndef __QUATERNION_H__
#define __QUATERNION_H__

#include "Vecteur3D.h"

class Quaternion
{
public:
	double w, i, j, k;

	Quaternion(double w, double i, double j, double k);
	Quaternion(Vecteur3D vecteur, double angle);

	void normalise();

	Quaternion operator+(const double value);
	Quaternion operator*(const double value);

	Quaternion operator+(const Quaternion& other);
	Quaternion operator-(const Quaternion& other);
	Quaternion operator*(const Quaternion& other);

	Quaternion operator*(const Vecteur3D& vecteur);

	void rotationParVecteur(const Vecteur3D& vecteur);

	void actualisationParVelociteAngulaire(const Vecteur3D& rotation, float duration);
};

#endif