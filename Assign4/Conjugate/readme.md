# Math 5620 Conjugate Gradient
This is an application of the Conjugate Gradient Method

**Author:** Raul Ramirez

**Description/Purpose:** 
This code was asked for us to compute problem 3.

**Input:** 
There are no inputs needed from the user, however, the Utilities folder contains the Matrix Gen file that contains the Conjugate Gradient method within.

**Output:** 
This program will compute the mesh, initialize the matrix, and solve using the conjugate gradient Method.

**Code:**
```cpp
int main()
{
	
	std::vector<std::vector<double>> mesh = computeMesh();	
	
	std::vector<double> bv = initMatrix(mesh);
	std::vector<double> Conjugate = conjugate(mesh,bv);	

	std::cout << "Mesh:" << std::endl;
	printMatrix(mesh);
	std::cout << "bv:" << std::endl;
	printVector(bv);
	
	std::cout << "Solution: " << std::endl;	
	printMatrix(Conjugate);
}
```

**Results**
```
Mesh:
0.0625 0.125 0.188
0.125  0.25  0.375
0.188  0.375 0.562

bv:
0.0625 0.125 0.186 0.125 0.247 0.366 0.186 0.366 0.533

Solution:
-0.097 -0.163 -0.154
-0.163 -0.276 -0.266
-0.154 -0.266 -0.266
```

**Last Modified:** March 2018
