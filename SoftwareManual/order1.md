# Numerical Solutions Software Manual

## **Routine Name:** order1

**Author:** Nitasha Jeske

**Language:** C++

**Description:** The analytic solution for a simple order 1 differential equation of the form u'=lambda u, u(0)=alpha.

**Input:**  The function takes a double of the parameters alpha and lambda and a double t, the point at which the user desires the value of u. 

**Output:** The function outputs the value of u at the given value t.  

**Code:**
```C++
double order1(double alpha, double lambda, double t){
    return alpha*exp(lambda*t);
}
```

**Example:**
```C++
int main(){
    cout << "For alpha=1, lambda=1, t=.5 : " << endl;
    cout << "Analytic sol: u = " << order1(1,1,.5) << endl;

    cout << "For alpha=2, lambda=-1, t=1.5 : " << endl;
    cout << "Analytic solution: " << order1(2,-1,1.5) << endl;

    cout << "For alpha=1, lambda=-100, t=1.5 : " << endl;
    cout << "Analytic sol: u = " << order1(.5,-100,1.5) << endl;
}
```

**Results:**  
```
For alpha=1, lambda=1, t=.5 : 
Analytic sol: u = 1.64872
For alpha=2, lambda=-1, t=1.5 : 
Analytic solution: 0.44626
For alpha=1, lambda=-100, t=1.5 : 
Analytic sol: u = 3.58755e-66
```

**Last Modification Date:** March 27 , 2018
