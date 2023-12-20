#include "ResolveurContact.h"

void ResolveurContact::resoudreContactsInterpenetration(Contacts& contacts, float duration)
{
	for (int i = 0; i < contacts.size(); i++)
	{
		contacts[i]->resoudreInterpenetration(duration);
	}
}

void ResolveurContact::resoudreContactsVelocite(Contacts& contacts, float duration)
{
	double nbIterationMax = contacts.size() * 2;

	while (this->iteration < nbIterationMax) {

		double minVs = DBL_MAX;
		int finalIndex = 0;
		int index = 0;

		for (auto contact : contacts) {
			double newVs = contact->getVelociteRelative();

			if (newVs < minVs) {

				minVs = newVs;
				finalIndex = index;
			}

			index++;
		}

		if (minVs >= 0.0f) { return; }

		contacts[finalIndex]->resoudreVelocite(duration);

		this->iteration++;
	}
}

void ResolveurContact::resoudreContacts(Contacts& contacts, float duration)
{
	//this->resoudreContactsInterpenetration(contacts, duration);
	this->resoudreContactsVelocite(contacts, duration);
}