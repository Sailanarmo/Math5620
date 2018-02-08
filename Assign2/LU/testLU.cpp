#include <iostream>
#include <iomanip>

#include "../../Utilities/matrixGen.hpp"

int main()
{
	
	std::vector<std::vector<double>> A = {{1,3,2},
										  {2,2,1},
										  {4,2,1}};

	std::vector<double> solution = {9,7,9};
	
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
