#include "ResolveurContact.h"

void ResolveurContact::resoudreContactsInterpenetration(Contacts& contacts, float duration)
{
	while (this->iteration < this->nbIterationMax) {

		double maxPenetration = DBL_MIN;
		int finalIndex = 0;
		int index = 0;

		for (auto contact : contacts) {
			double newPenetration = contact->donneeContact.penetration;

			if (newPenetration > maxPenetration) {

				maxPenetration = newPenetration;
				finalIndex = index;
			}

			index++;
		}

		if (maxPenetration <= 0.0f) { return; }

		contacts[finalIndex]->resoudreInterpenetration(duration);

		this->iteration++;
	}
}

void ResolveurContact::resoudreContactsVelocite(Contacts& contacts, float duration)
{
	while (this->iteration < this->nbIterationMax) {

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
	this->nbIterationMax = contacts.size() * 2;

	//this->resoudreContactsInterpenetration(contacts, duration);

	this->nbIterationMax = contacts.size() * 2;

	this->resoudreContactsVelocite(contacts, duration);
}