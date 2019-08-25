#pragma once

#include "../standard_normal_distribution/statistics.h"

class BlackScholesEuropean
{
public:
	BlackScholesEuropean(int _callput, double _S, double _K,
		double _vol, double _rd, double _rf, 		// dividend for equity, foreign interest rate for fx
		double _te, double _td);		// time to settlement date for fx
	~BlackScholesEuropean() {};
	double premium();
	double spotdelta();
	double forwarddelta();
	double gamma();
	double vega();
	double volga();
	double vanna();
	double rho();
	double rhof();
	double theta();
protected:
	int callput;
	double S, K, vol, rd, rf, te, td;
	double F, cfrd, cfrf;
	StandardNormalDistribution norm;
	double d1, d2, Nd1, Nd2, npd1;
};
