#include <stdio.h>
#include <stdlib.h>
 
 void print_2d_array(int rows, int cols, int *a) {
     for(int i = 0; i < rows; ++i) {
         for(int j = 0; j < cols; ++j) {
             printf("%d ", a[i * cols + j]);
         }
         printf("\n");
     }
 }
 
 int main(void) {
     int rows = 0, cols = 0;
     printf("Give me the array rows x cols dimensions:\n");
     printf("rows = ");
     scanf("%d", &rows);
     //  ... for production code check scanf error code !!!
     printf("cols = ");
     scanf("%d", &cols);
     //  ... for production code check scanf error code !!!
     
     int *arr = malloc(rows * cols * sizeof(int));
     //  ... for production code check if the array was successfully allocated
 
     // Initialize the array
     for(int i = 0; i < rows * cols; ++i) {
         arr[i] = i;
     }
 
     print_2d_array(rows, cols, arr);
 
     free(arr);
 }