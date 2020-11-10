#include <iostream>
#include "shapes.h"

int main() {
	try { 
		Rectangle r(4,5);
		Square s(2);
		Circle c(7);

		
		std::cout << "Rectangle: " << r.getlength() << " " << r.getwidth() 
			<< " " << r.area() << " " << r.perimeter() << std::endl;

		std::cout << "Square: " << s.getlength() << " " << s.getwidth() 
			<< " " << s.area() << " " << s.perimeter() << std::endl;
		
		std::cout << "Circle: " << c.getradius()
			<< " " << c.area() << " " << c.perimeter() << std::endl;
		
		
		std::cout << r.str() << std::endl;
		std::cout << s.str() << std::endl;
		std::cout << c.str() << std::endl;
	} // end try
	// This will catch an exception thrown from a negative side or radius
	catch (std::exception& e) {
		std::cout << e.what() << "\n";
	} // end catch 
	return 0;
}
