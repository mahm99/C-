/********************************************************************
* File:        Scheduler.cpp                                                    
* Author:      Mahmood Ul Mohasin Aziz                                                                                                                               
* Description:
* This file contains the program code for the Scheduler class. This
* class controls the whole program, allowing user to make multiple 
* choices from the menu options. It loads the file, creates new 
* classes and adds students to the class roster and waitlist.
* A user can choose to display the newly created classes, 
* display students in each class, search for students, sort 
* students by their last names.
*********************************************************************/

#include "Scheduler.h"

//Name: Scheduler
//Desc: Default Constructor
//Precondition: None
//Postcondition: Creates Scheduler object                                                         
Scheduler::Scheduler() {
}

//Name: Scheduler
//Desc: Overloaded Constructor
//Precondition: Valid fileName
//Postcondition: Creates Scheduler object
Scheduler::Scheduler(string fileName) {
  m_fileName = fileName;
}

//Name: ~Scheduler
//Desc: Destructor
//Precondition: None
//Postcondition: Deallocates everything dynamically allocated in Scheduler                        
Scheduler::~Scheduler() {
  // deleting class pointers.
  for(unsigned int i = 0; i < m_classes.size(); i++) {
    delete m_classes.at(i);
  }
}

//Name: LoadFile
//Desc: Loads a roster file
//Precondition: Valid roster file
//Postcondition: Populates roster
void Scheduler::LoadFile() {

  Student* newStudent;

  string fName, lName, cName, sId;
  int studentID = 0;
  bool myBool = false;
  
  ifstream myFile;
  myFile.open(m_fileName);

  // loading file using multiple getline.
  while ((getline(myFile,fName,','))
	 && (getline(myFile,lName,','))
	 && (getline(myFile,sId,','))
	 && (getline(myFile,cName,'\n'))) {
    studentID = stoi(sId);
    newStudent = new Student(fName, lName, studentID); // creating new student objects.
    AddStudent(newStudent, cName); // adding to the class.
    myBool = true;
  }

  // if incorrect file loaded letting the user know.
  if (!myBool) {
    cout << "Incorrect File loaded. Please restart the program." << endl;
  }
  myFile.close();
}

//Name: MainMenu
//Desc: Displays the main menu of the program
//      Has options for 1. Display All Courses, 2. Display Specific Course
//      3. Search for Specific Student, 4. Sort Roster, and 5. Quit
//Precondition: Has roster loaded
//Postcondition: Keeps running until user chooses 5 (quit)                                        
void Scheduler::MainMenu() {

  int choice = 0;
  const int QUIT = 5;

  // to stop looping.
  while (choice != QUIT) {

    // getting user input.
    do {
      
      cout << "1. Display All Courses\n"
	   << "2. Display Specific Course\n"
	   << "3. Search for Specific Student\n"
	   << "4. Sort Roster\n"
	   << "5. Quit" << endl;
      cin >> choice;
    } while ((choice < 1) || (choice > QUIT));

    // switch to initiate the user choice.
    switch(choice)
      {
      case 1:
	cout << endl; 
	DisplayCourses();
	cout << endl;
	break;
      case 2:
	cout << endl;
	DisplaySpecific();
	cout << endl;
	break;
      case 3:
	cout << endl;
	SearchStudent();
	cout << endl;
	break;
      case 4:
	cout << endl;
	SortRoster();
	cout << endl;
	break;
      case 5:
	cout << "Clearing files..\nExiting Databases..." << endl;
	break;
      }
  }
}

//Name: DisplayCourses()
//Desc: Displays each course in the m_classes (Just name and section)
//Precondition: Classes loaded into m_classes
//Postcondition: Displays Class info
void Scheduler::DisplayCourses() {

  // displaying the classes in the vector.
  if (m_classes.size() > 0) {
    for(unsigned int i = 0; i < m_classes.size(); i++) {
      cout << (i+1) << ". "
	   << *m_classes[i];
    }
  } else {
    cout << "Empty File! Please quit and reload the file." << endl;
  }
}

//Name: DisplaySpecific
//Desc: Prompts user for a specific course (lists each class by name/section)
//      Displays each student enrolled in course
//Precondition: Classes loaded into m_classes and rosters populated
//Postcondition: Displays student info by class                                                   
void Scheduler::DisplaySpecific() {

  int choice = 0;

  // to make sure classes are loaded.
  if (m_classes.size() > 0) {
    // getting user choice for a specific section.
    do {
      cout << "Which course would you like to display?\n" << endl;
      DisplayCourses();
      cin >> choice;
    } while ((choice < 1) || (choice > int(m_classes.size())));
    
  // displaying students in the user selected class.
    cout << "\tDISPLAYING STUDENTS\n     "
	 << *m_classes.at(choice - 1) << endl;
    m_classes.at(choice - 1)->DisplayStudents();

  } else { // else telling user file loaded is empty.
    cout << "Empty File! Please quit and reload the file." << endl;
  }
}

