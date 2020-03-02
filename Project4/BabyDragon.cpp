/*************************************************************                                     
* File: BabyDragon.cpp                                                          
* Author: Mahmood Ul Mohasin Aziz                                                                  
*
* Description:                                                                                     
* This file contains program code for class BabyDragon.h.
* This class inherits from Character class. Prints and
* updates special attack info related to BabyDragon.
************************************************************/
#include "BabyDragon.h"

// Name: BabyDragon() - Default Constructor                                                       
// Description: Creates a new baby dragon                                                         
// Preconditions: None                                                                            
// Postconditions: Can create a baby dragon                                                       
BabyDragon::BabyDragon():Monster() {}

// Name: Baby Dragon(string name, int hp)                                                         
// Description: Creates a new baby dragon                                                         
// Preconditions: None                                                                            
// Postconditions: Can create a baby dragon                                                       
BabyDragon::BabyDragon(string name, int health):Monster(name, health) {}

// Name: SpecialAttack                                                                            
// Description: Defines the Baby Dragon's special attack                                          
// Preconditions: None                                                                            
// Postconditions: Returns damage from special attack                                             
int BabyDragon::SpecialAttack() {
  int sAttack = 4; // special attack loss
  cout << " breaths a cone of fire at you!" << endl;
  return sAttack;
}
