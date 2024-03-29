#include <iostream>

#include "interval_bisection.h"
#include "black_scholes_functor.h"

int main()
{
	int callput;
	double S, K, rd, rf, te, td;

	callput = 1;
	S = 7.7610;	
	K = 7.7481;
	rd = 0.001444440118;
	rf = 0.001549120310;
	te = 0.079452054795;
	td = 0.084931506849;

	// Create the Black-Scholes Formula functor
	BlackScholes BSVan(callput, S, K, rd, rf, te, td);

	// test
	double prem = BSVan.operator()(0.10);
	std::cout << "Premium with vol = 0.10: " << prem << std::endl;		//0.0937515

	// Interval Bisection parameters
	double low_vol = 0.05;
	double high_vol = 0.35;
	double episilon = 0.000001;

	// Calculate the implied volatility
	double imp_vol = interval_bisection(prem, low_vol, high_vol, episilon, BSVan);
	std::cout << "Implied Vol: " << imp_vol << std::endl;

	std::cin.get();
	return 0;
}