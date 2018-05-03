# Numerical Solutions Software Manual

## **Routine Name:** log_de

**Author:** Nitasha Jeske

**Language:** C++

**Description:** This routine takes the constants and initial condition as input and produces the value of the solution at a given point. This routine will be useful for testing numerical methods. 

**Input:** Inputs will be alpha and beta, constants in the differential equation, p0, the initial condition on P(0), and the arbitrary point t we want to evaluate P at. 

**Output:** The routine will produce an approximate answer for P(t).

**Code:** 
```C++
double log_de(double alpha, double beta, double p0, double t){
    double denom=(alpha/p0-beta)*pow(2.7182818284,-alpha*t)+beta;
    return alpha/denom;
}
```

**Example:**
```C++
#include <cmath>
#include <iostream>
using namespace std;

int main(){
    cout << log_de(1, 2, 1, 0);
    cout << log_de(-.5, 1.2345, .5, 2.5);
}
```

**Results:** 
```C++
1
0.0761653
```

**Last Modification Date:** Jan. 19, 2018
