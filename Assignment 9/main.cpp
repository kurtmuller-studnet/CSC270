#include <iostream>
#include <string>
#include "Person.h"

int main() {

    std::cout << "Program Start: " << std::endl;

    int numberOfPeople;
    std::string personName, personId, value1, value2;
    std::string personType;


    std::cin >> numberOfPeople;

    std::string peopleInformation = "";

    for (int i = 0; i < numberOfPeople;i++){
        std::cin >> personType;
        if (personType == "p") {            
            Professor prof(personName, i);
            prof.setPublications(std::stoi(value1));
            prof.setRank(value2);

            peopleInformation += prof.getData();
        }// end if
        else if (personType == "s"){
            Student stud(personName, i);
            stud.setMajor(value1);
            stud.setMinor(value2);

            peopleInformation += stud.getData();
        }// end else if
    }// end for


    std::cout << peopleInformation << std::endl;

    std::cout << "After Second For Loop\n---END OF PROG---" << std::endl;
}// end main