# Spring

## Description of Program:
This program calculates the Spring Mass system for a differential equation. Since we are not given a specific function to solve for in the particular solution, it is currently stubbed off as to not cause any issues with the program.

## Spring Function:

The Spring function takes two initial conditions y_0 and t_0. It then takes an m, gamma, and k constants for our differential equation. Finally, t represents the differential equation over time. Currently, this is not spec'd out to solve complex differential equations if the square root of gamma^2 - 4mk.

```cpp
double spring(double y_0, double v_0, double m, double gamma, double k, double t);
```

## The Output
The output of the program should look like this:
```
Solution for the Spring Mass System: 6.58087e-06
```

## The Code

Again, as the description states, this is the complete function that will compute the solution for the Spring Mass System, with a check to see if the square root is negative.
```cpp
double spring(double y_0, double v_0, double m, double gamma, double k, double t)
{
	if (std::sqrt((std::pow(gamma,2)-4*(m)*(k)) < 0))
	{
		std::cout << "Please choose a gamma^2 - 4mk that will not result in a complex number." << std::endl;
		return 1.0;
	}

	double r_1 = -gamma + std::sqrt((std::pow(gamma,2)-4*(m)*(k)));
	double r_2 = -gamma - std::sqrt((std::pow(gamma,2)-4*(m)*(k)));

	return (((v_0 - r_2*y_0)/(r_1-r_2))*std::exp(r_1*t) + ((r_1*y_0 - v_0)/(r_1-r_2))*std::exp(r_2*t));

}
```

### Last Modified: 1-22-2018
### Author: Raul Ramirez
