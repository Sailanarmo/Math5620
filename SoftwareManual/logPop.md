# Numerical Solutions Software Manual

## **Routine Name:** logPop

**Author:** Nitasha Jeske

**Language:** C++

**Description:** The analytic solution for the logistic model of population growth initial value problem of the form P' = gamma P + beta P^2, P(0)=p0.

**Input:**  The function takes a double of the parameters alpha and lambda and a double t, the point at which the user desires the value of u. 

**Output:** The function outputs the value of u at the given value t.  

**Code:**
```C++
double logPop(double gamma, double beta, double p0, double t){
    double c = log(1/(-beta + gamma/p0))/gamma;
    return (gamma*exp(gamma*(c+t)))/(beta*exp(gamma*(c+t))+1);
}
```

**Example:**
```C++
int main(){
    cout << "For gamma=0.1, beta=0.0001 , p0=25, t=1.5 : " << endl;
    cout << "Analytic sol: u = " << logPop(.1,.0001,25, 1.5) << endl;

    cout << "For gamma=0.1, beta=0.0001 , p0=40000, t=.5 : " << endl;
    cout << "Analytic sol: u = " << logPop(.1,.0001,40000, .5) << endl;
}
```

**Results:**  
```
For gamma=0.1, beta=0.0001 , p0=25, t=1.5 : 
Analytic sol: u = 28.9288
For gamma=0.1, beta=0.0001 , p0=40000, t=.5 : 
Analytic sol: u = nan
```

**Last Modification Date:** March 27 , 2018
