#pragma once

#include "../european_option_pde_euler/fdm.h"


class FDMCrankNicolsonNeumann : public FDMBase
{
protected:
	void calculate_step_size();
	void set_initial_conditions();
	void calculate_boundary_conditions();
	void calculate_inner_domain();

public:
	FDMCrankNicolsonNeumann(double _x_dom, unsigned long _J,
		double _t_dom, unsigned long _N,
		ConvectionDiffusionPDE* _pde);

	void step_march();
};

