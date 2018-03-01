#include <iostream>
#include <cmath>
#include <utility>
#include <iomanip>

#include "../../Utilities/matrixGen.hpp"

std::vector<std::vector<double>> convertToMatrix(std::vector<double> &v)
{
	int size = 3;
	std::vector<std::vector<double>> temp(size,std::vector<double>(size,0.0));
	for (int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			temp[i][j] = v[i*3 + j];
		}
	}

	return temp;
}

void printMatrix(std::vector<std::vector<double>> &A)
{
	for (auto &&e : A)
	{
		for(auto &&f : e)
		{
			std::cout << std::setw(10) << std::setprecision(3) << f << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::vector<double> computeSinVector(std::vector<std::pair<double,double>> &container,double meshSize)
{
	std::vector<double> temp;
	double size = meshSize - 1.0;
		
	double h = 1.0/size;

	for (int i = 1; i <=3; ++i)
	{
		for(int j = 1; j <=3; ++j)
		{
			container.emplace_back(std::make_pair(0+(j*h),0+(i*h)));	
		}
	}

	for (auto && e : container)
	{
		temp.emplace_back(std::sin(e.first*e.second));
	}

	return temp;
}

int main()
{

	std::vector<std::vector<double>> A = {{-4,1,0,1,0,0,0,0,0},
										  {1,-4,1,0,1,0,0,0,0},
										  {0,1,-4,0,0,1,0,0,0},
										  {1,0,0,-4,1,0,1,0,0},
										  {0,1,0,1,-4,1,0,1,0},
										  {0,0,1,0,1,-4,0,0,1},
										  {0,0,0,1,0,0,-4,1,0},
										  {0,0,0,0,1,0,1,-4,1},
										  {0,0,0,0,0,1,0,1,-4}};
	
	std::vector<std::vector<double>> E = {{-20,4,0,4,1,0,0,0,0},
										  {4,-20,4,1,4,1,0,0,0},
										  {0,4,-20,0,1,4,0,0,0},
										  {4,1,0,-20,4,0,4,1,0},
										  {1,4,1,4,-20,4,1,4,1},
										  {0,1,4,0,4,-20,0,1,4},
										  {0,0,0,4,1,0,-20,4,0},
										  {0,0,0,1,4,1,4,-20,4},
										  {0,0,0,0,1,4,0,4,-20}};


	
	std::pair<double,double> pairs;	
	std::vector<std::pair<double,double>> container;

	std::vector<double> sinVector = computeSinVector(container, 5.0);		
	
	std::vector<double> solution = solveLU(A,sinVector);	
	std::vector<std::vector<double>> answer = convertToMatrix(solution);	
	std::cout << std::endl;
	std::cout << "5 Stencil Matrix: " << std::endl;
	printMatrix(answer);
	
	sinVector.clear();
	container.clear();
		
	sinVector = computeSinVector(container, 9.0);		
	std::vector<double> solution2 = solveLU(E,sinVector);
	std::vector<std::vector<double>> answer2 = convertToMatrix(solution2);
	std::cout << "9 Stencil Matrix: " << std::endl;
	printMatrix(answer2);

}
