#include "fdm.h"

FDMCrankNicolson::FDMCrankNicolson(double _x_dom, unsigned long _J,
	double _t_dom, unsigned long _N,
	ConvectionDiffusionPDE* _pde)
	: FDMBase(_x_dom, _J, _t_dom, _N, _Deref_pre_z_)
{
	calculate_step_size();
	set_initial_conditions();
}

void FDMCrankNicolson::calculate_step_size() {
	dx = x_dom / static_cast<double>(J - 1);
	dt = t_dom / static_cast<double>(N - 1);
} a