# Computational Mathematics Software Manual

## **Routine Name:** Matrix Norms

**Author:** Raul Ramirez

**Language:** C++

**Description:** This program simply runs a test of matrix norms. It relies on the Norm Library and Matrix Generation library found in the Utilities folder. 
    
**Input:**  There are no user inputs for this program, as the program will handle the various arguments passed in the function parameters.

**Output:** The output will be the 1-Norm and the Infinity-Norm of 1000x1000 matrices produced the program, for example.
```
Matrix1 Norm: 528.35
Matrix Inf Norm: 529.913
```

**Code:**
```C++
double matrixNorm1(std::vector<std::vector<double>> &A)
{
	std::vector<double> max;
	double m1Norm = 0;

	for (unsigned int i = 0; i < A.size(); ++i)
	{
		double sum = 0;
		for (unsigned int j = 0; j < A.size(); ++j)
		{
			sum += std::abs(A[i][j]);
		}
		max.emplace_back(sum);
	}
	
	m1Norm = *std::max_element(max.begin(),max.end());
	
	return m1Norm;
}

double matrixNormInf(std::vector<std::vector<double>> &A)
{
	std::vector<double> max;
	double infNorm = 0.0;

	for (unsigned int i = 0; i < A.size(); ++i)
	{
		double sum = 0.0;
		for (unsigned int j = 0; j < A.size(); ++j)
		{
			sum += std::abs(A[j][i]);
		}
		max.emplace_back(sum);
	}
	infNorm = *std::max_element(max.begin(),max.end());

	return infNorm;
}
```

**Example:**

```C++
int main()
{
	std::vector<std::vector<double>> M = makeMatrix();

	std::cout << "Matrix1 Norm: " << matrixNorm1(M) << std::endl;
	std::cout << "Matrix Inf Norm: " << matrixNormInf(M) << std::endl;

}
```

**Last Modification Date:** March/2018
