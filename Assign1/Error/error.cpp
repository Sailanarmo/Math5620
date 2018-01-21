#include <iostream>
#include <cmath>

double absError(double x, double y)
{
	return std::abs(x - y);
}

double relError(double x, double y)
{
	return (std::abs(absError(x,y))/std::abs(y));
}

int main()
{
	double real = 1.0;
	double est = 1.1;

	std::cout << "Absolute Error: " << absError(real,est) << std::endl;
	std::cout << "Relative Error: " << relError(real,est) << std::endl;

}
