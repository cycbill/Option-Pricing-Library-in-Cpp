#pragma once
class PayOff
{
private:
	double K;
public:
	PayOff(double& _K) {};
	virtual ~PayOff() {};

	virtual double operator() (const double& S) const = 0;
};

class PayOffCall : public PayOff
{
public:
	PayOffCall(double& _K) {};
	virtual ~PayOffCall() {};

	virtual double operator() (const double& S) const;
};

class PayOffPut : public PayOff
{
public:
	PayOffPut();
	virtual ~PayOffPut() {};

	virtual double operator() (const double& S) const;
};
