//
//  main.cpp
//
//

#include <iostream>
#include <string>
#include "degree.hpp"
#include "roster.hpp"


using namespace std;


int main () {
    
    cout << endl;
    cout << "=========Scripting and Programming - Applications - C867============= " << endl;
    cout << "Programming Language Used : C++" << endl;
    cout <<"WGU Student ID: " << endl;
    cout << "Student Name : " << endl;
    
    cout << "===================================================================== " << endl;
    cout << endl;
    
    const int numberOfStudents {5};
    const string studentData[numberOfStudents]

    // Here, I added my personal information at the end.
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Student,Name,sname@wgu.edu,26,50,26,40,SOFTWARE"};
    
    
    Roster classRoster;
    
    /*Adding each student from the studentData array to the classRoster */
    for (int i = 0; i< numberOfStudents; i++) {
        classRoster.parse(studentData[i]);
    }
    
    cout << "=======================Printing All Students ====================== " << endl;
    classRoster.printAll();
    cout << endl;
    
    cout << "======================= Printing Invalid Emails =================== " << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    cout << "================ Printing Average Days Per Course ================== " << endl;

    /*using for loop to loop through the classRosterArray and printing the average days in couse per student ID */
    for (int i = 0; i <= classRoster.getLastIndex() ; i++) {
        Student* student = classRoster.getStudent(i);
        if(student != nullptr) {
            classRoster.printAverageDaysInCourse(student -> get_ID());
        }
    }
    cout << endl;
    
    cout << "========== Printing Student Data by Degree Program : Software ====== " << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    cout << "========== Removing Student data for Student with ID A3============= " << endl;
    classRoster.remove("A3");
    cout << endl;
    
    cout << "==Showing the Student Data Table After Removing Student with ID A3== " << endl;

    classRoster.printAll();
    cout << endl;
    
    cout << "================Trying To Remove A Student with ID A3===============" << endl;
    classRoster.remove("A3");
    cout << endl;
    
    /* No need to manually call the destructor since it will be called automatically*/
    
    
        return 0;
}
