// Author: Blake A. Molina
// Created on: 5/19/17
// License: GPL

#ifndef EIGEN_MATRIX_H
#define EIGEN_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef double** matrix_ptr;

/*************************************************************************
 * matrix_ptr NewMatrix(int num_rows, int num_cols)
 *
 * Allocates memory for a 2D matrix and returns a pointer to the first index
 *
 * -> PARAMETERS:
 *    num_rows - number of rows in the matrix
 *    num_cols - number of columns in the matrix
 *
 * -> RETURNS: a pointer to a 2D array
 ************************************************************************/
matrix_ptr NewMatrix(int num_rows, int num_cols);

/*************************************************************************
 * void InitializeMatrix(matrix_ptr matrix, int num_rows, int num_cols)
 *
 * Initializes matrix with values from standard input stream
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to the beginning of a 2D array
 *    num_rows - number of rows in the matrix
 *    num_cols - number of columns in the matrix
 ************************************************************************/
void InitializeMatrix(matrix_ptr matrix, int num_rows, int num_cols);

/*************************************************************************
 * void InitializeMatrix(matrix_ptr matrix, int num_rows)
 *
 * Frees memory from a dynamically allocated 2D array.
 *
 * NOTE: Do not forget to call this method when instantiating new matrices.
 * Not doing so will result in memory leaks.
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to the beginning of a 2D array
 *    num_rows - number of rows in the matrix
 ************************************************************************/
void FreeMatrix(matrix_ptr matrix, int num_rows);

/*************************************************************************
 * void PrintMatrix(matrix_ptr matrix, int num_rows, int num_cols)
 *
 * Prints the contents of a 2D array
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to the beginning of a 2D array
 *    num_rows - number of rows in the matrix
 *    num_cols - number of columns in the matrix
 ************************************************************************/
void PrintMatrix(matrix_ptr matrix, int num_rows, int num_cols);


/*************************************************************************
 * void SwapRows(matrix_ptr matrix, int num_cols, int rowA, int rowB)
 *
 *  Swaps one row with another. This operation is typically performed when
 *  the pivot value equals 0. (Reduced row echelon form requires rows with
 *  more zeros at the bottom of the matrix).
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to the beginning of a 2D array
 *    num_cols - number of columns in the matrix
 *    rowA     - A row that will be swapped with row B
 *    rowB     - A row that will be swapped with row A
 ************************************************************************/
void SwapRows(matrix_ptr matrix, int num_cols, int rowA, int rowB);

/*************************************************************************
 * void DivideRow(matrix_ptr matrix, int num_cols, int row, double divisor)
 *
 *  Divides each value in row by a divisor. This operation is typically
 *  performed to reduce rows that share a common divisor.
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to the beginning of a 2D array
 *    num_cols - number of columns in the matrix
 *    row      - A row that will be divided by divisor
 *    divisor  - number to divide each value in the specified row of the matrix
 ************************************************************************/
void DivideRow(matrix_ptr matrix, int num_cols, int row, double divisor);

/*************************************************************************
 * void AddMultipleRow(matrix_ptr matrix, int num_cols, int row_receiver, int row_multiple, double scalar)
 *
 *  Adds the multiple of one row to another row
 *
 * -> PARAMETERS:
 *    matrix       - a pointer to the beginning of a 2D array
 *    num_cols     - number of columns in the matrix
 *    row_receiver - row that is being modified by (scalar * row_multiple)
 *    row_multiple - row that is being added to row_receiver
 *    scalar       - number that scales each element in a row (row_multiple)
 ************************************************************************/
void AddMultipleRow(matrix_ptr matrix, int num_cols, int row_receiver, int row_multiple, double scalar);

