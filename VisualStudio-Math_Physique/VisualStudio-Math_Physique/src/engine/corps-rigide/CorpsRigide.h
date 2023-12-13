#ifndef __CORPS_RIGIDE_H__
#define __CORPS_RIGIDE_H__

#include <vector>

#include "../Vecteur3D.h"
#include "../Quaternion.h"
#include "../Matrix34.h"

struct Forme
{
	std::vector<Vecteur3D> vertices;
	std::vector<std::array<int, 3>> indices;

	Forme() : vertices(), indices() {}
	Forme(const std::vector<Vecteur3D>& vertices, const std::vector<std::array<int, 3>>& indices) : vertices(vertices), indices(indices) {}

	double getMaxRayon() {
		double maxRayon = std::numeric_limits<double>::min();
		for (auto& vertice : this->vertices) {
			double rayon = vertice.norme();
			if (rayon > maxRayon)
				maxRayon = rayon;
		}
	}
};

class CorpsRigide
{
public:
	Forme forme;
	double inverseMasse;
	Matrix33 inverseTenseurInertie;
	
	Vecteur3D position, velocite, acceleration, force;
	
	Quaternion orientation;
	Vecteur3D velociteAngulaire, accelerationAngulaire, torque;
	
	Matrix34 transformMatrix;	

	CorpsRigide();
	CorpsRigide(const Forme& forme, double masse, const Matrix33& tenseurInertie);
	CorpsRigide(const Forme& forme, double masse, const Matrix33& tenseurInertie, const Vecteur3D& position, const Quaternion& orientation);
	CorpsRigide(const Forme& forme, double masse, const Matrix33& tenseurInertie, const Vecteur3D& position, const Quaternion& orientation, const Vecteur3D& velocite, const Vecteur3D& velociteAngulaire);

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

protected:
	virtual void nothing() {} // fonction virtuelle pour que dynamic_cast puisse fonctionner correctement avec la hiérarchie de classes
};

#endif