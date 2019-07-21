#include <iostream>
#include "lin_con_gen.h"

int main()
{
	// Set the initial seed and the dimentionality of the RNG
	unsigned long init_seed = 1;
	unsigned long num_draws = 20;
	std::vector<double> random_draws(num_draws, 0.0);

	// Create the LCG object and create the random uniform draws
	// on the open interval (0,1)
	LinearCongruentialGenerator lcg(num_draws, init_seed);
	lcg.get_uniform_draws(random_draws);

	// Output the random draws to the console/stdout
	for (unsigned long i = 0; i < num_draws; i++) {
		std::cout << random_draws[i] << " " << std::endl;
	}

	std::cin.get();
	return 0;
}