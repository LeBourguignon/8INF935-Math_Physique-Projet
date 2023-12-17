#ifndef __CONTACT_H__
#define __CONTACT_H__

#include "DonneeContact.h"

class Contact
{
public:
	DonneeContact donneeContact;

	Contact(const DonneeContact& donneeContact);

	float getVelociteRelative();
	void resoudre(float duration);
};

#endif
