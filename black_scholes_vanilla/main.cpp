#include <iostream>

#include "black_scholes_formula.h"

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

	std::cout << "premium: " << bsvanilla_premium(callput, S, K, vol, rd, rf, te, td) * 10000 << std::endl;
	std::cout << "spot delta: " << bsvanilla_spotdelta(callput, S, K, vol, rd, rf, te, td) * 100 << std::endl;
	std::cout << "forward delta: " << bsvanilla_forwarddelta(callput, S, K, vol, rd, rf, te, td) * 100 << std::endl;
	std::cout << "vega: " << bsvanilla_vega(S, K, vol, rd, rf, te, td) * 100 << std::endl;
	std::cin.get();
	return 0;
}