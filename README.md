# smlc - A Simple Matrix Library written in C

A very small and basic matrix library written in C. This library is purely written for interest in linear algebra/C programming and is not intended to compete in performance with other well known C/C++ matrix libraries. The intention behind this project is to allow programmers to quickly and easily be able to create and manipulate matrices without having to manually deal with dynamic 2D array allocation.


## Current Supported Matrix Operations
  - matrix addition, subtraction, and multiplication
  - rotating and transposing for NxN matrices
  - calculating determinants of matrices
  - converting matrices to reduced row echelon form
      - LU Decomposition (Guassian Elimination/Reduced row)
      - Cholesky Decomposition
  - solving systems of equations as matrices (using backward substitution)
  - determining linear independence/dependence 
  - calculating eigenvalues and eigenvectors
      - uses power method to find largest eigenvalue and largest eigenvector

## Using the Library - Code Examples

Example 1).
Given this system of equations:

![Alt text](https://cloud.githubusercontent.com/assets/10769110/26473871/a532fc6c-4162-11e7-929a-f7f463d9e15e.gif)

We can solve this system by writing the following code:
```c
Matrix matrix = NewMatrix(3,4);
FillMatrix(matrix);
PrintMatrix(SolveSystem(matrix));
```
where FillMatrix() is a function that allows you to enter matrix values from the console:
```c
void FillMatrix(Matrix matrix){
    for(int i = 0; i < matrix->num_rows; i++){
        for(int j = 0; j < matrix->num_cols; j++){
            printf("Enter value for [%d,%d]: ", i, j);
            scanf("%lf", (*(matrix->index+i)+j));
        }
    }
}
```


Output:
```c
7.0 
5.0 
3.0 
```


Example 2). Say we wanted to find the determinant of the following 5x5 matrix:

![Alt text](https://cloud.githubusercontent.com/assets/10769110/26476253/50f56184-4172-11e7-87ac-b73d8bd819e6.png)

This can be achieved via the following lines:
```c
Matrix matrix = NewMatrix(5,5);
FillMatrix(matrix);
printf("%lf", Determinant(matrix));
```

Output:
```c
-997.00000
```

Note that Determinant() returns a double (as fractions are common in matrices), so it is necessary to pass the "%lf" flag in the printf function in order to produce the correct output. 



Example 3). Say we wanted to find the Chelosky factor of the following Hermitian, positive-definite matrix:

![Alt text](https://cloud.githubusercontent.com/assets/10769110/26476280/85b21e3a-4172-11e7-95e9-ee6263ac0ebb.png)

We can achieve this by writing the following lines:
```c
Matrix matrix = NewMatrix(5,5);
FillMatrix(matrix);
Matrix result_matrix = Cholesky(matrix);
PrintMatrix(result_matrix);
```

Output:
```c
2.449  0.000 0.000 0.000 
1.225  2.121 0.000 0.000 
1.633  1.414 2.309 0.000 
3.266 -1.414 1.588 3.132 
```

More about the Chelosky decomposition algorithm can be seen at the bottom of this page.

However, because this is C, calling the matrix library function Free() is necessary in order to prevent memory leakage.
This can be achieved by the following line:
```c
FreeMatrix(&matrix);
``` 
  
  
### Cholesky Decomposition 
When it is applicable, the Cholesky decomposition is roughly twice as efficient as the LU decomposition for solving systems of linear equations. Below is an animation of the Cholesky decomposition algorithm on a 5×5 matrix. Access pattern are in white and writing pattern are in yellow.

![Alt text](https://cloud.githubusercontent.com/assets/10769110/26377885/14ace690-3fc7-11e7-9867-2d6c99d9e236.gif)

(GIF from https://en.wikipedia.org/wiki/Cholesky_decomposition)
  
