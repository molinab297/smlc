# smlc - A Simple Matrix Library written in C

A very small and basic matrix library written in C. This library is purely written for interest in linear algebra/C programming and is not intended to compete in performance with other well known C/C++ matrix libraries. Being that C can at times be a very verbose and terse language, the intention behind this project is allow programmers to quickly and easily be able to create and manipulate matrices dynamically without having to manually create dynamic 2D arrays and deal with pointers.

For example, given this system of equations:

![Alt text](https://cloud.githubusercontent.com/assets/10769110/26473871/a532fc6c-4162-11e7-929a-f7f463d9e15e.gif)

We could simply solve this system by writing the following code:

```c
Matrix matrix = NewMatrix(3,4);
FillMatrix(matrix);
PrintMatrix(SolveSystem(matrix));
```

Output:
```c
7.0 
5.0 
3.0 
```

Example 2). Say we wanted to find the determinant of the following 5x5 matrix. 

This can be achieved via the following lines:
```c
Matrix matrix = NewMatrix(5,5);
FillMatrix(matrix);
double determinant_multiplier = ReducedRowEchelonForm(matrix);
printf("%lf", Determinant(matrix,determinant_multiplier));
```

Output:
```c
output here
```

Example 3). Say we wanted to find the Chelosky factor of the following Hermitian, positive-definite matrix:
*add*

We can achieve this by writing the following lines:
```c
Matrix matrix = NewMatrix(5,5);
FillMatrix(matrix);
Matrix result_matrix = Cholesky(matrix);
PrintMatrix(result_matrix);
```c

Output:
```c
2.449  0.000 0.000 0.000 
1.225  2.121 0.000 0.000 
1.633  1.414 2.309 0.000 
3.266 -1.414 1.588 3.132 
```

More about the Chelosky decomposition algorithm can be seen at the bottom of this page.

Although, because we are dealing with C, don't forget to free memory from your declared matrices after you are done using them. This can achieved by the following line:
```c
FreeMatrix(matrix);
```

## Current supported matrix operations:
  - basic matrix addition, subtraction, and multiplication
  - rotating and transposing matrices (only NxN matrices at the moment)
  - calculating determinants of matrices
  - converting matrices to reduced row echelon form
      - LU Decomposition (Guassian Elimination/Reduced row)
      - Cholesky Decomposition
  - solving systems of equations as matrices (using backward substitution)
  - determining linear independence/dependence 
  - calculating eigenvectors & eigenvalues 
  
  
### Cholesky Decomposition 
When it is applicable, the Cholesky decomposition is roughly twice as efficient as the LU decomposition for solving systems of linear equations. 

Below is an animation of the Cholesky decomposition algorithm on a 5×5 matrix. Access pattern are in white and writing pattern are in yellow.

![Alt text](https://cloud.githubusercontent.com/assets/10769110/26377885/14ace690-3fc7-11e7-9867-2d6c99d9e236.gif)

(GIF from https://en.wikipedia.org/wiki/Cholesky_decomposition)
  
