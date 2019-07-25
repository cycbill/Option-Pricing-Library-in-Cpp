#include "digital.h"

DigitalOption::DigitalOption(PayOff* _pay_off) : pay_off(_pay_off) {}

double DigitalOption::pay_off_price(const double& S) const {
	return (*pay_off)(S);
}