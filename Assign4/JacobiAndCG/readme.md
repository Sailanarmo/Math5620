# Math 5620 Jacobi and Conjugate Gradient Method
The Jacobi Iteration Method is a method which converges on an answer. If needed, this can be used to compute something that is not too computationally intensive. Conjugate Gradient should just be avoided all together unless you are dealing with a symetric matrix.

**Author:** Raul Ramirez

**Description/Purpose:** 
This code was asked for us to compute problem 2 and to compare with Gauss-Seidel method.

**Input:** 
There are no inputs needed from the user, however, the Utilities folder contains the Matrix Gen file that contains the Jacobi and Conjugate Gradient methods within.

**Output:** 
This program will take a matrix A and a vector B and return the solution.

**Code:**
```cpp
int main()
{
	
	std::vector<std::vector<double>> A = {{16,3},
	                                      {7,-11}};		
	
	std::vector<double> b = {11,13};
	int gaussCounter = 0;	
	int jacobiCounter = 0;	
	int conjugateCounter = 0;	
	std::vector<double> Gauss = gauss(A,b,gaussCounter);	
	std::vector<double> Jacobi = jacobi(A,b,jacobiCounter);	
	std::vector<double> Conjugate = conjugate(A,b,conjugateCounter);	

	std::cout << "A:" << std::endl;
	printMatrix(A);
	std::cout << "b:" << std::endl;
	printVector(b);
	
	std::cout << std::endl;
	std::cout << "Gauss-Seidel Iterations: " << gaussCounter << std::endl;
	printSolution(Gauss);
	std::cout << "Jacobi Method Iterations: " << jacobiCounter << std::endl;
	printSolution(Jacobi);
	std::cout << "Conjugate Method Iterations: " << conjugateCounter << std::endl;
	printSolution(Conjugate);
}
```

**Results**
```
A:
16   3
7  -11

b:
11 13

Gauss-Seidel Iterations: 18
0.812   -0.665

Jacobi Method Iterations: 35
0.812   -0.665

Conjugate Method Iterations: 75
0.812   -0.665
```

**Last Modified:** March 2018
