#pragma once

#include <algorithm>

class PayOff
{
public:
	PayOff();  // Default (no parameter) constructor
	virtual ~PayOff() {};  // Virtual destructor

	// Overload () operator, turns the PayOf into an abstract function Object
	virtual double operator() (const double& S) const = 0;
};

class PayOffCall : public PayOff 
{
private:
	double K;  // Strike

public:
	PayOffCall(const double& _K);
	virtual ~PayOffCall() {};

	// Virtual function is now over-ridden (not pure-virtual anymore)
	virtual double operator() (const double& S) const;
};

class PayOffPut : public PayOff
{
private:
	double K;  // Strike

public:
	PayOffPut(const double& _K);
	virtual ~PayOffPut() {};
	virtual double operator() (const double& S) const;
};

