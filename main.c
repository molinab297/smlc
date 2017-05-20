// Author: Blake A. Molina
// Created on: 5/19/17
// License: GPL

#include "matrix.h"


int main()
{
    int num_rows, num_columns;
    printf("enter rows and columns: ");
    scanf("%d%d",&num_rows,&num_columns);

    double **matrix = NewMatrix(num_rows,num_columns);

    InitializeMatrix(matrix,num_rows,num_columns);
    Reduced_row_echelon_form(matrix,num_rows,num_columns);

    PrintMatrix(matrix, num_rows, num_columns);

    FreeMatrix(matrix, num_rows);

    return 0;
}