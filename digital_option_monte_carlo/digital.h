#pragma once

#include "payoff.h"

class DigitalOption
{
private:
	PayOff* pay_off;	// Pay-off class (in this instance call or put)

public:
	DigitalOption(PayOff* _pay_off);
	virtual ~DigitalOption() {};

	// Pure virtual pay-off operator
	virtual double pay_off_price(const double& S) const;
};

