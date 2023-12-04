#include "Contacts.h"

void Contacts::resoudre(float duration)
{
	for (auto contact : *this)
	{
		contact->resoudre(duration);
	}
}

void Contacts::deleteContacts()
{
	for (auto contact : *this)
	{
		delete contact;
	}
	this->~Contacts();
}