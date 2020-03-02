/********************************************************************                              
* File:        Node.cpp                                                                                                                            
* Author:      Mahmood Ul Mohasin Aziz                                                                                                                                 
*                                                                                                 
* Description:
* This file contains the program code for the Node class. It allows
* all other classes to set the next nodes in the linked list,
* access or change the values of the nodes, tell the program what the
* nest node is pointing at, and frees dynamically allocated memory.
*********************************************************************/
#include "Node.h"

// Constructor                                                                                   
// Preconditions: None                                                                           
// Postconditions: None                                                                          
Node::Node() {
  m_next = nullptr;
  m_value = false;
}

// Destructor                                                                                    
// Preconditions: None                                                                           
// Postconditions: Frees dynamically allocated memory                                            
Node::~Node() {
  m_next = nullptr;
}

// Overloaded Constructor                                                                        
// Preconditions: None                                                                           
// Postconditions: Initializes member variable with given argument                               
Node::Node(bool value) {
  // setting each node value.
  m_next = nullptr;
  m_value = value;
}

// ReplaceValue - Replaces m_value with opposite (if true then false or if false then true)      
// Preconditions: None                                                                           
// Postconditions: m_value negated                                                               
void Node::ReplaceValue() {
  // flipping.
  if (m_value == false) {
    m_value = true;
  } else if (m_value == true) {
    m_value = false;
  }
}

// SetNext() - Sets m_next                                                                       
// Preconditions: None                                                                           
// Postconditions: m_next is set                                                                 
void Node::SetNext(Node* nextNode) {
  // setting next node.
  m_next = nextNode;
}

// GetNext() - returns m_next                                                                    
// Preconditions: None                                                                           
// Postconditions: returns m_next                                                                
Node* Node::GetNext() {
  return m_next;
}

// GetValue() - returns m_value                                                                  
// Preconditions: None                                                                           
// Postconditions: returns m_value                                                               
bool Node::GetValue() {
  return m_value;
}
