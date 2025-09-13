#include <iostream>
#include <string>
#include "Student.h"
#include "LinkedList.h"
#include "Subject.h"

LinkedList<Student> studentList; // General list of students
LinkedList<Subject> subjectList; // General List of Subjects


using namespace std;

void enrollStudentInCourse() {
    int studentId, code;

    cout << "Enter student ID: ";
    cin >> studentId;
    cin.ignore();

    cout << "Enter Subject code: ";
    cin >> code;
    cin.ignore();

    Student* st = studentList.searchById(studentId);
    if (!st) {
        cout << "Student not found." << endl;
        return;
    }
    Subject* sj = subjectList.searchById(code);
    if (!sj) {
        cout << "Subject not found." << endl;
        return;
    }

    if (sj->addStudentOnSubject(*st)) {
        cout << "Enrollment successful." << endl;
    } else {
        cout << "The student is already enrolled in this course." << endl;
    }
}

void removeStudentFromCourse() {
    int studentId, code;

    cout << "Enter student ID: ";
    cin >> studentId;
    cin.ignore();

    cout << "Enter Subject code: ";
    cin >> code;
    cin.ignore();

    Subject* sj = subjectList.searchById(code);
    if (!sj) {
        cout << "Subject not found." << endl;
        return;
    }

    if (sj->removeStudentFromSubject(studentId)) {
        cout << "Student unenrolled successfully." << endl;
    } else {
        cout << "The student was not enrolled in this course." << endl;
    }
}



void removeSubjectById() {
    int code;
    cout << "Enter Subject ID (code) to remove: ";
    cin >> code;
    cin.ignore();

    if (subjectList.removeById(code)) {
        cout << "Subject removed successfully." << endl;
    } else {
        cout << "Subject not found." << endl;
    }
}


void createSubject(){
    int code; string name;
    cout << "Enter Subject code: ";
    cin >> code; 
    cin.ignore();

    if (subjectList.exists(code)) {
        cout << "Error: A subject with this code already exists." << endl;
        return;
    }

    cout << "Enter Subject name: ";
    getline(cin, name);

    Subject c(name, code);
    subjectList.insertAtEnd(c);
    cout << "Subject Created and added." << endl;
}


void findSubject(){
    int opt;
    cout << "Search subject by: 1) Code  2) Name" << endl;
    cin >> opt;
    cin.ignore();

    if (opt == 1) {
        int code;
        cout << "Enter Subject Code you are looking for: ";
        cin >> code;
        cin.ignore();

        Subject* sj = subjectList.searchById(code);
        if (sj) {
            cout << "== SUBJECT FOUND ==" << endl;
            sj->display();
        } else {
            cout << "Subject not found." << endl;
        }
    } 
    else if (opt == 2) {
        string name;
        cout << "Enter Subject name: ";
        getline(cin, name);

        bool found = false;
        subjectList.forEach([&](const Subject& s){
            if (s.getName() == name) {
                if (!found) {
                    cout << "== MATCHING SUBJECTS ==" << endl;
                }
                found = true;
                s.display();
                cout << "-----------------------" << endl;
            }
        });
        if (!found) cout << "No subjects found with that name." << endl;
    } 
    else {
        cout << "Invalid option." << endl;
    }
}


void createStudent() {
    int id;
    string name;
    cout << "Enter student ID: ";
    while (!(cin >> id)) {
        cout << "Invalid ID. Please enter a number: ";
        cin.clear();
        cin.ignore();
        }
    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, name);
    while (name.empty()) {
        cout << "Name cannot be empty. Enter student name: ";
        getline(cin, name);
        }
    Student s(id, name);
    studentList.insertAtEnd(s);
    cout << "Student Created and added." << endl;
}

void findStudentById() {
    int id;
    cout << "Enter student ID you are looking for: ";
    cin >> id;
    Student* st = studentList.searchById(id);
    if (st) st->display();
    else    cout << "Student not found." << endl;
}

