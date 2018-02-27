#ifndef MATRIX_GENERATOR_HPP
#define MATRIX_GENERATOR_HPP

#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <tuple>


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

std::vector<std::vector<double>> matrixAdd(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &B)
{
	int n = A.size();
	std::vector<std::vector<double> > sum(n,std::vector<double>(n,0));

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			sum[i][j] = A[i][j] + B[i][j];
		}
	}

	return sum;
}

std::vector<std::vector<double>> matrixDiff(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &B)
{
	int n = A.size();
	std::vector<std::vector<double> > diff(n,std::vector<double>(n,0));

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			diff[i][j] = A[i][j] - B[i][j];
		}
	}

	return diff;
}

template <typename F>
std::vector<std::vector<double>> matrixDiff(F f, std::vector<std::vector<double>> &B)
{
	int n = B.size();
	std::vector<std::vector<double> > diff(n,std::vector<double>(n,0));

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			diff[i][j] = f[i][j] - B[i][j];
		}
	}

	return diff;
}

std::vector<std::vector<double>> matrixProd(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &B)
{
	int n = A.size();
	std::vector<std::vector<double>> prod(n,std::vector<double>(n,0));
		std::cout << "A: " << std::endl;
		for(auto&&e: A)
		{
			for(auto&&f:e)
			{
				std::cout << f << " ";
			}
			std::cout << std::endl;
		}	
		std::cout << std::endl;
		std::cout << "B: " << std::endl;
		for(auto&&e: B)
		{
			for(auto&&f:e)
			{
				std::cout << f << " ";
			}
			std::cout << std::endl;
		}	
		std::cout << std::endl;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			prod[i][j] = 0;
			for(int k = 0; k < n; ++k)
			{
				prod[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	std::cout << "Prod: " << std::endl;
		for(auto&&e: prod)
		{
			for(auto&&f:e)
			{
				std::cout << f << " ";
			}
			std::cout << std::endl;
		}	
		std::cout << std::endl;
	return prod;
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

std::tuple<std::vector<std::vector<double>>, std::vector<std::vector<double>>, std::vector<std::vector<double>> > lUFactorize(std::vector<std::vector<double>> &A)
{
	int n = A.size();
	int max = 0;
	double largest = 0.0;

	std::vector<std::vector<double>> L(A.size(),std::vector<double>(A.size(),0));
	std::vector<std::vector<double>> U(A.size(),std::vector<double>(A.size(),0));
	std::vector<std::vector<double>> I(A.size(),std::vector<double>(A.size(),0));
	std::vector<std::vector<double>> P(A.size(),std::vector<double>(A.size(),0));
	std::vector<std::vector<double>> Slam(A.size(),std::vector<double>(A.size(),0));
	std::vector<std::vector<double>> temp(A.size(),std::vector<double>(A.size(),0));

	for(int i = 0; i < n; ++i)
	{
		I[i][i] = 1;
	}
	
	P = I;
	U = A;

	
		
	for(int j = 0; j < n-1; ++j)
	{
		largest = U[j][j];
		max = j;
		for(int i = 1; i < n; ++i)
		{
			if(std::abs(largest) < std::abs(U[i][j]))
			{
				largest = U[i][j];
				max = i;
			}
		}
		
		std::cout << "Largest: " << largest << " Max: " << max << std::endl;
		if(largest != j)
		{
			std::swap(U[j],U[max]);
			std::swap(L[j],L[max]);
			std::swap(P[j],P[max]);
		}

		std::cout << "U: " << std::endl;
		for(auto&&e: U)
		{
			for(auto&&f:e)
			{
				std::cout << f << " ";
			}
			std::cout << std::endl;
		}	
		std::cout << std::endl;
		double pivot = U[j][j];

		Slam = I;
		std::cout << "Slam: " << std::endl;
		for(auto&&e: Slam)
		{
			for(auto&&f:e)
			{
				std::cout << f << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for(int i = j+1; i < n; ++i)
		{
			Slam[i][j] = -U[i][j]/pivot;
		}
		
		std::cout << "U: " << std::endl;
		for(auto&&e: U)
		{
			for(auto&&f:e)
			{
				std::cout << f << " ";
			}
			std::cout << std::endl;
		}	
		std::cout << std::endl;
		std::cout << "Slam: " << std::endl;
		for(auto&&e: Slam)
		{
			for(auto&&f:e)
			{
				std::cout << f << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		L = matrixDiff(matrixAdd(L,I),Slam);
		U = matrixProd(Slam, U);
		
		std::cout << "U: " << std::endl;
		for(auto&&e: U)
		{
			for(auto&&f:e)
			{
				std::cout << f << " ";
			}
			std::cout << std::endl;
		}
	}

	L = matrixAdd(I,L);
	
	return {L,U,P};

}

std::vector<double> solveLU(std::vector<std::vector<double>> &L, std::vector<std::vector<double>> &U, std::vector<double> &b)
{
	int sum = 0;
	std::vector<double> x(L.size(),0);
	std::vector<double> z(L.size(),0);

	for (int i = 0; i < L.size(); ++i)
	{
		sum = 0;
		for(int j = 0; j < i; ++j)
		{
			sum+=L[i][j]*z[j];
		}
		z[i]=(b[i]-sum)/L[i][i];
	}
	
	for (int i = L.size()-1; i > 0; --i)
	{
		sum = 0;
		for(int j = L.size()-1; j > i; --j)
		{
			sum+=U[i][j]*x[j];
		}
		x[i]=(z[i]-sum)/U[i][i];
	}

	return x;
}

#endif
