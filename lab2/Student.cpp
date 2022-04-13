#include "Student.h"
#include <sstream>

Student::Student(int perm,
                 std::string lastName,
                 std::string firstAndMiddleNames) {
    // REMEMBER: PURPOSE OF A CONSTRUCTOR IS TO INITIALIZE
    // ALL DATA MEMBERS WITH REASONABLE VALUES
    this->perm = perm;
    this->lastName = lastName;
    this->firstAndMiddleNames = firstAndMiddleNames;
}

int Student::getPerm() const {
    return perm;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getFirstAndMiddleNames() const {
    return firstAndMiddleNames;
}

std::string Student::getFullName() const {
    return getFirstAndMiddleNames() + " " + getLastName();
}

std::string Student::toString() const {
    // e.g. [12345,Smith,Malory Logan]
    std::ostringstream oss;

    oss << "["
        << this->getPerm() << ","
        << this->getLastName() << ","
        << this->getFirstAndMiddleNames() << "]";
    return oss.str();
}
