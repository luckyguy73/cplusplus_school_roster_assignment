//  Created by Ian De Bie on 10/2/19.
//  Copyright © 2019 Ian De Bie. All rights reserved.

#ifndef softwareStudent_h
#define softwareStudent_h

#include <string>
#include "student.h"
using namespace std;

class SoftwareStudent : public Student {
private:
    // member variables
    Degree degreeType;
public:
    // constructors
    SoftwareStudent();
    SoftwareStudent(string studID, string first, string last, string email, int age, int days[], Degree degreeType);
    // accessors
    Degree getDegreeProgram();
    // print specific student data
    void print();
    // destructors
    ~SoftwareStudent();
};

#endif /* softwareStudent_h */
