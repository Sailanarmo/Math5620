#include <iostream>
#include <cmath>

double IVP(double lambda, double alpha, int count)
{
	return a * std::exp(l * count);
}

double logistic(double alpha, double beta, double p_0, int count)
{
	return (alpha / (((alpha - p_0 * b/p_0) * std::exp(-a * count) + beta));
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Count: " << i << " IVP: " << IVP(-1.5,7.3,i) << " ";	
		std::cout << "Count: " << i << " Logistic: " << logistic(2.5,1.7,3.2,i) << std::endl;	
	}

		

}
