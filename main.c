/****************************
 * Author: Blake A. Molina
 * Created on: 5/19/17
 * License: GPL
 ****************************/

#include "matrix.h"

void InitializeMatrix(matrix_ptr matrix){
    for(int i = 0; i < matrix->num_rows; i++){
        for(int j = 0; j < matrix->num_cols; j++){
            printf("Enter value for [%d,%d]: ", i, j);
            scanf("%lf", &matrix->index[i][j]);
            printf("\n");
        }
    }
}


int main()
{

    matrix_ptr matrix = NewMatrix(4,4);
    InitializeMatrix(matrix);
    RotateMatrixCounterClockwise(matrix);
    PrintMatrix(matrix);


    return 0;
}