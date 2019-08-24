#include <iostream>
#include <cmath>

#include "european_option_black_scholes.h"

/*
# define PI 3.141592653589793238462643383279502884L // pi

using namespace std;

double normal_cdf(double x) {
	return 0.5 * (1 + erf(x / sqrt(2)));
}

double normal_pdf(double x) {
	return 1.0 / sqrt(2 * PI) * exp(-x * x / 2);
}

*/


int main()
{
	BlackScholesEuropean BSVan(1, 7.7610, 7.7481, 0.0112424490582748, 0.001444440118, 0.001549120310, 0.079452054795, 0.084931506849);
	/*
	std::cout << "CF rd: " << BSVan.cfrd << std::endl;
	std::cout << "CF rf: " << BSVan.cfrf << std::endl;
	std::cout << "fwd: " << BSVan.fwd << std::endl;
	std::cout << "d1: " << BSVan.d1 << std::endl;
	std::cout << "d2: " << BSVan.d2 << std::endl;
	std::cout << "N'(d1): " << BSVan.npd1 << std::endl;
	*/
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