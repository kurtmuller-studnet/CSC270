#include <stdio.h>
#define PI 3.1415926

float diameter_func(float radius) {
    float result = radius * 2;
    return result;
}
float circumference_func(float diameter) {
    float circumference = diameter * PI;
    return circumference;
}

float area_func(float radius) {
    float area = PI * radius * radius;
    return area;
}

int main(void) {
    //Initilize the varibales needed
    float radius = 0;

    //Get the radius input by the user
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    //Calculate the diamter, circumference, and area with the functions

    float diameter = diameter_func(radius);
    float circumference = circumference_func(diameter);
    float area = area_func(radius);

    //Print the results
    if (radius > 0) {
        printf("A circle with radius: %f\n", radius);
        printf("\tDiameter: %0.3f\n", diameter);
        printf("\tArea: %0.3f\n", area);
        printf("\tCircumference: %0.3f\n", circumference);

        return 0;
    }
    else {
        printf("The radius must be greater than 0.\n");
        return 1;
    }


    return 0;
}



