/****************************
 * Author: Blake A. Molina
 * Created on: 5/19/17
 * License: GPL
 ****************************/

#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct{
    double **index;  // pointer to 2D array of matrix values
    size_t num_rows;
    size_t num_cols;
}matrix_struct;

typedef matrix_struct* Matrix;

/*************************************************************************
 * Matrix NewMatrix(size_t num_rows, size_t num_cols)
 *
 * Allocates memory for a 2D matrix and returns a pointer to the first index
 *
 * -> PARAMETERS:
 *    num_rows - number of rows in the matrix (must be a positive int)
 *    num_cols - number of columns in the matrix (must be a positive int)
 *
 * -> RETURNS: a matrix structure
 ************************************************************************/
Matrix NewMatrix(size_t num_rows, size_t num_cols);

/*************************************************************************
 * void InitializeMatrix(Matrix *matrix)
 *
 * Frees memory from a dynamically matrix structure.
 *
 * NOTE: Do not forget to call this method when instantiating new matrices.
 * Not doing so can result in memory leaks.
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to a matrix structure
 ************************************************************************/
void FreeMatrix(Matrix *matrix);

/*************************************************************************
 * void PrintMatrix(Matrix matrix)
 *
 *  Prints the contents of a matrix structure
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to a matrix structure
 ************************************************************************/
void PrintMatrix(Matrix matrix);

/*************************************************************************
 * void SwapRows(Matrix matrix, int rowA, int rowB)
 *
 *  Swaps one row with another. This operation is typically performed when
 *  the pivot value equals 0. (Reduced row echelon form requires rows with
 *  more zeros at the bottom of the matrix).
 *
 * -> PARAMETERS:
 *    matrix   - a matrix structure
 *    rowA     - A row that will be swapped with row B
 *    rowB     - A row that will be swapped with row A
 ************************************************************************/
void SwapRows(Matrix matrix, int rowA, int rowB);

/*************************************************************************
 * void DivideRow(Matrix matrix, int row, double divisor)
 *
 *  Divides each value in row by a divisor. This operation is typically
 *  performed to reduce rows that share a common divisor.
 *
 * -> PARAMETERS:
 *    matrix   - a matrix structure
 *    row      - A row that will be divided by divisor
 *    divisor  - number to divide each value in the specified row of the matrix
 ************************************************************************/
void DivideRow(Matrix matrix, int row, double divisor);

/*************************************************************************
 * void AddMultipleRow(Matrix matrix, int row_receiver, int row_multiple, double scalar)
 *
 *  Adds the multiple of one row to another row
 *
 * -> PARAMETERS:
 *    matrix       - a matrix structure
 *    row_receiver - row that is being modified by (scalar * row_multiple)
 *    row_multiple - row that is being added to row_receiver
 *    scalar       - number that scales each element in a row (row_multiple)
 ************************************************************************/
void AddMultipleRow(Matrix matrix, int row_receiver, int row_multiple, double scalar);

/*************************************************************************
 * double Reduced_row_echelon_form(Matrix matrix)
 *
 *  Converts a matrix to Reduced Row Echelon Form. This function uses
 *  3 helper functions (DivideRow(), AddMultipleRow, and SwapRows()) to
 *  perform elementary row operations.
 *
 * -> PARAMETERS:
 *    matrix   - a matrix structure
 *
 * -> RETURNS: A determinant multiplier. This value needs to be passed into
 *             Determinant(Matrix matrix, double determinant_multiplier)
 *             in order for the correct value to be calculated.
 *
 *    NOTE: If finding the determinant of the matrix is not of interest, simply
 *          call this function without assigning it to a variable.
 ************************************************************************/
double ReducedRowEchelonForm(Matrix matrix);

/*************************************************************************
 * Matrix SolveSystem(Matrix matrix)
 *
 *  Solves a system of linear equations (a matrix) by converting the system
 *  to reduced row echelon form (calls ReducedRowEchelonForm()) and then
 *  performs back-substitution to solve for each unknown variable.
 *
 * -> PARAMETERS:
 *    matrix   - a matrix structure
 *
 * -> RETURNS: a matrix structure which holds the solutions to the system
 *             of linear equations.
 *
 *    NOTE: This function will return a NULL pointer if either the system
 *    has no solutions (a zero row and then a value in the constant vector)
 *    or infinitely many solutions (a zero row). It will also output an
 *    error message.
 ************************************************************************/
Matrix SolveSystem(Matrix matrix);

/*************************************************************************
 * void Cholesky(Matrix original_matrix, Matrix new_matrix)
 *
 *   Similary to LU decomposition, The Cholesky decomposition is another
 *   method to convert a matrix to reduced row echelon form. Where applicable,
 *   the Cholesky decomposition is roughly twice as efficient as the LU
 *   decomposition for solving systems of linear equations.
 *
 * -> PARAMETERS:
 *    matrix  - a matrix structure
 *
 * -> RETURNS:
 *
 *    NOTE: The parameter matrix must be a Hermitian, positive-definite
 *    matrix (Symmetric and real for all values), in order for the algorithm
 *    to perform as designed.
 ************************************************************************/
Matrix Cholesky(Matrix matrix);

