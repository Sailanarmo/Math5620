#include <iostream>
#include <chrono>
#include <iomanip>

#include "../../Utilities/matrixGen.hpp"

double powerMethod(std::vector<std::vector<double>> &A, std::vector<double> &b, double tol, int maxIter)
{
	
	std::chrono::duration<double> time;
	auto start = std::chrono::high_resolution_clock::now();

	std::vector<double> y = matrixVec(A, b);

	int c = 0;

	double error = 10*tol;
	double lambdaOld = 0.0;

	int n = b.size();
	std::vector<double> x(n,0);

	double lambdaNew = 0.0;

	while(tol < error && c < maxIter)
	{
		double p = std::sqrt(dotProd(y,y));
		for (int i = 0; i < n; ++i)
		{
			x[i] = y[i]/p;
		}

		y = matrixVec(A,x);
		lambdaNew = dotProd(x,y);
		error = std::abs(lambdaNew-lambdaOld);
		lambdaOld = lambdaNew;
		c++;
	}
	std::vector<double> eigenValue = x;
	auto end = std::chrono::high_resolution_clock::now();
	time = end - start;
	//std::cout << "Time: " << time.count() << std::endl;
	return lambdaNew;

}

int main()
{
	int n = 0;
	std::vector<double> v = {1.0,1.0,1.0,1.0,1.0};

	//Hilbert Matrix
	std::vector<std::vector<double>> A = {{1.0, 1.0/2.0, 1.0/3.0, 1.0/4.0, 1.0/5.0},
										  {1.0/2.0,1.0/3.0,1.0/4.0,1.0/5.0,1.0/6.0},
										  {1.0/3.0,1.0/4.0,1.0/5.0,1.0/6.0,1.0/7.0},
										  {1.0/4.0,1.0/5.0,1.0/6.0,1.0/7.0,1.0/8.0},
										  {1.0/5.0,1.0/6.0,1.0/7.0,1.0/8.0,1.0/9.0}};

	
	std::cout << "5x5 Hilbert Matrix:" << std::endl;
	std::cout << std::endl;

	for (auto &&e : A)
	{
		for (auto && f : e)
		{
			std::cout << std::setw(10) << std::setprecision(3) << f << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Largest Eigenvalue for Hilbert: " << powerMethod(A, v, .000001, 100) << std::endl;
	std::cout << std::endl;
	for(int i = 2; i < 50;++i)
	{
		std::vector<std::vector<double>> M = makeTriDiag(i);

		std::vector<double> c(i,1.0);
		std::cout << "Largest Eigenvalue for Elliptic ODE of size " << i << ": " << powerMethod(M, c, .000001, 100) << std::endl;
		M.clear();
		c.clear();
	}
}
