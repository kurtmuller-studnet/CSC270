#include <sstream>
#include <iostream>
#include <string>
#include "shapes.h"

// This checks to see if a variable is less than 0, which is illegal
int Shape::checkVar(float variable) {
	if (variable < 0) {
		return 1;
	}
	else {
		return 0;
	}
}
// Exception for when there is a negative side in an object
const char * Shape::NegativeSideErr() const throw() {
	return "\nEXCEPTION: Negative Side Exception\n";
}
// Execption for when there is a negative radius in an object
const char * Shape::NegativeRadiusErr() const throw() {
	return "\nEXCEPTION: Negative Radius Exception\n";
}

/*****************************/

Rectangle::Rectangle(float length, float width) {
	this->length = length;
	this->width = width;
	int lengthChecK = checkVar(length);
	int widthCheck = checkVar(width);
	while (lengthChecK == 1 || widthCheck == 1) {
		std::cerr << NegativeSideErr() << std::endl;
		std::cout << "Length is :" << length << "\nWidth is: " << width << std::endl;
		std::cout << "Enter a new length and width: " << std::endl;
		std::cin >> this->length >> this->width;
		lengthChecK = checkVar(this->length); widthCheck = checkVar(this->width);
	}
}

float Rectangle::getlength() const {
	return length;
}

float Rectangle::getwidth() const {
	return width;
}

float Rectangle::perimeter() const {
	return 2 * length + 2 * width;
}

float Rectangle::area() const {
	
	return length * width;
}

std::string Rectangle::str() const {
	std::stringstream  out;
	// "A rectangle width sides (3,4)"

	out << "A rectangle width sides (" << length << "," << width << ")";
	return out.str();
}

/******************************/

Square::Square(float side) : Rectangle(side, side) {
}

std::string Square::str() const {
	std::stringstream  out;
	// "A square width sides (3)"

	out << "A square width sides (" << getlength() << ")";
	return out.str();
}

/******************************/

Circle::Circle(float radius) {
	this->radius = radius;
	int radiusCheck = checkVar(radius);
	while(radiusCheck == 1) {
		std::cerr << NegativeRadiusErr() << std::endl;
		std::cout << "Radius is :" << radius << std::endl;
		std::cout << "Enter a new radius: " << std::endl;
		std::cin >> this->radius;
		radiusCheck = checkVar(this->radius);
	}
}

float Circle::getradius() const {
	return radius;
}

float Circle::perimeter() const {	
	return 2 * radius * PI;
}

float Circle::area() const {
	return PI * radius * radius;
}

std::string Circle::str() const {
	std::stringstream  out;
	// "A circle width radius (3)"

	out << "A circle width radius (" << radius << ")";
	return out.str();
}

