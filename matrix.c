/****************************
 * Author: Blake A. Molina
 * Created on: 5/19/17
 * License: GPL
 ****************************/

#include "matrix.h"

/*******************************************************
 *     Matrix Instantiation, Deletion, & Printing
 *******************************************************/
Matrix NewMatrix(size_t num_rows, size_t num_cols){

    // Allocate memory for matrix struct
    Matrix newMatrix = (Matrix)malloc(sizeof(matrix_struct));
    newMatrix->num_rows = num_rows;
    newMatrix->num_cols = num_cols;

    // Allocate memory for 2d array of type double within matrix struct
    newMatrix->index = (double**)calloc(newMatrix->num_rows, sizeof(double*));
    for(int i = 0; i < newMatrix->num_rows; i++)
        newMatrix->index[i] = (double*)calloc(newMatrix->num_cols, sizeof(double));
    return newMatrix;
}

void FreeMatrix(Matrix *matrix) {
    if (!isEmpty(*matrix)) {
        // free memory from 2d array within matrix struct
        for (int i = 0; i < (*matrix)->num_rows; i++)
            free((*matrix)->index[i]);
        free((*matrix)->index);
        // free memory from matrix struct
        free(*matrix);
        *matrix = NULL;
    }
}

void PrintMatrix(Matrix matrix) {
    if (!isEmpty(matrix)) {
        for (int i = 0; i < matrix->num_rows; i++) {
            for (int j = 0; j < matrix->num_cols; j++)
                printf("%0.3f ", matrix->index[i][j]);
            printf("\n");
        }
    }
}

/*******************************************************
 *           Matrix Addition & Deletion
 *******************************************************/
Matrix MultiplyMatrices(Matrix matrix_A, Matrix matrix_B){
    // Makes sure matrices exist and dot product can be applied to the matrices
    if(isEmpty(matrix_A) || isEmpty(matrix_B) || matrix_A->num_cols != matrix_B->num_rows) {
        fprintf(stderr, "%s", "Error - Need an NxN matrix to perform matrix multiplication");
        return NULL;
    }

    Matrix result_matrix = NewMatrix(matrix_A->num_rows, matrix_B->num_cols);

    // Apply Dot Product
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


Matrix AddMatrices(Matrix matrix_A, Matrix matrix_B, int subtract_flag){
    // Makes sure matrices exists and are same size before performing addition
    if(isEmpty(matrix_A) || isEmpty(matrix_B) || matrix_A->num_rows != matrix_B->num_rows || matrix_A->num_cols != matrix_B->num_cols) {
        fprintf(stderr, "%s", "Error - Need an NxN matrix to perform matrix addition");
        return NULL;
    }

    // set subtraction flag to -1 if user passes in a 1 for the subtract parameter
    int subtraction_flag = 1;
    if(subtract_flag == 1)
        subtraction_flag = -1;

    Matrix result_matrix = NewMatrix(matrix_A->num_rows, matrix_A->num_cols);

    for(int i = 0; i < matrix_A->num_rows; i++){
        for(int j = 0; j < matrix_A->num_cols; j++)
            result_matrix->index[i][j] = matrix_A->index[i][j] + (subtraction_flag * matrix_B->index[i][j]);
    }
    return result_matrix;
}


/*******************************************************
 *          Matrix Transposing & Rotation
 *******************************************************/
void RotateMatrixClockwise(Matrix matrix){
    // make sure matrix exists and is square
    if(isEmpty(matrix) || !isSquare(matrix))
        fprintf(stderr, "%s", "Error - Need an Nxn matrix to rotate");
    else{
        Transpose(matrix);
        SwapColumns(matrix);
    }
}

void RotateMatrixCounterClockwise(Matrix matrix){
    // make sure matrix exists and is square
    if(isEmpty(matrix) || !isSquare(matrix))
        fprintf(stderr, "%s", "Error - Need an Nxn matrix to rotate");
    else{
        SwapColumns(matrix);
        Transpose(matrix);
    }
}

void Transpose(Matrix matrix){
    if(isEmpty(matrix))
        return;
    // Transpose NxN matrix
    for(int row = 0; row < matrix->num_rows; row++){
        for(int col = row; col < matrix->num_cols; col++)
            SwapValues(*(matrix->index+row)+col, *(matrix->index+col)+row);
    }
}


/*******************************************************
 *                Matrix Determinants
 *******************************************************/
double Determinant(Matrix matrix){
    // make sure matrix is square
    if(isEmpty(matrix) || !isSquare(matrix)) {
        fprintf(stderr, "%s", "Error - Need an NxN matrix to calculate determinant");
        return -1;
    }
    double determinant_multiplier = ReducedRowEchelonForm(matrix);
    int determinant = 1;
    for(int i = 0; i < matrix->num_rows; i++) // multiply diagonal
        determinant *= matrix->index[i][i];
    return determinant * determinant_multiplier; // scale determinant by value from performing elementary row operations
}


/*******************************************************
 *         Matrix Decomposition Algorithms
 *******************************************************/
double ReducedRowEchelonForm(Matrix matrix) {
    if(isEmpty(matrix))
        return -1;
    int pivot = 0;
    // function keeps track of determinant multiplier in case user needs to calculate
    // determinant value.
    double determinant_multiplier = 1;
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
        determinant_multiplier *= matrix->index[row][pivot]; // Apply Rule 1 and Rule 2 of Properties of Row Operations for Determinants
        DivideRow(matrix, row, matrix->index[row][pivot]);

        for (i = 0; i < matrix->num_rows; i++) {
            if (i != row)
                AddMultipleRow(matrix,i,row,-matrix->index[i][pivot]); // Rule 3 of Properties of Row Operations for Determinants
        }
    }
    return determinant_multiplier;
}

