#include "Quaternion.h"
#include <cmath>

Quaternion::Quaternion()
	: Quaternion(1, 0, 0, 0)
{
}

Quaternion::Quaternion(double w, double x, double y, double z)
	: w(w), x(x), y(y), z(z)
{
	this->normalise();
}

Quaternion::Quaternion(Vecteur3D vecteur, double angle)
	: Quaternion(cos(angle / 2), sin(angle / 2) * vecteur.x, sin(angle / 2) * vecteur.y, sin(angle / 2) * vecteur.z)
{
}


void Quaternion::normalise()
{
	double magnitude = sqrt(w * w + x * x + y * y + z * z);

	if (magnitude == 0)
		return;

	this->w /= magnitude;
	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;
}



Quaternion Quaternion::operator+(const Quaternion& other)
{
	return Quaternion(
		this->w + other.w,
		this->x + other.x,
		this->y + other.y,
		this->z + other.z
	);
}

Quaternion Quaternion::operator-(const Quaternion& other)
{
	return Quaternion(
		this->w - other.w,
		this->x - other.x,
		this->y - other.y,
		this->z - other.z
	);
}

Quaternion Quaternion::operator*(const Quaternion& other)
{
	return Quaternion(
		this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z,
		this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y,
		this->w * other.y + this->y * other.w + this->z * other.x - this->x * other.z,
		this->w * other.z + this->z * other.w + this->x * other.y - this->y * other.x
	);
}


Quaternion Quaternion::operator*(const Vecteur3D& vecteur)
{
	return *this * Quaternion(0, vecteur.x, vecteur.y, vecteur.z);
}


void Quaternion::rotationParVecteur(const Vecteur3D& vecteur)
{
	*this = *this * vecteur;
	this->normalise();
}


void Quaternion::actualisationParVelociteAngulaire(const Vecteur3D& rotation, float duration)
{
	*this = *this + (*this * (rotation * (double)(duration / 2)));
	this->normalise();
}
