# Math 5620 Implicit Euler

**Author:** Raul Ramirez

**Description/Purpose:** 
This code was asked for us to compute problem 3 in the homework that we were given. Implicit Euler, is a method better known as a backwards Euler method. 

**Input:** 
There are no inputs needed from the user, however, the Utilities folder contains the Matrix Gen file that contains the Implicit Euler function.

**Output:** 
This program will return a double once the solution is reached.

**Code:**
```cpp
template <typename T, typename F>
double implicitEuler(F f, T df, T x0, T t0, T tf, int iter)
{
	double h = (tf-t0)/n;
	double t = linespace(t0,tf,n+1);
	double y = 0.0;

	for (int i = 0; i < iter; ++i)
	{
		x0 = y;
		x1 = inv(eye(length(y0))-h*feval(df,t(i),x0))*(x0-h*feval(f,t(i),x0)-y);
		x1 = newtons(f, dt, x0);
		y = x1;
	}

	return y;
}
```

**Results**
```
lambda = 1
exact = 18.2212
approximation = 18.2212

lambda = -1
exact = 5.48812
approximation = 5.48813

lambda = 100
exact = 2.35385e+18
approximation = failed

p0 = 25
exact = 26.5049
approximation = 26.5049

p0 = 40000
exact = 12228
approximation = 12228.2
```

**Last Modified:** April 2018
