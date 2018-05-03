# Numerical Solutions Software Manual

## **Routine Name:** thomas

**Author:** Nitasha Jeske

**Language:** C++

**Description:** The thomas algorithm solves a linear system of equations with a tridiagonal matrix using gaussian elimination. 

**Input:** A tridiagonal matrix will be passed in as 3 vectors, subdiag, diag, and supdiag. Each of these vectors are of type double.  

**Output:** The routine will produce an approximate solution to the system as a vector of doubles.

**Code:** 
```C++
Vec thomas(Vec subdiag, Vec maindiag, Vec supdiag, Vec b){
    chrono::duration<double> time1;
    auto start = chrono::high_resolution_clock::now();
    for (int i=0; i < subdiag.size(); i++){
        double lik=subdiag[i]/maindiag[i];
        maindiag[i+1]=maindiag[i+1]-lik*supdiag[i];
        b[i+1]=b[i+1]-lik*b[i];
    }
    for (int i = (int)maindiag.size()-1; i>0; i--){
        double lik2=supdiag[i-1]/maindiag[i];
        b[i-1]=b[i-1]-lik2*b[i];
    }
    vector <double> x;
    for (int i=0; i < maindiag.size(); i++){
        x.push_back(b[i]/maindiag[i]);
    }
    auto end=chrono::high_resolution_clock::now();
    time1=end-start;
    cout<<time1.count()<<endl;
    return x;
}

```

**Example:**
```C++
#include <cmath>
#include <iostream>
using namespace std;

void Print (Vec a){
    for (int i=0; i < a.size(); i++){
        cout << a[i] << endl;
    }
    cout << endl;
}

int main(){
    Print(thomas({1,2},{1,2,3},{1,2}, {2,5,5}));
}
```

**Results:** 
```C++
3.185e-06
1
1
1
```

**Last Modification Date:** Feb 1, 2018