/*************************************************************************
 * double Reduced_row_echelon_form(matrix_ptr matrix, int num_rows, int num_cols)
 *
 *  Converts a matrix to Reduced Row Echelon Form
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to the beginning of a 2D array
 *    num_cols - number of columns in the matrix
 *    num_rows - number of rows in the matrix
 *
 * -> RETURNS: A determinant multiplier. This value needs to be passed into
 *             Determinant(matrix_ptr matrix, int num_rows, int num_cols, double determinant_multiplier)
 *             in order for the correct value to be calculated.
 *    NOTE: If finding the determinant of the matrix is not of interest, simply
 *          call this function without assigning it to a variable.
 ************************************************************************/
double Reduced_row_echelon_form(matrix_ptr matrix, int num_rows, int num_cols);

/*************************************************************************
 * matrix_ptr MultiplyMatrices(matrix_ptr matrixA, int A_num_rows, int A_num_cols, matrix_ptr matrixB, int B_num_rows, int B_num_cols)
 *
 *  Calculates and returns a matrix as the result of the product of two matrices
 *
 * -> PARAMETERS:
 *    matrixA     - a pointer to the beginning of matrix A
 *    A_num_cols  - number of columns in matrix A
 *    A_num_rows  - number of rows in matrix A
 *    matrixB     - a pointer to the beginning of matrix B
 *    B_num_cols  - number of columns in matrix B
 *    B_num_rows  - number of rows in matrix B
 *
 * -> RETURNS: a pointer to the result matrix, or a NULL ptr if matrixA's
 *             column size differs from matrixB's row size
 ************************************************************************/
matrix_ptr MultiplyMatrices(matrix_ptr matrixA, int A_num_rows, int A_num_cols, matrix_ptr matrixB, int B_num_rows, int B_num_cols);

/*************************************************************************
 * matrix_ptr AddMatrices(matrix_ptr matrixA, int A_num_rows, int A_num_cols, matrix_ptr matrixB, int B_num_rows, int B_num_cols, int subtract)
 *
 *  Calculates matrix addition or subtraction. The 'subtract' parameter serves
 *  as a boolean. Pass in a 0 for normal matrix addition and a 1 for matrix subtraction.
 *  This function returns a pointer to the beginning of a new 2D matrix.
 *
 * -> PARAMETERS:
 *    matrixA     - a pointer to the beginning of matrix A
 *    A_num_cols  - number of columns in matrix A
 *    A_num_rows  - number of rows in matrix A
 *    matrixB     - a pointer to the beginning of matrix B
 *    B_num_cols  - number of columns in matrix B
 *    B_num_rows  - number of rows in matrix B
 *    subtract    - pass in a 0 for normal addition and a 1 for subtraction
 *
 * -> RETURNS: a pointer to the result matrix, or a NULL ptr if two matrices
 *             differ in size.
 ************************************************************************/
matrix_ptr AddMatrices(matrix_ptr matrixA, int A_num_rows, int A_num_cols, matrix_ptr matrixB, int B_num_rows, int B_num_cols, int subtract);

/*************************************************************************
 * double Determinant(matrix_ptr matrix, int num_rows, int num_cols)
 *
 *  Calculates and returns the determinant of a matrix. The matrix is first
 *  put in triangular form i.e. :
 *      1 2 1
 *      0 2 0
 *      0 0 1
 *
 *  The product of the diagonal and the determinant multiplier is the
 *  determinant of the matrix.
 *
 *  NOTE: The matrix must already be in reduced row echelon form before
 *        the determinant is calculated, otherwise the resulting determinant
 *        will be an unexpected value. This is because the matrix needs to be
 *        in upper triangle form, which RREF achieves.
 *        See: double Reduced_row_echelon_form(..)
 *
 * -> PARAMETERS:
 *    matrix                 - a pointer to the beginning of a 2D array
 *    num_cols               - number of columns in the matrix
 *    num_rows               - number of rows in the matrix
 *    determinant_multiplier - a value that is multiplied to the diagonal
 *                             of a matrix in reduced row echelon form.
 *
 * -> RETURNS: the decimal value of the matrix determinant
 ************************************************************************/
double Determinant(matrix_ptr matrix, int num_rows, int num_cols, double determinant_multiplier);



#endif //EIGEN_MATRIX_H
