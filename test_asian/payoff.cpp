#include "payoff.h"

#include <algorithm>

PayOff::PayOff() {}

PayOffCall::PayOffCall(const double& _K) { K = _K; }

double PayOffCall::operator() (const double& S) const {
	std::max(S - K, 0.0);
}

PayOffPut::PayOffPut(const double& _K) { K = _K; }

double PayOffPut::operator() (const double& S) const {
	std::max(K - S, 0.0);
}
