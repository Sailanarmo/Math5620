#include <iostream>
#include "../../Utilities/matrixGen.hpp"

int main()
{
	std::cout << implicitEuler(0.0,-1.0,0.4,0.1, [](double a, double b){return a*a+2*b;}) << std::endl;
}
