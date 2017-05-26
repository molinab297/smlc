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

int main()
{
    int size;
    scanf("%d", &size);
    int ar[size];
    Matrix m;



    return 0;
}