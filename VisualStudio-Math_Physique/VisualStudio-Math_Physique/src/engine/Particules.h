#ifndef __PARTICULES_H__
#define __PARTICULES_H__

#include <vector>
#include "Particule.h"

class Particules : public std::vector<Particule*>
{
public:
	void actualiser(double duration);
};

#endif