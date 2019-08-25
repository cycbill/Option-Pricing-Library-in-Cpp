#include <iostream>
#include "black_scholes_functor.h"
#include "newton_raphson.h"

int main()
{
	// First we create the parameter list
	int callput;
	double S, K, rd, rf, te, td;

	callput = 1;
	S = 7.7610;
	K = 7.7481;
	rd = 0.001444440118;
	rf = 0.001549120310;
	te = 0.079452054795;
	td = 0.084931506849;

	// Create the Black-Scholes option functor
	BlackScholes BSVan(callput, S, K, rd, rf, te, td);

	// test
	double prem = BSVan.option_price(0.10);
	std::cout << "Premium with vol = 0.10: " << prem << std::endl;		//0.0937515

	// Newton Raphson parameters
	double init = 0.05; // Our guess impl. vol of 5%
	double epsilon = 0.000001;

	// Calculate the implied volatility
	double imp_vol = newton_raphson<BlackScholes,
		&BlackScholes::option_price,
		&BlackScholes::option_vega>
		(prem, init, epsilon, BSVan);

	// Output the values
	std::cout << "Implied Vol: " << imp_vol << std::endl;

	std::cin.get();
	return 0;
}