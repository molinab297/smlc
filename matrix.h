// Author: Blake A. Molina
// Created on: 5/19/17
// License: GPL

#ifndef EIGEN_MATRIX_H
#define EIGEN_MATRIX_H

#include <stdio.h>
#include <stdlib.h>


// Allocates memory for a 2D matrix and returns a pointer to the first index
double **NewMatrix(int num_rows, int num_cols);

void InitializeMatrix(double **matrix, int num_rows, int num_cols);

// Reclaims memory from matrix
void FreeMatrix(double **matrix, int num_rows);

void PrintMatrix(double **matrix, int num_rows, int num_cols);

// Swaps one row with another. This operation is typically
// performed when the pivot value equals 0. (Reduced row echelon
// form requires rows with more zeros at the bottom of the matrix).
void SwapRows(double **matrix, int num_cols, int rowA, int rowB);

// Divides each value in row by a divisor. This operation is typically
// performed to reduce rows that share a common divisor.
void DivideRow(double **matrix, int num_cols, int row, double divisor);

// Adds the multiple of one row to another row
void AddMultipleRow(double **matrix, int num_cols, int i, int k, double v);

// Converts a matrix to Reduced Row Echelon Form
void Reduced_row_echelon_form(double **matrix, int num_rows, int num_cols);

// Calculates and returns a matrix as the result of the product of two matrices.
double **MultiplyMatrices(double **matrixA, int A_num_rows, int A_num_cols, double **matrixB, int B_num_rows, int B_num_cols);

// Calculates matrix addition or subtraction. The 'subtract' parameter serves as a boolean. Pass in a 0 for normal
// matrix addition and a 1 for matrix subtraction. This function returns a pointer to the beginning of a new 2D matrix.
double **AddMatrices(double **matrixA, int A_num_rows, int A_num_cols, double **matrixB, int B_num_rows, int B_num_cols, int subtract);

// Calculates and returns the determinant of a matrix.
double Determinant(double **matrix, int num_rows, int num_cols);


#endif //EIGEN_MATRIX_H
