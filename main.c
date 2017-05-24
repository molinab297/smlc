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

    matrix_ptr matrix = NewMatrix(3,3);
    InitializeMatrix(matrix);
    ReducedRowEchelonForm(matrix);
    if(isLinearIndependent(matrix))
        printf("%s", "Linearly independent");


    return 0;
}