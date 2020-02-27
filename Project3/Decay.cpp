/********************************************************************
* File:        Decay.cpp
* Author:      Mahmood Ul Mohasin Aziz
*                                                                                                 
* Description:
* This file contains program code for the Decay class. Decay class runs 
* the whole program by allowing user to simulate the lists from the 
* loaded file, or to randomly create a list to simulate. After every 
* single simulation the loaded lists are cleared, but the program runs 
* until user chooses to quit. Also, while running this class makes call
* to all other classes simultaneously to solve and clear the lists.
*********************************************************************/
#include "Decay.h"

// CONSTANTS
const int MIN = 1;
const int MAX = 10000;
const char ONE = '1';
const char ZERO = '0';
const char SEMI_CLN = ';';
const bool TRUE = true;
const bool FALSE = false;

// Welcome msg.
const string WEL_MSG = "\vWelcome to Decay, where you code a frustrating system\
                         \ninstead of doing your physics homework.\v";
  
// Constructor                                                                                   
// Preconditions: None                                                                           
// Postconditions: None
Decay::Decay() {
  m_file = ""; 
}

// Destructor - Deletes all lists in m_list                                                      
// Preconditions: m_list is populated                                                            
// Postconditions: All lists are deleted and there are no memory leaks                           
Decay::~Decay() {
  EmptyLists(); // calling EmptyLists() to clear the vector.
}

// EmptyLists() - Empties all lists in m_list                                                    
// Preconditions: m_list is populated                                                            
// Postconditions: All lists are deleated and there are no memory leaks                          
void Decay::EmptyLists() {

  // To check if the vector is not empty.
  if (int(m_list.size()) > 0) {
    for (int i = 0; i < int(m_list.size()); i++) {  
      delete m_list.at(i); //clearing left over lists.
    }
    m_list.clear(); //clearing the vector.
  }
}

// LoadFile - Requests a file and loads all linked lists in a file (separated by ;)              
// Preconditions: Valid input file exists (preferably with three lines of data)                  
// Postconditions: m_list is initialized                                                         
void Decay::LoadFile() {

  // decalring identifiers;
  string currLine = "";
  DecayList* myList;
  Node* myNode;

  // loading the file.
  if (m_file == "")  {
    cout << "What is the name of the file? (.txt)" << endl;
    cin >> m_file;
        
    ifstream myFile;
    myFile.open(m_file);

    // getting each line using a delimiter.
    while (getline(myFile, currLine, '\n')) {
      myList = new DecayList(); // creating new list.
      
      for (int i = 0; i < int(currLine.size()); i++) {
	if (currLine[i] == SEMI_CLN) {
	  m_list.push_back(myList); // pushing back.
	}
	else if (currLine[i] == ONE) {                                                 
          myNode = new Node(TRUE); 
          myList->InsertEnd(myNode); // creating and inserting new nodes.  
	}
	else if (currLine[i] == ZERO) {                                                         
          myNode = new Node(FALSE);
          myList->InsertEnd(myNode);  
	}
      }
    }
    myFile.close();
  } else {
    cout << "You've already loaded a file." << endl; // if the file was already loaded.
  }
}

// ChooseList - After a file is loaded, allows user to choose a list to simulate                 
// Preconditions: User has chosen to start simulation                                            
// Postconditions: Simulation is started on list chosen by user                                  
void Decay::ChooseList() {

  // initializing variable.
  int userChoice = 0;
  
  // if the user did not load a file first.
  if (m_file == "")  {
    cout << "Load a file first!" << endl;
  } else if (int(m_list.size()) == 0) { // if the user loads in a empty file.
    m_file = "";
    cout << "Your file is empty. Please load a file again." << endl;
  }

  // starts the simulation.
  else {
    cout << "Which Decay scenario do you want to experience?" << endl;

    // printing out the available loaded lists.
    for (int i = 0; i < int(m_list.size()); i++) {
      cout << (i+1) << ".List " << (i+1) << "("
	   << m_list.at(i)->GetSize() << " nodes)" << endl;
    }
    cin >> userChoice; // getting input.

    // validating input.
    while ((userChoice < 1) || (userChoice > int(m_list.size()))) {
      cout << "Please select a valid list." << endl;
      cin >> userChoice;
    }
    // setting the right index.
    userChoice = userChoice - 1;
    RunSimulation(userChoice); // running the simulation.
  }
  
}

// CreateRandomList - Creates list of a specific size (1-10000) times 3 nodes each               
// Preconditions: m_list is empty                                                                
// Postconditions: m_list.at(0) has a list loaded into it                                        
void Decay::CreateRandomList() {

  EmptyLists(); // if file was loaded already and then user decides to randomly create list.
  
  // initializing variables.
  int numLen = 0;
  int counter = 0;
  int randNum = 0;

  // creating new list and declaring a node.
  Node* myNode;
  DecayList* myList = new DecayList();

  do {
    cout << "How large a list would you like?" << endl;
    cin >> numLen;
  } while ((numLen < MIN) || (numLen > MAX)); // input validation.

  numLen = (numLen * NUM_CONSECUTIVE);

  // creating list.
  while (counter < numLen) {
    
    randNum = rand() % 2;
    myNode = new Node(randNum);
    myList->InsertEnd(myNode);
    counter++;
  }
  m_list.push_back(myList);

  // running simulation.
  RunSimulation(0);
}

// RunSimulation - Simulate one of the loaded lists                                              
// Preconditions: A DecayList is available                                                       
// Postconditions: Simulation is run                                                             
void Decay::RunSimulation(int index) {

  // initializing variables.
  int numNode = 0;
  int removedVal = 0;
  
  cout << "The sequence has been initialized." << endl;

  // check if the list was cleared.
  while (!(m_list.at(index)->CheckEmpty())) {

    // if prints successfully, asking for the node to flip.
    if (m_list.at(index)->PrintDecayList()) {
      cout << "Which node to change?" << endl;
      
      for (int i = 0; i < int(m_list.at(index)->GetSize()); i++) {
	cout << (i+1) << "    ";
      }
      cout << endl;
      
      cin >> numNode; // getting and setting input to the right value.
      numNode = numNode - 1;

      // flipping the node values.
      m_list.at(index)->InvertValue(numNode);
      removedVal = m_list.at(index)->TraverseList(TRUE);
      
      if (removedVal > 0) { // to print removed msg.
	cout << removedVal << " nodes removed." << endl;
      }
    }
  }
  // clears after simulations ends.
  EmptyLists();
  cout << "All nodes from that list have been removed!" << endl;
  cout << "All lists have been cleared." << endl;
  m_file = "";
}

// Start - Starts sim. Can load file, choose list, or create random list                         
// Preconditions: A DecayList is available                                                       
// Postconditions: Empties all lists after one is simulated.                                     
void Decay::Start() {
  
  int userChoice = 0;
  
  while (userChoice != 4) {

    // getting input.
    do {
      cout << WEL_MSG << endl << "1. Load File"
	   << "\n2. Simulate Loaded File"
	   << "\n3. Simulate Random List"
	   << "\n4. Quit" << endl;
      cin >> userChoice;
    } while ((userChoice < 1) || (userChoice > 4));

    // switch cases.
    switch (userChoice) {
      
    case 1:
      LoadFile();
      break;
      
    case 2:
      ChooseList();
      break;
      
    case 3:
      CreateRandomList();
      break;
      
    case 4:
      cout << "Exiting..." << endl;
      break;
    }
  }
}
