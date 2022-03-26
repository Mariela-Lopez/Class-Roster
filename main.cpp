#include <iostream>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;



int main() {
    
    const string studentData[5] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Mariela,Mendoza,mmen301@wgu.edu,24, 40,40,45,SOFTWARE"
    };
    
    cout <<"Course Title: Scripting and Programming Applications" << endl;
    cout <<"Programming Language: C++" << endl;
    cout << "Student ID: 006245034" << endl;
    cout <<"Name: Mariela Mendoza" << endl;
    cout << endl;

   Roster* classRoster = new Roster(studentData);
   
    cout << "Displaying all students: " << endl;
    classRoster->printAll();
    cout << endl;
    
    cout << "Invalid Emails:" << endl;
    classRoster->printInvalidEmails();
    cout << endl;
    
    classRoster->printAverageDaysInCourse("A1");
    classRoster->printAverageDaysInCourse("A2");
    classRoster->printAverageDaysInCourse("A3");
    classRoster->printAverageDaysInCourse("A4");
    classRoster->printAverageDaysInCourse("A5");
    cout << endl;
    
    cout << "Showing students in Degree Program: SOFTWARE" << endl;
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    
    cout << "Removing A3 student:" << endl;
    classRoster->remove("A3");

    classRoster->printAll();
    cout << endl;

    cout <<"verifying A3 is removed:" << endl;
    classRoster->remove("A3");
    cout << endl;
    
   // classRoster->add("343", "mariela", "mendoza", "m.m.ela01@gmail.com", 30, 23, 12, 23, "software");
    
    return 0;
      
}
