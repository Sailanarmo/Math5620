#ifndef MATRIX_GENERATOR_HPP
#define MATRIX_GENERATOR_HPP

#include <vector>
#include <random>
#include <algorithm>
#include <numeric>


#define SIZE 1000

double randNumber()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(0.0,1.0);

	ranDouble = unif(generator);

	return ranDouble;
}

std::vector<std::vector<double> > makeMatrix()
{
	double random = 0.0;
	std::vector<std::vector<double> > A;
	
	for (int i = 0; i < SIZE; ++i)
	{
		std::vector<double> k;
		for(int j = 0; j < SIZE; ++j)
		{
			random = randNumber();
			k.emplace_back(random);
		}
		A.emplace_back(k);	
	}
	return A;
}

std::vector<double> makeVectorB()
{
	double random = 0.0;
	std::vector<double> b;
	for (int i = 0; i < SIZE; ++i)
	{
		random = randNumber();
		b.emplace_back(random);	
	}
	return b;
}

std::vector<double> makeGuessVector()
{
	std::vector<double> x;
	for(int i = 0; i < SIZE; ++i)
	{
		x.push_back(1);
	}
	return x;
}


std::vector<std::vector<double> > makeDiagonallyDominate(std::vector<std::vector<double> > &A)
{
	for (int i = 0, j = 0; i < SIZE && j < SIZE; ++i,++j)
	{
			A[i][j] += SIZE;
	}
	return A;
}


std::vector<std::vector<double> > makeSymmetric(std::vector<std::vector<double> > &A)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			A[j][i] = A[i][j];
		}
	}
	return A;
}

std::vector<double> vecComb(double a, std::vector<double> &u, double b, std::vector<double> &v)
{
	int n = u.size();
	std::vector<double> w(n);
	for (int i = 0; i < n; ++i)
	{
		w[i] = a * u[i] + b * v[i];
	}

	return w;
}

double inverse(std::vector<double> &u, std::vector<double> &v)
{
	return std::inner_product(u.begin(),u.end(),v.begin(), 0.0);
}

std::vector<double> matrixVectProd(std::vector<std::vector<double> > &A, std::vector<double> &v)
{
	int n = A.size();
	std::vector<double> c(n);
	for (int i = 0; i < n; ++i)
	{
		c[i] = inverse(A[i],v);
	}

	return c;
}

std::vector<double> matrixVec(std::vector<std::vector<double>> &A, std::vector<double> &v)
{
	std::vector<double> prod;
	for(int i = 0; i < A[0].size(); ++i)
	{
		prod.push_back(0);
	}
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			prod[i]+=A[i][j]*v[j];
		}
	}

	return prod;
}

double dotProd(std::vector<double> &v1, std::vector<double> &v2)
{
	double sum = 0.0;

	for (int i = 0; i < v1.size(); ++i)
	{
		sum = sum + v1[i]*v2[i];
	}

	return sum;
}

std::vector<double> scalarVec(std::vector<double> &v1, float a)
{
	for (int i = 0; i < v1.size(); ++i)
	{
		v1[i]=v1[i]*a;
	}

	return v1;
}

double vecNorm(std::vector<double> &v)
{
	return std::sqrt(inverse(v,v));	
}

std::vector<double> thomas(std::vector<double> &a, std::vector<double> &b, std::vector<double> &c, std::vector<double> &f)
{
	
	int n = f.size();
	std::vector<double> x(n);

	for(int i = 1; i < n; ++i)
	{
		double m = a[i-1]/b[i-1];
		b[i] -= m*c[i-1];
		f[i] -= m*f[i-1];
	}
	
	x[n-1] = f[n-1]/b[n-1];

	for(int i = n-2; i >= 0; --i)
	{
		x[i] = (f[i] - c[i]*x[i+1])/b[i];
	}

	return x;
}

std::vector<double> matrixStripper(std::vector<std::vector<double>> &A, std::vector<double> &sol)
{
	
	std::vector<double> a,b,c,x;

	for(int i = 0; i < A.size(); ++i)
	{
		if(i+1 < A.size())
		{
			a.push_back(A[i+1][i]);
			c.push_back(A[i][i+1]);
		}
		b.push_back(A[i][i]);
	}
	
	x = thomas(a,b,c,sol);

	return x;

}

std::vector<std::vector<double>> makeTriDiag(int n)
{
	
	std::vector<std::vector<double> > A(n,std::vector<double>(n,0));
		
	for (int i = 0; i < A.size(); ++i)
	{
		if(i+1 < A.size())
		{
			A[i+1][i] = 1;
			A[i][i+1] = 1;
		}
			A[i][i] = -2;
	}
	return A;
}

double vectorNorm2(std::vector<double> &n)
{
	double vectNorm2 = 0.0;
	for(auto &&e: n)
	{
		vectNorm2 += std::pow(e,2);
	}

	vectNorm2 = std::abs(vectNorm2);

	return std::sqrt(vectNorm2);
}

double vectorNormInf(std::vector<double> &n)
{
	std::vector<double> a;
	double vectNormInf = 0.0;

	for(auto &&e: n)
	{
		a.push_back(std::abs(e));
	}

	vectNormInf = *std::max_element(a.begin(),a.end());

	return vectNormInf;
}

#endif
