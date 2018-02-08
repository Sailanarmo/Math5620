#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

#include "../Utilities/matrixGen.hpp"
 

int main()
{
 
	std::vector<std::vector<double>> M = {{1, 4 ,0 ,0},
										  {3, 4 ,1 ,0},
										  {0, 1, 3, 4},
										  {0, 0, 2, 3}};

	std::vector<double> f = {11,18,9,5};
	std::vector<double> solution;
		
	solution = matrixStripper(M, f);

	for(auto && e: solution)
	{
		std::cout << e << std::endl;
	}
		 
    return 0;
}
