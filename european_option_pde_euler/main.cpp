//PDE method for vanilla option pricing under Black-Scholes framework
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main() {

	int callput = 1;
	double spot = 7.7610;
	double strike = 7.7481;
	double vol = 0.0112424490582748;
	double te = 0.079452054795;
	double td = 0.084931506849;
	double rd = 0.001444440118;
	double rf = 0.001549120310;

	double num_t = 101;
	double num_spot = 201;

	double range = 5.0 * vol * sqrt(te);
	double max_spot = log(spot) + ((rd - rf) * td + 0.5 * vol * vol * te + range);
	double min_spot = log(spot) + ((rd - rf) * td + 0.5 * vol * vol * te - range);
	double dt = te / num_t;
	double ds = (max_spot - min_spot) / (num_spot - 1);

	VectorXd log_s_grid = VectorXd::LinSpaced(num_spot, min_spot, max_spot);

	e




	cin.get();
	return 0;
}