// Author: Blake A. Molina
// Created on: 5/19/17
// License: GPL

#ifndef EIGEN_MATRIX_H
#define EIGEN_MATRIX_H

#include <stdio.h>
#include <stdlib.h>


/*************************************************************************
 * double **NewMatrix(int num_rows, int num_cols)
 *
 * Allocates memory for a 2D matrix and returns a pointer to the first index
 *
 * -> PARAMETERS:
 *    num_rows - number of rows in the matrix
 *    num_cols - number of columns in the matrix
 *
 * -> RETURNS: a pointer to a 2D array
 ************************************************************************/
double **NewMatrix(int num_rows, int num_cols);

/*************************************************************************
 * void InitializeMatrix(double **matrix, int num_rows, int num_cols)
 *
 * Initializes matrix with values from standard input stream
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to the beginning of a 2D array
 *    num_rows - number of rows in the matrix
 *    num_cols - number of columns in the matrix
 ************************************************************************/
void InitializeMatrix(double **matrix, int num_rows, int num_cols);

/*************************************************************************
 * void InitializeMatrix(double **matrix, int num_rows)
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
void FreeMatrix(double **matrix, int num_rows);

/*************************************************************************
 * void PrintMatrix(double **matrix, int num_rows, int num_cols)
 *
 * Prints the contents of a 2D array
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to the beginning of a 2D array
 *    num_rows - number of rows in the matrix
 *    num_cols - number of columns in the matrix
 ************************************************************************/
void PrintMatrix(double **matrix, int num_rows, int num_cols);


/*************************************************************************
 * void SwapRows(double **matrix, int num_cols, int rowA, int rowB)
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
void SwapRows(double **matrix, int num_cols, int rowA, int rowB);

/*************************************************************************
 * void DivideRow(double **matrix, int num_cols, int row, double divisor)
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
void DivideRow(double **matrix, int num_cols, int row, double divisor);

/*************************************************************************
 * void AddMultipleRow(double **matrix, int num_cols, int row_receiver, int row_multiple, double scalar)
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
void AddMultipleRow(double **matrix, int num_cols, int row_receiver, int row_multiple, double scalar);

/*************************************************************************
 * void Reduced_row_echelon_form(double **matrix, int num_rows, int num_cols)
 *
 *  Converts a matrix to Reduced Row Echelon Form
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to the beginning of a 2D array
 *    num_cols - number of columns in the matrix
 *    num_rows - number of rows in the matrix
 ************************************************************************/
void Reduced_row_echelon_form(double **matrix, int num_rows, int num_cols);

/*************************************************************************
 * double **MultiplyMatrices(double **matrixA, int A_num_rows, int A_num_cols, double **matrixB, int B_num_rows, int B_num_cols)
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
 * -> RETURNS: a pointer to the result matrix.
 ************************************************************************/
double **MultiplyMatrices(double **matrixA, int A_num_rows, int A_num_cols, double **matrixB, int B_num_rows, int B_num_cols);

/*************************************************************************
 * double **AddMatrices(double **matrixA, int A_num_rows, int A_num_cols, double **matrixB, int B_num_rows, int B_num_cols, int subtract)
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
 * -> RETURNS: a pointer to the result matrix
 ************************************************************************/
double **AddMatrices(double **matrixA, int A_num_rows, int A_num_cols, double **matrixB, int B_num_rows, int B_num_cols, int subtract);

/*************************************************************************
 * double Determinant(double **matrix, int num_rows, int num_cols)
 *
 *  Calculates and returns the determinant of a matrix.
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to the beginning of a 2D array
 *    num_cols - number of columns in the matrix
 *    num_rows - number of rows in the matrix
 *
 * -> RETURNS: the decimal value of the matrix determinant
 ************************************************************************/
double Determinant(double **matrix, int num_rows, int num_cols);


#endif //EIGEN_MATRIX_H
