# Math 5620 Runge Kutta Method

**Author:** Raul Ramirez

**Description/Purpose:** 
This code was asked for us to compute problem 4 in the homework assignment. is in a family of implicit and explicit iterative methods, which include the well-known routine called the Euler Method, used in temporal discretization for the approximate solutions of ordinary differential equations. These methods were developed around 1900 by the German mathematicians C. Runge and M. W. Kutta.

**Input:** 
There are no inputs needed from the user, however, the Utilities folder contains the Matrix Gen file that contains the appropriate methods.

**Output:** 
This program will take a matrix A and a vector B and return the solution.

**Code:**
```cpp
template <typename T, typename F>
T runge_kutta_order2(F f, unsigned int n, T h, T x0, T y0)
{
	long double y[n], x[n], k[n][n];

	x[0] = x0;
	y[0] = y0;

	for (auto i = 1u; i <= n; i++)
	{
		x[i] = x[i - 1] + h;
	}

	for (auto j = 1u; j <= n; j++)
	{
		k[1][j] = h * f(x[j - 1], y[j - 1]);
		std::cout << "K[1] = " << k[1][j] << "\t";
		k[2][j] = h * f(x[j - 1] + h, y[j - 1] + k[1][j]);
		std::cout << "K[2] = " << k[2][j] << "\n";
		y[j] = y[j - 1] + ((k[1][j] + k[2][j]) / 2);
		std::cout << "y[" << h * j << "] = " << std::setprecision(5) << y[j] << std::endl;
	}
	return y;
}

template <typename T, typename F>
T runge_kutta_order4(F f, unsigned int n, T h, T x0, T y0)
{
	long double y[n], x[n], k[n][n];

	x[0] = x0;
	y[0] = y0;

	for (auto i = 1u; i <= n; i++)
	{
		x[i] = x[i - 1] + h;
	}

	for (auto j = 1u; j <= n; j++)
	{
		k[1][j] = h * f(x[j - 1], y[j - 1]);
		std::cout << "K[1] = " << k[1][j] << "\t";
		k[2][j] = h * f(x[j - 1] + h, y[j - 1] + k[1][j]);
		std::cout << "K[2] = " << k[2][j] << "\n";
		y[j] = y[j - 1] + ((k[1][j] + k[2][j]) / 2);
		std::cout << "y[" << h * j << "] = " << std::setprecision(5) << y[j] << std::endl;
	}
	return y;
}

int main()
{
	std::cout << runge_kutta_order2(0.0,-1.0,0.4,0.1,[](double a,double b){return a*a+2*b;}) << std::endl;	
	std::cout << runge_kutta_order4(0.0,-1.0,0.4,0.1,[](double a,double b){return a*a+2*b;}) << std::endl;	
}
```


**Last Modified:** April 2018
