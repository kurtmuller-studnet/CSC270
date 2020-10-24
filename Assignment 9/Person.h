#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>

class Person {
    public:
        int id;
        std::string name;
        Person();
        Person(std::string personName, int personId);
        std::string getData();
        std::string getName();
        int getId();
        void setName(std::string newName);
        void setId(int newId);

};

class Professor: public Person {
    public:
        Professor() {}
        Professor (std::string personName, int personId);
        void setPublications(std::string newPublications);
        void setRank(std::string newRank);
        std::string getData();
        int getPublications();
        std::string getRank();

    private:
        int publications;
        std::string rank;
};

class Student: public Person {
    public:
        Student() {}
        Student (std::string personName, int personId);
        std::string getData();
        std::string getMajor();
        std::string getMinor();
        void setMajor(std::string newMajor);
        void setMinor(std::string newMinor);
    private:
        std::string major;
        std::string minor;
};
#endif /*PERSON_H_*/

