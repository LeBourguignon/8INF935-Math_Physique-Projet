#include "GenerateursContact.h"

void GenerateursContact::ajouterContact(Contacts& contacts, unsigned int limit)
{
	for (auto generateurContact : *this) {
		generateurContact->ajouterContact(contacts, limit);
	}
}

void GenerateursContact::deleteGenerateurs()
{
	for (auto generateurContact : *this)
	{
		delete generateurContact;
	}
	this->~GenerateursContact();
}
