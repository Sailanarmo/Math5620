# Math 5620 Initial Value Problems

**Author:** Raul Ramirez

**Description/Purpose:** 
This program is designed to solve a First Order Initial Value Problem.

**Input:** 
There is no input given by the user, everything is handled internally. 

**Output:** 
The output will be a series of doubles.

**Code:**
```cpp
double IVP(double lambda, double alpha, int count)
{
	return a * std::exp(l * count);
}

double logistic(double alpha, double beta, double p_0, int count)
{
	return (alpha / (((alpha - p_0 * b/p_0) * std::exp(-a * count) + beta));
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Count: " << i << " IVP: " << IVP(-1.5,7.3,i) << " ";	
		std::cout << " Logistic: " << logistic(2.5,1.7,3.2,i) << std::endl;	
	}
}
```

**Results**
```
Count: 0 IVP: 7.3 Logistic: 3.2
Count: 1 IVP: 1.62885 Logistic: 1.53886
Count: 2 IVP: 0.363446 Logistic: 1.47596
Count: 3 IVP: 0.0810957 Logistic: 1.47103
Count: 4 IVP: 0.0180949 Logistic: 1.47062
Count: 5 IVP: 0.00403752 Logistic: 1.47059
Count: 6 IVP: 0.000900892 Logistic: 1.47059
Count: 7 IVP: 0.000201016 Logistic: 1.47059
Count: 8 IVP: 4.48528e-05 Logistic: 1.47059
Count: 9 IVP: 1.0008e-05 Logistic: 1.47059
```

**Last Modified:** April 2018
