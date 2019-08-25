#include <iostream>

#include "jump_diffusion_formula.h"

int main()
{
	// First we create the parameter list
	int callput = 1;
	double S = 100.0;
	double K = 100.0;
	double rd = 0.05;
	double rf = 0.00;
	double v = 0.2;
	double te = 1.0;
	double td = 1.0;

	int N = 50;				// Times in the finite sum approximation
	double m = 1.083287;	// Scale factor for J
	double lambda = 1.0;	// Intensity for jumps
	double nu = 0.4;		// Stdev of lognormal jump process

	// Then we calculate the call jump-diffusion value
	double jd_premium = bs_jd_premium(callput, S, K, v, rd, rf, te, td, N, m, lambda, nu);
	std::cout << "Option Price under JD: " << jd_premium << std::endl;

	std::cin.get();
	return 0;
}