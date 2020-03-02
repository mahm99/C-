/********************************************************************
* File:        Class.cpp
* Author:      Mahmood Ul Mohasin Aziz
* Description:
* This file contains the program code for the Class class. This class
* controls everything related to the class vector. It adds students
* to the roster and waitlist based on the situation, and prints
* out the requested information about the section. This class finds
* the student the user is trying to look for, and also allows to
* sort the roster and waitlist. 
*********************************************************************/

#include "Class.h"

//Name: Class()
//Desc: Default Constructor
//Precondition: None
//Postcondition: Creates Class object
Class::Class() {
  m_name = "";
  m_section = 0;
}

//Name: Class
//Desc: Overloaded Constructor
//Precondition: Have name and number
//Postcondition: Creates Class object
Class::Class(string name, int section) {
  m_name = name;
  m_section = section;
}

//Name: ~Class
//Desc: Destructor
//Precondition: None
//Postcondition: Deallocates anything dynamically allocated in a Class                            
Class::~Class() {

  // condition only to make sure roster is not empty.
  if (m_roster.Size() > 0) {
    for(int i = 0; i < m_roster.Size(); i++) {
      delete m_roster[i];
    }
  }
  // condition to avoid looping if waitlist is empty.
  if (m_waitlist.Size() > 0) {
    for(int i = 0; i < m_waitlist.Size(); i++) {
      delete m_waitlist[i];
    }
  }
}

//Name: DisplayStudents
//Desc: Displays all students in Class. Displays students in the m_roster
//      and if there are students in the m_waitlist, displays them
//      Additionally shows count of students in m_roster and count in m_waitlist
//Precondition: Class has students enrolled
//Postcondition: Lists all students for a specific Class
void Class::DisplayStudents() {

  cout << "Total Enrolled: " << m_roster.Size() << endl;
  for(int i = 0; i < m_roster.Size(); i++) {
    cout << (i+1) << ". " << *m_roster[i];
  }
  
  if (m_waitlist.IsEmpty() == 0) {
    cout << "\nTotal Waitlisted: " << m_waitlist.Size() << endl;
    for(int i = 0; i < m_waitlist.Size(); i++) {
      cout << (i+1) << ". " << *m_waitlist[i];
    }
  }
}

//Name: AddStudent
//Desc: A student is added to a Class. If there is room in the m_roster, added there.
//      If the m_roster is full, attempts to add student to m_waitlist.
//      Else new section added, waitlist moved to new section and new student added.
//Precondition: Class exists
//Postcondition: Adds a student to a Class; returns true if added else false
bool Class::AddStudent(Student* newStudent) {

  if (!IsRosterFull()) {
    m_roster.Enqueue(newStudent);
    return true;
  }

  else if (!IsWaitlistFull()) {
    m_waitlist.Enqueue(newStudent);
    return true;
  }
  return false;
  
}

//Name: Sort
//Desc: Sorts the students alphabetically by last name for both roster and waitlist
//Precondition: None
//Postcondition: m_roster and m_waitlist are sorted                                               
void Class::SortStudents() {
  m_roster.Sort();
  m_waitlist.Sort();
}

//Name: GetName                                                                                 
//Desc: Returns name of Class                                                                     
//Precondition: None                                                                              
//Postcondition: Class name is returned                                                           
string Class::GetName() {
  return m_name;
}

//Name: SetName                                                                                   
//Desc: Allows Class name to be set                                                               
//Precondition: name is a valid string                                                            
//Postcondition: Class name is updated                                                            
void Class::SetName(string name) {
  m_name = name;
}

//Name: GetSection                                                                                
//Desc: Returns section of Class                                                                  
//Precondition: None                                                                              
//Postcondition: Class section is returned                                                        
int Class::GetSection() {
  return m_section;
}

//Name: SetSection                                                                                
//Desc: Allows Class section to be set                                                            
//Precondition: section is a valid integer                                                        
//Postcondition: Class section is updated                                                         
void Class::SetSection(int section) {
  m_section = section;
}

//Name: TransferWaitToRoster                                                                      
//Desc: When an m_roster is full and m_waitlist is full, copies all students in                   
//      m_waitlist to a destination Class                                                         
//Precondition: m_waitlist is full                                                                
//Postcondition: m_waitlist is empty and all students were transferred to new Class               
void Class::TransferWaitToRoster(Class& destination) {

  // moving waitlisted students into the newly created section.
  if (m_waitlist.IsFull() == 1) {
    
    for(int i = 0; i < m_waitlist.Size(); i++) {
      destination.AddStudent(m_waitlist[i]);
    }
    m_waitlist.ClearData();
  }
}

//Name: IsRosterFull()                                                                            
//Desc: Returns bool of if the m_roster is at capacity                                            
//Precondition: None                                                                              
//Postcondition: Returns bool                                                                     
bool Class::IsRosterFull() {

  // condition to check if the roster is full.
  if (m_roster.Size() == ROSTER_MAX) {
    return true;
  }
  return false;
}

//Name: IsWaitlistFull()                                                                          
//Desc: Returns bool of if the m_waitlist is at capacity                                          
//Precondition: None                                                                              
//Postcondition: Returns bool                                                                     
bool Class::IsWaitlistFull() {

  // condition to check if the waitlist is full.
  if (m_waitlist.Size() == WAIT_MAX) {
    return true;
  }
  return false;
}

//Name: SearchClass                                                                               
//Desc: Searches m_roster and m_waitlist for a string.                                            
//      If string exists in m_roster or m_waitlist, Class information printed                     
//Precondition: None                                                                              
//Postcondition: Returns bool                                                                     
bool Class::SearchClass(string item) {

  // Searching for the student in the roster.
  for(int i = 0; i < m_roster.Size(); i++) {
    if ((m_roster[i]->GetFName() == item) || (m_roster[i]->GetLName() == item)) {
	return true;
      }
  }
  // Condition to avoid looping if the waitlist is empty
  // for searching.
  if (m_waitlist.IsEmpty() == 0) {
    for(int i = 0; i < m_waitlist.Size(); i++) {
      if ((m_waitlist[i]->GetFName() == item) || (m_waitlist[i]->GetLName() == item)) {
        return true;
      }
    }
  }
  return false;
}

// Name: Overloaded <<                                                                            
// Description: Prints the details of a Class (Class name and section)                            
// Preconditions: all variables are set valid                                                     
// Postconditions: returns an ostream with output of the Class                                    
ostream& operator<<(ostream& out, Class& Classy) {

  // outputting the class information.
  out << "Course: " << Classy.GetName() << " Section: " << Classy.GetSection() << endl;
  return out;
}
