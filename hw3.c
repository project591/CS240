#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Test out how you are allocating memory and if its actually working correctly. 
int main() {

    // Rows and columns will be defined by the user. 
    int rows = 0, columns = 0;
    int** matrix;
    int count = 0, i, j;

    scanf("%d %d", &rows, &columns);

    matrix = malloc(sizeof(int*) * rows); // Allocating memory for thhe rows

    for (int i = 0; i < rows; i++) // Allocating memory for the columns
        *(matrix + i) = malloc(sizeof(int*) * columns);
        //matrix[i] = malloc(sizeof(int*) * columns); Original method. 

    for (i = 0; i < rows; i++)
        for (j = 0; j < columns; j++)
        {
            scanf("%d", &*(*(matrix + i) + j));
            //scanf("%d", &matrix[i][j]); original
        }
    // This will print the transpose of the matrix
    for (i = 0; i < columns; i++)
        for (j = 0; j < rows; j++){
            printf("%d ", *(*(matrix + j) + i)); // Pointer way of printing this. 
          //  printf("%d ", matrix[j][i]); original way of printing this
    if (j == rows - 1) // When it hits the end of a column. 
        printf("\n");
}
    return 0; 
}
