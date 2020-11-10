#include <sstream>
#include <iostream>
#include <string>
#include <exception>
#include "shapes.h"

/*****************************/

Rectangle::Rectangle(float length, float width) {
	setLength(length);
	setWidth(width);
}

float Rectangle::getlength() const {
	return length;
}

float Rectangle::getwidth() const {
	return width;
}

void Rectangle::setLength(float num) {
	if (num >= 0) {
		this->length = num;
	}
	else {
		throw std::invalid_argument ("EXCEPTION: Negative Side Exception");
	}
}

void Rectangle::setWidth(float num) {
	if (num >= 0) {
		this->width = num;
	}
	else {
		throw std::invalid_argument ("EXCEPTION: Negative Side Exception");
	}
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
	setRadius(radius);
}

float Circle::getradius() const {
	return radius;
}

void Circle::setRadius(float num) {
	if (num >= 0) {
		this->radius = num;
	}
	else {
		throw std::invalid_argument ("EXCEPTION: Negative Radius Exception");
	}
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

