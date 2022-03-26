#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;



Student::Student(string studentId1,string firstName1, string lastName1,string email1, int age1,int daysInCourseList1[], string degreeProgram1) {
   
    studentId = studentId1;
    firstName = firstName1;
    lastName = lastName1;
    email = email1;
    age = age1;
    daysInCourseList = new int[3];
    daysInCourseList[0] = daysInCourseList1[0];
    daysInCourseList[1] = daysInCourseList1[1];
    daysInCourseList[2] = daysInCourseList1[2];
    if(degreeProgram1 == "NETWORK"){
        degreeProgram = DegreeProgram::NETWORK;
    }
    if(degreeProgram1 == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    if(degreeProgram1 == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    }

}

Student::~Student() {
    delete[] daysInCourseList;
}

void Student::setStudentId (string studentId) {
    this->studentId = studentId;
}
void Student::setFirstName (string firstName) {
    this->firstName = firstName;
}

void Student::setLastName (string lastName) {
    this->lastName = lastName;
}

void Student::setEmail (string email) {
    this->email = email;
}

void Student::setAge (int age) {
    this->age = age;
}

void Student::setDaysInCourseList(int daysInCourseList[]) {
    this->daysInCourseList[0] = daysInCourseList[0];
}

void Student::setDegreeProgram (DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

string Student::getStudentId() const{
    return studentId;
}

string Student::getFirstName() const{
    return firstName;
}

string Student::getLastName() const{
    return lastName;
}

string Student::getEmail() const{
    return email;
}

int Student::getAge() const{
    return age;
}

int *Student::getDaysInCourseList() const{
    return daysInCourseList;
}

DegreeProgram Student::getDegreeProgram() const{
    return degreeProgram;
}

void Student::print() const{
    
    cout << getStudentId() << "   ";
    cout << getFirstName() << "   ";
    cout << getLastName() << "   ";
    cout << getEmail() << "   ";
    cout << getAge() << "   ";
    cout << "{"<< daysInCourseList[0] << ", "  << daysInCourseList[1]<< ", " << daysInCourseList[2] << "}   ";
    if (getDegreeProgram() == DegreeProgram::NETWORK){
        cout << "NETWORK" << endl;
    }
    if(getDegreeProgram() == DegreeProgram::SECURITY) {
        cout << "SECURITY" << endl;
    }
    if(getDegreeProgram() == DegreeProgram::SOFTWARE) {
        cout << "SOFTWARE" << endl;
    }
    
}
