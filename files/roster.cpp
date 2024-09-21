//
//  roster.cpp
//
#include <iostream>
#include <string>
#include <sstream>
#include "roster.hpp"



using std::string;
using std::array;
using std::size_t;
using std::cout;
using std::endl;

//Constructor
/*Constructor to initialize the class roster array and to set the last index to -1*/
Roster::Roster() : lastIndex (-1) {
    for (int i=0; i<sizeOfArray;i++) {
        classRosterArray[i] = nullptr; /*initializing all pointer to nullptr*/
    }
} //-1 to indicate the array is initially empty.

//Deconstructor to free memory allocated for each student object
Roster::~Roster() {
    for(int i=0; i<= lastIndex; i++) {
        delete classRosterArray[i];
    }
}

/*method for parsing the student data and adding to roster array: parses student data from a string of array and add the student to the roster.*/
void Roster::parse(const string& studentData) {
    
    const int numberOfFields {9};
    string parsedData [numberOfFields];
    size_t start {0};
    size_t end {0};
    
    for (int i = 0; i < numberOfFields -1 ; i++)  {
        end = studentData.find(",", start);
        parsedData[i] = studentData.substr(start, end - start);
        start = end + 1;
    }
    
    parsedData[numberOfFields - 1] = studentData.substr(start); /*getting the last field
    assigning the fields to the parsed data by index and adding the parsed data*/
    string studentID = parsedData[0];
    string firstName = parsedData[1];
    string lastName = parsedData[2];
    string emailAddress = parsedData[3];
    int age = std::stoi(parsedData[4]);
    int daysInCourse1 = std::stoi(parsedData[5]);
    int daysInCourse2 = std::stoi(parsedData[6]);
    int daysInCourse3 = std::stoi(parsedData[7]);
    
    DegreeProgram degreeProgram = SOFTWARE; // Default initialization of degreeProgram
    if(parsedData[8] == "SECURITY") degreeProgram = SECURITY;
    if(parsedData[8] == "NETWORK") degreeProgram = NETWORK;
    if(parsedData[8] == "SOFTWARE") degreeProgram = SOFTWARE;
    
    add(studentID, firstName, lastName,emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3,degreeProgram);
    }

/*implementing method to add a student data using if condition. I am creating an array daysInCourse to hold the 3 course completion days.*/
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse1, double daysInCourse2, double daysInCourse3, DegreeProgram degreeProgram) {
    if (lastIndex < sizeOfArray-1) {
        double daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3};
        classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
    }
}

/*Using a nested loops to remove a a student using a StudentID by looping through the roster array and making sure that if the array is not equal to a null pointer and the array holds a student ID, then to delete the given student ID. The inner for loop shifts the remianing students to fill the gap left by the removed student.*/
void Roster::remove(string studentID)  {
    bool found = false;
    for (int i = 0; i<= lastIndex; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i] -> get_ID() == studentID) {
            found = true;
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            //shifting elements to the left to fill the gap
            for (int j = i; j < lastIndex; j++) {
                classRosterArray[j] = classRosterArray[j+1];
            }
            classRosterArray[lastIndex] = nullptr;
            lastIndex--;
            break;
        }
    } if (!found) {  /*Error Message to display if the studentID is not found.*/
        cout << "The Student ID you entered does not exist. Please enter a valid student ID" << endl;
    }
}

/*Implementing printAll() function using a for loop with an inner if condition to print out student data from the class roster array.*/
void Roster::printAll() const {
    for (int i=0; i <= lastIndex; i++)  {
        if (classRosterArray[i] != nullptr)
            classRosterArray[i] ->print();
        
    }
}

/*Implementation of the method to print average days per course for each student using a nested for loop with an inner if condition. */
void Roster::printAverageDaysInCourse(string studentID) const {
    bool found = false; // to check if StudentID is found
    for (int i = 0; i <= lastIndex; i++) {  //using for loop to loop through the array
        if (classRosterArray[i] != nullptr && classRosterArray[i] ->get_ID() == studentID) {
            found = true; /*To flag true when the student id is found so we don't get a print out of the if(!found) condition.*/
            cout << "Average Days in course is: " ;
            double AverageDaysInCourse = ((classRosterArray[i] -> get_num_course_completion() [0] +
                                           classRosterArray[i] -> get_num_course_completion() [1] +
                                           classRosterArray[i] -> get_num_course_completion() [2]) / 3);
            cout << AverageDaysInCourse << endl;
            
            break; /*To exit the loop after finding the student*/
        }
    }
    if(!found) { /*Error message to display if the student ID is not found*/
        cout <<"The Student ID is not found" << endl;
    }
}

/*Implementing method to print invalid email addresses. I am using a for loop to iterate through the array and an inner if condition to check if @ and . are not present and if a space is present, making the email address invalid.*/
void Roster::printInvalidEmails() const {
    for (int i = 0; i <= lastIndex; i++) {
        string email = classRosterArray[i] -> get_emailaddress();
        /*'npos' constant used with the find function to indicate the search was not successful.*/
        if((email.find('@') == string::npos) || (email.find('.') == string::npos) || (email.find(' ')!= string::npos)) {
            cout << "Invalid Email: " << email << endl;
        }
    }
}
/* Implementing the method to print by degree program from the class student array. I am using a for loop again with an inner if condition. */
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for(int i=0; i <= lastIndex; i++) { //using for to loop through each student
        if (classRosterArray[i] -> get_degreeprogram() == degreeProgram) {
            classRosterArray[i] -> print(); //Print the student details if the degree program matches.
        }
    }
      
      
}

/* Implementing the Student getter and last index getter as I will need these in the main cpp to print the average days per course using student ID.*/
Student* Roster::getStudent(int index) const {
    if(index >= 0 && index <= lastIndex) {
        return classRosterArray[index];
    }
    return nullptr;
}

int Roster::getLastIndex() const {
    return lastIndex;
}
    



