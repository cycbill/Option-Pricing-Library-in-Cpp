
#include <iostream>
#include <vector>

#include "random_number_generation\lin_con_gen.h"
#include "statistics.h"

int main()
{
	
	// Set the initial seed and the dimentionality of the RNG
	unsigned long init_seed = 1;
	unsigned long num_draws = 20;
	std::vector<double> uniform_draws(num_draws, 0.0);

	// Create the LCG object and create the random uniform draws
	// on the open interval (0,1)
	LinearCongruentialGenerator lcg(num_draws, init_seed);
	lcg.get_uniform_draws(uniform_draws);

	// Create the Standard Normal Distribution and random draw vectors
	StandardNormalDistribution snd;
	std::vector<double> normal_draws(num_draws, 0.0);

	// Create standard normal draws
	snd.random_draws(uniform_draws, normal_draws);

	// Output the values of the standard normal random draws
	for (int i = 0; i < normal_draws.size(); i++) {
		std::cout << normal_draws[i] << std::endl;
	}

	std::cin.get();
	return 0;
}