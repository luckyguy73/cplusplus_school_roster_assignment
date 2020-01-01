//  Created by Ian De Bie on 10/2/19.
//  Copyright © 2019 Ian De Bie. All rights reserved.

#ifndef student_h
#define student_h
#include "degree.h"
#include <string>
using namespace std;

class Student {
public:
    // the size of the array of the number of days to complete each course
    const static int numberOfDays = 3;
    // constructors
    Student();
    Student(string studID, string first, string last, string email, int age, int days[]);
    // accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    // each subclass should override the getDegreeProgram() function
    // degree type should be populated in subclasses only
    virtual Degree getDegreeProgram() = 0;
    // mutators
    void setStudentID(string studID);
    void setFirstName(string first);
    void setLastName(string last);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(Degree degreeType);
    // print specific student data
    virtual void print() = 0;
    // destructor
    ~Student();
    
protected:
    // member variables
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int days[numberOfDays];
    // degree type should be populated in subclasses only
    Degree degreeType;
};

#endif /* student_h */
