// Author: Blake A. Molina
// Created on: 5/19/17
// License: GPL
#include "matrix.h"

void SwapRows(double **matrix, int num_cols, int rowA, int rowB){
    for(int i = 0; i < num_cols; i++){
        double temp = matrix[rowA][i];
        matrix[rowA][i] = matrix[rowB][i];
        matrix[rowB][i] = temp;
    }
}

void DivideRow(double **matrix, int num_cols, int row, double divisor){
    for(int i = 0; i < num_cols; i++)
        matrix[row][i] /= divisor;
}


void AddMultipleRow(double **matrix, int num_cols, int row_receiver, int row_multiple, double scalar){
    for (int col = 0; col < num_cols; col++)
        matrix[row_receiver][col] += scalar * matrix[row_multiple][col];
}

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

double **NewMatrix(int num_rows, int num_cols){
    double **matrix = (double**)malloc(num_rows*sizeof(double*));
    for(int i = 0; i < num_rows; i++)
        matrix[i] = (double*)malloc(num_cols*sizeof(double));
    return matrix;
}

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