Matrix Cholesky(Matrix matrix){
    if(isEmpty(matrix))
        return NULL;
    Matrix new_matrix = NewMatrix(matrix->num_rows, matrix->num_cols);
    // loop over each row
    for(int i = 0; i < matrix->num_rows; i++){
        double temp_for_diag = 0;
        // calculate non-diagonal value
        for(int j = 0; j < i; j++){
            double temp_for_non_diag = 0.0;
            for(int k = 0; k < j; k++)
                // calculate non-diagonal value
                temp_for_non_diag += (new_matrix->index[i][k] * new_matrix->index[j][k]);
            new_matrix->index[i][j] = (1.0/new_matrix->index[j][j])*(matrix->index[i][j] - temp_for_non_diag);
            temp_for_diag += (pow(new_matrix->index[i][j], 2.0));
        }
        // calculate diagonal value
        new_matrix->index[i][i] = sqrt(matrix->index[i][i] - temp_for_diag);
    }
    return new_matrix;
}


/*******************************************************
 *             Matrix Helper Functions
 *******************************************************/
void SwapRows(Matrix matrix, int rowA, int rowB){
    for(int i = 0; i < matrix->num_cols; i++){
        double temp = matrix->index[rowA][i];
        matrix->index[rowA][i] = matrix->index[rowB][i];
        matrix->index[rowB][i] = temp;
    }
}

void DivideRow(Matrix matrix, int row, double divisor){
    for(int i = 0; i < matrix->num_cols; i++)
        matrix->index[row][i] /= divisor; // Reduce row by dividing by a common divisor
}


void AddMultipleRow(Matrix matrix, int row_receiver, int row_multiple, double scalar){
    for (int col = 0; col < matrix->num_cols; col++)
        matrix->index[row_receiver][col] += scalar * matrix->index[row_multiple][col];
}


void SwapColumns(Matrix matrix){
    size_t column_right = matrix->num_cols-1;
    for(int column_left = 0; column_left < matrix->num_cols/2; column_left++){
        for(int row = 0; row < matrix->num_rows; row++)
            SwapValues(*(matrix->index+row)+column_left, *(matrix->index+row)+column_right);
        column_right--;
    }
}

void SwapValues(double *index_one, double *index_two){
    double temp_value = *index_one;
    *index_one        = *index_two;
    *index_two        = temp_value;
}

int isEmpty(Matrix matrix){
    if(!matrix || matrix->num_rows <= 0 || matrix->num_cols <= 0)
        return 1;
    return 0;
}

int isSquare(Matrix matrix){
    if(matrix->num_rows == matrix->num_cols)
        return 1;
    return 0;
}


/*******************************************************
 *           Miscellaneous Matrix operations
 *******************************************************/
int IsLinearIndependent(Matrix matrix){
    if(isEmpty(matrix))
        return -1;
    // Linear independent matrices have a non-zero determinant
    double determinant = Determinant(matrix);
    if(determinant != 0)
        return 1;
    return 0;
}

Matrix SolveSystem(Matrix matrix){

    if(isEmpty(matrix))
        return NULL;

    // Make sure the matrix is augmented with a constant column vector
    if(matrix->num_cols < matrix->num_rows){
        fprintf(stderr,"%s", "Must augment matrix with a constant vector");
        return NULL;
    }

    // Reduce system before solving for unknowns
    ReducedRowEchelonForm(matrix);
    Matrix result_matrix = NewMatrix(matrix->num_rows,1);

    // Use back-substitution to solve reduced matrix
    for(int i = matrix->num_rows-1; i >= 0; i--){

        // The matrix has no solutions if it's inconsistent
        if(matrix->index[i][i] == 0 && matrix->index[i][matrix->num_cols-1] != 0){
            fprintf(stderr,"%s","No solutions");
            return NULL;
        }
        // if the unknown variable has a non-zero coefficient, then a value for it must exist
        else if(matrix->index[i][i] != 0) {
            result_matrix->index[i][0] = matrix->index[i][matrix->num_cols-1];

            for(int j = i+1; j < matrix->num_rows; j++) {
                if(matrix->index[i][j] != 0)
                    result_matrix->index[i][0] = matrix->index[i][j] * result_matrix->index[j][0];
            }

            result_matrix->index[i][0] /= matrix->index[i][i]; // cause of nan
        }
        // The matrix has infinitely many solutions if a zero row exists
        else{
            fprintf(stderr,"%s","Infinitely many solutions");
            return NULL;
        }
    }

    return result_matrix;
}




