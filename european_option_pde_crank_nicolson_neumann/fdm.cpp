#include <fstream>

#include "fdm.h"
#include "../tridiagonal_matrix_algorithm/tridiagonal_matrix_algorithm.h"

//#include "../tridiagonal_matrix_algorithm/tridiagonal_matrix_algorithm.cpp"

FDMCrankNicolsonNeumann::FDMCrankNicolsonNeumann(double _x_dom, unsigned long _J,
	double _t_dom, unsigned long _N,
	ConvectionDiffusionPDE* _pde)
	: FDMBase(_x_dom, _J, _t_dom, _N, _pde)
{
	calculate_step_size();
	set_initial_conditions();
}

void FDMCrankNicolsonNeumann::calculate_step_size() {
	dx = x_dom / static_cast<double>(J - 1);
	dt = t_dom / static_cast<double>(N - 1);
}

void FDMCrankNicolsonNeumann::set_initial_conditions() {
	// Spatial settings
	double cur_spot = 0.0;

	old_result.resize(J, 0.0);
	new_result.resize(J, 0.0);
	x_values.resize(J, 0.0);

	for (unsigned long j = 0; j < J; j++) {
		cur_spot = static_cast<double>(j) * dx;
		old_result[j] = pde->init_cond(cur_spot);
		x_values[j] = cur_spot;
	}

	// Temporal settings
	prev_t = t_dom;
	cur_t = t_dom;
}

void FDMCrankNicolsonNeumann::calculate_boundary_conditions() {
	new_result[0] = pde->boundary_left(cur_t, x_values[0]);
	new_result[J - 1] = pde->boundary_right(cur_t, x_values[J - 1]);
}

void FDMCrankNicolsonNeumann::calculate_inner_domain() {

	std::vector<double> A(J - 2, 0.0), B(J - 2, 0.0), C(J - 2, 0.0), D(J - 2, 0.0), X(J - 2, 0.0);

	// Only use inner result indices (1 to J-2)
	for (unsigned long j = 1; j < J - 1; j++) {
		// Temporary variables and throughout
		double dt_diffu = dt * (pde->diff_coeff(prev_t, x_values[j]));
		double dtdxp2_conv = dt * dx * 0.5 * (pde->conv_coeff(prev_t, x_values[j]));

		// Differencing coefficients (see \alpha, \beta and \gamma in text)
		alpha = 0.5 * (dt_diffu - dtdxp2_conv) / (dx * dx);
		beta = -dt_diffu / (dx * dx) + 0.5 * dt * (pde->zero_coeff(prev_t, x_values[j]));
		gamma = 0.5 * (dt_diffu + dtdxp2_conv) / (dx * dx);

		if (j == 1)
		{
			B[j - 1] = -2 * alpha + 1 - beta;
			C[j - 1] = alpha - gamma;
			D[j - 1] = ((2 * alpha + 1 + beta) * old_result[j] +
				(-alpha + gamma) * old_result[j + 1]);
		}
		else if (j == J - 2)
		{
			A[j - 1] = -alpha + gamma;
			B[j - 1] = 1 - beta - 2 * gamma;
			D[j - 1] = ((alpha - gamma) * old_result[j - 1] +
				(1 + beta + 2 * gamma) * old_result[j]);
		}
		else 
		{
			A[j - 1] = -alpha;
			B[j - 1] = 1 - beta;
			C[j - 1] = -gamma;

			D[j - 1] = (alpha * old_result[j - 1] +
				(1 + beta) * old_result[j] +
				gamma * old_result[j + 1]);
		}
	}

	tridiag_mtx_algo(J - 2, A, B, C, D, X);

	for (unsigned long j = 1; j < J - 1; j++) {
		new_result[j] = X[j - 1];
	}
}

void FDMCrankNicolsonNeumann::step_march() {
	std::ofstream fdm_out("fdm.csv");

	for (unsigned long n = 1; n <= N; n++) {
		cur_t = t_dom - n * dt;
		calculate_boundary_conditions();
		calculate_inner_domain();
		for (unsigned long j = 0; j < J; j++) {
			fdm_out << x_values[j] << " " << cur_t << " " << new_result[j] << std::endl;
		}
		old_result = new_result;
	}

	fdm_out.close();
}