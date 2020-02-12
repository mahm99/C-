/**********************************************************
 * File:        Foundable.cpp
 * Author:      Mahmood Ul Mohasin Aziz
 * 
 * Description:
 * This file contains c++ program code for the class
 * Foundable. This class manages and stores all the foundable's 
 * information from the text file into an array. Also, it
 * holds the info about the wizard defeated foundables, and 
 * make them accessible to all other classes int the program.
 ********************************************************/

#include "Foundable.h"

// Name: Foundable() (Default Constructor)                                                       
// Desc: If a new Foundable is declared, it makes the values "valid"                             
// Preconditions: None                                                                           
// Postconditions: Creates new Foundable with valid data  
Foundable::Foundable() {
  m_name = "";
  m_type = "";
  m_rarity = 0;
  m_toughness = 0;

}

// Name: Foundable() (Overloaded Constructor)                                                    
// Desc: Foundable with passed in values                                                         
// Preconditions: Requires valid input data                                                      
// Postconditions: Creates new Foundable with passed data  
Foundable::Foundable(string name, string type, int rarity, int toughness) {
  SetName(name);
  SetType(type);
  SetRarity(rarity);
  SetToughness(toughness);
}

// Name: GetName()                                                                              
// Preconditions: None                                                                          
// Postconditions: Returns name       
string Foundable::GetName() {
  return m_name;
}

// Name: GetType()                                                                             
// Preconditions: None                                                                           
// Postconditions: Returns type  
string Foundable::GetType() {
  return m_type;
}

// Name: GetRarity()                                                                             
// Preconditions: None                                                                           
// Postconditions: Returns rarity  
int Foundable::GetRarity() {
  return m_rarity;
}

// Name: GetToughness()                                                                        
// Preconditions: None                                                                           
// Postconditions: Returns toughness   
int Foundable::GetToughness() {
  return m_toughness;
}

// Name: SetName()                                                                             
// Preconditions: Requires valid type                                                           
// Postconditions: Updates value of m_name   
void Foundable::SetName(string newName) {
  m_name = newName;
}

// Name: SetType()                                                                              
// Preconditions: Requires valid type                                                           
// Postconditions: Updates value of m_type   
void Foundable::SetType(string newType) {
  m_type = newType;
}

// Name: SetRarity()                                                                               
// Preconditions: Requires valid rarity (1-5)                                                    
// Postconditions: Updates value of m_rarity   
void Foundable::SetRarity(int newRarity) {
  m_rarity = newRarity;
}

// Name: SetToughness()                                                                          
// Preconditions: Requires valid toughness                                                       
// Postconditions: Updates value of m_toughness 
void Foundable::SetToughness(int newToughness) {
  m_toughness = newToughness;
 }




