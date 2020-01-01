//  Created by Ian De Bie on 10/2/19.
//  Copyright © 2019 Ian De Bie. All rights reserved.

#include "softwareStudent.h"
#include <iostream>
#include <iomanip>
using namespace std;

SoftwareStudent::SoftwareStudent() : Student() {
    this->degreeType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studID, string first, string last, string email, int age, int days[], Degree degreeType)
        : Student(studID, first, last, email, age, days) {
    this->degreeType = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram() {
    return this->degreeType;
}

void SoftwareStudent::print() {
    this->Student::print();
    cout << "Degree Program: " << degreePrograms[getDegreeProgram()] << "\t" << endl;
}

SoftwareStudent::~SoftwareStudent() {
    // calling super destructor in case it needs to destroy something
    Student::~Student();
}
