#include "CorpsRigide.h"
#include "../Constant.h"

CorpsRigide::CorpsRigide()
	: CorpsRigide(Forme(), 0, Matrix33(std::array<std::array<double, 3>, 3>({ {1,0,0},{0,1,0},{0,0,1} })))
{
}

CorpsRigide::CorpsRigide(const Forme& forme, double masse, const Matrix33& tenseurInertie)
	: CorpsRigide(forme, masse, tenseurInertie, Vecteur3D(), Quaternion())
{
}

CorpsRigide::CorpsRigide(const Forme& forme, double masse, const Matrix33& tenseurInertie, const Vecteur3D& position, const Quaternion& orientation)
	: CorpsRigide(forme, masse, tenseurInertie, position, orientation, Vecteur3D(), Vecteur3D())
{
}

CorpsRigide::CorpsRigide(const Forme& forme, double masse, const Matrix33& tenseurInertie, const Vecteur3D& position, const Quaternion& orientation, const Vecteur3D& velocite, const Vecteur3D& velociteAngulaire)
	: forme(forme), inverseMasse((masse == 0) ? 0 : 1 / masse), tenseurInertieInverseLocal(tenseurInertie.inverse()),
	position(position), velocite(velocite), acceleration(Vecteur3D()), force(Vecteur3D()),
	orientation(orientation), velociteAngulaire(velociteAngulaire), accelerationAngulaire(Vecteur3D()), torque(Vecteur3D()),
	transformMatrix(Matrix34(std::array<std::array<double, 4>, 3>({ {1,0,0},{0,1,0},{0,0,1} }))),
	inverseTenseurInertie(Matrix33(std::array<std::array<double, 3>, 3>({ {1,0,0},{0,1,0},{0,0,1} })))
{
	// Initialisation des données dérivées (transformMatrix et tenseurInertieInverse)
	calculerDonneesDerivees();
}



void CorpsRigide::actualiser(double duration)
{
	// Mise à jour de la position
	this->position = this->position + this->velocite * duration;

	// Mise à jour de l'orientation
	this->orientation.actualisationParVelociteAngulaire(this->velociteAngulaire, duration);



	// Calcule les données dérivées (transformMatrix et tenseurInertieInverse)
	calculerDonneesDerivees();
	


	// Mise à jour de l'accélération
	this->acceleration = this->force * this->inverseMasse;

	// Mise à jour de l'accélération angulaire
	this->accelerationAngulaire = this->inverseTenseurInertie * this->torque;



	// Mise à jour de la vitesse
	this->velocite = this->velocite * Constant::facteurAmortissementLineaire + this->acceleration * duration;

	// Mise à jour de la rotation
	this->velociteAngulaire = this->velociteAngulaire * Constant::facteurAmortissementAngulaire + this->accelerationAngulaire * duration;



	// Réinitialisation des accumulateur
	this->reinitialiserAccumulateur();
}

double CorpsRigide::getMass()
{
	return (this->inverseMasse == 0) ? Constant::masseInfinie : (1 / this->inverseMasse);
}



void CorpsRigide::ajouterForce(const Vecteur3D& force){
	this->force = this->force + force;
}

void CorpsRigide::ajouterTorque(const Vecteur3D& torque)
{
	this->torque = this->torque + torque;
}




void CorpsRigide::ajouterForcePosition(const Vecteur3D& force, const Vecteur3D& position){
	this->force = this->force + force;
	this->torque = this->torque + (position - this->position) % force;
}

void CorpsRigide::ajouterForcePositionRelative(const Vecteur3D& force, const Vecteur3D& positionRelative){
	this->ajouterForcePosition(force, this->transformMatrix * positionRelative);
}

void CorpsRigide::calculerDonneesDerivees()
{
	this->transformMatrix = Matrix34(this->position, this->orientation);

	this->inverseTenseurInertie.values = this->tenseurInertieInverseLocal.values;
	this->inverseTenseurInertie.setOrientation(this->orientation);
}

void CorpsRigide::reinitialiserAccumulateur(){
	this->force = Vecteur3D();
	this->torque = Vecteur3D();
}