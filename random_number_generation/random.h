#pragma once

#include <vector>

class RandomNumberGenerator
{
protected:
	unsigned long init_seed;	// Initial random seed value
	unsigned long cur_seed;		// Current random seed value
	unsigned long num_draws;	// Dimensionality of the RNG

public:
	RandomNumberGenerator(unsigned long _num_draws, unsigned long _init_seed)
		: num_draws(_num_draws), init_seed(_init_seed), cur_seed(_init_seed) {};
	virtual ~RandomNumberGenerator() {};

	virtual unsigned long get_random_seed() const { return cur_seed; }
	virtual void set_random_seed(unsigned long _seed) { cur_seed = _seed; }
	virtual void reset_random_seed() { cur_seed = init_seed; }
	virtual void set_num_draws(unsigned long _num_draws) { num_draws = _num_draws; }

	// Obtain a random integer (need for create random uniforms)
	virtual unsigned long get_random_integer() = 0;

	// Fills a vector with uniform random variables on the open interval (0,1)
	virtual void get_uniform_draws(std::vector<double>& draws) = 0;
};

