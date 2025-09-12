#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
private:
    int id;
    std::string name;

public:
    Student();
    Student(int id, const std::string& name);
    ~Student() = default;         
    int getId() const;
    std::string getName() const;
    void display() const;
};

#endif
