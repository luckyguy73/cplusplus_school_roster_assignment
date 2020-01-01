//  Created by Ian De Bie on 10/2/19.
//  Copyright © 2019 Ian De Bie. All rights reserved.

#ifndef roster_h
#define roster_h

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "degree.h"
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
using namespace std;

const int numStudents = 5;
const string studentData[numStudents] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Ian,De Bie,idebie@wgu.edu,46,15,21,12,SOFTWARE"
};

class Roster {
public:
    // member variables
    int lastIndex;
    int capacity;
    Student** classRosterArray;
    // constructors
    Roster();
    Roster(int capacity);
    Student* getStudent(int index);
    void renderStudentData();
    void add(string studentID, string firstName, string lastName, string email, int age,
             int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeType);
    bool remove(string studentID);
    void printAll();
    void printInvalidEmails();
    bool isEmailValid(string email);
    void printAverageDaysInCourse(string studentID);
    void printByDegreeProgram(Degree degreeType);
    ~Roster();
};

#endif /* roster_h */
