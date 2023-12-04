#pragma once

#include "Contact.h"

class ResolveurContact
{
protected:
	unsigned int iteration = 0;

public:
	void resoudreContact(Contact& contact, float duration);
};

