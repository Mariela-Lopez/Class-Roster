#ifndef student_h
#define student_h
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;



class Student  {
    private:
    
    string studentId;
    string firstName;
    string lastName;
    string email;
    int age;
    int* daysInCourseList;
    DegreeProgram degreeProgram;
    
    public:
    
    Student(string studentId1,string firstName1, string lastName1,string email1, int age1,int daysInCourseList[3], string degreeProgram1);
    
    ~Student();
       
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysInCourseList(int daysInCourseList[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    string getStudentId() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    int *getDaysInCourseList() const;
    DegreeProgram getDegreeProgram() const;
    
    void print() const;
    
};

#endif /* student_h */
