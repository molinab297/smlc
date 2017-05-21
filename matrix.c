// Author: Blake A. Molina
// Created on: 5/19/17
// License: GPL
#include "matrix.h"

void SwapRows(matrix_ptr matrix, int num_cols, int rowA, int rowB){
    for(int i = 0; i < num_cols; i++){
        double temp = matrix[rowA][i];
        matrix[rowA][i] = matrix[rowB][i];
        matrix[rowB][i] = temp;
    }
}

void DivideRow(matrix_ptr matrix, int num_cols, int row, double divisor){
    for(int i = 0; i < num_cols; i++)
        matrix[row][i] /= divisor; // Reduce row by dividing by a common divisor
}


void AddMultipleRow(matrix_ptr matrix, int num_cols, int row_receiver, int row_multiple, double scalar){
    for (int col = 0; col < num_cols; col++)
        matrix[row_receiver][col] += scalar * matrix[row_multiple][col];
}

double Reduced_row_echelon_form(matrix_ptr matrix, int num_rows, int num_cols) {
    int pivot = 0;
    // function keeps track of determinant multiplier in case user needs to calculate
    // determinant value.
    int determinant_multiplier = 1;
    for(int row = 0; row < num_rows; row++) {
        if (pivot > num_cols-1)
            break;
        int i = row;
        while (matrix[i][pivot] == 0) {
            i++;
            if (i >= num_rows-1) {
                i = row;
                pivot++;
                if (pivot > num_cols-1)
                    break;
            }
        }
        SwapRows(matrix, num_cols, i, row);
        determinant_multiplier *= matrix[row][pivot]; // Apply Rule 1 of Properties of Row Operations for Determinants
        DivideRow(matrix, num_cols, row, matrix[row][pivot]);

        for (i = 0; i < num_rows; i++) {
            if (i != row)
                AddMultipleRow(matrix,num_cols,i,row,-matrix[i][pivot]);
        }
    }
    return determinant_multiplier;
}

void InitializeMatrix(matrix_ptr matrix, int num_rows, int num_cols){
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_cols; j++){
            printf("Enter value for [%d,%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
            printf("\n");
        }
    }
}

matrix_ptr NewMatrix(int num_rows, int num_cols){
    matrix_ptr matrix = (double**)malloc(num_rows*sizeof(double*));
    for(int i = 0; i < num_rows; i++)
        matrix[i] = (double*)malloc(num_cols*sizeof(double));
    return matrix;
}

void FreeMatrix(matrix_ptr matrix, int num_rows){
    for(int i = 0; i < num_rows; i++)
        free(matrix[i]);
    free(matrix);
}

void PrintMatrix(matrix_ptr matrix, int num_rows, int num_cols){
    for(int i = 0;i < num_rows; i++){
        for(int j = 0; j < num_cols; j++)
            printf("%0.1f", matrix[i][j]);
        printf("\n");
    }
}

matrix_ptr MultiplyMatrices(matrix_ptr matrixA, int A_num_rows, int A_num_cols, matrix_ptr matrixB, int B_num_rows, int B_num_cols){
    // Makes sure dot product can be applied to the matrices
    if(A_num_cols != B_num_rows)
        return NULL;

    matrix_ptr result_matrix = NewMatrix(A_num_rows, B_num_cols);

    for(int row = 0; row < A_num_rows; row++){
        for(int column = 0; column < B_num_cols; column++){
            int sum = 0;
            for(int i = 0; i < A_num_rows; i++)
                sum += matrixA[row][i] * matrixB[i][column];
            result_matrix[row][column] = sum;
        }
    }
    return result_matrix;
}


matrix_ptr AddMatrices(matrix_ptr matrixA, int A_num_rows, int A_num_cols, matrix_ptr matrixB, int B_num_rows, int B_num_cols, int subtract){
    // Makes sure matrices are same size before performing addition
    if(A_num_rows != B_num_rows || A_num_cols != B_num_cols)
        return NULL;

    // set subtraction flag to -1 if user passes in a 1 for the subtract parameter
    int subtraction_flag = 1;
    if(subtract == 1)
        subtraction_flag = -1;

    matrix_ptr result_matrix = NewMatrix(A_num_rows, A_num_cols);
    for(int i = 0; i < A_num_rows; i++){
        for(int j = 0; j < A_num_cols; j++)
            result_matrix[i][j] = matrixA[i][j] + (subtraction_flag * matrixB[i][j]);
    }
    return result_matrix;
}


double Determinant(matrix_ptr matrix, int num_rows, int num_cols, double determinant_multiplier){
    if(num_rows != num_cols) // make sure matrix is square
        return -1;
    int determinant = 1;
    for(int i = 0; i < num_rows; i++) // multiply diagonal
        determinant *= matrix[i][i];
    return determinant * determinant_multiplier; // scale determinant by value from performing elementary row operations
}