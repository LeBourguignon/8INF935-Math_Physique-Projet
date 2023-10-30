#include "Quaternion.h"

Quaternion::Quaternion(double w, double i, double j, double k)
	: w(w), i(i), j(j), k(k)
{
	this->normalise();
}

Quaternion::Quaternion(Vecteur3D vecteur, double angle)
	: Quaternion(cos(angle / 2), sin(angle / 2) * vecteur.x, sin(angle / 2) * vecteur.y, sin(angle / 2) * vecteur.z)
{
}


void Quaternion::normalise()
{
	double magnitude = sqrt(w * w + i * i + j * j + k * k);

	if (magnitude == 0)
		return;

	this->w /= magnitude;
	this->i /= magnitude;
	this->j /= magnitude;
	this->k /= magnitude;
}


Quaternion Quaternion::operator+(const double value)
{
	return Quaternion(
		this->w + value,
		this->i + value,
		this->j + value,
		this->k + value
	);
}

Quaternion Quaternion::operator*(const double value)
{
	return Quaternion(
		this->w * value,
		this->i * value,
		this->j * value,
		this->k * value
	);
}


Quaternion Quaternion::operator+(const Quaternion& other)
{
	return Quaternion(
		this->w + other.w,
		this->i + other.i,
		this->j + other.j,
		this->k + other.k
	);
}

Quaternion Quaternion::operator-(const Quaternion& other)
{
	return Quaternion(
		this->w - other.w,
		this->i - other.i,
		this->j - other.j,
		this->k - other.k
	);
}

Quaternion Quaternion::operator*(const Quaternion& other)
{
	return Quaternion(
		this->w * other.w - this->i * other.i - this->j * other.j - this->k * other.k,
		this->w * other.i + this->i * other.w + this->j * other.k - this->k * other.j,
		this->w * other.j + this->j * other.w + this->k * other.i - this->i * other.k,
		this->w * other.k + this->k * other.w + this->i * other.j - this->j * other.i
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
	*this = *this + (*this * rotation * (duration / 2));
	this->normalise();
}
