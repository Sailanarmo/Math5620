# Numerical Solutions Software Manual

## Comparison of Iterations to Convergence for Laplace Equation

Size of matrix | Gauss-Seidel | Jacobi | Conjugate Gradient 
------------ | ------------- | ------------- | -------------
4 x 4 | 6| 9 | 4
9 x 9 | 13 | 21 | 5
16 x 16 | 18 | 30 | 10
25 x 25 | 22 | 37 | 11 
64 x 64 | 27 | 46 | 14 
169 x 169 | 29 | 51 | 14 
576 x 576 | 31 | 55 | 14 

Conjugate Gradient is the fastest method of convergence for the Laplace equation for all sizes my computer could handle. Gauss-Seidel was the next fastest method, and Jacobi had the largest number of iterations to convergence. 


### Code:
```
int main(){
GSLaplace5(4,0,1); //4
GSLaplace5(5,0,1); //9
GSLaplace5(6,0,1); //16
GSLaplace5(7, 0, 1); //25
GSLaplace5(10,0,1); //64
GSLaplace5(15,0,1); //169
GSLaplace5(25,0,1); //576

JLaplace5(4,0,1); //4
JLaplace5(5,0,1); //9
JLaplace5(6,0,1); //16
JLaplace5(7, 0, 1); //25
JLaplace5(10,0,1); //64
JLaplace5(15,0,1); //169
JLaplace5(25,0,1); //576

CGLaplace5(4,0,1); //4
CGLaplace5(5,0,1); //9
CGLaplace5(6,0,1); //16
CGLaplace5(7, 0, 1); //25
CGLaplace5(10,0,1); //64
CGLaplace5(15,0,1); //169
CGLaplace5(25,0,1); //576
}
```
