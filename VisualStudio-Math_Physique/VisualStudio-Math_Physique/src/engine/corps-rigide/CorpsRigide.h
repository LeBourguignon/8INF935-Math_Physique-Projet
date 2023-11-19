#ifndef __CORPS_RIGIDE_H__
#define __CORPS_RIGIDE_H__

#include "../Vecteur3D.h"
#include "../Quaternion.h"
#include "../Matrix34.h"

class CorpsRigide
{
public:
	double inverseMasse;
	Vecteur3D position, velocite, acceleration, force;
	
	Quaternion orientation;
	Vecteur3D velociteAngulaire, accelerationAngulaire, torque;
	
	Matrix34 transformMatrix;
	Matrix33 tenseurInertieInverse;

	CorpsRigide();
	CorpsRigide(Vecteur3D position, Quaternion orientation, double masse, Matrix33 tenseurInertie);
	CorpsRigide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, double masse, Matrix33 tenseurInertie);
	CorpsRigide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, Vecteur3D acceleration, Vecteur3D accelerationAngulaire, double masse, Matrix33 tenseurInertie);

	void actualiser(double duration);
	double getMass();

	void ajouterForce(const Vecteur3D& force);
	void ajouterTorque(const Vecteur3D& torque);

	void ajouterForcePosition(const Vecteur3D& force, const Vecteur3D& position);
	void ajouterForcePositionRelative(const Vecteur3D& force, const Vecteur3D& positionRelative);

private:
	Matrix33 tenseurInertieInverseLocal;

	void calculerDonneesDerivees();
	void reinitialiserAccumulateur();
};

#endif