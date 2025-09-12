#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() : id(0), name("") {} //a null student 

Student::Student(int id, const string& name) {
    this ->id = id;
    this ->name = name;
}

int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

void Student::display() const {
    cout << "Name : " << name << "ID : " << id << endl;
}