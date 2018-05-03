#include <iostream>

int main()
{
	double dt = 0.00001;
	double alpha = 10.0;
	double beta = 0.0001;
	double gamma = 0.01;
	
	std::vector<double> lambdas {1.0, -1.0, 100.0};
	std::vector<double> P_0 {25.0, 40000.0};

	std::cout << "Lambda" << std::endl;
	for (auto && e: lambdas)
	{
		std::cout << explicitEuler(alpha,beta,gamma, dt, [&](double a, double b) { (void)b; return lambda * a;}) << std::endl;
	}

	std::cout << "Logistic" << std::endl;
	for (auto && e: P_0)
	{
		std::cout << explicitEuler(alpha,beta,gamma, dt, [&](double a, double b) { (void)b; return gamma * a-beta * a * a;}) << std::endl;
	}
}
