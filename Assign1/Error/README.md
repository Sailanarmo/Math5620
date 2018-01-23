# Error

## Description of Program:
This program returns the absolute error and the relative error of two variables.

## Absolute Error Function:
The Absolute Error Function takes two arguments x and y. It then returns the absolute value of x - y.
```cpp
double absError(double x, double y);
```
## Relative Error Function:
The Relative Error Function takes two arguments x and y. It then returns the absolute value of the Absolute Error(x,y) divided by the absolute value of y.
```cpp
double relError(double x, double y);
```

## The Output
The output of the program should look like this:
```
Absolute Error: 0.1 
Relative Error: 0.0909091
```

## The Code
These are the two functions in their entirety: 

```cpp
double absError(double x, double y)
{
	return std::abs(x - y);
}

double relError(double x, double y)
{
	return (std::abs(absError(x,y))/std::abs(y));
}
```

### Last Modified: 1-22-2018
### Author: Raul Ramirez
