/******************************************************                                            
* File: BabyDragon.h                                                                                                                                              
* Author: Mahmood Ul Mohasin Aziz                                                                                                                                            
* Description:                                                                                     
* This is the header file for the BabyDragon class. 
*****************************************************/


#ifndef _BABYDRAGON_H_
#define _BABYDRAGON_H_

#include "Monster.h"

class BabyDragon: public Monster {
 public:
  // Name: BabyDragon() - Default Constructor
  // Description: Creates a new baby dragon
  // Preconditions: None
  // Postconditions: Can create a baby dragon
  BabyDragon();
  // Name: Baby Dragon(string name, int hp)
  // Description: Creates a new baby dragon
  // Preconditions: None
  // Postconditions: Can create a baby dragon
  BabyDragon(string, int);
  // Name: SpecialAttack
  // Description: Defines the Baby Dragon's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
