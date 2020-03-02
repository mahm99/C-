/*************************************************************                                     
* File: Paladin.cpp                                                         
* Author: Mahmood Ul Mohasin Aziz                                                                                                                                            
* Description:                                                                                     
* This file contains program code for class Paladin.h.
* This class inherits from Character class. Prints and
* updates special attack info related to Paladin.
************************************************************/
#include "Paladin.h"

// Name: Paladin() - Default Constructor                                                          
// Description: Creates a new paladin                                                             
// Preconditions: None                                                                            
// Postconditions: Can create a paladin                                                           
Paladin::Paladin():Character() {}

// Name: Paladin(string name, int hp)                                                             
// Description: Creates a new paladin                                                             
// Preconditions: None                                                                            
// Postconditions: Can create a paladin                                                           
Paladin::Paladin(string name, int health):Character(name, health) {}

// Name: ~Paladin - Virtual Destructor                                                            
// Description: Makes sure everything in child class is deallocated                               
// Preconditions: None                                                                            
// Postconditions: Everything dynamically allocated is deallocated                                
Paladin::~Paladin() {
  SetName("");
  SetHealth(0);
}

// Name: SpecialAttack                                                                            
// Description: Defines the Paladin's special attack                                              
// Preconditions: None                                                                            
// Postconditions: Returns damage from special attack                                             
int Paladin::SpecialAttack() {
  int sAttack = (rand() % 8) + 1; // randomizing loss from 1-8.
  cout << " uses smite evil!" << endl;
  return sAttack;
}
