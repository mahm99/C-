/******************************************************                                            
* File: Goblin.h                                                         
* Author: Mahmood Ul Mohasin Aziz                                                                         
* Description:                                                                                     
* This is the header file for the goblin class.  
*****************************************************/

#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include "Monster.h"

class Goblin: public Monster {
 public:
  // Name: Goblin() - Default Constructor
  // Description: Creates a new goblin
  // Preconditions: None
  // Postconditions: Can create a goblin
  Goblin();
  // Name: Goblin(string name, int hp)
  // Description: Creates a new goblin
  // Preconditions: None
  // Postconditions: Can create a goblin
  Goblin(string, int);
  // Name: SpecialAttack
  // Description: Defines the Goblin's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
