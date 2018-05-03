# Numerical Solutions Software Manual

## **Routine Name:** lusolve

**Author:** Nitasha Jeske

**Language:** C++

**Description:** This code computes the LU factorization of a matrix with scaled partial pivoting. It does this by first identifying the largest scaled pivot in the remaining rows, switching rows if necessary, and then doing a Gaussian elimination step to reduce the rows below. It replaces the lower triagular entries with the l_i,k factor used to reduce rows, while replacing the upper triangular entries with the Gauss reduced matrix. Then uses forward substitution on Ly=Pb, and backward substitution on Ux=Y.

**Input:**  The input to the lufactor routine is a matrix and the input to the solveLY

**Output:** The lufactor routine returns a matrix which contains the L matrix as the entries below the diagonal, and the U matrix as the diagonal and entries above the diagonal. Then the lusolve routine uses the lufactor matrix and returns a vector x, which is the approximate solution to the system of equations. 

**Code:**
```C++
tuple <Matrix, Matrix> lufactor(Matrix matrix1){
    int rows = (int)matrix1[0].size();
    vector <int> map (matrix1[0].size());
    vector <double> S (rows);
    Matrix Perm (rows, Vec(rows,0));
    for (int i=0; i<rows; i++){
        Perm[i][i]=1;
    }
    for (int k=0; k<rows; k++){
        S[k]=VnormInf(matrix1[k]);
    }
    for (int k=0; k<rows; k++){
        int maxRow=k;
        double maxVal=matrix1[k][k]/S[k];
        for (int i=k+1; i<rows; i++){
            double val=matrix1[i][k]/S[i];
            if (abs(val)>abs(maxVal)){
                maxVal=val;
                maxRow=i;
                swap(matrix1[maxRow],matrix1[k]);
                swap(Perm[maxRow],Perm[maxRow]);
                swap(map[maxRow], map[k]);
                swap(Perm[maxRow], Perm[k]);
            }
        }
        for (int i=k+1; i<matrix1.size(); i++){
            double lik=matrix1[i][k]/matrix1[k][k];
            for (int j=k+1; j<matrix1[0].size(); j++){
                matrix1[i][j]=matrix1[i][j]-lik*matrix1[k][j];
            }
            matrix1[i][k]=lik;
        }
    }
    return {matrix1,Perm};
}

Vec lusolve (Matrix matrix1, Vec b){
    auto [LU, Perm] = lufactor(matrix1);
    Vec Pb = matrixvec(Perm, b);
    Vec y = forward_sub(LU, Pb);
    Vec x = back_sub(LU, y);
    return x; // change to x
}

```

**Example:**
```C++
#include <cmath>
#include <iostream>
# include <vector>
using namespace std;

typedef vector <vector <double>> Matrix;
typedef vector <double> Vec;

double maxEntry (vector <double> vec){
    double current=max(abs(vec[0]), abs(vec[1]));
    for (int i=2; i < vec.size(); i++){
        current=max(current, abs(vec[i]));
    }
    return current;
}

double VnormInf (vector <double> vec){
    double maximum= maxEntry(vec);
    return maximum;
}

Matrix initMatrix (int row, int col){
    Matrix randmatrix (row, vector <double> (col));
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            randmatrix[i][j]=rand()%50;
        }
    }
    return randmatrix;
}

void Print(Matrix matrix1){
    for (int i=0; i<matrix1.size(); i++){
        for (int j=0; j<matrix1[0].size();j++){
            cout<< matrix1[i][j] << "  ";
        }
        cout << endl;
    }
}

int main(){
    Matrix matrix2={{2,1,-4, 3},{5, -6, 2, 1}, {3, 1, 0, -2}, {4, 5, 0, -3}};
    Vec vec1 = {1,2,3,4};
    Print(lusolve(matrix2, vec1));
}
```

**Results:**  
```
0.6171875
-0.0546875
-0.40625
-0.6015625
```

**Last Modification Date:** Feb. 7, 2017
