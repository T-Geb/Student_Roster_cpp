//
//  degree.hpp
// 
//
 

#pragma once
#include <stdio.h>
#include <string>
#include <array>

/*Creating an enumarated data type to contain values representing degree program. This will be used to manipulate degree programs to the student's table. */
enum DegreeProgram {
    SECURITY, NETWORK, SOFTWARE
};

/*Creating an array of strings that will represent the names of the degree programs corresponding with the values in the DegreeProgram enumatation*/
static const std::string DegreeProgramStrings [] = {"SECURITY", "NETWORK", "SOFTWARE"};




