#ifndef __CUBOIDES_H__
#define __CUBOIDES_H__

#include <vector>
#include "Cuboide.h"

class Cuboides : public std::vector<Cuboide*>
{
public:
	void actualiser(double duration);

	void deleteCuboides();
};

#endif