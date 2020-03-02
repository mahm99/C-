/*************************************************************                                     
* File: Entity.cpp                                                         
* Author: Mahmood Ul Mohasin Aziz                                                                          
* Description:
* This file contains program code for the class Entity.h.
* It mainly handles the program execution related to
* entity objects including setting the name, and values of
* the objects. It also allows the Game.cpp to access the info
* of the objects. It is also the parent class for Character
* and Monster.
************************************************************/
#include "Entity.h"

// Name: Entity() - Default Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes (not specifically used)
Entity::Entity() {
  m_name = "";
  m_health = 0;
}

// Name: Entity(string, int) - Overloaded Constructor                                             
// Description: Abstract class - cannot directly instantiate this class                           
// Preconditions: None
// Postconditions: Populates variables used in child classes
Entity::Entity(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// Name: virtual ~Entity - Virtual Destructor                                                     
// Description: Makes sure everything in child class is deallocated                               
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Entity::~Entity() {
  //resetting all the values
  SetName("");
  SetHealth(0);
}

// Name: GetName()
// Description: Returns name of entity
// Preconditions: Entity has name
// Postconditions: None
string Entity::GetName() {
  return m_name;
}

// Name: GetHealth()
// Description: Returns health of entity
// Preconditions: Entity has health
// Postconditions: None
int Entity::GetHealth() {
  return m_health;
}

// Name: SetName()
// Description: Sets name of entity
// Preconditions: None
// Postconditions: Name is set
void Entity::SetName(string newName) {
  m_name = newName;
}

// Name: SetHealth()
// Description: Sets health of entity
// Preconditions: None
// Postconditions: Health is set
void Entity::SetHealth(int newHealth) {
  m_health = newHealth;
}


// Name: Overloaded <<
// Description: Prints the details of an entity
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of entity
ostream& operator<<(ostream& output, Entity& entity) {

  // outputting data.
  output << entity.GetName() << "'s health: "
	 << entity.GetHealth() << endl; 
  return output;
}

