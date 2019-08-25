#pragma once
class BlackScholes
{
private:
	int callput;
	double S, K, rd, rf, te, td;


public:
	BlackScholes(int _callput, double _S, double _K,
		double _rd, double _rf, double _te, double _td);
	~BlackScholes() {};
	double option_price(double vol) const;
	double option_vega(double vol) const;
};

