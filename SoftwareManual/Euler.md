# Numerical Solutions Software Manual

## **Routine Name:** Euler

**Author:** Nitasha Jeske

**Language:** C++

**Description:** Explicit Euler's method is a way to approximate the value of y in a first order differential equation using a form of numerical integration. If the initial value of the curve is given, an unkown value on the curve can be estimated using Euler's.

**Input:**  The function takes the initial value (x0, y0), the value x you want to find, delta T, the string f corresponding to the dy/dx function, the tolerance, and maximum number of iterations. 

**Output:** The function outputs a double which represents y, the value of the function at the desired x. 

**Code:**
```C++
double Euler (double x0, double y0, double x, double deltat, string f, double tol, int maxIter){
    int n=0;
    while (std::abs(x-x0) > tol && n < maxIter){
        y0=y0+(deltat*func(x0,y0, f));
        x0=x0+deltat;
        n++;
    }
    return y0;
}
```

**Example:**
```C++

double func2(double x, double y, string f){
    if (f=="f1") return y;
    if (f=="f2") return -y;
    if (f=="f3") return -100*y;
    if (f=="f4") return .1*y-.0001*pow(y,2);
    else return 0.0;
}

int main(){
    cout << "For alpha=1, lambda=1, t=.5 : " << endl;
    cout << "Explicit Euler: " << Euler(0,1,.5, .01, "f1", .01, 1000) << endl << endl;

    cout << "For alpha=2, lambda=-1, t=1.5 : " << endl;
    cout << "Explicit Euler: " << Euler(0,2,1.5, .01, "f2", .01, 1000) << endl << endl;

    cout << "For alpha=1, lambda=-100, t=1.5 : " << endl;
    cout << "Explicit Euler: " << Euler(0,.5,1.5, .01, "f3", .01, 1000) << endl << endl;

    cout << "For gamma=0.1, beta=0.0001 , p0=25, t=1.5 : " << endl;
    cout << "Explicit Euler: " << Euler(0,25,1.5, .01, "f4", .01, 1000) << endl << endl;

    cout << "For gamma=0.1, beta=0.0001 , p0=40000, t=.5 : " << endl;
    cout << "Explicit Euler: " << Euler(0,40000,.5, .01, "f4", .01, 1000) << endl << endl;

}
```

**Results:**  
```
For alpha=1, lambda=1, t=.5 : 
Explicit Euler: 1.62835

For alpha=2, lambda=-1, t=1.5 : 
Explicit Euler: 0.447377

For alpha=1, lambda=-100, t=1.5 : 
Explicit Euler: 0

For gamma=0.1, beta=0.0001 , p0=25, t=1.5 : 
Explicit Euler: 28.8988

For gamma=0.1, beta=0.0001 , p0=40000, t=.5 : 
Explicit Euler: 13764.8

```

**Last Modification Date:** March 19, 2018