/*************************************************************************
 * Matrix MultiplyMatrices(Matrix matrix_A, Matrix matrix_B)
 *
 *  Calculates and returns a matrix as the result of the product of two
 *  matrices
 *
 * -> PARAMETERS:
 *    matrix_A     - a pointer to matrix A
 *    matrix_B     - a pointer to matrix B
 *
 * -> RETURNS: the result matrix, or a NULL ptr if matrix_A's column size
 *             differs from matrix_B's row size
 ************************************************************************/
Matrix MultiplyMatrices(Matrix matrix_A, Matrix matrix_b);

/*************************************************************************
 * Matrix AddMatrices(Matrix matrix_A, Matrix matrix_B, int subtract_flag)
 *
 *  Calculates matrix addition or subtraction. The 'subtract' parameter serves
 *  as a boolean. Pass in a 0 for normal matrix addition and a 1 for matrix
 *  subtraction. This function returns a pointer to the beginning of a new
 *  2D matrix.
 *
 * -> PARAMETERS:
 *    matrixA       - a pointer to the beginning of matrix A
 *    matrixB       - a pointer to the beginning of matrix B
 *    subtract_flag - pass in a 0 for normal addition and a 1 for subtraction
 *
 * -> RETURNS: the result matrix, or a NULL ptr if two matrices
 *             differ in size.
 ************************************************************************/
Matrix AddMatrices(Matrix matrix_A, Matrix matrix_B, int subtract_flag);

/*************************************************************************
 * double Determinant(Matrix matrix)
 *
 *  Calculates and returns the determinant of a matrix. The matrix is first
 *  put in triangular form i.e. :
 *
 *      1 2 1
 *      0 2 0
 *      0 0 1
 *
 *  The product of the diagonal and the determinant multiplier is the
 *  determinant of the matrix.
 *
 *  NOTE: matrix will be converted to reduced row echelon form. This is
 *        because the matrix needs to be in upper triangle form.
 *        See: double Reduced_row_echelon_form(..)
 *
 * -> PARAMETERS:
 *    matrix                 - a matrix structure
 *
 * -> RETURNS: the decimal value of the matrix determinant
 ************************************************************************/
double Determinant(Matrix matrix);

/*************************************************************************
 * void Transpose(Matrix matrix_A)
 *
 *  Takes the transpose of a matrix. The transpose of a matrix is every value
 *  within the matrix in index [i][j] swapped with [j][i].
 *
 * -> PARAMETERS:
 *    matrix       - a matrix structure
 ************************************************************************/
void Transpose(Matrix matrix);

/*************************************************************************
 * void SwapValues(double *index_one, double *index_two)
 *
 *  Swaps values given two pointers to indicies in a 2d array. Note that
 *  this function is a helper function to RotateMatrixClockwise and
 *  RotateMatrixCounterClockwise. Although, this function can be used if
 *  one wishes to swap two values in a 2d array (which would be unnecessary
 *  because public access is already given to the 2d array).
 *
 * -> PARAMETERS:
 *    index_one       - a pointer to an index in a 2d array
 *    index_two       - a pointer to another index in a 2d array
 ************************************************************************/
void SwapValues(double *index_one, double *index_two);

/*************************************************************************
 * void SwapColumns(Matrix matrix)
 *
 *  Interchanges values in columns within a matrix. (Like SwapValues(),
 *  but the operation is performed on the entire column).
 *
 * -> PARAMETERS:
 *    matrix       - a matrix structure
 ************************************************************************/
void SwapColumns(Matrix matrix);

/*************************************************************************
 * void RotateMatrixClockwise(Matrix matrix)
 *
 *  Rotates an NxN matrix 90 degrees clockwise. The function achieves this
 *  by first transposing the matrix (by calling Transpose()) and then by
 *  interchanging columns (by calling SwapColumns()).
 *
 * -> PARAMETERS:
 *    matrix      - a matrix structure
 ************************************************************************/
void RotateMatrixClockwise(Matrix matrix);

/*************************************************************************
 * RotateMatrixCounterClockwise(Matrix matrix)
 *
 *  Rotates an NxN matrix 90 degrees counterclockwise. This performs the
 *  same operations as RotateMatrixClockwise() except in reverse, i.e.,
 *  interchange columns, then transpose.
 *
 * -> PARAMETERS:
 *    matrix       - a matrix structure
 ************************************************************************/
void RotateMatrixCounterClockwise(Matrix matrix);

/*************************************************************************
 * int IsLinearIndependent(Matrix matrix)
 *
 *  Determines if a matrix is linearly independent. A matrix is said to be
 *  independent if it's determinant is not equal to 0.
 *
 * -> PARAMETERS:
 *    matrix       - a matrix structure
 *
 * -> RETURNS: 0 for false or 1 for true
 ************************************************************************/
int IsLinearIndependent(Matrix matrix);

/*************************************************************************
 * int isSquare(Matrix matrix)
 *
 *  Determines if a matrix is square or not.
 *
 * -> PARAMETERS:
 *    matrix       - a matrix structure
 *
 * -> RETURNS: 0 for false or 1 for true
 ************************************************************************/
int isSquare(Matrix matrix);

/*************************************************************************
 * int isEmpty(Matrix matrix)
 *
 *  Determines if a matrix is at least a 1x1 matrix or if it hasn't been
 *  instantiated by calling NewMatrix (See NewMatrix()).
 *
 * -> PARAMETERS:
 *    matrix       - a matrix structure
 *
 * -> RETURNS: 0 for false or 1 for true
 ************************************************************************/
int isEmpty(Matrix matrix);



#endif //MATRIX_H
