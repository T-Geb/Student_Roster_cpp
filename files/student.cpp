//
//  student.cpp
//


#include "student.hpp"


//Implementing getters: using this-> to access member variables
string Student::get_ID() {
    return this->studentID;
}
string Student::get_firstname()  {
    return this->firstName;
}
string Student::get_lastname()  {
    return this->lastName;
}
string Student::get_emailaddress()  {
    return this->emailAddress;
}
int Student::get_age()  {
    return this->age;
}
double* Student::get_num_course_completion()   {
    return this->numCourseCompletion;
}
DegreeProgram Student::get_degreeprogram()  {
    return this->degreeProgram;
}

//Implementing Setters: using this -> to access member variables

void Student::set_ID(string studentID) {
    this->studentID = studentID;
}
void Student::set_firstname(string firstName) {
    this->firstName = firstName;
}
void Student::set_lastname(string lastName) {
    this->lastName = lastName;
}
void Student::set_emailaddress(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::set_age(int age_set) {
    this->age = age_set;
}
void Student::set_num_course_completion(double numCourseCompletion []) {
    for (int i=0 ; i < num_course_array; i++ )
        this->numCourseCompletion[i] = numCourseCompletion[i];
}

void Student::set_degreeprogram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

//Implementing Constructors:
Student::Student()
    : studentID(""),
      firstName(""),
      lastName(""),
      emailAddress(""),
      age(0),
      numCourseCompletion{0, 0, 0},
      degreeProgram (DegreeProgram::SECURITY) {
          
      }

Student::Student(string studentID, string firstName,string lastName, string emailAddress, int age,  double numCourseCompletion [], DegreeProgram degreeProgram)
   :studentID(studentID),
    firstName(firstName),
    lastName (lastName),
    emailAddress(emailAddress),
    age(age),
    degreeProgram(degreeProgram) {
    for (int i = 0; i < num_course_array; ++i) {
      this->numCourseCompletion[i] = numCourseCompletion[i];
            }
    }

//Implementing Destructor to release resources assigned by the student. 
Student::~Student() {
    
}

//Implementing print function to print student's data following the given format.

void Student::print()    {
    cout << get_ID() << "\t" ;
    cout << "First Name: " << get_firstname() << "\t" ;
    cout << "Last Name: " << get_lastname() << "\t" ;
    cout << "Email Address: " << get_emailaddress() << "\t";
    cout << "Age: " << get_age() << "\t" ;
    cout << "Course Completions: {";
    
    double* completions = get_num_course_completion();
    /*Using a for loop to iterate through the array for course completion to retrieve each each index*/
    for (int i=0; i< num_course_array; i++) {
        cout << completions[i];
        if(i<2) {
            cout << ", ";  /*to add a comma for the first two indexes since we have 3 elements*/
        }
    } cout << "}";
    cout << "\t";
    cout << "Degree Program: " << DegreeProgramStrings[this->get_degreeprogram()]  << endl;
}

    
    
      
    

