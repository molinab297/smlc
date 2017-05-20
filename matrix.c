// Author: Blake A. Molina
// Created on: 5/19/17
// License: GPL
#include "matrix.h"

// Swaps one row with another. This operation is typically
// performed when the pivot value equals 0. (Reduced row echelon
// form requires rows with more zeros at the bottom of the matrix).
void SwapRows(double **matrix, int num_cols, int rowA, int rowB){
    for(int i = 0; i < num_cols; i++){
        double temp = matrix[rowA][i];
        matrix[rowA][i] = matrix[rowB][i];
        matrix[rowB][i] = temp;
    }
}

// Divides each value in row by a divisor. This operation is typically
// performed to reduce rows that share a common divisor.
void DivideRow(double **matrix, int num_cols, int row, double divisor){
    for(int i = 0; i < num_cols; i++)
        matrix[row][i] /= divisor;
}

// Adds the multiple of one row to another row
void AddMultipleRow(double **matrix, int num_cols, int i, int k, double v){
    for (int col = 0; col < num_cols; col++)
        matrix[i][col] += v * matrix[k][col];
}

// Converts a matrix to Reduced Row Echelon Form
void Reduced_row_echelon_form(double **matrix, int num_rows, int num_cols) {
    int pivot = 0;
    for(int row = 0; row < num_rows; row++) {
        if (pivot > num_cols-1)
            return;
        int i = row;
        while (matrix[i][pivot] == 0) {
            i++;
            if (i >= num_rows-1) {
                i = row;
                pivot++;
                if (pivot > num_cols-1)
                    return;
            }
        }
        SwapRows(matrix, num_cols, i, row);
        DivideRow(matrix, num_cols, row, matrix[row][pivot]);
        for (i = 0; i < num_rows; i++) {
            if (i != row) {
                AddMultipleRow(matrix,num_cols,i,row,-matrix[i][pivot]);
            }
        }
    }
}

void InitializeMatrix(double **matrix, int num_rows, int num_cols){
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_cols; j++){
            double new_value;
            printf("Enter value for [%d,%d]: ", i, j);
            scanf("%lf", &new_value);
            matrix[i][j] = new_value;
            printf("\n");
        }
    }
}

// Allocates memory for a 2D matrix and returns a pointer to the first index
double **NewMatrix(int num_rows, int num_cols){
    double **matrix = (double**)malloc(num_rows*sizeof(double*));
    for(int i = 0; i < num_rows; i++)
        matrix[i] = (double*)malloc(num_cols*sizeof(double));
    return matrix;
}

// Reclaims memory from matrix
void FreeMatrix(double **matrix, int num_rows){
    for(int i = 0; i < num_rows; i++)
        free(matrix[i]);
    free(matrix);
}

void PrintMatrix(double **matrix, int num_rows, int num_cols){
    for(int i = 0;i < num_rows; i++){
        for(int j = 0; j < num_cols; j++)
            printf("%f\t", matrix[i][j]);
        printf("\n");
    }
}