#include <iostream>

#include "../../Utilities/norms.hpp"
#include "../../Utilities/matrixGen.hpp"


int main()
{
	std::vector<std::vector<double>> M = makeMatrix();

	std::cout << "Matrix1 Norm: " << matrixNorm1(M) << std::endl;
	std::cout << "Matrix Inf Norm: " << matrixNormInf(M) << std::endl;

}
