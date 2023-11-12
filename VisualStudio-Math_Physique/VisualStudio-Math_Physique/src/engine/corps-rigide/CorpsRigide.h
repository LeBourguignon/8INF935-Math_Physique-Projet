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

	CorpsRigide();
	CorpsRigide(Vecteur3D position, Quaternion orientation, double masse);
	CorpsRigide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, double masse);

	void actualiser(double duration);
	double getMass();
	Matrix34 getTransformMatrix() const;
	void ajouterForce(const Vecteur3D& force);
	void ajouterForcePosition(const Vecteur3D& force, const Vecteur3D& position);
	void ajouterForcePositionRelative(const Vecteur3D& force, const Vecteur3D& positionRelative);
	void reinitialiserAccumulateur();
};

#endif