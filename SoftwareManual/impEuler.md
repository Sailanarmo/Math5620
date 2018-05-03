# Numerical Solutions Software Manual

## **Routine Name:** impEuler

**Author:** Nitasha Jeske

**Language:** C++

**Description:** Implicit Euler's method is a way to approximate the value of y in a first order differential equation using a form of numerical integration and Newton's method of finding roots. If the initial value of the curve is given, an unkown value on the curve can be estimated using implicit Euler's.

**Input:**  The function takes the initial value (x0, y0), the value x you want to find, delta T, the string f corresponding to the dy/dx function, the tolerance, and maximum number of iterations. 

**Output:** The function outputs a double which represents y, the value of the function at the desired x. 

**Code:**
```C++
double impEuler(double x0, double y0, double x, double deltat, string f, string df, double tol, int maxIter){
    int n=0;
    while (std::abs(x-x0) > tol && n <maxIter){
        x0=x0+deltat;
        double y1a = newton(y0, f, df, tol, maxIter);
        y0=y0+deltat*func2(x0, y1a, f);
        n++;
    }
    return y0;
}

```

**Example:**
```C++
//  g and g' functions or newtons method
double func(double y, string f, double yk){
    float h=.01;
    if (f=="f1") return y-yk - h*y;
    if (f=="df1") return 1-h;
    if (f=="f2") return y- yk + h*y;
    if (f=="df2") return 1+h;
    if (f=="f3") return y- yk + 100*h*y;
    if (f=="df3") return 1+100*h;
    if (f=="f4") return y- yk - h*(.1*y-.0001*y*y);
    if (f=="df4") return 1-.1*h+.0002*h*y;
    else return 0.0;
}

double newton(double x0, string f, string df, double tol, int maxIter){
    // initialize variables, and calculate initial value of function and derivative
    double error=10*tol;
    int count=0;
    double yk = x0;
    double f0=func(x0, f, yk);
    double fp0=func(x0,df, yk);
    // until the tolerance is less than error or max # of iterations is exceeded
    while(error > tol && count < maxIter){
        // checks to see if derivative is zero (less than machine epsilon)
        if(abs(fp0)<1.11022e-16){
            // if so output error message and quit program
            cout <<"Derivative is zero. Pleas input different guess."<< endl;
            return EXIT_SUCCESS;
        }
        count++;
        // identify a closer approximation
        double x= x0-f0/fp0;
        // find the error
        double error0=abs(x-x0);
        // check that the sequence is converging
        if(count>2 && error < error0){
            // if not output error message and quit program
            cout << "Please choose a point with a sufficiently small interval for which the sequence    will converge." << endl;
            return EXIT_SUCCESS;
        }
        error=error0;
        //take that point to be the new guess
        x0=x;
        // evaluate the function and derivative at new guess
        f0=func(x0,f, yk);
        fp0=func(x0,df, yk);
    }
    // when the tolerance is less than the error the approximation will be returned
    return x0;
}

double func2(double x, double y, string f){
    if (f=="f1") return y;
    if (f=="f2") return -y;
    if (f=="f3") return -100*y;
    if (f=="f4") return .1*y-.0001*pow(y,2);
    else return 0.0;
}

int main(){
    cout << "For alpha=1, lambda=1, t=.5 : " << endl;
    cout << "Implicit Euler: " << impEuler(0,1,.5, .01, "f1", "df1", .01, 1000) << endl;

    cout << "For alpha=2, lambda=-1, t=1.5 : " << endl;
    cout << "Implicit Euler: " << impEuler(0,2,1.5, .01, "f2", "df2", .01, 1000) << endl;

    cout << "For alpha=1, lambda=-100, t=1.5 : " << endl;
    cout << "Implicit Euler: " << impEuler(0,.5,1.5, .01, "f3", "df3", .01, 1000) << endl;
    
    cout << "For gamma=0.1, beta=0.0001 , p0=25, t=1.5 : " << endl;
    cout << "Implicit Euler: " << impEuler(0,25,1.5, .01, "f4", "df4", .01, 1000) << endl;

    cout << "For gamma=0.1, beta=0.0001 , p0=40000, t=.5 : " << endl;
    cout << "Implicit Euler: " << impEuler(0,40000,.5, .01, "f4", "df4", .01, 1000) << endl;
}
```

**Results:**  
```
For alpha=1, lambda=1, t=.5 : 
Implicit Euler: 1.63635

For alpha=2, lambda=-1, t=1.5 : 
Implicit Euler: 0.454094

For alpha=1, lambda=-100, t=1.5 : 
Implicit Euler: 7.00649e-46

For gamma=0.1, beta=0.0001 , p0=25, t=1.5 : 
Implicit Euler: 28.9027

For gamma=0.1, beta=0.0001 , p0=40000, t=.5 : 
Implicit Euler: 14154.7

```

**Last Modification Date:** April 1, 2018