//Name: SearchStudent                                                                             
//Desc: Prompts user for a specific string to search for (student name)                           
//      Returns each course that name appears                                                     
//Precondition: Classes loaded into m_classes and rosters populated                               
//Postcondition: Displays classes that student is in                                              
void Scheduler::SearchStudent() {

  string name;
  bool myBool;
  bool forMsg = false;

  if (m_classes.size() > 0) {
    // asking for the user input.
    cout << "What name do you want to search for?" << endl;
    cin >> name;
    
    // loop to get through every class in the vector.
    for(unsigned int i = 0; i < m_classes.size(); i++) {
      myBool = m_classes.at(i)->SearchClass(name);
      
      // condition to print the class details if input matches the data.
      if (myBool) {
	if (!forMsg) {
	  cout << "Items with " << name << " in them:" << endl;
	  forMsg = true;
	}
	cout << *m_classes.at(i);
      }
    }
    // condition to let user know if nothing matches the input.
    if (!forMsg) {
      cout << "No items found! Please try again." << endl; 
    }
  } else {
    cout << "Empty File! Please quit and reload the file." << endl;
  }
}

//Name: SortRoster                                                                                
//Desc: For each Class, each m_roster and m_waitlist is sorted by last name                       
//Precondition: Classes loaded into m_classes and rosters populated                               
//Postcondition: Does not display anything but rosters are sorted                                 
void Scheduler::SortRoster() {

  if (m_classes.size() > 0) {
    // to loop through every class in the veector for sorting.
    for(unsigned int i = 0; i < m_classes.size(); i++) {
      m_classes.at(i)->SortStudents();
    }
    cout << "Class rosters have been sorted for you!" << endl;
  } else {
    cout << "Empty File! Please quit and reload the file." << endl;
  }
}

//Name: Start                                                                                     
//Desc: Welcomes users, loadsfile and calls mainmenu                                              
//Precondition: None                                                                              
//Postcondition: m_classes is populated                                                           
void Scheduler::Start() {

  // printing the welcome msg and running the program.
  cout << "Welcome to the UMBC Scheduler" << endl;
  LoadFile();
  MainMenu();
}

//Name: FindClass                                                                                 
//Desc: Helper function that searches for a class name in m_classes and                           
//      returns the index of where the Class exists to add the student                            
//      HINT: May want to implement to go backwards through m_classes                             
//Precondition: None                                                                              
//Postcondition: Returns the index of the "current" section of a class                            
int Scheduler::FindClass(string className) {

  int index = 0;

  // looping through the vector to find the last section that was added.
  for (unsigned int i = 0; i < m_classes.size(); i++) {
    if (m_classes.at(i)->GetName() ==  className) {
      index = i;
    }    
  }
  return index;
}

//Name: AddStudent                                                                                
//Desc: Helper function from LoadFile that decides what to do with a new student                  
//      Scenario 1 - No classes in m_classes - Creates new class and adds student                 
//      Scenario 2 - Add Student to existing class where m_roster and m_waitlist                  
//      are not full                                                                              
//      Scenario 3 - Add Student when existing class is full ->create new class and               
//      move m_waitlist to new section                                                            
//Precondition: None                                                                              
//Postcondition: Student added to a class                                                         
void Scheduler::AddStudent(Student* newStudent, string cName) {

  Class* newClass;
  bool myBool;
  
  int section = 1;
  
  // creating first object if the vector is empty.
  if (int(m_classes.size()) == 0) {
    newClass = new Class(cName, section);
    newClass->AddStudent(newStudent);
    m_classes.push_back(newClass);
  }
  // condition to check if program is exceeding max classes.
  else if (int(m_classes.size()) <= MAX_CLASSES) {
    
    int index = FindClass(cName);
    
    // adding the students if the class is same.
    if (cName == m_classes.at(index)->GetName()) {    
      myBool = m_classes.at(index)->AddStudent(newStudent);
      
      // if class is full new section created and the waitlist is moved.
      if (!myBool) {
	int newSect = m_classes.at(index)->GetSection() + section;
	newClass = new Class(cName, newSect);
	m_classes.at(index)->TransferWaitToRoster(*newClass);
	newClass->AddStudent(newStudent);
	m_classes.push_back(newClass);
      }
    }
    // if the class does not exist in the vector.
    else if (cName != m_classes.at(index)->GetName()) {
      newClass = new Class(cName, section);
      newClass->AddStudent(newStudent);
      m_classes.push_back(newClass);
    }
  } else {
    cout << "You have added the maximum number of classes" << endl;
  }
  
}
