#include <iostream>
#include <cmath>


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


int main()
{
	std::cout << spring(1.0,1.5,2.0,6.0,2.0,8.0) << std::endl;
}
