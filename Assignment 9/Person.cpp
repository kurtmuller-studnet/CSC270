#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "Person.h"

Person::Person() {}
Person::Person (std::string personName, int personId) {
    this->name = personName;
    this->id = personId;
}
std::string Person::getData() {
    //For converting id to a string
    std::stringstream strStream;
    strStream << this->id;
    std::string idStr;
    strStream >> idStr;

    std::string str = this->name + " (id " + idStr + ")";
    return str;
}
std::string Person::getName() {
    return this->name;
}
int Person::getId() {
    return this->id;
}
//Setters
void Person::setName(std::string newName) {
    this->name = newName;
}
void Person::setId(int newId) {
    this->id = newId;
}

Professor::Professor (std::string personName, int personId) : Person(personName, personId){}
std::string Professor::getData() {
    std::string str;

    //For converting id to a string because Moodle compiler does not allow use of std::to_string()
    std::stringstream strStream;
    strStream << this->id;
    std::string idStr;
    strStream >> idStr;

    //Converting publications to a string
    std::stringstream strStream2;
    strStream2 << this->publications;
    std::string publicationsStr;
    strStream2 >> publicationsStr;

    //Selects the appropriate string to return based on varibles of the object
    if (this->getRank() != "none" && this->getPublications() != 0){
        str = this->rank + " professor " + this->name + " (id " + idStr + ") has " + publicationsStr + " publications\n";
    }
    else if (this->getRank() != "none" && this->getPublications() == 0) {
        str = this->getRank() + " professor " + this->name + " (id " + idStr + ")\n";
    }
    else if (this->getPublications() != 0 && this->getRank() == "none") {
        str = "professor " + this->name + " (id " + idStr + ") has " + publicationsStr + " publications\n";
    }
    else {
        str = "professor " + this->name + "(id " + idStr + ")\n";
    }
    return str;
}
void Professor::setPublications(std::string newPublications) {   
    int x;
    sscanf(newPublications.c_str(), "%d", &x);   
    this->publications = x;
}
void Professor::setRank(std::string newRank) {
    this->rank = newRank;
}
int Professor::getPublications() {
    return this->publications;
}
std::string Professor::getRank() {
    return this->rank;
}

Student::Student (std::string personName, int personId) : Person(personName, personId){}
std::string Student::getData() {
    std::string str;

    //Converts id to a string
    std::stringstream strStream;
    strStream << this->id;
    std::string tempStr;
    strStream >> tempStr;

    //Selects the appropriate string to return based on varibles of the object
    if (this->getMajor() != "none" && this->getMinor() != "none"){
        str = this->major + " major " + this->name + " (id " + tempStr + ") minors in " + this->getMinor() + "\n";
    }
    else if (this->getMajor() != "none" && this->getMinor() == "none") {
        str = this->getMajor() + " major " + this->name + " (id " + tempStr + ")\n";
    }
    else if (this->getMinor() != "none" && this->getMajor() == "none") {
        str = this->name + " (id " + tempStr + ") minors in " + this->getMinor() + "\n";
    }
    else{
        str = this->name + "(id " + tempStr + ")\n"; 
    }
    return str;
}
std::string Student::getMajor() {
    return this->major;
}
std::string Student::getMinor() {
    return this->minor;
}
void Student::setMajor(std::string newMajor) {
    this->major = newMajor;
}
void Student::setMinor(std::string newMinor) {
    this->minor = newMinor;
}