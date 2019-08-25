#pragma once

#include "standard_normal_functions.h"

double d1(double S, double K, double vol, double rd, double rf, double te, double td) {
	return (log(S / K) + (rd - rf) * td + 0.5 * vol * vol * te) / (vol * sqrt(te));
}

double d2(double S, double K, double vol, double rd, double rf, double te, double td) {
	double d1_ = d1(S, K, vol, rd, rf, te, td);
	return d1_ - vol * sqrt(te);
}

double Nd1(int callput, double S, double K, double vol, double rd, double rf, double te, double td) {
	double d1_ = d1(S, K, vol, rd, rf, te, td);
	return norm_cdf(callput * d1_);
}

double Nd2(int callput, double S, double K, double vol, double rd, double rf, double te, double td) {
	double d2_ = d2(S, K, vol, rd, rf, te, td);
	return norm_cdf(callput * d2_);
}

double npd1(double S, double K, double vol, double rd, double rf, double te, double td) {
	double d1_ = d1(S, K, vol, rd, rf, te, td);
	return norm_pdf(d1_);
}

double bsvanilla_premium(int callput, double S, double K, double vol, double rd, double rf, double te, double td) {
	double cfrd = exp(rd * td);
	double cfrf = exp(rf * td);
	double F = S * cfrd / cfrf;
	double Nd1_ = Nd1(callput, S, K, vol, rd, rf, te, td);
	double Nd2_ = Nd2(callput, S, K, vol, rd, rf, te, td);
	return callput / cfrd * (F * Nd1_ - K * Nd2_);
}

double bsvanilla_spotdelta(int callput, double S, double K, double vol, double rd, double rf, double te, double td) {
	double cfrf = exp(rf * td);
	double Nd1_ = Nd1(callput, S, K, vol, rd, rf, te, td);
	return callput / cfrf * Nd1_;
}

double bsvanilla_forwarddelta(int callput, double S, double K, double vol, double rd, double rf, double te, double td) {
	double cfrd = exp(rd * td);
	double Nd1_ = Nd1(callput, S, K, vol, rd, rf, te, td);
	return callput / cfrd * Nd1_;
}

double bsvanilla_vega(double S, double K, double vol, double rd, double rf, double te, double td) {
	double cfrf = exp(rf * td);
	double npd1_ = npd1(S, K, vol, rd, rf, te, td);
	return S / cfrf * sqrt(te) * npd1_;
}