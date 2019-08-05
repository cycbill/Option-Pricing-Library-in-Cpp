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

	// Simple random number generation method
	unsigned long init_seed = 1;
	LinearCongruentialGenerator lcg(vals, init_seed);
	std::vector<double> snd_uniform_draws(vals, 0.0);
	lcg.get_uniform_draws(snd_uniform_draws);

	// Create the Standard Normal Distribution and random draw vectors
	StandardNormalDistribution snd;
	snd.random_draws(snd_uniform_draws, spot_normals);

	// Create the correlated standard normal distribution
	CorrelatedSND csnd(rho, &spot_normals);
	std::vector<double> csnd_uniform_draws(vals, 0.0);



	

}