#include "Subject.h"
#include <iostream>

Subject::Subject(const std::string& name, int code){
    this -> name = name;
    this -> code = code;
}

Subject::~Subject(){}

const std::string& Subject::getName() const {return name;}
int Subject::getId() const {return code;}

bool Subject::addStudentOnSubject(const Student& s)
{
    if(registered.exists(s.getId())){
        return false;
    }
    registered.insert(s);
    return true;
}

bool Subject::removeStudentFromSubject(int studentID){
    return registered.remove(studentID);
}

void Subject::display() const {
    std::cout << "Subject: " << code << " - " << name << '\n';
    std::cout << "Enrolled students (" << registered.getSize() << "):\n";
    registered.displayAll();
}
