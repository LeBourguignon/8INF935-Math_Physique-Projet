#ifndef __CORPS_RIGIDES_H__
#define __CORPS_RIGIDES_H__

#include "./CorpsRigide.h"

class CorpsRigides : public std::vector<CorpsRigide*>
{
public:
	void actualiser(double duration);

	void deleteCorpsRigides();
};

#endif