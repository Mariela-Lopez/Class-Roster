
#ifndef roster_h
#define roster_h
#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

class Roster  {
    private:
    
    Student* *classRosterArray;
    int studentCount = 0;

    public:
    
    Roster(const string studentData[]);
    ~Roster();
    
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeprogram);
    
    void remove(string studentID);
    
    void printAll();
    
    void printAverageDaysInCourse(string studentID);
    
    void printInvalidEmails();
    
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    void parseAndAdd(string studentData);
    
};

#endif /* roster_h */
