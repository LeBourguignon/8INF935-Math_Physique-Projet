#include "Contact.h"

Contact::Contact(const DonneeContact& donneeContact)
	: donneeContact(donneeContact)
{
}

double Contact::getVelociteRelative()
{
	return (this->donneeContact.corpsRigides[0]->velocite - this->donneeContact.corpsRigides[1]->velocite) * this->donneeContact.normalContact;
}

void Contact::resoudreInterpenetration(float duration)
{
	Vecteur3D localPointContact0 = this->donneeContact.pointContact - this->donneeContact.corpsRigides[0]->position;

	Vecteur3D inertieAngulaireMonde0 = localPointContact0 % this->donneeContact.normalContact;
	inertieAngulaireMonde0 = this->donneeContact.corpsRigides[0]->inverseTenseurInertie * inertieAngulaireMonde0;
	inertieAngulaireMonde0 = inertieAngulaireMonde0 % localPointContact0;

	double inertieLineaire0 = this->donneeContact.corpsRigides[0]->inverseMasse;
	double inertieAngulaire0 = this->donneeContact.normalContact * inertieAngulaireMonde0;



	Vecteur3D localPointContact1 = this->donneeContact.pointContact - this->donneeContact.corpsRigides[1]->position;

	Vecteur3D inertieAngulaireMonde1 = localPointContact1 % this->donneeContact.normalContact;
	inertieAngulaireMonde1 = this->donneeContact.corpsRigides[1]->inverseTenseurInertie * inertieAngulaireMonde1;
	inertieAngulaireMonde1 = inertieAngulaireMonde1 % localPointContact1;

	double inertieLineaire1 = this->donneeContact.corpsRigides[1]->inverseMasse;
	double inertieAngulaire1 = this->donneeContact.normalContact * inertieAngulaireMonde1;



	double totalInertie = inertieLineaire0 + inertieLineaire1 + inertieAngulaire0 + inertieAngulaire1;
	double inverseTotalInertie = 1 / totalInertie;

	double moveLineaire0 = this->donneeContact.penetration * inertieLineaire0 * inverseTotalInertie;
	double moveAngulaire0 = this->donneeContact.penetration * inertieAngulaire0 * inverseTotalInertie;

	double moveLineaire1 = -this->donneeContact.penetration * inertieLineaire1 * inverseTotalInertie;
	double moveAngulaire1 = -this->donneeContact.penetration * inertieAngulaire1 * inverseTotalInertie;



	this->donneeContact.corpsRigides[0]->position = this->donneeContact.corpsRigides[0]->position + (this->donneeContact.normalContact * moveLineaire0);

	Vecteur3D localPoint0 = this->donneeContact.corpsRigides[0]->transformMatrix.inverse() * this->donneeContact.pointContact;
	Vecteur3D impulsePerMove0 = this->donneeContact.corpsRigides[0]->inverseTenseurInertie * (localPoint0 % this->donneeContact.normalContact);
	Vecteur3D rotationPerMove0 = impulsePerMove0 * (1 / inertieAngulaire0);
	this->donneeContact.corpsRigides[0]->orientation.rotationParVecteur(rotationPerMove0 * moveAngulaire0);

	this->donneeContact.corpsRigides[1]->position = this->donneeContact.corpsRigides[1]->position + (-this->donneeContact.normalContact * moveLineaire1);

	Vecteur3D localPoint1 = this->donneeContact.corpsRigides[1]->transformMatrix.inverse() * this->donneeContact.pointContact;
	Vecteur3D impulsePerMove1 = this->donneeContact.corpsRigides[1]->inverseTenseurInertie * (localPoint1 % this->donneeContact.normalContact);
	Vecteur3D rotationPerMove1 = impulsePerMove1 * (1 / inertieAngulaire1);
	this->donneeContact.corpsRigides[1]->orientation.rotationParVecteur(rotationPerMove1 * moveAngulaire1);
}

void Contact::resoudreVelocite(float duration)
{
	double e = this->donneeContact.restitution;

	CorpsRigide* c_1 = this->donneeContact.corpsRigides[0];
	CorpsRigide* c_2 = this->donneeContact.corpsRigides[1];

	Vecteur3D r_1 = this->donneeContact.pointContact - c_1->position;
	Vecteur3D r_2 = this->donneeContact.pointContact - c_2->position;

	Matrix33 inverse_J_1 = c_1->inverseTenseurInertie;
	Matrix33 inverse_J_2 = c_2->inverseTenseurInertie;

	Vecteur3D u_rel = c_1->velocite - c_2->velocite;
	Vecteur3D n = this->donneeContact.normalContact;

	double k = (e + 1) * (u_rel * n);
	k /= (n * (c_1->inverseMasse + c_2->inverseMasse) + ((inverse_J_1 * (r_1 % n)) % r_1) + ((inverse_J_2 * (r_2 % n)) % r_2)) * n;

	c_1->velocite = c_1->velocite - n * k * c_1->inverseMasse;
	c_1->velociteAngulaire = c_1->velociteAngulaire - inverse_J_1 * (r_1 % (n * k));

	c_2->velocite = c_2->velocite + n * k * c_2->inverseMasse;
	c_2->velociteAngulaire = c_2->velociteAngulaire + inverse_J_2 * (r_2 % (n * k));
}