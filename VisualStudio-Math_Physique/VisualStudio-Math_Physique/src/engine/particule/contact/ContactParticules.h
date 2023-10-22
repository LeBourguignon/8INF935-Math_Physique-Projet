#ifndef __CONTACT_PARTICULES_H__
#define __CONTACT_PARTICULES_H__

#include "ContactParticule.h"
#include <vector>

class ContactParticules : public std::vector<ContactParticule*>
{
	void resoudre(float duration);
};

#endif