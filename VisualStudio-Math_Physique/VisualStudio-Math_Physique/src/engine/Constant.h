#ifndef __CONSTANT_H__
#define __CONSTANT_H__

namespace Constant {
	// Facteur d'amortissement
	const double facteurAmortissementLineaire = 0.999999999;

	// Facteur d'amortissement
	const double facteurAmortissementAngulaire = 0.99999;

	// "Masse infinie" = 0
	const double masseInfinie = 0;

	// Limite de collision pouvant etre generee
	const unsigned int limiteCollision = 30;
}

#endif