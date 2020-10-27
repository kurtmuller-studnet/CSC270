#include <iostream>

class MySum {
    public:
        int var;

        MySum(){};
        MySum(int a) : var(a) {} //Memeber Intializers

        MySum operator + (MySum &obj) {
            MySum reobj;
            reobj.var = this->var + obj.var;
            return reobj;
        }
};

int main() {
    MySum int_a(2), int_b(2);
    MySum reobj = int_a + int_b;
    std::cout << reobj.var;
}

//outputs 4