/*************************************************************                                     
* File: Goblin.cpp
* Author: Mahmood Ul Mohasin Aziz
* Description:                                                                                   
* This file contains program code for class Goblin.h.                                              
* This class inherits from Character class. Prints and                                            
* updates special attack info related to Goblin.
************************************************************/
#include "Goblin.h"


// Name: Goblin() - Default Constructor                                                           
// Description: Creates a new goblin                                                              
// Preconditions: None                                                                            
// Postconditions: Can create a goblin                                                            
Goblin::Goblin():Monster() {}

// Name: Goblin(string name, int hp)                                                              
// Description: Creates a new goblin                                                              
// Preconditions: None                                                                            
// Postconditions: Can create a goblin                                                            
Goblin::Goblin(string name, int health):Monster(name, health) {}

// Name: SpecialAttack                                                                            
// Description: Defines the Goblin's special attack                                               
// Preconditions: None                                                                            
// Postconditions: Returns damage from special attack                                             
int Goblin::SpecialAttack() {
  int sAttack = 2; // special attack loss
  cout << " knaws at your ankle!" << endl;
  return sAttack;
}
