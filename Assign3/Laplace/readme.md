# Math 5620 Laplace Equations
This routine was written to give an approximate solution of the Laplace equation using different sized meshes in order to compute them

**Routine Name:**           laplace.cpp

**Author:** Raul Ramirez

**Description/Purpose:** 
This code was asked for us to compute problems 5 and 6 on our assignment. We were asked to compute the mesh of the Laplace equation, initialize the matrix and right hand sides, and solve the linear system using an approximate LU Factorization.

**Input:** 
The user will not give any input into the program itself however this program relies heavily on the Utilities folder in the Matrix Generation file. The program also relies on c++17 as it uses a Tuple in order to compute our LU Factorization of our matrix. So in order to compile this program, one must use *g++ -std=c++17 laplace.cpp*, if this is not used, the program will fail to run.

**Output:** 
This program will return two matrices with the output from the 5-Stencil Matrix and the 9-Stencil Matrix. It is also interesting to know, that the matrices are Symmetric. 

```
5 Stencil Matrix:
-0.097 -0.163 -0.154
-0.163 -0.276 -0.266
-0.154 -0.266 -0.266

9 Stencil Matrix:
-0.00427 -0.00718 -0.00678
-0.00718 -0.0123  -0.0119
-0.00678 -0.0119  -0.0124
```

**Code:**
```cpp
int main()
{
	
	std::vector<std::pair<double,double>> container;

	std::vector<double> sinVector = computeSinVector(container, 5.0);		
	
	std::vector<double> solution = solveLU(A,sinVector);	
	std::vector<std::vector<double>> answer = convertToMatrix(solution);	
	std::cout << std::endl;
	std::cout << "5 Stencil Matrix: " << std::endl;
	printMatrix(answer);
	
	sinVector.clear();
	container.clear();
		
	sinVector = computeSinVector(container, 9.0);		
	std::vector<double> solution2 = solveLU(E,sinVector);
	std::vector<std::vector<double>> answer2 = convertToMatrix(solution2);
	std::cout << "9 Stencil Matrix: " << std::endl;
	printMatrix(answer2);

}
```


**Last Modified:** March/2018
