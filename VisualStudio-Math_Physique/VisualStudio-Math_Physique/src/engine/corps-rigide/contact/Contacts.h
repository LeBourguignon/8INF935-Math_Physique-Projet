#ifndef __CONTACTS_H__
#define __CONTACTS_H__

#include "Contact.h"
#include <vector>

class Contacts : public std::vector<Contact*>
{
public:
	void resoudre(float duration);

	void deleteContacts();
};

#endif