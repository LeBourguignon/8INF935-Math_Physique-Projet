#ifndef __CONTACT_H__
#define __CONTACT_H__

#include "DonneeContact.h"

class Contact
{
public:
	DonneeContact donneeContact;

	Contact(const DonneeContact& donneeContact);

	double getVelociteRelative();

	void resoudreInterpenetration(float duration);
	void resoudreVelocite(float duration);
};

#endif
