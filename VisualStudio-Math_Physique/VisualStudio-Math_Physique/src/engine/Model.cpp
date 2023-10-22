#include "Model.h"

#include "particule/force/GraviteParticule.h"
#include "particule/contact/ResolveurContactParticule.h"
#include "Constant.h"

Model::Model()
{
	this->generateurContactParticuleNaive = new GenerateurContactParticuleNaive(this->particules, 0.2f);
	generateursContact.push_back(this->generateurContactParticuleNaive);
}


Particules Model::getParticules()
{
	return particules;
}

void Model::ajouterParticule(Particule* particule, Vecteur3D gravite = Vecteur3D())
{
	this->particules.push_back(particule);
	this->registreForceParticule.ajouterForceParticule(particule, new GraviteParticule(gravite));
	this->generateurContactParticuleNaive->ajouterParticule(particule);
}

void Model::reinitialisation()
{
	// Destruction des objets
	this->particules.deleteParticules();
	this->registreForceParticule.deleteForce();
	this->generateursContact.deleteGenerateurs();

	// Initialisation du model
	this->particules = Particules();
	this->registreForceParticule = RegistreForceParticule();
	this->generateursContact = GenerateursContactParticule();

	this->generateurContactParticuleNaive = new GenerateurContactParticuleNaive(this->particules, 0.2f);
	generateursContact.push_back(this->generateurContactParticuleNaive);
}

void Model::startDemo1()
{
	this->reinitialisation();

	this->ajouterParticule(new Particule(Vecteur3D(-10, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 10), Vecteur3D(10, 0, 0));
	this->ajouterParticule(new Particule(Vecteur3D(10, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 10), Vecteur3D(-10, 0, 0));

	/*this->ajouterParticule(new Particule(Vecteur3D(-10, -10, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 10), Vecteur3D(10, 10, 0));
	this->ajouterParticule(new Particule(Vecteur3D(10, -10, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 10), Vecteur3D(-10, 10, 0));
	this->ajouterParticule(new Particule(Vecteur3D(10, 10, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 10), Vecteur3D(-10, -10, 0));
	this->ajouterParticule(new Particule(Vecteur3D(-10, 10, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 10), Vecteur3D(10, -10, 0));*/
}


void Model::actualiser(float duration)
{
	// Mise à jour des forces sur les particules
	this->registreForceParticule.actualiserForce(duration);

	// Mise à jour des particules
	this->particules.actualiser(duration);

	// Génerer les contacts
	ContactParticules contactParticules;
	this->generateursContact.ajouterContact(contactParticules, Constant::limiteCollision);

	// Résoudre les contacts
	ResolveurContactParticule resolveurContact;
	resolveurContact.resoudreContact(contactParticules, duration);

	// Suppression des contacts
	contactParticules.deleteContactParticules();
}