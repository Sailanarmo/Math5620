# Math 5620 Explicit Euler

**Author:** Raul Ramirez

**Description/Purpose:** 
This code was asked for us to compute problem 2. Euler was used in the last assignment and therefore the description has already been given.

**Input:** 
There are no inputs needed from the user, however, the Utilities folder contains the Matrix Gen file that contains the Explicit Euler Method

**Output:** 
A double with the exact and approximated solutions
**Code:**
```cpp
int main()
{
	
    double dt = 0.00001;
	double alpha = 10.0;
	double beta = 0.0001;
	double gamma = 0.01;
	
	std::vector<double> lambdas {1.0, -1.0, 100.0};
	std::vector<double> P_0 {25.0, 40000.0};

	std::cout << "Lambda" << std::endl;
	for (auto && e: lambdas)
	{
		std::cout << explicitEuler(alpha,beta,gamma, dt, [&](double a, double b) { (void)b; return lambda * a;}) << std::endl;
	}

	std::cout << "Logistic" << std::endl;
	for (auto && e: P_0)
	{
		std::cout << explicitEuler(alpha,beta,gamma, dt, [&](double a, double b) { (void)b; return gamma * a-beta * a * a;}) << std::endl;
	}
}
```

**Results**
```
Lambda = 1
exact = 27.1828
approximation = 27.1824

Lambda = -1
exact = 3.67879
approximation = 3.67881

Lambda = 100
exact = 2.68812e+44
approximation = 2.55455e+44

p0 = 25
exact = 27.5568
approximation = 27.5568

p0 = 40000
exact = 8490.15
approximation = 8490.11
```

**Last Modified:** March 2018
