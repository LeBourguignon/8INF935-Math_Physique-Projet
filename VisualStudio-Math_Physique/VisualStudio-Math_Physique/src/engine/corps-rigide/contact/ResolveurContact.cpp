#include "ResolveurContact.h"

void ResolveurContact::resoudreContacts(Contacts& contacts, float duration)
{
	float nbIterationMax = contacts.size() * 2;

	while (this->iteration < nbIterationMax) {

		float minVs = std::numeric_limits<float>::max();
		int vsFinalIndex = 0;
		int vsIndex = 0;

		for (auto contact : contacts) {
			float newVs = contact->getVelociteRelative();

			if (newVs < minVs) {

				minVs = newVs;
				vsFinalIndex = vsIndex;
			}

			vsIndex++;
		}

		if (minVs >= 0) { return; }

		contacts[vsFinalIndex]->resoudre(duration);

		this->iteration++;
	}
}