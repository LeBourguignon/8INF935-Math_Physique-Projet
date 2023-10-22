#ifndef __CONSTANT_H__
#define __CONSTANT_H__

namespace Constant {
	// Facteur d'amortissement
	const double facteurAmortissement = 0.999999999;

	// "Masse infinie" = 0
	const double masseInfinie = 0;

	// Limite de collision pouvant etre generee
	const unsigned int limiteCollision = 30;
}

#endif