#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>
#include "Student.h"
#include "LinkedList.h"


class Subject
{
private:
    std::string name;
    int code;
    LinkedList<Student> registered;

public:
    Subject(const std::string& name, int code);
    ~Subject();
    
    const std::string& getName() const;
    int getId() const;

    bool addStudentOnSubject(const Student& s);
    bool removeStudentFromSubject(int studentId);
    void display() const;
};

#endif