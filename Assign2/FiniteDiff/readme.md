# Computational Mathematics Software Manual

## **Routine Name:** Finite Difference Approximation

**Author:** Raul Ramirez

**Language:** C++

**Description:** Using the LU Factorization routine, we compute what the coefficient matrix should look like with some error in there. This was asked for us to in Problem 1 of our homework assignment. 
    
**Input:**  There are no user inputs for this program as this relies on other functions provided by the matrixGen.hpp file in the Utilities folder.

**Output:** The matrix containing the finite difference coeficients in a tridiagonal matrix. 

**Code:**
```C++
std::tuple<std::vector<std::vector<double>>, std::vector<std::vector<double>>, std::vector<std::vector<double>> > lUFactorize(std::vector<std::vector<double>> &A)
{
	int n = A.size();
	int max;
	double largest;

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

	
		
	for(int j = 0; j < n; ++j)
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
		
		std::cout << largest << " " << max << std::endl;
		if(max != j)
		{
			std::swap(U[j],U[max]);
			std::swap(L[j],L[max]);
			std::swap(P[j],P[max]);
		}
		for(auto&&e: U)
		{
			for(auto&&f:e)
			{
				std::cout << f << " ";
			}
			std::cout << std::endl;
		}	
		double pivot = U[j][j];

		Slam = I;

		for(int i = j+1; i < n; ++i)
		{
			Slam[i][j] = -U[i][j]/pivot;
		}
		
		L = matrixDiff(matrixAdd(L,I),Slam);
		U = matrixProd(Slam, U);
		
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
```

**Example:**

**Output**
```
-2 1 0
1 -2 1
0 1 -2
```
**Last Modification Date:** November 2017
