#include "TreeProducts.h"



TreeProducts::TreeProducts(double FinalTime_) : FinalTime(FinalTime_) {}

double TreeProducts::GetFinalTime() const
{
	return FinalTime;
}
