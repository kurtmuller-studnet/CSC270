#include <stdio.h>

//a and b are passed by value while sum is passed by reference
//Returns the sum of a and b and returns the int 
int add(int a, int b, int *sum){
    // Dereference first. We want to update the value of sum, not the value of the pointer
    *sum = a + b;
    return *sum;
}

int main(void){
    int a, b, sum;

    a = 5; b = 7;
    //Pass the pointer to sum, NOT the actual variable
    add(a, b, &sum);

    printf("The sum of %d and %d is %d.\n", a, b, sum);
    return 0;
}