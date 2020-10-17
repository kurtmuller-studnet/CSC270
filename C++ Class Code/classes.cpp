#include <iostream>
#include <string>

class HelloClass{
    public:
        int myNum;
        std::string greeting;
};

int main(){
    HelloClass myObj; // Create an object of MyClass

    // Access attributes and set value
    myObj.myNum = 15;
    myObj.greeting = "Hello C++ Class!";

    std::cout << myObj.myNum << "\n";
    std::cout << myObj.greeting << std::flush;


}