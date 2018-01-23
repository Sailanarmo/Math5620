#include <iostream>
#include <cmath>

double logistics(double alpha, double beta, double p_0, double t)
{
	return ((alpha/(((alpha)/p_0 + beta)*std::exp(-alpha*t) + beta)));
}


int main()
{
	std::cout << logistics(1.78,1.22,2.83,2.7) << std::endl;
}
