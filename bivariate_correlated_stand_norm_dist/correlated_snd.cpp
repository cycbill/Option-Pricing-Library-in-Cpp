#include "correlated_snd.h"

#include <iostream>
#include <cmath>

CorrelatedSND::CorrelatedSND(const double _rho,
	const std::vector<double>* _uncorr_draws)
	: rho(_rho), uncorr_draws(_uncorr_draws) {}

CorrelatedSND::~CorrelatedSND() {}

// This carries out the actual correlation modification. 
void CorrelatedSND::correlation_calc(std::vector<double>& dist_draws)
{
	for (int i = 0; i < dist_draws.size(); i++) {
		dist_draws[i] = rho * (*uncorr_draws)[i] + dist_draws[i] * sqrt(1 - rho * rho);
	}
}
