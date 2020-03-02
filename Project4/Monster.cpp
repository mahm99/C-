/*************************************************************                                     
* File: Monster.cpp
* Author: Mahmood Ul Mohasin Aziz                                                                          
* Description:
* This file contains program code for class Monster.h.
* This class inherits from Entity class. Prints and
* updates attack info related to Monster.
************************************************************/
#include "Monster.h"

// Name: Monster() - Default Constructor                                                          
// Description: Would be used to create a monster but abstracted                                  
// Preconditions: None                                                                            
// Postconditions: Used to populate child class data                                              
Monster::Monster():Entity() {}

// Name: Monster(string name, int hp) - Overloaded Constructor                                    
// Description: Would be used to create a monster but abstracted                                  
// Preconditions: None                                                                            
// Postconditions: Used to populate child class data                                              
Monster::Monster(string name, int health):Entity(name, health) {}

// Name: Attack()                                                                                 
// Description: Describes attack statements for monster                                           
// Preconditions: None                                                                            
// Postconditions: Returns damage                                                                 
int Monster::Attack() {
  int nAttack = 1; // special attack loss
  cout << " deals 1 point of damage!" << endl;
  return nAttack;
}
