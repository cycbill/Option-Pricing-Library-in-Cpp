#include "european_option_black_scholes.h"

BlackScholesEuropean::BlackScholesEuropean(int _callput, double _S, double _K, double _vol, double _rd, double _rf, double _te, double _td)
	: callput(_callput), S(_S), K(_K), vol(_vol), rd(_rd), rf(_rf), te(_te), td(_td)
{
	cfrd = exp(rd * td);
	cfrf = exp(rf * td);
	F = S * cfrd / cfrf;
	d1 = (log(F / K) + 0.5 * vol * vol * te) / (vol * sqrt(te));
	d2 = d1 - vol * sqrt(te);
	Nd1 = norm.cdf(callput * d1);
	Nd2 = norm.cdf(callput * d2);
	npd1 = norm.pdf(d1);
}

double BlackScholesEuropean::premium() {
	return callput / cfrd * (F * Nd1 - K * Nd2);
}

double BlackScholesEuropean::spotdelta() {
	return callput / cfrf * Nd1;
}

double BlackScholesEuropean::forwarddelta() {
	return callput / cfrd * Nd1;
}

double BlackScholesEuropean::gamma() {
	return callput * Nd1;
}

double BlackScholesEuropean::vega() {
	return S / cfrf * sqrt(te) * npd1;
}

double BlackScholesEuropean::volga() {
	return S / cfrf * sqrt(te) * npd1 * d1 * d2 / vol;
}

double BlackScholesEuropean::vanna() {
	return -1.0 / cfrf * npd1 * d2 / vol;
}

double BlackScholesEuropean::rho() {
	return callput * K * te / cfrd * Nd2;
}

double BlackScholesEuropean::rhof() {
	return -callput * S * te / cfrf * Nd1;
}

double BlackScholesEuropean::theta() {
	return -1.0 / cfrf * npd1 * S * vol / (2 * sqrt(te))
		+ callput * (rf * S / cfrf * Nd1 - rd * K / cfrd * Nd2);
}
