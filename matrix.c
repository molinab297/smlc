/****************************
 * Author: Blake A. Molina
 * Created on: 5/19/17
 * License: GPL
 ****************************/

#include "matrix.h"

void SwapRows(matrix_ptr matrix, int rowA, int rowB){
    for(int i = 0; i < matrix->num_cols; i++){
        double temp = matrix->index[rowA][i];
        matrix->index[rowA][i] = matrix->index[rowB][i];
        matrix->index[rowB][i] = temp;
    }
}

void DivideRow(matrix_ptr matrix, int row, double divisor){
    for(int i = 0; i < matrix->num_cols; i++)
        matrix->index[row][i] /= divisor; // Reduce row by dividing by a common divisor
}


void AddMultipleRow(matrix_ptr matrix, int row_receiver, int row_multiple, double scalar){
    for (int col = 0; col < matrix->num_cols; col++)
        matrix->index[row_receiver][col] += scalar * matrix->index[row_multiple][col];
}

double Reduced_row_echelon_form(matrix_ptr matrix) {
    int pivot = 0;
    // function keeps track of determinant multiplier in case user needs to calculate
    // determinant value.
    int determinant_multiplier = 1;
    for(int row = 0; row < matrix->num_rows; row++) {
        if (pivot > matrix->num_cols-1)
            return determinant_multiplier;
        int i = row;
        while (matrix->index[i][pivot] == 0) {
            i++;
            if (i >= matrix->num_rows-1) {
                i = row;
                pivot++;
                if (pivot > matrix->num_cols-1)
                    return determinant_multiplier;
            }
        }
        SwapRows(matrix, i, row);
        determinant_multiplier *= (-1*matrix->index[row][pivot]); // Apply Rule 1 and Rule 2 of Properties of Row Operations for Determinants
        DivideRow(matrix, row, matrix->index[row][pivot]);

        for (i = 0; i < matrix->num_rows; i++) {
            if (i != row)
                AddMultipleRow(matrix,i,row,-matrix->index[i][pivot]); // Rule 3 of Properties of Row Operations for Determinants
        }
    }
    return determinant_multiplier;
}


matrix_ptr NewMatrix(int num_rows, int num_cols){
    matrix_ptr newMatrix;
    newMatrix = malloc(sizeof(matrix_ptr));
    newMatrix->num_rows = num_rows;
    newMatrix->num_cols = num_cols;
    newMatrix->index = (double**)malloc(newMatrix->num_rows*sizeof(double*));
    for(int i = 0; i < newMatrix->num_rows; i++)
        newMatrix->index[i] = (double*)malloc(newMatrix->num_cols*sizeof(double));
    return newMatrix;
}

void FreeMatrix(matrix_ptr *matrix){
    for(int i = 0; i < (*matrix)->num_rows; i++)
        free((*matrix)->index[i]);
    free((*matrix)->index);
    free(*matrix);
}

void PrintMatrix(matrix_ptr matrix){
    for(int i = 0;i < matrix->num_rows; i++){
        for(int j = 0; j < matrix->num_cols; j++)
            printf("%0.1f ", matrix->index[i][j]);
        printf("\n");
    }
}

matrix_ptr MultiplyMatrices(matrix_ptr matrix_A, matrix_ptr matrix_B){
    // Makes sure dot product can be applied to the matrices
    if(matrix_A->num_cols != matrix_B->num_rows) {
        fprintf(stderr, "%s", "Error - Need an NxN matrix to perform matrix multiplication");
        return NULL;
    }

    matrix_ptr result_matrix = NewMatrix(matrix_A->num_rows, matrix_B->num_cols);

    for(int row = 0; row < matrix_A->num_rows; row++){
        for(int column = 0; column < matrix_B->num_cols; column++){
            int sum = 0;
            for(int i = 0; i < matrix_A->num_rows; i++)
                sum += matrix_A->index[row][i] * matrix_B->index[i][column];
            result_matrix->index[row][column] = sum;
        }
    }
    return result_matrix;
}


matrix_ptr AddMatrices(matrix_ptr matrix_A, matrix_ptr matrix_B, int subtract_flag){
    // Makes sure matrices are same size before performing addition
    if(matrix_A->num_rows != matrix_B->num_rows || matrix_A->num_cols != matrix_B->num_cols) {
        fprintf(stderr, "%s", "Error - Need an NxN matrix to perform matrix addition");
        return NULL;
    }

    // set subtraction flag to -1 if user passes in a 1 for the subtract parameter
    int subtraction_flag = 1;
    if(subtract_flag == 1)
        subtraction_flag = -1;

    matrix_ptr result_matrix = NewMatrix(matrix_A->num_rows, matrix_A->num_cols);

    for(int i = 0; i < matrix_A->num_rows; i++){
        for(int j = 0; j < matrix_A->num_cols; j++)
            result_matrix->index[i][j] = matrix_A->index[i][j] + (subtraction_flag * matrix_B->index[i][j]);
    }
    return result_matrix;
}


double Determinant(matrix_ptr matrix, double determinant_multiplier){
    if(matrix->num_rows != matrix->num_cols) { // make sure matrix is square
        fprintf(stderr, "%s", "Error - Need an NxN matrix to calculate determinant");
        return -1;
    }
    int determinant = 1;
    for(int i = 0; i < matrix->num_rows; i++) // multiply diagonal
        determinant *= matrix->index[i][i];
    return determinant * determinant_multiplier; // scale determinant by value from performing elementary row operations
}

void Transpose(matrix_ptr matrix){
    // Transpose NxN matrix
    for(int row = 0; row < matrix->num_rows; row++){
        for(int col = row; col < matrix->num_cols; col++)
            SwapValues(*(matrix->index+row)+col, *(matrix->index+col)+row);
    }
}

void SwapColumns(matrix_ptr matrix){
    int k = matrix->num_cols-1;
    for(int i = 0; i < matrix->num_cols/2; i++){
        for(int j = 0; j < matrix->num_rows; j++)
            SwapValues(*(matrix->index+j)+i, *(matrix->index+j)+k);
        k--;
    }
}

void SwapValues(double *index_one, double *index_two){
    double temp = *index_one;
    *index_one  = *index_two;
    *index_two  = temp;
}

void RotateMatrixClockwise(matrix_ptr matrix){
    if(matrix->num_rows != matrix->num_cols)
        fprintf(stderr, "%s", "Error - Need an Nxn matrix to rotate");
    else{
        Transpose(matrix);
        SwapColumns(matrix);
    }
}

void RotateMatrixCounterClockwise(matrix_ptr matrix){
    if(matrix->num_rows != matrix->num_cols)
        fprintf(stderr, "%s", "Error - Need an Nxn matrix to rotate");
    else{
        SwapColumns(matrix);
        Transpose(matrix);
    }
}
