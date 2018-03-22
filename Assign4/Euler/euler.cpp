#include <iostream>
#include <cmath>
#include <iomanip>

double df(double x, double y)
{
	double a = x+y;
	return a;
}


int main()
{
	
//	int n;
	double x0 = 0.0;
	double y0 = 1.0;
	double x = 0.1;
	double h = 0.025;

	double y = 0.0;
	std::cout.precision(5);
	std::cout.setf(std::ios::fixed);

	while (std::abs(x-x0) > 0.00001)
	{
		y = y0 + (h*df(x0,y0));
		std::cout << x0 << " " << y0 << " " << df(x0,y0) << " " << y << std::endl;
		y0 = y;
		x0 = x0 + h;
	}

	std::cout << x0 << " " << y << std::endl;	
	std::cout << y << std::endl;

}
