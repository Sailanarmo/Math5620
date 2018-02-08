# Math 5620 Elliptic Differential Equation
This routine can compute an Elliptic Differential Equation using the Thomas Algorithm on a finite difference coefficient Matrix. It is also stubbed for future uses.


**Routine Name:**           testEliptic.cpp

**Author:** Raul Ramirez

**Description/Purpose:** 
This code was asked for us to compute problems 3 and 8 on the homework set that we received. Three was to program this problem with a stubbed version to take on future functions. While Problem 8 asked us to solve the Elliptic ODE where f(x) = sin(pi*x), which u(0) = 2.5 and u(1) = 5.0. The program takes this function captured through a lambda, and computes a solution vector using the Thomas Algorithm.

**Input:** 
The user will need to define what the function f(x) is in the future, the user will also need to define what the initial conditions are for the elliptic differential equation. The user will also need to input what size of mesh they would like to compute the code over.

**Output:** 
This program will give back a vector of doubles based on the size of mesh the user has inputed. It will also compute the Vector2 Norm and VectorInf Norm of both the exact solution and the computed solution, the difference will be taken and the error is displayed on the screen.

**Code:**
```cpp
int n = 0;
	const double PI = 3.14159;

	std::cout << "Enter a number for your mesh: ";
	std::cin >> n;
	n = n-1;	
	double a = 0.0;
	double b = 1.0;
	
	double h = ((b-a)/(n+1));
	double u_a = 2.5;
	double u_b = 5.0;
	double vec2Norm = 0.0;	
	double vecInfNorm = 0.0;	
	
	std::vector<std::vector<double>> M = makeTriDiag(n);
	std::vector<double> sol;
	std::vector<double> solution;
	std::vector<double> exactDouble(n,0);
		
	sol = pushSolution([&](double x){return (std::sin(PI*x));}, n, u_a, u_b, a, b);

	solution = matrixStripper(M,sol);

	std::cout << std::endl;	
	std::cout << "Estimated Solution: " << std::endl;
	printVector(solution);

	std::cout << std::endl;

	for (int i = 1; i < n+1; ++i)
	{
		exactDouble[i-1] = exact(a+i*h);		
	}

	std::cout << "Exact Solution: " << std::endl;
	printVector(exactDouble);

	std::cout << std::endl;
	std::cout << "Vector 2 Norm: ";
	vec2Norm = vectorNorm2(exactDouble) - vectorNorm2(solution);
	std::cout << vec2Norm << std::endl;

	std::cout << "Vector Inf Norm: ";
	vecInfNorm = vectorNormInf(exactDouble) - vectorNormInf(solution);
	std::cout << vecInfNorm << std::endl;

```
**Example:**
```
Enter a number for your mesh: 10

Estimated Solution: 
  2.71149
  2.92721
  3.15085
  3.3852
  3.63169
  3.89035
  4.1597
  4.43699
  4.71849

Exact Solution: 
  2.71869
  2.94044
  3.16803
  3.40364
  3.64868
  3.90364
  4.16803
  4.44044
  4.71869

Vector 2 Norm: 0.0303661
Vector Inf Norm: 0.00019691
```


**Last Modified:** September/2017
