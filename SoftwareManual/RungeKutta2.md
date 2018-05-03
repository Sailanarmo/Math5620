# Numerical Solutions Software Manual

## **Routine Name:** RungeKutta2

**Author:** Nitasha Jeske

**Language:** C++

**Description:** This routine uses the RungeKutta order 2 equations to solve a differential equation of the form u' = lambda u, u(0)=alpha. 

**Input:**  The function takes the initial value (x0, y0), the value x you want to find, the interval h, and the string f corresponding to the du/dt function. 

**Output:** The function outputs a double which represents u, the value of the function at the desired x. 

**Code:**
```C++
double RungeKutta2(double x0, double y0, double x, double h, string f){
    // Count number of iterations using step size
    int n = (x-x0)/h;

    double k1, k2;
    float y = y0;
    for (int i=0; i<n; i++){
        //runge kutta formulas to find next iter of y
        k1 = h*func2(x0, y, f);
        k2 = h*func2(x0+h/2, y+k1/2, f);

        // update x and y
        x0 = x0 + h;
        y += k2;
    }
    return y;
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
    cout << "Runge Kutta 2: " << RungeKutta2(0, 1, .5, .01, "f1") << endl << endl;

    cout << "For alpha=2, lambda=-1, t=1.5 : " << endl;
    cout << "Runge Kutta 2: " << RungeKutta2(0, 2, 1.5, .01, "f2") << endl << endl;

    cout << "For alpha=1, lambda=-100, t=1.5 : " << endl;
    cout << "Runge Kutta 2: " << RungeKutta2(0, .5, 1.5, .01, "f3") << endl << endl;

    cout << "For gamma=0.1, beta=0.0001 , p0=25, t=1.5 : " << endl;
    cout << "Runge Kutta 2: " << RungeKutta2(0, 25, 1.5, .01, "f4") << endl << endl;

    cout << "For gamma=0.1, beta=0.0001 , p0=40000, t=.5 : " << endl;
    cout << "Runge Kutta 2: " << RungeKutta2(0, 40000, .5, .01, "f4") << endl << endl;
}
```

**Results:**  
```
For alpha=1, lambda=1, t=.5 : 
Runge Kutta 2: 1.64871

For alpha=2, lambda=-1, t=1.5 : 
Runge Kutta 2: 0.446271

For alpha=1, lambda=-100, t=1.5 : 
Runge Kutta 2: 0

For gamma=0.1, beta=0.0001 , p0=25, t=1.5 : 
Runge Kutta 2: 28.9288

For gamma=0.1, beta=0.0001 , p0=40000, t=.5 : 
Runge Kutta 2: 13787

```

**Last Modification Date:** March 30, 2018
