#pragma once

#include "../black_scholes_vanilla/black_scholes_formula.h"
#include "../black_scholes_vanilla/standard_normal_functions.h"

// Calculate the Merton jump-diffusion price based on
// a finite sum approximation to the infinite series
// solution, making use of the BS call price.
double bs_jd_premium(const int callput, const double S, const double K, const double sigma, 
	const double rd, const double rf, const double te, const double td, const int N,
	const double m,	const double lambda, const double nu) 
{
	double price = 0.0;	// Stores the final call price
	double factorial = 1.0;

	// Pre-calculate as much as possible
	double lambda_p = lambda * m;
	double lambda_p_T = lambda_p * te;

	// Calculate the finite sum over N terms
	for (int n = 0; n < N; n++) {
		double sigma_n = sqrt(sigma * sigma + n * nu * nu / te);
		double rd_n = rd - lambda * (m - 1) + n * log(m) / td;

		// Calculate n!
		if (n == 0) {
			factorial *= 1;
		}
		else {
			factorial *= n;
		}

		// Refine the jump price over the loop
		price += ((exp(-lambda_p_T) * pow(lambda_p_T, n)) / factorial) *
			bsvanilla_premium(callput, S, K, sigma_n, rd_n, rf, te, td);
	}

	return price;
}