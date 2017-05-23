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
            scanf("%lf", (*(matrix->index+i)+j));
        }
    }
}


int main()
{

    matrix_ptr matrix_1 = NewMatrix(4,4);
    matrix_ptr matrix_2 = NewMatrix(4,4);
    InitializeMatrix(matrix_1);
    Cholesky(matrix_1,matrix_2);
    PrintMatrix(matrix_2);
    FreeMatrix(&matrix_1);
    FreeMatrix(&matrix_2);


    return 0;
}