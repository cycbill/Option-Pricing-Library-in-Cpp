#include "black_scholes.h"

#include "../black_scholes_vanilla/european_option_black_scholes.h"
#include "../standard_normal_distribution/statistics.h"


BlackScholes::BlackScholes(int _callput, double _S, double _K,
	double _rd, double _rf, double _te, double _td)
	: callput(_callput), S(_S), K(_K), rd(_rd), rf(_rf), te(_te), td(_td) {}

double BlackScholes::operator()(double vol) const {
	BlackScholesEuropean BSVan(callput, S, K, vol, rd, rf, te, td);
	return BSVan.premium();
}