#include <numeric>  // Necessary for std::accumulate
#include <cmath>  // For log/exp functions
#include "asian.h"

// ===========
// AsianOption
// ===========

AsianOption::AsianOption(PayOff* _pay_off) : pay_off(_pay_off) {}

// =====================  
// AsianOptionArithmetic
// =====================  
AsianOptionArithmetic::AsianOptionArithmetic(PayOff* _pay_off) : AsianOption(_pay_off) {}

// Arithmetic mean pay-off price
double AsianOptionArithmetic::pay_off_price(const std::vector<double>& spot_prices) const {
	unsigned num_times = spot_prices.size();
	double sum = std::accumulate(spot_prices.begin(), spot_prices.end(), 0);
	double arith_mean = sum / static_cast<double>(num_times);
	return (*pay_off)(arith_mean);
}


asian::~asian()
{
}
