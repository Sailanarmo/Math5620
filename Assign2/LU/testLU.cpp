#include <iostream>
#include <iomanip>

#include "../../Utilities/matrixGen.hpp"

int main()
{
	
	std::vector<std::vector<double>> A = {{8.0,8.0,4.0,2.0,6.0},
										  {5.0,5.0,5.0,3.0,1.0},
										  {10.0,3.0,10.0,3.0,3.0},
										  {5.0,2.0,9.0,4.0,8.0},
										  {10.0,3.0,7.0,7.0,4.0}};

	std::vector<double> solution = {8,27};
	
	auto [L,U,P] = lUFactorize(A);
	
	for (auto &&e : L)
	{
		for (auto && f : e)
		{
			std::cout << std::setw(10) << std::setprecision(3) << f << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (auto &&e : U)
	{
		for (auto && f : e)
		{
			std::cout << std::setw(10) << std::setprecision(3) << f << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::vector<double> sol = solveLU(L,U,solution);

	for (auto &&e: sol)
	{
		std::cout << e << std::endl;
	}
}