void findStudent() {
    int option;
    cout << "Search by: 1. ID  2. Name" << endl;
    cin >> option;
    cin.ignore();

    if (option == 1) {
        int id;
        cout << "Enter student ID: ";
        cin >> id;
        Student* st = studentList.searchById(id);
        if (st) st->display();
        else    cout << "Student not found." << endl;
    } 
    else if (option == 2) {
        string name;
        cout << "Enter student name: ";
        getline(cin, name);
        studentList.searchByName(name);
    }
    else {
        cout << "Invalid option." << endl;
    }
}

void displayStudents() {
    cout << "All students:" << endl;
    studentList.displayAll();
}

void removeStudentById() {
    int id;
    cout << "Enter student ID to remove: ";
    cin >> id;
    if (studentList.removeById(id)) {
        cout << "Student removed successfully." << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

void displaySubject() {
    cout << "All Subjects: " << endl;
    subjectList.display();
}

void showMenu() {
    cout << "=== ACADEMIC MANAGEMENT SYSTEM ===" << endl;
    cout << "STUDENTS" << endl;
    cout << "1. Create Student" << endl;
    cout << "2. Find Student" << endl;
    cout << "3. Remove Student" << endl;
    cout << endl;

    cout << "COURSES" << endl;
    cout << "4. Create Course" << endl;
    cout << "5. Find Course" << endl;
    cout << "6. Remove Course" << endl;
    cout << endl;

    cout << "REGISTRATION" << endl;
    cout << "7. Enroll student in course" << endl;
    cout << "8. Remove student from course" << endl;
    cout << endl;

    cout << "GRADES" << endl;
    cout << "9. Register grade" << endl;
    cout << endl;

    cout << "REPORTS" << endl;
    cout << "10. Get all students" << endl;
    cout << "11. Get courses from student" << endl;
    cout << "12. Calculate course average" << endl;
    cout << "13. Calculate overall GPA (Grade Point Average)" << endl;
    cout << endl;

    cout << "0. Exit" << endl;
    cout << "===================================" << endl;
}

void runMenu() {
    int option = -1;
    showMenu();
    
    while (option != 0) {
        cout << endl;
        cout << "Select an option: ";
        cin >> option;

        if (option == 1) {
            cout << "=== CREATE STUDENT ===" << endl;
            createStudent();
        }
        else if (option == 2) {
            cout << "=== FIND STUDENT ===" << endl;
            findStudent();
        }
        else if (option == 3) {
            cout << "=== REMOVE STUDENT ===" << endl;
            removeStudentById();
        }
        else if (option == 4) {
            cout << "=== CREATE COURSE ===" << endl;
            createSubject();
        }
        else if (option == 5) {
            cout << "=== FIND COURSE ===" << endl;
            findSubject();
        }
        else if (option == 6) {
            cout << "=== REMOVE COURSE ===" << endl;
            removeSubjectById();
        }
        else if (option == 7) {
            cout << "=== ENROLL STUDENT IN COURSE ===" << endl;
            enrollStudentInCourse();
        }
        else if (option == 8) {
            cout << "=== REMOVE STUDENT FROM COURSE ===" << endl;
            removeStudentFromCourse();
        }
        else if (option == 9) {
            cout << "=== REGISTER GRADE ===" << endl;
            // function to register grade
        }
        else if (option == 10) {
            cout << "=== GET ALL STUDENTS ===" << endl;
            displayStudents();
        }
        else if (option == 11) {
            cout << "=== GET COURSES FROM STUDENT ===" << endl;
            displaySubject();
        }
        else if (option == 12) {
            cout << "=== CALCULATE COURSE AVERAGE ===" << endl;
            // function to calculate course average
        }
        else if (option == 13) {
            cout << "=== CALCULATE OVERALL GPA ===" << endl;
            // function to calculate overall GPA
        }
        else if (option == 0) {
            cout << "Exiting the program." << endl;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
}

int main() {
    runMenu();
    return 0;
}