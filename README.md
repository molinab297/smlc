# smlc - A Simple Matrix Library written in C

A very small and basic matrix library written in C. This library is purely written for interest in linear algebra/C programming and is not intended to compete in performance with other well known C/C++ matrix libraries. Being that C can at times be a very verbose and terse language, the intention behind this project is allow programmers to quickly and easily be able to create and manipulate matrices dynamically without having to mess with pointers.

For example, given this system of equations:

*insert pic here*

we could simply solve this system by writing the following code

'''c++
Matrix matrix = NewMatrix(3,4);
FillMatrix(matrix);
PrintMatrix(SolveSystem(matrix));
'''

Output:

*insert pic here*

## Includes common and well known matrix algorithms such as:
  - basic matrix addition, subtraction, and multiplication
  - rotating and transposing matrices (only NxN matrices at the moment)
  - calculating determinants of matrices
  - converting matrices to reduced row echelon form
  - solving systems of equations as matrices (using backward substitution)
  - determining linear independence/dependence 
  - calculating eigenvectors & eigenvalues 
  
## Supported Decomposition Algorithms at the moment:   
  - LU Decomposition (Guassian Elimination/Reduced row)
  - Cholesky Decomposition

  
### Cholesky Decomposition 
When it is applicable, the Cholesky decomposition is roughly twice as efficient as the LU decomposition for solving systems of linear equations. 

Below is an animation of the Cholesky decomposition algorithm on a 5×5 matrix. Access pattern are in white and writing pattern are in yellow.

![Alt text](https://cloud.githubusercontent.com/assets/10769110/26377885/14ace690-3fc7-11e7-9867-2d6c99d9e236.gif)

(GIF from https://en.wikipedia.org/wiki/Cholesky_decomposition)
  
