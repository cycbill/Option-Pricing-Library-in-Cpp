#include <iostream>
#include <cmath>

# define PI 3.141592653589793238462643383279502884L /* pi */

using namespace std;

double normal_cdf(double x) {
	return 0.5 * (1 + erf(x / sqrt(2)));
}

double normal_pdf(double x) {
	return 1.0 / sqrt(2 * PI) * exp(-x * x / 2);
}

class BlackScholesVanilla {
public:
	int callput;
	double spot, strike, vol, te, td, rd, rf;
	double cfrd, cfrf, fwd, d1, d2, Nd1, Nd2, npd1;

	BlackScholesVanilla(int callput, double spot, double strike, double vol, double te, double td, double rd, double rf) {
		//assign values to class member variables
		this->callput = callput;
		this->spot = spot;
		this->strike = strike;
		this->vol = vol;
		this->te = te;
		this->td = td;
		this->rd = rd;
		this->rf = rf;
		//pre calculations
		cfrd = exp(rd * td);
		cfrf = exp(rf * td);
		fwd = spot * cfrd / cfrf;
		double test_var = log(fwd / strike);
		d1 = (log(fwd / strike) + 0.5 * vol * vol * te) / (vol * sqrt(te));
		d2 = d1 - vol * sqrt(te);
		Nd1 = normal_cdf(callput * d1);
		Nd2 = normal_cdf(callput * d2);
		npd1 = normal_pdf(d1);
	}
	/*
	double calc_d1(void) {
		d1 = (log(fwd / strike) + 0.5 * vol * vol * te) / (vol * sqrt(te));
		return d1;
	}

	double calc_d2(void) {
		d2 = d2 - vol * sqrt(te);
		return d2;
	}

	double calc_Nd1(void) {
		Nd1 = normal_cdf(callput * d1);
		return Nd1;
	}

	double calc_Nd2(void) {
		Nd2 = normal_cdf(callput * d2);
		return Nd2;
	}

	double calc_npd1(void) {
		npd1 = normal_pdf(d1);
		return npd1;
	}
	*/
	double premium(void) {
		return callput / cfrd * (fwd * Nd1 - strike * Nd2);
	}

	double spotdelta(void) {
		return callput / cfrf * Nd1;
	}

	double forwarddelta(void) {
		return callput / cfrd * Nd1;
	}

	double gamma(void) {
		return callput * Nd1;
	}

	double vega(void) {
		return spot / cfrf * sqrt(te) * npd1;
	}

	double volga(void) {
		return spot / cfrf * sqrt(te) * npd1 * d1 * d2 / vol;
	}

	double vanna(void) {
		return -1.0 / cfrf * npd1 * d2 / vol;
	}

	double rho(void) {
		return callput * strike * te / cfrd * Nd2;
	}

	double rhof(void) {
		return -callput * spot * te / cfrf * Nd1;
	}

	double theta(void) {
		return -1.0 / cfrf * npd1 * spot * vol / (2 * sqrt(te))
			+ callput * (rf * spot / cfrf * Nd1 - rd * strike / cfrd * Nd2);
	}
};


int main()
{
	BlackScholesVanilla BSVan(1, 7.7610, 7.7481, 0.0112424490582748, 0.079452054795, 0.084931506849, 0.001444440118, 0.001549120310);

	cout << "CF rd: " << BSVan.cfrd << endl;
	cout << "CF rf: " << BSVan.cfrf << endl;
	cout << "fwd: " << BSVan.fwd << endl;
	cout << "d1: " << BSVan.d1 << endl;
	cout << "d2: " << BSVan.d2 << endl;
	cout << "N'(d1): " << BSVan.npd1 << endl;

	cout << "premium: " << BSVan.premium() * 10000 << endl;
	cout << "spot delta: " << BSVan.spotdelta() * 100 << endl;
	cout << "forward delta: " << BSVan.forwarddelta() * 100 << endl;
	cout << "gamma: " << BSVan.gamma() * 100 << endl;
	cout << "vega: " << BSVan.vega() * 100 << endl;
	cout << "volga: " << BSVan.volga() << endl;
	cout << "vanna: " << BSVan.vanna() << endl;
	cout << "rho: " << BSVan.rho() * 100 << endl;
	cout << "rhof: " << BSVan.rhof() * 100 << endl;
	cout << "theta: " << BSVan.theta() << endl;
	cin.get();
	return 0;
}