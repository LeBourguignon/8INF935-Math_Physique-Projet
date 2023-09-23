#ifndef __MANAGERPARTICULE_H__
#define __MANAGERPARTICULE_H__

#include <vector>
#include "../engine/Particule.h"

class ManagerParticule
{
private:
	std::vector<Particule> particules;
	std::vector<double> ttls;

public:
	ManagerParticule();
	void add(Particule, double ttl);
	void draw(double deltaTime);
};

#endif