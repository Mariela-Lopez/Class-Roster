
#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
using namespace std;


Roster::Roster(const string studentData[]) {
    this->classRosterArray = new Student*[10];
    int i = 0;
    while (i < 5) {
        parseAndAdd(studentData[i]);
        i++;
    }
}

Roster::~Roster() {
    delete[] classRosterArray;
}
    
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeprogram){
    int daysInCourseList[3] = { daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[studentCount] = new Student( studentID,firstName, lastName, emailAddress, age, daysInCourseList, degreeprogram );
    studentCount++;
    
}

void Roster::parseAndAdd(string studentData) {
    size_t rhs = studentData.find(",");
    string studentId = studentData.substr(0,rhs);
    
    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs-lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs-lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string email = studentData.substr(lhs, rhs-lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string ageString = studentData.substr(lhs, rhs-lhs);
    int age = stoi(ageString);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string daysInCourse1String = studentData.substr(lhs, rhs-lhs);
    int daysInCourse1 = stoi(daysInCourse1String);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string daysInCourse2String = studentData.substr(lhs, rhs-lhs);
    int daysInCourse2 = stoi(daysInCourse2String);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string daysInCourse3String = studentData.substr(lhs, rhs-lhs);
    int daysInCourse3 = stoi(daysInCourse3String);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string degreeProgram = studentData.substr(lhs, rhs-lhs);
    
    add( studentId, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::printAverageDaysInCourse(string studentID) {
   
    for (int i = 0; i < studentCount; i++) {
        if (classRosterArray[i]->getStudentId().compare(studentID) == 0) {
            int total = classRosterArray[i]->getDaysInCourseList()[0] + classRosterArray[i]->getDaysInCourseList()[1] + classRosterArray[i]->getDaysInCourseList()[2];
            cout << classRosterArray[i]->getStudentId() << " Average days in Course: " << total / 3 << endl;
        }
    }
}

void Roster::printAll() {
    int i = 0;
    while(i < studentCount) {
        classRosterArray[i]->print();
        i++;
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < studentCount; i++) {
        string email = classRosterArray[i]->getEmail();
        bool isInvalid = false;
        if (email.find('@') == string::npos) {
            isInvalid = true;
        }
        if (email.find('.') == string::npos) {
            isInvalid = true;
        }
        if (email.find(' ') != string::npos) {
            isInvalid = true;
        }
        if (isInvalid) {
            cout << email << endl;
        }
    }
}

void Roster::remove(string studentID) {
    Student* *newArray = new Student*[10];
    int newArrayCount = 0;
    for (int i = 0; i < studentCount; i++) {
        if (classRosterArray[i]->getStudentId() != studentID) {
            newArray[newArrayCount] = classRosterArray[i];
            newArrayCount++;
        }
    }
    classRosterArray = newArray;
    studentCount = newArrayCount;
    if (newArrayCount) {
        cout << "The student: " << studentID << " was not found" << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < studentCount; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
    
}

