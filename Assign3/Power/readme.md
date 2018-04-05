# Math 5620 Power Methods
This Routine will compute the Largest and Smallest Eigenvalues of a matrix. In this specific use of this routine, we used the Hilbert Matrix and an Elliptic ODE to solve.

**Routine Name:**           power.cpp

**Author:** Raul Ramirez

**Description/Purpose:** 
This code was asked for us to compute problems 2, 3, and 4 of our assignment. Using the Power Method, we computed the Hilbert Matrix, the elliptic ODE, and the inverse power method for the finite difference method in problem 2.  

**Input:** 
The user will not need to put in any input as the Hilbert Matrix is already hard coded in for the user and the elliptic ode is handled by the program as well.

**Output:** 
This program will give us the output for the largest Eigenvalues that we requested for the Hilbert Matrix the Elliptic ODE given to us. It is interesting that the Elliptic ODE will converge to -4 as the size of the Matrix and Vectors grow. It will also compute the smallest Eigenvalue for the Elliptic ODE as well.

```
Largest Eigenvalue for Hilbert Matrix: 1.57 
Largest Eigenvalue for Elliptic ODE of Size: 50 : -3.97
```

**Code:**
```cpp
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
```


**Last Modified:** March/2018
