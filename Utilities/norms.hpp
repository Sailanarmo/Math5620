#ifndef NORMS_HPP
#define NORMS_HPP

#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

double matrixNorm1(std::vector<std::vector<double>> &A)
{
	std::vector<double> max;
	double m1Norm = 0;

	for (unsigned int i = 0; i < A.size(); ++i)
	{
		double sum = 0;
		for (unsigned int j = 0; j < A.size(); ++j)
		{
			sum += std::abs(A[i][j]);
		}
		max.emplace_back(sum);
	}
	
	m1Norm = *std::max_element(max.begin(),max.end());
	
	return m1Norm;
}

double matrixNormInf(std::vector<std::vector<double>> &A)
{
	std::vector<double> max;
	double infNorm = 0.0;

	for (unsigned int i = 0; i < A.size(); ++i)
	{
		double sum = 0.0;
		for (unsigned int j = 0; j < A.size(); ++j)
		{
			sum += std::abs(A[j][i]);
		}
		max.emplace_back(sum);
	}
	infNorm = *std::max_element(max.begin(),max.end());

	return infNorm;
}

double vectorNorm2(std::vector<double> &v)
{
	double vectNorm2 = 0.0;
	for (auto && e: v)
	{
		vectNorm2 += std::pow(e,2);
	}

	vectNorm2 = std::abs(vectNorm2);

	return std::sqrt(vectNorm2);
}

double vectorNormInf(std::vector<double> &v)
{
	std::vector<double> x;
	double vectNormInf = 0.0;

	for (auto &&e: v)
	{
		x.emplace_back(std::abs(e));
	}

	vectNormInf = *std::max_element(x.begin(),x.end());

	return vectNormInf;
}


#endif
