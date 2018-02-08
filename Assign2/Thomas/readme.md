# Computational Mathematics Software Manual

## **Routine Name:** The Thomas Algorithm

**Author:** Raul Ramirez

**Language:** C++

**Description:** This code is given a tridiagonal matrix to solve for Ax = b. The user will hard code a tridiagonal matrix and a solution vector in order for this compute the system. This reaches into the utilities folder and calls a function called a matrix stripper, which will strip the upper, lower, and middle diagonals of the matrix and call a function name thomas to compute the work.
    
**Input:**  The user must hard code a tridiagonal matrix in order for this to work, and an appropriate solution vector for the method to solve. 

**Output:** The solution to Ax = b is printed out to the screen in the solution vector x.

**Code:**
```C++
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
```

**Example:**

```C++
int main()
{
 
	std::vector<std::vector<double>> M = {{1, 4 ,0 ,0},
										  {3, 4 ,1 ,0},
										  {0, 1, 3, 4},
										  {0, 0, 2, 3}};

	std::vector<double> f = {11,18,9,5};
	std::vector<double> solution;
		
	solution = matrixStripper(M, f);

	for(auto && e: solution)
	{
		std::cout << e << std::endl;
	}
		 
    return 0;
}
```

**Output**
```
3
2
1
1
```
**Last Modification Date:** November 2017
