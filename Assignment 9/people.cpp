#include <iostream>
#include <string>

class Person {
    public:
        std::string name;
        int id;

        //Intialize the variables of Person
        Person(std::string personName, int personId) {
            this->name = personName;
            this->id = personId;
        }

        // Returns a formated string of objects attributes
        void getData() {
            printf("%s has an id number of %d\n", this->name.c_str(), this->id);
        }

        //Getters
        std::string getName() {
            return this->name;
        }
        int getId() {
            return this->id;
        }
        //Setters
        void setName(std::string newName) {
            this->name = newName;
        }
        void setId(int newId) {
            this->id = newId;
        }

};

class Professor: public Person {
    private:
        int publications;
        std::string rank;

        //Getters
        int getPublications() {
            return this->publications;
        }
        std::string getRank() {
            return this->rank;
        }

        //Setters
        void setPublications(int newPublications) {
            this->publications = newPublications;
        }
        void setRank(std::string newRank) {
            this->rank = newRank;
        }
};

class Student: public Person {
    private:
        std::string major;
        std::string minor;

        //Getters
        std::string getMajor() {
            return this->major;
        }
        std::string getMinor() {
            return this->minor;
        }

        //Setters
        void setMajor(std::string newMajor) {
            this->major = newMajor;
        }
        void setMinor(std::string newMinor) {
            this->minor = newMinor;
        }
};

int main() {

    Person test1 = Person("Bruh", 1234);
    test1.getData();

    std::cout << "Add the people that you want:\n";
    std::string inputPersonStr;
    std::cin >> inputPersonStr;

    int count = 0;
    std::string delimiter = " ";
    std::string personName;
    std::string personId;


    size_t pos = 0;
    std::string token;
    while ((pos = inputPersonStr.find(delimiter)) != std::string::npos) {
        token = inputPersonStr.substr(0, pos);
        std::cout << token;
        switch (count){
            case 0:
                personName = token;
            case 1:
                personId = token;
        }
        inputPersonStr.erase(0, pos + delimiter.length());
        count++;
    }

    std::cout << "Name: " << personName << " and ID: " << personId;
   
}