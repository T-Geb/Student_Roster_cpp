//
//  roster.hpp
//

#pragma once
#include <stdio.h>
#include <string>
#include "student.hpp"

using std::string;

/*Creating a class representing a roster of students to manage the array of student objects */
class Roster {
    
private:
    
    static const int sizeOfArray {5}; //size of the array for storing student objects
    Student* classRosterArray [sizeOfArray]; // Array of pointers to Student objects
    int lastIndex; // index of the last student in the roster
    
public:
    
    Roster();    //default constructor

    /* creating methods to parse through student data from a string of array and add the student to the roster with specific requirements. Methods to add student data to an instance of the object Roster, to remove student data using studentID as a parameter and printall function to print out the parsed and added data. etc.. */
    void parse(const string& studentData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse1, double daysInCourse2, double daysInCourse3, DegreeProgram degreeProgram) ;
    
    void remove(string studentID) ;
    void printAll() const;
    void printAverageDaysInCourse(string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    Student* getStudent(int index) const; /*method to get student by index to be able to use it to loop through the classRosterArray in int main.*/
    int getLastIndex() const; // Method to get the last index
    
    ~Roster(); //Destructor to release memory allocated for each student in the roster.
    
};







