/********************************************************************
* File:        Student.cpp
* Author:      Mahmood Ul Mohasin Aziz
* Description: 
* This file contains the program code for the Student class. This
* class controls everything related to the Student objects. It 
* manages the data about a student, and prints out the information
* when requested. It also allows to compare the name strings of
* a student object for sorting purposes.
*********************************************************************/

#include "Student.h"

// Name: Student                                                                                  
// Description: Default Constructor
// Preconditions: None
// Postconditions: Creates new student object
Student::Student() {
  m_fName = "";
  m_lName = "";
  m_id = 0;
}

// Name: Student (fName, lName, id)
// Description: Overloaded Constructor
// Preconditions: Data being passed is valid
// Postconditions: Creates new student object
Student::Student(string fName, string lName, int id) {
  m_fName = fName;
  m_lName = lName;
  m_id = id;
}

// Name: Getters and Setters
// Description: Either returns data or sets data in class
// Preconditions: Setter data is valid
// Postconditions: Either returns data or sets data
string Student::GetFName() {
  return m_fName;
}
string Student::GetLName() {
  return m_lName;
}

int Student::GetID() {
  return m_id;
}

void Student::SetFName(string fName) {
  m_fName = fName;
}

void Student::SetLName(string lName) {
  m_lName = lName;
}

void Student::SetID(int id) {
  m_id = id;
}

// Name: Overloaded <<
// Description: Prints the details of a student
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of student
ostream& operator<<(ostream& out, Student& Student) {

  // outputting the details.
  out << Student.GetFName() << ", " << Student.GetLName()
      << ", " << Student.GetID() << "." << endl;
  return out;
}

// Name: Overloaded <
// Description: Overloaded comparison operator (used for sorting)
// Preconditions: Two students being compared
// Postconditions: Returns m_lName first and then m_fName if m_lName same
bool operator< (const Student &s1, const Student &s2) {

  // comparing ASCII values of the name strings.
  if (s1.m_lName > s2.m_lName) {
    return true;
  }
  else if (s1.m_lName == s2.m_lName) {  
    if (s1.m_fName > s2.m_fName) {
      return true;
    }
  } 
  return false;
  
}
