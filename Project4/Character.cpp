/*************************************************************
* File: Character.cpp                                                          
* Author: Mahmood Ul Mohasin Aziz                                                                  
* Description:
* This file contains the program code for class Character.h.
* It is the child class of Entity class. Prints and updates 
* attack info related to character.
************************************************************/
#include "Character.h"

// Name: Character() - Default Constructor
// Description: Creates a new character
// Preconditions: None
// Postconditions: Can create a character
Character::Character():Entity() {}

// Name: Character(string name, int hp) - Overloaded constructor
// Description: Creates a new character
// Preconditions: None
// Postconditions: Can be used to populate character or child classes
Character::Character(string name, int health):Entity(name, health) {}

// Name: ~Character - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Character::~Character() {
  SetName("");
  SetHealth(0);
}

// Name: Attack()
// Description: Describes attack statements for character
// Preconditions: None
// Postconditions: Returns damage
int Character::Attack() {
  int attack = (rand() % 6) + 1; // randomizing loss from 1-6.
  cout << " attacks dealing "; 
  return attack;
}

// Name: SpecialAttack()
// Description: Tells player that character does not have special attack
// may be used for child class special attacks
// Preconditions: None
// Postconditions: May be used to call child class SpecialAttack
int Character::SpecialAttack() {
  cout << "You have no Special Attack!" << endl;
  return 0; // no loss for non-specialized character.
}
