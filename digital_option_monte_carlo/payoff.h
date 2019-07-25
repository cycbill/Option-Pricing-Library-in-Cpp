#pragma once

#include <algorithm> // This is needed for the std::max comparison function, used in the pay-off calculations

class PayOff {
public:
	PayOff(); // Default (no parameter) constructor
	virtual ~PayOff() {}; // Virtual destructor

	// Overload () operator, turns the PayOff into an abstract function object
	virtual double operator() (const double& S) const = 0;
};

class PayOffCall : public PayOff {
private:
	double K; // Strike price

public:
	PayOffCall(const double& _K);
	virtual ~PayOffCall() {};

	// Virtual function is now over-ridden (no pure-virtual anymore)
	virtual double operator() (const double& S) const;
};

class PayOffPut : public PayOff {
private:
	double K; // Strike price

public:
	PayOffPut(const double& _K);
	virtual ~PayOffPut() {};
	virtual double operator() (const double& S) const;
};

