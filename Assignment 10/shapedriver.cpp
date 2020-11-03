#include <iostream>
#include "shapes.h"

int main() {
	Rectangle r(3,4);
	Square s(3);
	Circle c(3);

	
	std::cout << "Rectangle: " << r.getlength() << " " << r.getwidth() 
		<< " " << r.area() << " " << r.perimeter() << std::endl;

	std::cout << "Square: " << s.getlength() << " " << s.getwidth() 
		<< " " << s.area() << " " << s.perimeter() << std::endl;
	
	std::cout << "Circle: " << c.getradius()
		<< " " << c.area() << " " << c.perimeter() << std::endl;
	
	
	std::cout << r.str() << std::endl;
	std::cout << s.str() << std::endl;
	std::cout << c.str() << std::endl;
	return 0;
}
