#include "Temperature.h"

Temperature::Temperature (float degrees, int system) {
    //Depending on what temperature type it is, it will convert it to celsius and assign that to this->celsius in the Temperature class
    switch (system) {
        case CELSIUS:
            this->celsius = degrees;
            break;
        case FAHRENHEIT:
            this->celsius = (degrees - 32.0) / 1.8;
            break;
        case KELVIN:
            this->celsius = degrees - 273.15;
            break;
    }
}
float Temperature::getFahrenheit() const {
    return this->celsius * 1.8 + 32.0;
}
float Temperature::getCelsius() const {
    return this->celsius;
}
float Temperature::getKelvin() const {
    return this->celsius + 273.15;
} 
