//  Created by Ian De Bie on 10/2/19.
//  Copyright © 2019 Ian De Bie. All rights reserved.

#include "roster.h"
#include <iomanip>
using namespace std;

Roster::Roster() : lastIndex(-1), capacity(0), classRosterArray(nullptr) {}

Roster::Roster(int capacity) : lastIndex(-1), capacity(capacity) {
    classRosterArray = new Student*[capacity];
}

Student* Roster::getStudent(int index) {
    return classRosterArray[index];
}

void Roster::renderStudentData() {
    for(int i = 0; i < numStudents; ++i) {
        string field;
        stringstream ss(studentData[i]);
        vector<string> studentFields;
        
        while (getline(ss, field, ','))
            studentFields.push_back(field);
        
        add(studentFields.at(0), studentFields.at(1), studentFields.at(2), studentFields.at(3),
            stoi(studentFields.at(4)), stoi(studentFields.at(5)), stoi(studentFields.at(6)),
            stoi(studentFields.at(7)), studentFields.at(8));
        
        ss.str("");
        ss.clear();
    }
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeType) {
    ++lastIndex;
    int days[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    if (degreeType == "SECURITY")
        classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, email, age, days, SECURITY);
    else if (degreeType == "NETWORK")
        classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, email, age, days, NETWORK);
    else
        classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, email, age, days, SOFTWARE);
}

bool Roster::remove(string studentID) {
    cout << "Removing ID: " << studentID << endl;
    
    for (int i = 0; i <= this->lastIndex; ++i) {
        auto s = this->classRosterArray[i];
        
        if (s->getStudentID() == studentID) {
            
            for (int j = i; j < this->lastIndex - 1; ++j)
                this->classRosterArray[j] = this->classRosterArray[j + 1];
            
            this->classRosterArray[lastIndex] = nullptr;
            --lastIndex;
            cout << "Student ID: " << studentID << " removed." << endl << endl;
            return true;
        }
    }
    cout << "Student ID: " << studentID << " not found." << endl << endl;
    return false;
}

void Roster::printAll() {
    cout << "Printing all student data:" << endl;
    
    // note that requirement E.3.c. provided print format omits email address
    for (int i = 0; i <= this->lastIndex; ++i)
        this->classRosterArray[i]->print();

    cout << endl;
}

void Roster::printInvalidEmails() {
    cout << "Invalid email addresses: " << endl;
    
    for (int i = 0; i <= this->lastIndex; ++i) {
        auto s = this->classRosterArray[i];

        if (!isEmailValid(s->getEmail()))
            cout << "ID: " << s->getStudentID() << "\t" << "Email: " << s->getEmail() << endl;
    }
    cout << endl;
}

bool Roster::isEmailValid(string email) {
    if(email.find("@") == string::npos) return false;
    if(email.find(".") == string::npos) return false;
    if(email.find(" ") != string::npos) return false;
    
    return true;
}

void Roster::printAverageDaysInCourse(string studentID) {
    int avg = 0;
    
    for (int i = 0; i <= this->lastIndex; ++i) {
        auto s = this->classRosterArray[i];
        
        if (s->getStudentID() == studentID) {
            avg = (s->getDays()[0] + s->getDays()[1] + s->getDays()[2]) / 3;
            break;
        }
    }
    cout << "ID: " << studentID << "\t" << "Average: " << avg << endl;
}

void Roster::printByDegreeProgram(Degree degreeType) {
    cout << "Students enrolled in " << degreePrograms[degreeType] << " Degree Program:" << endl;
    
    for (int i = 0; i <= this->lastIndex; ++i) {
        auto s = this->classRosterArray[i];
        
        if (s->getDegreeProgram() == degreeType) s->print();
    }
    cout << endl;
}

Roster::~Roster() {
    cout << "Destructor called..." << endl;
    delete [] classRosterArray;
}

int main() {
    // 1.  Print out to the screen, via your application, the course title,
    // the programming language used, your student ID, and your name.
    cout << "C867: Scripting and Programming - Applications" << endl;
    cout << "C++" << " ID# 001114841" << endl << "Ian De Bie" << endl << endl;
    
    // 2.  Create an instance of the Roster class called classRoster.
    Roster * classRoster = new Roster(numStudents);
    
    // 3.  Add each student to classRoster.
    classRoster->renderStudentData();
    
    // 4.  Convert the following pseudo code to complete the rest of the main() function:
    // classRoster.printAll();
    classRoster->printAll();
    
    // classRoster.printInvalidEmails();
    classRoster->printInvalidEmails();
    
    // loop through classRosterArray and for each element:
    // classRoster.printAverageDaysInCourse(/*current_object's student id*/);
    cout << "Average days in course:" << endl;
    for (int i = 0; i <= classRoster->lastIndex; ++i)
        classRoster->printAverageDaysInCourse(classRoster->getStudent(i)->getStudentID());
    cout << endl;
    
    // classRoster.printByDegreeProgram(SOFTWARE);
    classRoster->printByDegreeProgram(SECURITY);
    classRoster->printByDegreeProgram(NETWORK);
    classRoster->printByDegreeProgram(SOFTWARE);
    
    // classRoster.remove("A3");
    classRoster->remove("A3");
    
    // classRoster.remove("A3");
    // expected: the above line should print a message saying such a student with this ID was not found.
    classRoster->remove("A3");
    
    // 5.  Call the destructor to release the Roster memory.
    classRoster->~Roster();
    
    return 0;
}
