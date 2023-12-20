#include "Contacts.h"

void Contacts::deleteContacts()
{
	for (auto contact : *this)
	{
		delete contact;
	}
	this->~Contacts();
}