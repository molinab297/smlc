/****************************
 * Author: Blake A. Molina
 * Created on: 5/19/17
 * License: GPL
 ****************************/

#include "matrix.h"

void FillMatrix(Matrix matrix){
    for(int i = 0; i < matrix->num_rows; i++){
        for(int j = 0; j < matrix->num_cols; j++){
            printf("Enter value for [%d,%d]: ", i, j);
            scanf("%lf", (*(matrix->index+i)+j));
        }
    }
}

void PrintMatrix(Matrix matrix){
    if(!isEmpty(matrix)){
        for(int i = 0;i < matrix->num_rows; i++){
            for(int j = 0; j < matrix->num_cols; j++)
                printf("%0.1f ", matrix->index[i][j]);
            printf("\n");
        }
    }
}

int main()
{

    Matrix matrix = NewMatrix(4,3);
    Determinant(matrix, 1);


    return 0;
}