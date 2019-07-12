// monte carlo simulation
// vanilla option pricing under Black-Scholes frame work

#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

//generate underlying asset price
double generate_asset_price(double spot, double vol, double rd, double rf, double te, double td, double rdn_num) {
	return spot * exp((rd - rf) * td - 0.5 * vol * vol * te + vol * sqrt(te) * rdn_num);
}

//vanilla call option payoff
double payoff(int callput, double S, double K) {
	return max((S - K)*callput, 0.0);
}

int main() {
	const int mc_count = 10000;
	default_random_engine generator;
	normal_distribution<double> distribution(0.0, 1.0);

	int callput = 1;
	double spot = 7.7610;
	double strike = 7.7481;
	double vol = 0.0112424490582748;
	double te = 0.079452054795;
	double td = 0.084931506849;
	double rd = 0.001444440118;
	double rf = 0.001549120310;

	double spot_bump_size = 0.0001;
	double vol_bump_size = 0.0001;

	double spot_up = spot * (1 + spot_bump_size);
	double spot_down = spot * (1 - spot_bump_size);
	double vol_up = vol + vol_bump_size;
	double vol_down = vol - vol_bump_size;

	double payoff_sum = 0.0;
	double payoff_sum_spot_up = 0.0;
	double payoff_sum_spot_down = 0.0;
	double payoff_sum_vol_up = 0.0;
	double payoff_sum_vol_down = 0.0;
	double payoff_sum_spot_up_vol_up = 0.0;

	for (int i = 0; i < mc_count; i++) {
		double rdn_num = distribution(generator);
		payoff_sum				+= payoff(callput, generate_asset_price(spot, vol, rd, rf, te, td, rdn_num), strike);
		payoff_sum_spot_up		+= payoff(callput, generate_asset_price(spot_up, vol, rd, rf, te, td, rdn_num), strike);
		payoff_sum_spot_down	+= payoff(callput, generate_asset_price(spot_down, vol, rd, rf, te, td, rdn_num), strike);
		payoff_sum_vol_up		+= payoff(callput, generate_asset_price(spot, vol_up, rd, rf, te, td, rdn_num), strike);
		payoff_sum_vol_down		+= payoff(callput, generate_asset_price(spot, vol_down, rd, rf, te, td, rdn_num), strike);
		payoff_sum_spot_up_vol_up += payoff(callput, generate_asset_price(spot_up, vol_up, rd, rf, te, td, rdn_num), strike);
	}

	double cfrd = exp(rd * td);
	double cfrf = exp(rf * td);

	double premium				= cfrd / cfrf * payoff_sum / mc_count;
	double premium_spot_up		= cfrd / cfrf * payoff_sum_spot_up / mc_count;
	double premium_spot_down	= cfrd / cfrf * payoff_sum_spot_down / mc_count;
	double premium_vol_up		= cfrd / cfrf * payoff_sum_vol_up / mc_count;
	double premium_vol_down		= cfrd / cfrf * payoff_sum_vol_down / mc_count;
	double premium_spot_up_vol_up = cfrd / cfrf * payoff_sum_spot_up_vol_up / mc_count;

	double delta = (premium_spot_up - premium_spot_down) / (spot_up - spot_down);
	double gamma = (premium_spot_up - 2.0 * premium + premium_spot_down) / pow((spot_up - spot_down)/2.0, 2.0) * spot;
	double vega = (premium_vol_up - premium_vol_down) / (vol_bump_size * 2.0);
	double volga = (premium_vol_up - 2.0 * premium + premium_vol_down) / pow(vol_bump_size, 2.0 );
	double vanna = ((premium_spot_up_vol_up - premium_vol_up) - (premium_spot_up - premium)) / ((spot_up - spot) * vol_bump_size);

	cout << "premium: " << premium*10000 << endl;
	cout << "delta: " << delta*100 << endl;
	cout << "gamma: " << gamma << endl;
	cout << "vega: " << vega*100 << endl;
	cout << "volga: " << volga << endl;
	cout << "vanna: " << vanna << endl;

	cin.get();
	return 0;
}