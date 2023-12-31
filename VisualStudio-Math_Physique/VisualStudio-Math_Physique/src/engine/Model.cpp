#include "Model.h"

#include "Constant.h"

#include "particule/force/GraviteParticule.h"
#include "particule/force/RessortBungeeParticule.h"
#include "particule/force/RessortFixeParticule.h"
#include "particule/force/TraineeParticule.h"
#include "particule/force/FlottabiliteParticule.h"

#include "particule/contact/ResolveurContactParticule.h"
#include "particule/contact/CableParticule.h"
#include "particule/contact/TigeParticule.h"

#include "corps-rigide/force/GenerateurGravite.h"
#include "corps-rigide/force/GenerateurTrainee.h"
#include "corps-rigide/force/GenerateurRessort.h"
#include "corps-rigide/force/GenerateurRessortFixe.h"
#include "corps-rigide/force/GenerateurRessortBungee.h"
#include "corps-rigide/cuboide/force/GenerateurFlottabiliteCuboide.h"
#include "corps-rigide/contact/ResolveurContact.h"

#include "corps-rigide/contact/GenerateurContactCorpsRigide.h" // TODO
#include "corps-rigide/contact/GenerateurContactTigeCorpsRigides.h"

Model::Model()
{
	this->generateurContactParticuleNaive = new GenerateurContactParticuleNaive(this->particules, 0.1f);
	generateursContactParticule.push_back(this->generateurContactParticuleNaive);
}


void Model::reinitialisation()
{
	// Destruction des objets
	this->particules.deleteParticules();
	this->registreForceParticule.deleteForce();
	this->generateursContactParticule.deleteGenerateurs();

	this->corpsRigides.deleteCorpsRigides();
	this->registreForce.deleteForce();
	this->constGenerateursContact.deleteGenerateurs();

	// Initialisation du model
	this->particules = Particules();
	this->registreForceParticule = RegistreForceParticule();
	this->generateursContactParticule = GenerateursContactParticule();

	this->generateurContactParticuleNaive = new GenerateurContactParticuleNaive(this->particules, 0.1f);
	generateursContactParticule.push_back(this->generateurContactParticuleNaive);

	this->corpsRigides = CorpsRigides();
	this->registreForce = RegistreForce();
	this->constGenerateursContact = GenerateursContact();
}

/*
	Particule
*/

Particules Model::getParticules()
{
	return particules;
}

void Model::ajouterParticule(Particule* particule, Vecteur3D gravite = Vecteur3D())
{
	this->particules.push_back(particule);

	this->registreForceParticule.ajouterForceParticule(particule, new GraviteParticule(gravite));
	this->registreForceParticule.ajouterForceParticule(particule, new FlottabiliteParticule(0.2, 0.008, -5, 20));
	this->registreForceParticule.ajouterForceParticule(particule, new TraineeParticule(0.001, 0.01));

	this->generateurContactParticuleNaive->ajouterParticule(particule);
}


