# smlc - A Simple Matrix Library written in C

The intention behind this project is to create a very small, quick, and basic matrix library; and for that reason it is written in C. This library is purely written for interest in linear algebra/C programming and is not intended to compete in performance with other well known C/C++ matrix libraries. 

## This library will include common and well known matrix algorithms such as:
  - basic matrix addition, subtraction, and multiplication
  - rotating and transposing matrices
  - calculating determinants of matrices
  - converting matrices to reduced row echelon form 
  - solving systems of equations as matrices (using backward substitution)
  - determining linear independence/dependence 
  - calculating eigenvectors & eigenvalues
  
## Supported Decomposition Algorithms ATM:   
  - Guassian Elimination (Reduced row)
  - Cholesky Decomposition

### Cholesky Decomposition 
When it is applicable, the Cholesky decomposition is roughly twice as efficient as the LU decomposition for solving systems of linear equations.

An animation of the Cholesky decomposition in-place algorithm on a 5×5 matrix. Access pattern are in white and writing pattern are in yellow.
![Alt text](https://cloud.githubusercontent.com/assets/10769110/26377885/14ace690-3fc7-11e7-9867-2d6c99d9e236.gif)

[GIF from https://en.wikipedia.org/wiki/Cholesky_decomposition)
  
