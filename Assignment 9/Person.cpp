#include <string>
#include <iostream>
#include "Person.h"

Person::Person() {}
Person::Person (std::string personName, int personId) {
    this->name = personName;
    this->id = personId;
}
std::string Person::getData() {
    std::cout << this->name << " (id " << this->id << ")" << std::endl;
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
    if (this->getRank() != "none" && this->getPublications() != 0){
        str = this->rank + " " + this->name + " (id " + std::to_string(this->id) + ") has " + std::to_string(this->getPublications()) + " publications.\n";
    }
    else if (this->getRank() != "none" && this->getPublications() == 0) {
        str = this->getRank() + " " + this->name + " (id " + std::to_string(this->id) + ").\n";
    }
    else if (this->getPublications() != 0 && this->getRank() == "none") {
        str = this->name + " (id " + std::to_string(this->id) + ") has " + std::to_string(this->getPublications()) + " publications.\n";
    }
    else {
        str = this->name + "(id " + std::to_string(this->id) + ")\n";
    }
    return str;
}
void Professor::setPublications(int newPublications) {
    this->publications = newPublications;
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
    if (this->getMajor() != "none" && this->getMinor() != "none"){
        str = this->major + " major " + this->name + " (id " + std::to_string(this->id) + ") minors in " + this->getMinor() + ".\n";
    }
    else if (this->getMajor() != "none" && this->getMinor() == "none") {
        str = this->getMajor() + " major " + this->name + " (id " + std::to_string(this->id) + ").\n";
    }
    else if (this->getMinor() != "none" && this->getMajor() == "none") {
        str = this->name + " (id " + std::to_string(this->id) + ") minors in " + this->getMinor() + ".\n";
    }
    else{
        str = this->name + "(id " + std::to_string(this->id) + ")./n"; 
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