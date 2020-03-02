/*************************************************************                                     
* File: Rogue.cpp
* Author: Mahmood Ul Mohasin Aziz                                                                            
* Description:
* This file contains program code for class Rogue.h.
* This class inherits from Character class. Prints and
* updates special attack info related to Rogue.
************************************************************/
#include "Rogue.h"

// Name: Rogue() - Default Constructor                                                            
// Description: Creates a new rogue                                                               
// Preconditions: None                                                                            
// Postconditions: Can create a rogue                                                             
Rogue::Rogue():Character() {}

// Name: Rogue(string name, int hp)                                                               
// Description: Creates a new rogue                                                               
// Preconditions: None                                                                            
// Postconditions: Can create a rogue                                                             
Rogue::Rogue(string name, int health):Character(name, health) {}

// Name: ~Rogue - Virtual Destructor                                                              
// Description: Makes sure everything in child class is deallocated                               
// Preconditions: None                                                                            
// Postconditions: Everything dynamically allocated is deallocated                                
Rogue::~Rogue() {
  SetName("");
  SetHealth(0);
}

// Name: SpecialAttack                                                                            
// Description: Defines the Rogue's special attack                                                
// Preconditions: None                                                                            
// Postconditions: Returns damage from special attack
int Rogue::SpecialAttack() {
  int sAttack = (rand() % 11) + 2; // randomizing loss from 2-12.
  cout << " performs a sneak attack!" << endl;
  return sAttack;
}
