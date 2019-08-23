#pragma once
class TreeProducts
{
public:
	TreeProducts(double FinalTime_);
	virtual double FinalPayOff(double Spot) const = 0;
	virtual double PreFinalValue(double Spot,
		double Time,
		double DiscountedFutureValue)
		const = 0;
	virtual ~TreeProducts();
	virtual TreeProducts* clone() const = 0;
	double GetFinalTime() const;

private:
	double FinalTime;
};

