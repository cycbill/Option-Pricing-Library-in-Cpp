#include <iostream>

#include "option.h"
#include "option.h"
#include "../random_number_generation/lin_con_gen.h"
#include "../standard_normal_distribution/statistics.h"
#include "../bivariate_correlated_stand_norm_dist/correlated_snd.h"
#include "heston_mc.h"

void generate_normal_correlation_paths(double rho,
	std::vector<double>& spot_normals, std::vector<double>& cor_normals)
{
	unsigned vals = spot_normals.size();
	unsigned long init_seed_1 = 1;
	unsigned long init_seed_2 = 5;

	// Simple random number generation method
	LinearCongruentialGenerator lcg_1(vals, init_seed_1), lcg_2(vals, init_seed_2);
	std::vector<double> uniform_draws_1(vals, 0.0), uniform_draws_2(vals, 0.0);
	lcg_1.get_uniform_draws(uniform_draws_1);
	lcg_2.get_uniform_draws(uniform_draws_2);

	// Create the Standard Normal Distribution and random draw vectors
	StandardNormalDistribution snd;
	snd.random_draws(uniform_draws_1, spot_normals);

	// Create the correlated standard normal distribution
	CorrelatedSND csnd(rho, &spot_normals);
	csnd.random_draws(uniform_draws_2, cor_normals);
}

int main()
{
	// First we create the parameter list
	unsigned num_sims = 100000;		// Number of simulated asset paths
	unsigned num_intervals = 1000;	// Number of intervals for the asset path to sampled

	double S_0 = 100.0;
	double K = 100.0;
	double r = 0.0319;
	double v_0 = 0.010201;
	double T = 1.00;

	double rho = -0.7;		// Correlation of asset and volatility
	double kappa = 6.21;	// Mean-reversion rate
	double theta = 0.019;	// Long run average volatility
	double xi = 0.61;		// Vol of vol

	// Create the PayOff, Option and Heston objects
	PayOff* pPayOffCall = new PayOffCall(K);
	Option* pOption = new Option(K, r, T, pPayOffCall);
	HestonEuler hest_euler(pOption, kappa, theta, xi, rho);

	// Create the spot and vol initial normal and price paths
	std::vector<double> spot_draws(num_intervals, 0.0);
	std::vector<double> vol_draws(num_intervals, 0.0);
	std::vector<double> spot_prices(num_intervals, S_0);
	std::vector<double> vol_prices(num_intervals, v_0);

	// Monte Carlo options pricing
	double payoff_sum = 0.0;
	for (unsigned i = 0; i < num_sims; i++) {
		std::cout << "Calculating path" << i + 1 << " of " << num_sims << std::endl;
		generate_normal_correlation_paths(rho, spot_draws, vol_draws);
		hest_euler.calc_vol_path(vol_draws, vol_prices);
		hest_euler.calc_spot_path(spot_draws, vol_prices, spot_prices);
		payoff_sum += pOption->pay_off->operator()(spot_prices[num_intervals - 1]);
	}
	double option_price = (payoff_sum / static_cast<double>(num_sims)) * exp(-r * T);
	std::cout << "Option Price: " << option_price << std::endl;

	// Free memory
	delete pOption;
	delete pPayOffCall;

	std::cin.get();
	return 0;
}