#include <iostream>
#include <string>
#include "Person.h"

int main() {
    Person test1 = Person("Deez nuts", 5433);
    test1.getData();
    std::cout << "\n--END TEST 1--\n";
    printf("\n");

    Professor test2 = Professor("Got Em", 2123);
    test2.getData();
    printf("\n");

    test2.setPublications(2);
    test2.getData();
    printf("\n");

    test2.setPublications(0);
    test2.setRank("Assistant Professor");
    test2.getData();
    printf("\n");

    test2.setPublications(4);
    test2.setRank("Professor");
    test2.getData();
    printf("\n");
    std::cout << "\n--END TEST 2--\n";
    printf("\n");

    Student test3 = Student("Jimmy Dean", 6969);
    test3.getData();
    printf("\n");

    test3.setMinor("Communications");
    test3.getData();
    printf("\n");

    test3.setMinor("");
    test3.setMajor("Comp Sci");
    test3.getData();
    printf("\n");

    test3.setMinor("Economics and Finace");
    test3.getData();
    printf("\n");
    std::cout << "\n--END TEST 3--\n";
}