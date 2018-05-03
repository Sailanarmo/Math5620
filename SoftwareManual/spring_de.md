# Numerical Solutions Software Manual

## **Routine Name:** spring_de

**Author:** Nitasha Jeske

**Language:** C++

**Description:** This routine takes the constants and initial condition as input and produces the value of the solution at a given point. This routine will be useful for testing numerical methods. 

**Input:** Inputs will be the constants of the differential equation, m, c, and k. Then the initial values, p0 and v0 can be used to calculate c1 and c2 using the equations c1 + c2 + u1 + u2 = p0 and r1c1 + r2c2 + r1u1 + u1'e^r1t + u2'e^r2t = v0. Where u1 = - integral from 0 to t of (e^r2sf(s))/((r2-r1)e^(r1+r2)s)ds and  u2 = integral from 0 to t of (e^r1sf(s))/((r2-r1)e^(r1+r2)s)ds. The arbitrary point t we want to evaluate y at is also passed in. 

**Output:** The routine will produce an approximate answer for y(t).

**Code:** 
```C++
double spring_de(double m, double c, double k, double c1, double c2, double u1, double u2, double t){
    double r1=(-c+sqrt(c*c-4*m*k))/(2*m);
    double r2=(-c-sqrt(c*c-4*m*k))/(2*m);
    double y_c=c1*pow(2.7182818284,r1*t)+c2*pow(2.7182818284,r2*t);
    double y_p=u1*pow(2.7182818284,r1*t)+u2*pow(2.7182818284,r2*t);
    return y_c+y_p;
}
```

**Example:**
```C++
#include <cmath>
#include <iostream>
using namespace std;

int main(){
    cout << spring_de(1,3,2,1,-1,3,4,0);
    cout << spring_de(1,3,2,1,-1,3,4,2);
}
```

**Results:** 
```C++
7
0.596288
```

**Last Modification Date:** Jan. 19, 2018