void Model::startDemoParticule1()
{
	this->reinitialisation();

	this->ajouterParticule(new Particule(Vecteur3D(-10, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 10), Vecteur3D(10, 0, 0));
	this->ajouterParticule(new Particule(Vecteur3D(10, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 10), Vecteur3D(-10, 0, 0));
}

void Model::startDemoParticule2()
{
	this->reinitialisation();

	Particule* particule1 = new Particule(Vecteur3D(-1, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 5);
	Particule* particule2 = new Particule(Vecteur3D(1, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 5);
	this->ajouterParticule(particule1, Vecteur3D(-5, 0, 0));
	this->ajouterParticule(particule2, Vecteur3D(5, 0, 0));
	this->registreForceParticule.ajouterForceParticule(particule1, new RessortBungeeParticule(100, 5, particule2));
	this->registreForceParticule.ajouterForceParticule(particule2, new RessortBungeeParticule(100, 5, particule1));
}

void Model::startDemoParticule3()
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

void Model::startDemoParticule4()
{
	this->reinitialisation();

	Particule* particule1 = new Particule(Vecteur3D(0, 0, 0), Vecteur3D(4, 0, 0), Vecteur3D(0, 0, 0), 2);
	Particule* particule2 = new Particule(Vecteur3D(-1, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 2);
	Particule* particule3 = new Particule(Vecteur3D(-2, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 2);
	Particule* particules12[2] = { particule1, particule2 };
	Particule* particules23[2] = { particule2, particule3 };
	this->ajouterParticule(particule1, Vecteur3D(0, 0, 0));
	this->ajouterParticule(particule2, Vecteur3D(0, 0, 0));
	this->ajouterParticule(particule3, Vecteur3D(0, 0, 0));
	CableParticule* cable12 = new CableParticule(particules12, 3, 0);
	CableParticule* cable23 = new CableParticule(particules23, 3, 0);
	generateursContactParticule.push_back(cable12);
	generateursContactParticule.push_back(cable23);
}

void Model::startDemoParticule5()
{
	this->reinitialisation();

	Particule* particule1 = new Particule(Vecteur3D(0, 2, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 0);
	Particule* particule2 = new Particule(Vecteur3D(2, 2, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 1);
	Particule* particules12[2] = { particule1, particule2 };
	this->ajouterParticule(particule1, Vecteur3D(0, 0, 0));
	this->ajouterParticule(particule2, Vecteur3D(0, -1, 0));
	TigeParticule* tige12 = new TigeParticule(particules12, 2);
	generateursContactParticule.push_back(tige12);
}

void Model::startDemoParticule6()
{
	this->reinitialisation();

	Particule* particule1 = new Particule(Vecteur3D(0, 0, 0), Vecteur3D(4, 0, 0), Vecteur3D(0, 0, 0), 0);
	Particule* particule2 = new Particule(Vecteur3D(-1, 1, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 2);
	Particule* particule3 = new Particule(Vecteur3D(-1, -1, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 2);
	Particule* particules12[2] = { particule1, particule2 };
	Particule* particules13[2] = { particule1, particule3 };
	this->ajouterParticule(particule1, Vecteur3D(0, 0, 0));
	this->ajouterParticule(particule2, Vecteur3D(0, 0, 0));
	this->ajouterParticule(particule3, Vecteur3D(0, 0, 0));
	CableParticule* cable12 = new CableParticule(particules12, 4, 0);
	CableParticule* cable23 = new CableParticule(particules13, 4, 0);
	generateursContactParticule.push_back(cable12);
	generateursContactParticule.push_back(cable23);
}

void Model::startDemoParticule7()
{
	this->reinitialisation();

	Particule* particule1 = new Particule(Vecteur3D(-10, 1, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 1);
	Particule* particule2 = new Particule(Vecteur3D(-10, -1, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 1);
	this->ajouterParticule(particule1, Vecteur3D(1, 0, 0));
	this->ajouterParticule(particule2, Vecteur3D(1, 0, 0));
	this->registreForceParticule.ajouterForceParticule(particule1, new TraineeParticule(0.01, 0.1));
}

void Model::startDemoParticule8()
{
	this->reinitialisation();

	Particule* particule1 = new Particule(Vecteur3D(1, 1, 1), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 0.008);
	Particule* particule2 = new Particule(Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 0.008);
	Particule* particule3 = new Particule(Vecteur3D(-1, -1, -1), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0), 0.008);
	this->ajouterParticule(particule1, Vecteur3D(0, -10, 0));
	this->ajouterParticule(particule2, Vecteur3D(0, -10, 0));
	this->ajouterParticule(particule3, Vecteur3D(0, -10, 0));
}

/*
	Corps Rigide
*/

CorpsRigides Model::getCorpsRigides()
{
	return this->corpsRigides;
}

void Model::ajouterCuboide(Cuboide* cuboide, Vecteur3D gravite)
{
	this->corpsRigides.push_back(cuboide);
	this->registreForce.ajouterForce(cuboide, new GenerateurGravite(gravite));
	this->registreForce.ajouterForce(cuboide, new GenerateurFlottabiliteCuboide(-5, 200));
	this->registreForce.ajouterForce(cuboide, new GenerateurTrainee(0.1, 0.5));
}

void Model::startDemoCuboide1()
{
	this->reinitialisation();

	Cuboide* anchorLeft = new Cuboide(Vecteur3D(0.5, 0.5, 0.5), 1000000, Vecteur3D(-3, 10, -5), Quaternion());
	this->corpsRigides.push_back(anchorLeft);
	Cuboide* anchorRight = new Cuboide(Vecteur3D(0.5, 0.5, 0.5), 1000000, Vecteur3D(3, 10, -5), Quaternion());
	this->corpsRigides.push_back(anchorRight);

	Cuboide* top = new Cuboide(Vecteur3D(1, 1, 0.2), 1000, Vecteur3D(0, 10, -5), Quaternion());
	this->ajouterCuboide(top, Vecteur3D(0, -1, 0));

	Cuboide* left = new Cuboide(Vecteur3D(0.5, 0.5, 0.5), 1000, Vecteur3D(-3, 5, -5), Quaternion());
	this->ajouterCuboide(left, Vecteur3D(0, -1, 0));

	Cuboide* right = new Cuboide(Vecteur3D(0.5, 0.5, 0.5), 1000, Vecteur3D(3, 5, -5), Quaternion());
	this->ajouterCuboide(right, Vecteur3D(0, -1, 0));

	this->registreForce.ajouterForce(top, new GenerateurRessort(Vecteur3D(-0.5, 0.5, 0), anchorLeft, Vecteur3D(), 500, 3));
	this->registreForce.ajouterForce(top, new GenerateurRessort(Vecteur3D(0.5, 0.5, 0), anchorRight, Vecteur3D(), 500, 3));

	this->registreForce.ajouterForce(left, new GenerateurRessort(Vecteur3D(0, 0.25, 0), top, Vecteur3D(0, -0.5, 0), 500, 3));
	this->registreForce.ajouterForce(top, new GenerateurRessort(Vecteur3D(0, -0.5, 0), left, Vecteur3D(0, 0.25, 0), 500, 3));

	this->registreForce.ajouterForce(right, new GenerateurRessort(Vecteur3D(0, 0.25, 0), top, Vecteur3D(0, -0.5, 0), 500, 3));
	this->registreForce.ajouterForce(top, new GenerateurRessort(Vecteur3D(0, -0.5, 0), right, Vecteur3D(0, 0.25, 0), 500, 3));

	this->registreForce.ajouterForce(right, new GenerateurRessort(Vecteur3D(-0.25, 0, 0), left, Vecteur3D(0.25, 0, 0), 500, 3));
	this->registreForce.ajouterForce(left, new GenerateurRessort(Vecteur3D(0.25, 0, 0), right, Vecteur3D(-0.25, 0, 0), 500, 3));
}

void Model::startDemoCuboide2()
{
	this->reinitialisation();

	Cuboide* top = new Cuboide(Vecteur3D(2, 1, 2), 10, Vecteur3D(0, 3.75, 0), Quaternion());
	this->ajouterCuboide(top, Vecteur3D(0, -10, 0));

	Cuboide* mid = new Cuboide(Vecteur3D(0.2, 3, 0.2), 1, Vecteur3D(0, 1.75, 0), Quaternion());
	this->ajouterCuboide(mid, Vecteur3D(0, -10, 0));

	Cuboide* bot = new Cuboide(Vecteur3D(0.5, 0.5, 0.5), 1, Vecteur3D(0, 0, 0), Quaternion());
	this->ajouterCuboide(bot, Vecteur3D(0, -10, 0));

	CorpsRigide* topMid[2] = { top, mid };
	Vecteur3D topMidAttache1[2] = { Vecteur3D(0.1, -0.5, 0.1), Vecteur3D(0.1, 1.5, 0.1) };
	Vecteur3D topMidAttache2[2] = { Vecteur3D(-0.1, -0.5, -0.1), Vecteur3D(-0.1, 1.5, -0.1) };
	constGenerateursContact.push_back(new GenerateurContactTigeCorpsRigides(topMid, topMidAttache1, 0.0f));
	constGenerateursContact.push_back(new GenerateurContactTigeCorpsRigides(topMid, topMidAttache2, 0.0f));

	CorpsRigide* midBot[2] = { mid, bot };
	Vecteur3D midBotAttache1[2] = { Vecteur3D(0.1, 0.25, 0.1), Vecteur3D(0.1, -1.5, 0.1) };
	Vecteur3D midBotAttache2[2] = { Vecteur3D(-0.1, 0.25, -0.1), Vecteur3D(-0.1, -1.5, -0.1) };
	constGenerateursContact.push_back(new GenerateurContactTigeCorpsRigides(midBot, midBotAttache1, 0.0f));
	constGenerateursContact.push_back(new GenerateurContactTigeCorpsRigides(midBot, midBotAttache2, 0.0f));

}


void Model::actualiser(float duration)
{
	// Mise � jour des forces sur les particules
	this->registreForceParticule.actualiserForce(duration);

	// Mise � jour des forces sur les corps rigides
	this->registreForce.actualiserForce(duration);



	// Mise � jour des particules
	this->particules.actualiser(duration);

	// Mise � jour des corpsRigides
	this->corpsRigides.actualiser(duration);



	// G�nerer les contacts des particules
	ContactParticules contactParticules;
	this->generateursContactParticule.ajouterContact(contactParticules, Constant::limiteCollision);

	// G�nerer les contacts des corpsRigides
	GenerateursContact generateursContact;
	// TODO Octree
	for (int i = 0; i < this->corpsRigides.size(); ++i)
	{
		BoundingVolumeSphere spherei(this->corpsRigides[i]);
		for (int j = i + 1; j < this->corpsRigides.size(); ++j)
		{
			BoundingVolumeSphere spherej(this->corpsRigides[j]);
			if (spherei.PossibleCollision(spherej))
				generateursContact.push_back(new GenerateurContactCorpsRigide(this->corpsRigides[i], this->corpsRigides[j], 1.0f));
		}
	}

	Contacts contacts;
	generateursContact.ajouterContact(contacts, Constant::limiteCollision);
	constGenerateursContact.ajouterContact(contacts, Constant::limiteCollision);



	// Suppression des g�n�rateurs de contacts des corpsRigides
	generateursContact.deleteGenerateurs();



	// R�soudre les contacts des particules
	ResolveurContactParticule resolveurContactParticule;
	resolveurContactParticule.resoudreContact(contactParticules, duration);

	// R�soudre les contacts des corpsRigides
	ResolveurContact resolveurContact;
	resolveurContact.resoudreContacts(contacts, duration);



	// Suppression des contacts des particules
	contactParticules.deleteContactParticules();

	// Suppression des contacts des corpsRigides
	contacts.deleteContacts();
}