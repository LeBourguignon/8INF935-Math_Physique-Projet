#include "Contact.h"

Contact::Contact(const DonneeContact& donneeContact)
	: donneeContact(donneeContact)
{
}

void Contact::resoudre(float duration)
{
	double e = this->donneeContact.restitution;

	CorpsRigide *c_1 = this->donneeContact.corpsRigides[0];
	CorpsRigide *c_2 = this->donneeContact.corpsRigides[1];

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


float Contact::getVelociteRelative()
{
	return (this->donneeContact.corpsRigides[0]->velocite - this->donneeContact.corpsRigides[1]->velocite) * this->donneeContact.normalContact;
}