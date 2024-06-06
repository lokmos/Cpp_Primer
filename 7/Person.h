#ifndef PERSON_H
#define PERSON_H

#include <string>

// struct Person {
//     std::string name;
//     std::string address;

//     std::string getName() const {return name;}
//     std::string getAddress() const {return address;}
// };

class Person {
// friend declarations
friend std::istream &read(std::istream &is, Person& person);
friend std::ostream &print(std::ostream &os, const Person& person);

private:
    std::string name;
    std::string address;

public:
    // constructors
    Person() = default;
    Person(const std::string &n, const std::string &a) : name(n), address(a) {}
    Person(std::istream &is) {read(is, *this);}

    // member functions
    std::string getName() const {return name;}
    std::string getAddress() const {return address;}
};

std::istream &read(std::istream &is, Person& person);
std::ostream &print(std::ostream &os, const Person& person);

#endif