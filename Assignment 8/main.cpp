/*
 * main.cpp
 *
 * Created on Oct 17, 2020
 * Author: Kurt Muller
*/
#include <iostream>
#include "Temperature.h"

int main() {
    float temp = 68.0;

    std::cout << "Fahrenheit: " << temp << std::endl;
    Temperature t(temp, Temperature::FAHRENHEIT);

    std::cout << "in Celcius: " << t.getCelsius() << std::endl;
    std::cout << "in Kelvin : " << t.getKelvin() << std::endl;
}