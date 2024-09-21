//
//  student.hpp
//


#pragma once
#include <iostream>
#include <iomanip>
#include "degree.hpp"

using std::cout;
using std::endl;
using std::string;

/*Creating a class representing a Student. This class contains attributes and methods to manage student information*/
class Student {
    
    
public: //constant variable for array declaration for numCourseComplesion.
    const static int num_course_array = 3;
private:
    /*Declaring attributes for */
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    double numCourseCompletion[num_course_array];
    DegreeProgram degreeProgram;
    
public:
    //Declaring Constructors
    Student (); //Default constructor to initialize the student with default values.
    
    /*Below is a constructor with parameters to initliazed the student with given values.*/
    Student (string studentID, string firstName, string lastName, string emailAddress, int age,  double numCourseCompletion [], DegreeProgram degreeProgram);
    
    //Destructor to release resources assigned by the student.
    ~Student ();
    //Creating method getters for each variable
    string get_ID ();
    string get_firstname ();
    string get_lastname ();
    string get_emailaddress();
    int get_age ();
    double* get_num_course_completion(); /* gets the number of days to complete each course. using a pointer to the array of days*/
    DegreeProgram get_degreeprogram ();
    
    
    //Creating method setters for each variable
    void  set_ID (string studentID);
    void  set_firstname (string firstName) ;
    void  set_lastname (string lastName);
    void  set_emailaddress(string emailAddress);
    void  set_age (int age_years);
    void  set_num_course_completion(double numCourseCompletion []);
    void  set_degreeprogram (DegreeProgram degreeProgram);
    
    
    
    //creating print() function:
/* the print function returns the student's data   */
    void print()  ;
    
};

