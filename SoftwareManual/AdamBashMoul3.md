# Numerical Solutions Software Manual

## **Routine Name:** AdamBashMoul3

**Author:** Nitasha Jeske

**Language:** C++

**Description:** This routine uses a predictor corrector method to solve a differential equation of the form u' = lambda u, u(0)=alpha. It does this by predicting using a fourth order Adams-Bashforth method, and using a correction step predicted by the value in a third order Adams-Moulton setting. The intial values for the Adams-Bashforth method are generated using the respective number of steps in a Runge Kutta order 4 method. 

**Input:**  The function takes the initial value (x0, y0), the value x you want to find, the interval h, and the string f corresponding to the du/dt function. 

**Output:** The function outputs a double which represents u, the value of the function at the desired x. 

**Code:**
```C++
double AdamBashMoul3(double x0, double y0, double x, double h, string f){
    double x1=x0+h;
    double x2=x0+2*h;
    double x3=x0+3*h;
    double y1 = RungeKutta4(x0, y0, x1, h, f);
    double y2 = RungeKutta4(x0, y0, x2, h, f);
    double y3 = RungeKutta4(x0, y0, x3, h, f);
    int n = (x-x0)/h-3;
    for (int i=0; i<n; i++){
        double x4=x3+h;
        double y_star = y3 + h/24*(-9*func2(x0, y0, f) + 37*func2(x1, y1, f) - 59*func2(x2, y2, f)+55*func2(x3, y3, f));
        double y4 = y3 + h/24 * (func2(x1, y1, f) - 5 * func2(x2, y2, f) + 19*func2(x3, y3, f)+9*func2(x4, y_star, f));
        x0=x1; x1=x2; x2=x3; x3=x4;
        y0=y1; y1=y2; y2=y3; y3=y4;
    }
    return y3;
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
    cout << "Adam-Bash-Moul 3: " << AdamBashMoul3(0, 1, .5, .01, "f1") << endl << endl;

    cout << "For alpha=2, lambda=-1, t=1.5 : " << endl;
    cout << "Adam-Bash-Moul 3: " << AdamBashMoul3(0, 2, 1.5, .01, "f2") << endl << endl;

    cout << "For alpha=1, lambda=-100, t=1.5 : " << endl;
    cout << "Adam-Bash-Moul 3: " << AdamBashMoul3(0, .5, 1.5, .01, "f3") << endl << endl;

    cout << "For gamma=0.1, beta=0.0001 , p0=25, t=1.5 : " << endl;
    cout << "Adam-Bash-Moul 3: " << AdamBashMoul3(0, 25, 1.5, .01, "f4") << endl << endl;

    cout << "For gamma=0.1, beta=0.0001 , p0=40000, t=.5 : " << endl;
    cout << "Adam-Bash-Moul 3: " << AdamBashMoul3(0, 40000, .5, .01, "f4") << endl << endl;
}
```

**Results:**  
```
For alpha=1, lambda=1, t=.5 : 
Runge Kutta 4: 1.64872

For alpha=2, lambda=-1, t=1.5 : 
Runge Kutta 4: 0.44626

For alpha=1, lambda=-100, t=1.5 : 
Runge Kutta 4: -2.77456e-16

For gamma=0.1, beta=0.0001 , p0=25, t=1.5 : 
Runge Kutta 4: 28.9288

For gamma=0.1, beta=0.0001 , p0=40000, t=.5 : 
Runge Kutta 4: 13783.6

```

**Last Modification Date:** March 30, 2018
