/****************************
 * Author: Blake A. Molina
 * Created on: 5/19/17
 * License: GPL
 ****************************/

#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double **index; // pointer to 2d matrix
    int num_rows;
    int num_cols;
}Matrix;

typedef Matrix* matrix_ptr;

/*************************************************************************
 * matrix_ptr NewMatrix(int num_rows, int num_cols)
 *
 * Allocates memory for a 2D matrix and returns a pointer to the first index
 *
 * -> PARAMETERS:
 *    num_rows - number of rows in the matrix
 *    num_cols - number of columns in the matrix
 *
 * -> RETURNS: a pointer to a matrix
 ************************************************************************/
matrix_ptr NewMatrix(int num_rows, int num_cols);

/*************************************************************************
 * void InitializeMatrix(matrix_ptr *matrix)
 *
 * Frees memory from a dynamically matrix structure.
 *
 * NOTE: Do not forget to call this method when instantiating new matrices.
 * Not doing so can result in memory leaks.
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to a pointer to a matrix structure
 ************************************************************************/
void FreeMatrix(matrix_ptr *matrix);

/*************************************************************************
 * void PrintMatrix(matrix_ptr matrix)
 *
 * Prints the contents of a 2D array
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to a matrix structure
 ************************************************************************/
void PrintMatrix(matrix_ptr matrix);

/*************************************************************************
 * void SwapRows(matrix_ptr matrix, int rowA, int rowB)
 *
 *  Swaps one row with another. This operation is typically performed when
 *  the pivot value equals 0. (Reduced row echelon form requires rows with
 *  more zeros at the bottom of the matrix).
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to a matrix structure
 *    rowA     - A row that will be swapped with row B
 *    rowB     - A row that will be swapped with row A
 ************************************************************************/
void SwapRows(matrix_ptr matrix, int rowA, int rowB);

/*************************************************************************
 * void DivideRow(matrix_ptr matrix, int row, double divisor)
 *
 *  Divides each value in row by a divisor. This operation is typically
 *  performed to reduce rows that share a common divisor.
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to a matrix structure
 *    row      - A row that will be divided by divisor
 *    divisor  - number to divide each value in the specified row of the matrix
 ************************************************************************/
void DivideRow(matrix_ptr matrix, int row, double divisor);

/*************************************************************************
 * void AddMultipleRow(matrix_ptr matrix, int row_receiver, int row_multiple, double scalar)
 *
 *  Adds the multiple of one row to another row
 *
 * -> PARAMETERS:
 *    matrix       - a pointer to a matrix structure
 *    row_receiver - row that is being modified by (scalar * row_multiple)
 *    row_multiple - row that is being added to row_receiver
 *    scalar       - number that scales each element in a row (row_multiple)
 ************************************************************************/
void AddMultipleRow(matrix_ptr matrix, int row_receiver, int row_multiple, double scalar);

/*************************************************************************
 * double Reduced_row_echelon_form(matrix_ptr matrix)
 *
 *  Converts a matrix to Reduced Row Echelon Form
 *
 * -> PARAMETERS:
 *    matrix   - a pointer to a matrix structure
 *
 * -> RETURNS: A determinant multiplier. This value needs to be passed into
 *             Determinant(matrix_ptr matrix, double determinant_multiplier)
 *             in order for the correct value to be calculated.
 *
 *    NOTE: If finding the determinant of the matrix is not of interest, simply
 *          call this function without assigning it to a variable.
 ************************************************************************/
double Reduced_row_echelon_form(matrix_ptr matrix);

/*************************************************************************
 * matrix_ptr MultiplyMatrices(matrix_ptr matrix_A, matrix_ptr matrix_B)
 *
 *  Calculates and returns a matrix as the result of the product of two matrices
 *
 * -> PARAMETERS:
 *    matrix_A     - a pointer to matrix A
 *    matrix_B     - a pointer to matrix B
 *
 * -> RETURNS: a pointer to the result matrix structure, or a NULL ptr if
 *             matrix_A's column size differs from matrix_B's row size
 ************************************************************************/
matrix_ptr MultiplyMatrices(matrix_ptr matrix_A, matrix_ptr matrix_b);

/*************************************************************************
 * matrix_ptr AddMatrices(matrix_ptr matrix_A, matrix_ptr matrix_B, int subtract_flag)
 *
 *  Calculates matrix addition or subtraction. The 'subtract' parameter serves
 *  as a boolean. Pass in a 0 for normal matrix addition and a 1 for matrix subtraction.
 *  This function returns a pointer to the beginning of a new 2D matrix.
 *
 * -> PARAMETERS:
 *    matrixA       - a pointer to the beginning of matrix A
 *    matrixB       - a pointer to the beginning of matrix B
 *    subtract_flag - pass in a 0 for normal addition and a 1 for subtraction
 *
 * -> RETURNS: a pointer to the result matrix, or a NULL ptr if two matrices
 *             differ in size.
 ************************************************************************/
matrix_ptr AddMatrices(matrix_ptr matrix_A, matrix_ptr matrix_B, int subtract_flag);

/*************************************************************************
 * double Determinant(matrix_ptr matrix)
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
 *    determinant_multiplier - a value that is multiplied to the diagonal
 *                             of a matrix in reduced row echelon form.
 *
 * -> RETURNS: the decimal value of the matrix determinant
 ************************************************************************/
double Determinant(matrix_ptr matrix, double determinant_multiplier);



#endif //MATRIX_H
