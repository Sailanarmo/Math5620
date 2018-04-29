#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "matrixGen.hpp"

std::vector<double> sol(std::vector<double> &x,std::vector<std::vector<double> > &A, std::vector<double> &b, int tol, int n)
{
	
	double sum;	
	double error = 10*tol;
	int k = 0;
	std::vector<double> x_1(A.size(),0);
	//while(n != 0)
	while(error > tol && k < n)
	{
		for (unsigned int i = 0; i < A.size(); ++i)
		{
			sum = 0.0;
			for (unsigned int j = 0; j < i; ++j)
			{
				//if(j != i)
				//{
					sum += A[i][j]*x[j];
				//}
			}
			//x[i] = std::pow(x[i],k+1); 
			x_1[i] = (b[i]-sum)/A[i][i];

			for (int j = i+1; j < n; j++)
			{
				sum+=A[i][j]*x[j];
			}
			x_1[i] = (b[i]-sum)/A[i][i];
		}
		sum = 0.0;

		for(unsigned int i = 0; i < A.size(); ++i)
		{
			double diff = std::abs(x_1[i]-x[i]);
			sum = sum+diff*diff;
		}
		error = std::sqrt(sum);
		x = x_1;
		k++;
	}
	std::cout << k << std::endl;
	return x;
}


int main()
{
	
	std::ofstream myFile;	
	//std::vector<std::vector<double> > A = makeMatrix();
	std::vector<double> x = makeGuessVector();
	std::vector<double> b = makeVectorB();
	
	//A = makeDiagonallyDominate(A);



	std::vector<double> xSol = sol(x,A,b,.001,1000);
	
	myFile.open("jacobi-sol.txt");
	for(auto &&e:xSol)
	{
		myFile  << e;
	}
	myFile << std::endl;
	myFile.close();
		
	return 0;
}
