#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

//Converts Celsius to Fahrenheit
float fahrenheit_conv(float celsius){
    float result = celsius * 1.8 + 32;
    return result;

}
//Convert either fahrenheit or kelvin to celsius
float celsius_conv(float temp, char type){
    float result;
    if (type == 'f'){
        result = (temp -32)/1.8;
    }
    else if (type == 'k'){
        result = temp - 273.15;
    }
    return result;
}
//Convert celsius to kelvin 
float kelvin_conv(float celsius){
    float result = celsius + 273.15;
    return result;
}
//Helper to see if a char is a number
bool isNumber (char c){
    if ((c >= '0')&&(c <= '9')){
        return true;
    }
    else{
        return false;
    }
}

//Main
int main(void){
    char input[31];
    char tempType;
    printf("Enter input temperature: ");
    scanf("%s", input);

    float celsius, fahrenheit, kelvin;
    
    //If this variables changes, then the input was wrong and will cause the program to terminate
    int cont = 1;
    //This varible will determine the error message that displays due to invalid input
    //0 = properly played out, 1 = missing temperature scale, 2 = invalid temp
    int reason = 0;

    while(cont == 1){
        //For index of Letter in input, and check if the char is a number
        int letterIndex;
        bool isNum;
        
        //If there is no letter input, the program will terminate with an error message
        for (int i = 0; i < strlen(input); i++){
            isNum = isNumber(input[i]);
            if (isNum || input[i] == '.') {
                continue;
            }
            else{
                letterIndex = i;
                break;
            }  
        }

        int numCount = 0;

        //Goes through input to find where the index of the temperature type is
        for (int i = 0; i < strlen(input); i++){
            isNum = isNumber(input[i]);
            if (isNum || input[i] == '.' || input[i] == '-') {
                numCount++;
                continue;
            }
            else{
                if (numCount == 0){
                    reason = 1;
                    cont = 0;
                    break;
                }
                letterIndex = i;
                break;
            } 
        }

        //If the numCount is 0, that means there were no numbers in the input, which is invalid and will terminate with an error
        if (numCount == 0){
            reason = 1;
            cont = 0;
            break;
        }

        //Will assign a tempType based on the last letter of the input, if there was an improper tempType, then the program will terminate with an error
        if (input[letterIndex] == 'c' || input[letterIndex] == 'C'){
            tempType = 'C';
        }
        else if (input[letterIndex] == 'f' || input[letterIndex] == 'F'){
            tempType = 'F';
        }
        else if (input[letterIndex] == 'k' || input[letterIndex] == 'K'){
            tempType = 'K';
        }
        else {
            reason = 2;
            cont = 0;
        }

        char temperatureChar[letterIndex + 1];
        float temperture;

        //Converts the input to a float
        for (int i = 0; i < strlen(input); i++){
            temperatureChar[i] = input[i];
            if (i == letterIndex - 1){
                temperture = atof(temperatureChar);
                break;
            }
        }

        //Will convert the temperature input based upon what tempType it is
        switch (tempType) {
            case 'F':
                fahrenheit = temperture;
                celsius = celsius_conv(fahrenheit, 'f');
                kelvin = kelvin_conv(celsius);
                printf("%0.2f Fahrenheit converts to:\n\t%0.2f C\n\t%0.2f K\n", fahrenheit, celsius, kelvin);
                cont = 0;
                break;
            case 'C':
                celsius = temperture;
                fahrenheit = fahrenheit_conv(celsius);
                kelvin = kelvin_conv(celsius);
                printf("%0.2f Celsius converts to:\n\t%0.2f F\n\t%0.2f K\n", celsius, fahrenheit, kelvin);
                cont = 0;
                break;
            case 'K':
                kelvin = temperture;
                celsius = celsius_conv(kelvin, 'k');
                fahrenheit = fahrenheit_conv(celsius);
                printf("%0.2f Kelvin converts to:\n\t%0.2f C\n\t%0.2f F\n", kelvin, celsius, fahrenheit);
                cont = 0;
                break; 
        }

    }

    //Based upon what value reason is, it will give an error message
    switch (reason){
        case 0:
            break;
        case 1:
            printf("Invalid temperature scale\n");
            break;
        case 2:
            printf("Invalid temperature scale\n");
            break;
    }
    return 0;
}