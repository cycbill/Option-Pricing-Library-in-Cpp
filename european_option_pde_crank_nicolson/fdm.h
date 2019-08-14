#pragma once

#include "../european_option_pde_euler/fdm.h"

//#include "../european_option_pde_euler/pde.cpp"

class FDMCrankNicolson : public FDMBase
{
protected:
	void calculate_step_size();
	void set_initial_conditions();
	void calculate_boundary_conditions();
	void calculate_inner_domain();

public:
	FDMCrankNicolson(double _x_dom, unsigned long _J,
					 double _t_dom, unsigned long _N,
					 ConvectionDiffusionPDE* _pde);
	
	void step_march();
};

