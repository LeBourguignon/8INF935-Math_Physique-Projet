#include "CorpsRigide.h"
#include "../Constant.h"

CorpsRigide::CorpsRigide()
	: CorpsRigide(Vecteur3D(), Quaternion(), 0, Matrix33(std::array<std::array<double, 3>, 3>({ {1,0,0},{0,1,0},{0,0,1} })))
{
}

CorpsRigide::CorpsRigide(Vecteur3D position, Quaternion orientation, double masse, Matrix33 tenseurInertie)
	: CorpsRigide(position, orientation, Vecteur3D(), Vecteur3D(), masse, tenseurInertie)
{
}

CorpsRigide::CorpsRigide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, double masse, Matrix33 tenseurInertie)
	: CorpsRigide(position, orientation, velocite, velociteAngulaire, Vecteur3D(), Vecteur3D(), masse, tenseurInertie)
{
}

CorpsRigide::CorpsRigide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, Vecteur3D acceleration, Vecteur3D accelerationAngulaire, double masse, Matrix33 tenseurInertie)
	: position(position), velocite(velocite), acceleration(acceleration), force(Vecteur3D()),
	orientation(orientation), velociteAngulaire(velociteAngulaire), accelerationAngulaire(accelerationAngulaire), torque(Vecteur3D()),
	inverseMasse((masse == 0) ? 0 : 1 / masse), 
	transformMatrix(Matrix34(std::array<std::array<double, 4>, 3>({ {1,0,0},{0,1,0},{0,0,1} }))), 
	tenseurInertieInverse(Matrix33(std::array<std::array<double, 3>, 3>({{1,0,0},{0,1,0},{0,0,1}}))),
	tenseurInertieInverseLocal(tenseurInertie.inverse())
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
	this->accelerationAngulaire = this->tenseurInertieInverse * this->torque;



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

	this->tenseurInertieInverse.values = this->tenseurInertieInverseLocal.values;
	this->tenseurInertieInverse.setOrientation(this->orientation);
}

void CorpsRigide::reinitialiserAccumulateur(){
	this->force = Vecteur3D();
	this->torque = Vecteur3D();
}