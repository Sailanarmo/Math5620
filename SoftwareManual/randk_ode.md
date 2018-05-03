# Numerical Solutions Software Manual

## **Routine Name:** randk_ode

**Author:** Nitasha Jeske

**Language:** C++

**Description:** This routine computes the finite difference approximate solution of the elliptic ode, by defining the value at the grid lines using the mesh points. The function k(x) is generated with random numbers between 10 and 50. 

**Input:** Inputs will be doubles, a and b, and integers m and n.

**Output:** The routine will produce a vector of the values at half way between the nodes. 

**Code:** 
```C++
void randk_ode(double a, double b, int m, int n){
    int size = 2*floor((m+1)/2)-1+n;
    Vec k(size);
    for ( int i=0; i< size; i++){
        k[i]=rand()%41 + 10;
    }
    Vec coeffs = fdCoeff(m,n);
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

int main(){
    Print(rand_ode(0,1,2,1);
```

**Results:** 
```C++
2.03554
1.39459
0.89169
0.42682
```

**Last Modification Date:** Feb. 7, 2018
