#include <iostream>
#include <vector>
#include <cmath>

#include "../../Utilities/matrixGen.hpp"

void printVector(std::vector<double> &vec)
{
	for (auto &&e : vec)
	{
		std::cout << "  " << e << std::endl;
	}
}

template<typename F>
std::vector<double> pushSolution(F f, int n, double u_a, double u_b, double a, double b)
{
	std::vector<double> sol(n,0);

	double h = ((b-a)/n);
	double h2 = h * h;	
//	h^2 = ((b-a)/n)^2;


	for (int i = 1; i < n; ++i)
	{
		sol[i-1] = (h2*f(a + i*h));
	}

	sol[0] -= u_a;	
	sol[sol.size()-1] -= u_b;
	return sol;
}

double exact(double x)
{
	return 2.5*x + 2.5 - (1/(3.14159*3.14159)) * std::sin(3.14159*x);
}

int main()
{

	int n = 0;
	const double PI = 3.14159;

	std::cout << "Enter a number for your mesh: ";
	std::cin >> n;
	n = n-1;	
	double a = 0.0;
	double b = 1.0;
	
	double h = ((b-a)/(n+1));
	double u_a = 2.5;
	double u_b = 5.0;
	double vec2Norm = 0.0;	
	double vecInfNorm = 0.0;	
	
	std::vector<std::vector<double>> M = makeTriDiag(n);
	std::vector<double> sol;
	std::vector<double> solution;
	std::vector<double> exactDouble(n,0);
		
	sol = pushSolution([&](double x){return (std::sin(PI*x));}, n, u_a, u_b, a, b);

	solution = matrixStripper(M,sol);

	std::cout << std::endl;	
	std::cout << "Estimated Solution: " << std::endl;
	printVector(solution);

	std::cout << std::endl;

	for (int i = 1; i < n+1; ++i)
	{
		exactDouble[i-1] = exact(a+i*h);		
	}

	std::cout << "Exact Solution: " << std::endl;
	printVector(exactDouble);

	std::cout << std::endl;
	std::cout << "Vector 2 Norm: ";
	vec2Norm = vectorNorm2(exactDouble) - vectorNorm2(solution);
	std::cout << vec2Norm << std::endl;

	std::cout << "Vector Inf Norm: ";
	vecInfNorm = vectorNormInf(exactDouble) - vectorNormInf(solution);
	std::cout << vecInfNorm << std::endl;
		
}
