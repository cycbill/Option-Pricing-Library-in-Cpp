#include "../random_number_generation/lin_con_gen.h"
#include "../standard_normal_distribution/statistics.h"
#include "correlated_snd.h"
#include <fstream>
#include <vector>

int main()
{
	// Number of values
	int num_draws = 20;

	/* ================ */
	/* UNCORRELATED SND */
	/* ================ */

	int init_seed = 1;
	std::vector<double> snd_uniform_draws(num_draws, 0.0);
	std::vector<double> snd_normal_draws(num_draws, 0.0);

	// Uniform random number generation
	LinearCongruentialGenerator lcg(num_draws, init_seed);
	lcg.get_uniform_draws(snd_uniform_draws);

	// Create standard normal draws
	StandardNormalDistribution snd;
	snd.random_draws(snd_uniform_draws, snd_normal_draws);


	/* ================ */
	/* CORRELATION SND */
	/* =============== */

	// Correlation coefficient
	double rho = 0.5;

	int init_seed_2 = 10;
	std::vector<double> csnd_uniform_draws(num_draws, 0.0);
	std::vector<double> csnd_normal_draws(num_draws, 0.0);
	
	// Uniform random number generation
	LinearCongruentialGenerator lcg_2(num_draws, init_seed_2);
	lcg_2.get_uniform_draws(csnd_uniform_draws);

	// Create the correlated standard normal distribution
	CorrelatedSND csnd(rho, &snd_normal_draws);
	csnd.correlation_calc(csnd_normal_draws);


	// Output the values of the 2 correlated SND draws
	std::ofstream csnd_out("csnd.csv");

	for (int i = 0; i < snd_normal_draws.size(); i++) {
		csnd_out << snd_normal_draws[i] << " " << csnd_normal_draws[i] << std::endl;
	}

	csnd_out.close();
	return 0;
}