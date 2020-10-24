#include <iostream>
#include <string>
#include <sstream>
#include "Person.h"

int main() {
    //Initialize all the variable that will be required
    int numberOfPeople;
    std::string peopleInformation = "";
    std::string personName, personId, value1, value2;
    std::string personType;
    
    //Ask user for number of people
    std::cin >> numberOfPeople;

    //For loop dealing with the assinging of values to the corresponding objects
    for (int i = 0; i < numberOfPeople;i++){
        
        //Ask the user for the necessary information
        std::cin >> personType;
        std::cin >> personName >> value1 >> value2;

        if (personType == "p") {  
            Professor prof(personName, i + 1);
            prof.setPublications(value1);
            prof.setRank(value2);

            peopleInformation += prof.getData();
        }// end if
        else if (personType == "s"){
            Student stud(personName, i + 1);
            stud.setMajor(value1);
            stud.setMinor(value2);

            peopleInformation += stud.getData();
        }// end else if
    }// end for

    //Prints out the formatted results
    std::cout << peopleInformation.substr(0, peopleInformation.size()-1) << std::endl;
}// end main