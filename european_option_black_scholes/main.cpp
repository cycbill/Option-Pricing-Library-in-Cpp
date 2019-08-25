#include <iostream>
#include <cmath>

#include "european_option_black_scholes.h"

int main()
{
	int callput;
	double S, K, vol, rd, rf, te, td;

	callput = 1;
	S = 7.7610;
	K = 7.7481;
	vol = 0.0112424490582748;
	rd = 0.001444440118;
	rf = 0.001549120310;
	te = 0.079452054795;
	td = 0.084931506849;

	BlackScholesEuropean BSVan(callput, S, K, vol, rd, rf, te, td);

	std::cout << "premium: " << BSVan.premium() * 10000 << std::endl;
	std::cout << "spot delta: " << BSVan.spotdelta() * 100 << std::endl;
	std::cout << "forward delta: " << BSVan.forwarddelta() * 100 << std::endl;
	std::cout << "gamma: " << BSVan.gamma() * 100 << std::endl;
	std::cout << "vega: " << BSVan.vega() * 100 << std::endl;
	std::cout << "volga: " << BSVan.volga() << std::endl;
	std::cout << "vanna: " << BSVan.vanna() << std::endl;
	std::cout << "rho: " << BSVan.rho() * 100 << std::endl;
	std::cout << "rhof: " << BSVan.rhof() * 100 << std::endl;
	std::cout << "theta: " << BSVan.theta() << std::endl;
	std::cin.get();
	return 0;
}