# Computational Mathematics Software Manual

## **Routine Name:** LU Factorization

**Author:** Raul Ramirez

**Language:** C++

**Description:** LU Factorization routine to solve Ax = b. 
    
**Input:**  There are no user inputs for this program, as the program will handle the various arguments passed in the function parameters.

**Output:** The solution to Ax = b is printed out to the screen in the solution vector x.

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
}```

**Example:**

```C++
int main()
{
	
	std::vector<std::vector<double>> A = {{1,3,2},
										  {2,2,1},
										  {4,2,1}};

	std::vector<double> solution = {9,7,9};
	
	auto [L,U,P] = lUFactorize(A);
	
	std::vector<double> sol = solveLU(L,U,solution);

	for (auto &&e: sol)
	{
		std::cout << e << std::endl;
	}
}
```

**Output**

1
2
1

**Last Modification Date:** November 2017
