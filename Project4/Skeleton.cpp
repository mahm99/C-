/*************************************************************                                     
* File: Skeleton.cpp                                                         
* Author: Mahmood Ul Mohasin Aziz                                                                  
* Description:                                                                                     
* This file contains program code for class Skeleton.h.
* This class inherits from Character class. Prints and
* updates specail attack info related to Skeleton.
************************************************************/
#include "Skeleton.h"

// Name: Skeleton() - Default Constructor                                                         
// Description: Creates a new skeleton                                                            
// Preconditions: None                                                                            
// Postconditions: Can create a skeleton                                                          
Skeleton::Skeleton():Monster() {}

// Name: Skeleton(string name, int hp)                                                            
// Description: Creates a new skeleton                                                            
// Preconditions: None                                                                            
// Postconditions: Can create a skeleton                                                          
Skeleton::Skeleton(string name, int health):Monster(name, health) {}

// Name: SpecialAttack                                                                            
// Description: Defines the Skeleton's special attack                                             
// Preconditions: None                                                                            
// Postconditions: Returns damage from special attack                                             
int Skeleton::SpecialAttack() {
  int sAttack = 1; // special attack loss
  cout << " bashes you with it's arm!" << endl;
  return sAttack;
}
