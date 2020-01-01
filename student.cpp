//  Created by Ian De Bie on 10/2/19.
//  Copyright © 2019 Ian De Bie. All rights reserved.

#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
using namespace std;

Student::Student()
: studentID(""), firstName(""), lastName(""), email(""), age(0) {
    for (int i = 0; i < numberOfDays; ++i)
        this->days[i] = 0;
}

Student::Student(string studID, string first, string last, string email, int age, int days[])
: studentID(studID), firstName(first), lastName(last), email(email), age(age) {
    for (int i = 0; i < numberOfDays; ++i)
        this->days[i] = days[i];
}

string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmail() {
    return email;
}

int Student::getAge() {
    return age;
}

int* Student::getDays() {
    return days;
}

void Student::setStudentID(string studID) {
    this->studentID = studID;
}

void Student::setFirstName(string first) {
    this->firstName = first;
}

void Student::setLastName(string last) {
    this->lastName = last;
}

void Student::setEmail(string email) {
    this->email = email;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDays(int days[]) {
    for (int i = 0; i < numberOfDays; ++i)
        this->days[i] = days[i];
}

void Student::setDegreeProgram(Degree degreeType) {
    this->degreeType = degreeType;
}

// the print method displays all fields EXCEPT the degree program which is printed by subclass
void Student::print() {
    cout << "ID: " << getStudentID() << "\t";
    cout << "First Name: " << setw(5) << left << getFirstName() << "\t";
    cout << "Last Name: " << getLastName() << "\t";
    cout << "Age: " << getAge() << "\t";
    cout << "daysInCourse: {" << getDays()[0];
    cout << ", " << getDays()[1] << ", " << getDays()[2] << "}\t";
}

Student::~Student() {
    // Student object does not declare anything dynamically using keyword new
}
