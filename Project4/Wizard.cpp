/*************************************************************                                     
* File: Wizard.cpp                                                          
* Author: Mahmood Ul Mohasin Aziz                                                                                                                                            
* Description:                                                                                     
* This file contains program code for class Wizard.h.
* This class inherits from Character class. Prints and
* updates special attack info related to Wizard.
************************************************************/
#include "Wizard.h"

// Name: Wizard() - Default Constructor
// Description: Creates a new wizard
// Preconditions: None
// Postconditions: Can create a wizard
Wizard::Wizard():Character() {}

// Name: Wizard(string name, int hp)
// Description: Creates a new wizard
// Preconditions: None
// Postconditions: Can create a wizard
Wizard::Wizard(string name, int health):Character(name, health) {}

// Name: ~Wizard - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Wizard::~Wizard() {
  SetName("");
  SetHealth(0);
}

// Name: SpecialAttack
// Description: Defines the Wizard's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack                                             
int Wizard::SpecialAttack() {
  int sAttack =	(rand() % 10) + 3; // randomizing loss from 3-12.
  cout << " casts magic missile!" << endl;
  return sAttack;

}
