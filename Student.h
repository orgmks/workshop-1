#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
private:
    int id;
    string nombre;
public:
    Student(); //default constructor
    ~Student(); 
    Student(int id, const string& name);

    int getID() const;
    string getName() const;
    void display() const;

    
};

#endif
