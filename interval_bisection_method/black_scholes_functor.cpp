#include "black_scholes_functor.h"

#include "../black_scholes_vanilla/black_scholes_formula.h"
#include "../black_scholes_vanilla/standard_normal_functions.h"

BlackScholes::BlackScholes(int _callput, double _S, double _K,
	double _rd, double _rf, double _te, double _td)
	: callput(_callput), S(_S), K(_K), rd(_rd), rf(_rf), te(_te), td(_td) {}

double BlackScholes::operator()(double vol) const {
	return bsvanilla_premium(callput, S, K, vol, rd, rf, te, td);
}