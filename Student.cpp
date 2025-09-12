#include "Student.h"
#include <iostream>

Student::Student() :
     id(0), name("") {}

Student::Student(int id, const std::string& name) : 
    id(id), name(name) {}

int Student::getId() const {
     return id; }

std::string Student::getName() const { 
    return name; }

void Student::display() const {
    std::cout << "Name: " << name << " | ID: " << id << '\n';
}
