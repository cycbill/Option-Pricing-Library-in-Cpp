#pragma once
class PayOff
{
public:
	PayOff() {};
	virtual ~PayOff() {};

	virtual double operator() (const double& S) const = 0;
};

class PayOffCall : public PayOff
{
private:
	double K;
public:
	PayOffCall(const double& _K) {};
	virtual ~PayOffCall() {};

	virtual double operator() (const double& S) const;
};

class PayOffPut : public PayOff
{
private:
	double K;
public:
	PayOffPut(const double& _K) {};
	virtual ~PayOffPut() {};

	virtual double operator() (const double& S) const;
};
