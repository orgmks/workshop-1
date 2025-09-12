#include <iostream>
#include <string>
#include "Student.h"
#include "LinkedList.h"

LinkedList<Student> studentList; // General list of students


using namespace std;

void createStudent() {
    int id; string name;
    cout << "Enter student ID: ";  cin >> id;  cin.ignore();
    cout << "Enter student name: "; getline(cin, name);
    Student s(id, name);
    studentList.insertAtEnd(s);
    cout << "Student created and added.\n";
}

void findStudentById() {
    int id;
    cout << "Enter student ID you are looking for: ";
    cin >> id;
    Student* st = studentList.searchById(id);
    if (st) st->display();
    else    cout << "Student not found.\n";
}

void displayAll() {
    cout << "All students:\n";
    studentList.displayAll();
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
            findStudentById();
        }
        else if (option == 3) {
            cout << "=== REMOVE STUDENT ===" << endl;
            // function to remove student
        }
        else if (option == 4) {
            cout << "=== CREATE COURSE ===" << endl;
            // function to create course
        }
        else if (option == 5) {
            cout << "=== FIND COURSE ===" << endl;
            // function to find course
        }
        else if (option == 6) {
            cout << "=== REMOVE COURSE ===" << endl;
            // function to remove course
        }
        else if (option == 7) {
            cout << "=== ENROLL STUDENT IN COURSE ===" << endl;
            // function to enroll student in course
        }
        else if (option == 8) {
            cout << "=== REMOVE STUDENT FROM COURSE ===" << endl;
            // function to remove student from course
        }
        else if (option == 9) {
            cout << "=== REGISTER GRADE ===" << endl;
            // function to register grade
        }
        else if (option == 10) {
            cout << "=== GET ALL STUDENTS ===" << endl;
            displayAll();
            break;
        }
        else if (option == 11) {
            cout << "=== GET COURSES FROM STUDENT ===" << endl;
            // function to get courses from student
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