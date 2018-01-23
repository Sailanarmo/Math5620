# Logistics

## Description of Program:
This program attempts to solve the logistic differential equation assigned in our homework. This was initially solved by hand and was then coded to attempt to solve the differential equation.

## Logistics Function:
This function takes a double alpha, double beta, double p_0, and a double t. The function then returns the solution of the differential equation given by the values.

```cpp
double logistics(double alpha, double beta, double p_0, double t);
```

## The Output
The output of the program should look like this:
```
Solution for the Logistics Differential Equation: 1.44115
```

## The Code
This code simply returns the solution to the differential equation. With the appropriate parameters, we get the solution as stated above.
```cpp
double logistics(double alpha, double beta, double p_0, double t)
{
	return ((alpha/(((alpha)/p_0 + beta)*std::exp(-alpha*t) + beta)));
}
```

### Last Modified: 1-22-2018
### Author: Raul Ramirez
