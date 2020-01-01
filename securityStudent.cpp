//  Created by Ian De Bie on 10/2/19.
//  Copyright © 2019 Ian De Bie. All rights reserved.

#include "securityStudent.h"
#include <iostream>
#include <iomanip>
using namespace std;

SecurityStudent::SecurityStudent() : Student() {
    this->degreeType = SECURITY;
}

SecurityStudent::SecurityStudent(string studID, string first, string last, string email, int age, int days[], Degree degreeType)
        : Student(studID, first, last, email, age, days) {
    this->degreeType = SECURITY;
}

Degree SecurityStudent::getDegreeProgram() {
    return this->degreeType;
}

void SecurityStudent::print() {
    this->Student::print();
    cout << "Degree Program: " << degreePrograms[getDegreeProgram()] << "\t" << endl;
}

SecurityStudent::~SecurityStudent() {
    // calling super destructor in case it needs to destroy something
    Student::~Student();
}
