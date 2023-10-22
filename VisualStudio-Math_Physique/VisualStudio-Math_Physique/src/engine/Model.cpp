#include "Model.h"

#include "particule/force/GraviteParticule.h"
#include "particule/force/RessortBungeeParticule.h"
#include "particule/force/RessortFixeParticule.h"
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

void Model::startDemo2()
{
	this->reinitialisation();

	Particule* particule1 = new Particule(Vecteur3D(-1, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 5);
	Particule* particule2 = new Particule(Vecteur3D(1, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 5);
	this->ajouterParticule(particule1, Vecteur3D(-5, 0, 0));
	this->ajouterParticule(particule2, Vecteur3D(5, 0, 0));
	this->registreForceParticule.ajouterForceParticule(particule1, new RessortBungeeParticule(100, 5, particule2));
	this->registreForceParticule.ajouterForceParticule(particule2, new RessortBungeeParticule(100, 5, particule1));
}

void Model::startDemo3()
{
	this->reinitialisation();

	Particule* particule1 = new Particule(Vecteur3D(1, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 1);
	Particule* particule2 = new Particule(Vecteur3D(1, 1, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 2);
	this->ajouterParticule(particule1, Vecteur3D(1, 0, 0));
	this->ajouterParticule(particule2, Vecteur3D(1, 0, 0));
	RessortFixeParticule* ressort1 = new RessortFixeParticule(20, 2, Vecteur3D(0, 0, 0));
	RessortFixeParticule* ressort2 = new RessortFixeParticule(20, 2, Vecteur3D(0, 1, 0));
	this->registreForceParticule.ajouterForceParticule(particule1, ressort1);
	this->registreForceParticule.ajouterForceParticule(particule2, ressort2);
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