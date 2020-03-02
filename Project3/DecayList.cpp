/********************************************************************                              
* File:        DecayList.cpp                                                                                                                            
* Author:      Mahmood Ul Mohasin Aziz                                                                 
*
* Description:
* This file conatains the program code for the DecayList class.
* DecayList keeps track of the node heads and size of the list. 
* During the simualtion it traverses through the link list and 
* removes the nodes. It also frees any dynamic memory created.
*********************************************************************/
#include "DecayList.h"
#include <vector>

// CONSTANTS
const int ZERO = 0;

// Constructor                                                                                   
// Preconditions: None                                                                           
// Postconditions: New list is created                                                           
DecayList::DecayList() {
  m_head = nullptr;
  m_size = 0;
}

// Destructor                                                                                    
// Preconditions: None
// Postconditions: Dynamically allocated memory freed                                             
DecayList::~DecayList(){
  
  //de-allocating dynamically allocated memory.
  Node* curr = m_head;
  Node* temp = nullptr;

  while (curr) {
    temp = curr;
    curr = curr->GetNext();
    delete temp;
    m_size--;
  }
  delete curr;
  m_head = curr;
}

// GetSize - Returns size of list                                                                
// Preconditions: None                                                                           
// Postconditions: Returns size (as integer)                                                     
int DecayList::GetSize() {
  return m_size;
}

// InvertValue - Chooses a node to replace value (with opposite value)                          
// Preconditions: Node to be changed exists                                                      
// Postconditions: Node's value is negated                                                       
void DecayList::InvertValue(int index) {

  Node* curr = m_head;
  
  for (int i = 0; i < m_size; i++) {
    if (i == index) { // flipping values
      curr->ReplaceValue();
    }
    curr = curr->GetNext();
  }
  
}

// PrintDecayList() - Prints the list of nodes and their values                                  
// Preconditions: None                                                                           
// Postconditions: m_value are printed out in order returns true if successfully prints          
bool DecayList::PrintDecayList() {

  Node* curr = m_head;
  if (!CheckEmpty()) { // checking if the list is not empty.
    while (curr) {
      cout << "|" << curr->GetValue() << "|->";
      curr = curr->GetNext();
    }
    cout << "END" << endl;
    return true;
  } else {
    return false;
  }
}

// TraverseList - Loops list to see if any sequences of 3 or more nodes with a value of 1       
// Preconditions: DecayList has Nodes. Passed value to be checked (true by default)              
// Postconditions: Removes all sequences of nodess with 3 or more cards with a value of 1; returns
// number of cards removed
int DecayList::TraverseList(bool myBool) {

  vector<int> myInt; // to hold indexes.
  
  // initializing variables.
  int counter = 0;
  int returnCounter = 0;
  Node* curr = m_head;
  
  while (curr) {

    // comparing values.
    if (curr->GetValue() == myBool) {
      myInt.push_back(counter);
    } else {
      myInt.clear();
    }
    counter++;
    curr = curr->GetNext();

    // condition to remove nodes.
    if (int(myInt.size()) == NUM_CONSECUTIVE) {
      returnCounter += RemoveNodes(int(myInt.at(0)),  int(myInt.at(NUM_CONSECUTIVE - 1)));
      counter -= NUM_CONSECUTIVE; // negating index.
      myInt.clear(); // clearing previous indexes.
    }
  }
  
  return returnCounter;
}

// RemoveNodes - Called when 3 or more 1's in a row. Nodes are removed left to right.             
// Preconditions: A DecayList has a minimum of 3 nodes                                            
// Postconditions: The nodes are removed, which resizes DecayList; Returns number removed.        
int DecayList::RemoveNodes(int indexOne, int indexTwo) {

  // initializing nodes and variables.
  Node* curr = m_head;
  Node* prev = m_head;
  Node* temp = nullptr;
  int counter = 0;
  
  if (indexOne == ZERO) { // if the nodes are first three.
    while ((curr) && (counter <= indexTwo)) {
      temp = curr;
      curr = curr->GetNext();
      delete temp;
      counter++;
      m_size--;
    }
    m_head = curr; // setting m_head to the current node.

  } else {
    // iterates until counter reaches to the indexOne and sets prev to curr.
    while ((curr) && (counter < indexOne)) {
      prev = curr;
      curr = curr->GetNext();
      counter++;
    }

    // iterates and removes all the nodes until counter reaches indexTwo.
    while ((curr) && (counter <= indexTwo)) {
      temp = curr;
      curr = curr->GetNext();
      delete temp;
      counter++;
      m_size--;
    }
    prev->SetNext(curr); //connecting the prev to the updated curr.
  }
  return (indexTwo - indexOne + 1); // returning num of nodes removed.
}

// CheckEmpty - Called to see if the list is empty                                               
// Preconditions: Nodes were removed from list                                                   
// Postconditions: If empty, returns true and round ends                                         
bool DecayList::CheckEmpty() {
  
  if (m_size > ZERO) {
    return false;
  } else {
    return true;
  }
}

// InsertEnd - Inserts new Node into end of DecayList                                            
// Preconditions: DecayList exists - may not create m_tail                                       
// Postconditions: Inserts passed node to end of list                                            
void DecayList::InsertEnd(Node* passedNode) {
  
  Node* curr = m_head;
 
  // setting node head.
  if (!curr) {
    m_head = passedNode;
    m_size++;

  } else { 

    // setting end.
    while (curr->GetNext()) {
      curr = curr->GetNext();
    }
    curr->SetNext(passedNode);
    m_size++;
  }
}
