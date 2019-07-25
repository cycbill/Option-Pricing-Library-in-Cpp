#pragma once

#include "../european_option_pde_euler/payoff.h"

class Option
{
public:
	PayOff* pay_off;
	double K;
	double r;
	double T;

	Option(double _K, double _r,
		double _T, PayOff* _pay_off);

	virtual ~Option();
};