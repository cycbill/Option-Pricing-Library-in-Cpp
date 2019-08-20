//Program: Black Scholes Vanilla
#include <iostream>

using namespace std;

//double black_scholes_vanilla(int callput, double spot, double strike, double vol, double texp, 
//	double tdel, )

class BlackScholesEuropean {
public:
	int callput;
	double spot, strike, vol, te, td, rd, rf;
	double forward(void) {
		return spot * exp(rd * td) / exp(rf * td);
	}
//	double d1(void) {
//		return ( log(forward/strike) + 
//	}
//	double d2(void);
//	double Nd1(void);
//	double Nd2(void);
//	double npd1(void);
//	double premium(void);

};
