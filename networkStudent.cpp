//  Created by Ian De Bie on 10/2/19.
//  Copyright © 2019 Ian De Bie. All rights reserved.

#include "networkStudent.h"
#include <iostream>
#include <iomanip>
using namespace std;

NetworkStudent::NetworkStudent() : Student() {
    this->degreeType = NETWORK;
}

NetworkStudent::NetworkStudent(string studID, string first, string last, string email, int age, int days[], Degree degreeType)
        : Student(studID, first, last, email, age, days) {
    this->degreeType = NETWORK;
}

Degree NetworkStudent::getDegreeProgram() {
    return this->degreeType;
}

void NetworkStudent::print() {
    this->Student::print();
    cout << "Degree Program: " << degreePrograms[getDegreeProgram()] << "\t" << endl;
}

NetworkStudent::~NetworkStudent() {
    // calling super destructor in case it needs to destroy something
    Student::~Student();
}
