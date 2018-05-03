# Numerical Solutions Software Manual

## **Routine Name:** fdCoeff

**Author:** Nitasha Jeske

**Language:** C++

**Description:** This routine computes the coefficients for finite difference approximations of an arbitrary order of accruacy for a given derivative.

**Input:** Inputs will be the mth derivative and accuracy n, both of type integer.

**Output:** The routine will produce a vector of the coefficients. 

**Code:** 
```C++
Vec fdCoeff ( int m, int n){
    int size = 2*floor((m+1)/2)-1+n;
    double p = (size-1)/2;
    Matrix A(size, Vec(size));
    for (int i=0; i<size; i++){
        for ( int j=0; j<size; j++){
            A[i][j]=pow(-p+j, i);
        }
    }
    Vec b (size, 0);
    b[m]=factorial(m);
    Vec x0 (size, 0);
    Vec ans = Jacobi(A, b, x0, .01, 1000);
    return ans;
}

```

**Example:**
```C++
#include <cmath>
#include <iostream>
# include <vector>
using namespace std;

typedef vector <vector <double>> Matrix;
typedef vector <double> Vec;

int factorial (int n){
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main(){
Print(fdCoeff(2,1));
```

**Results:** 
```C++
-1
2
-1
```

**Last Modification Date:** Feb. 6, 2018
