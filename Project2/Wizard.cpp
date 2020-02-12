/**********************************************************
 * File:        Wizard.cpp
 * Author:      Mahmood Ul Mohasin Aziz
 *
 * Description: 
 * This file contains c++ program code for the class 
 * Wizard that determines the wizard's game, manages 
 * holds the info about the wizard, the foundables 
 * wizard defeated, updates the stat info, printing 
 * out the list, etc.
 ********************************************************/

#include "Wizard.h"

// Name: Wizard() Default Constructor
// Preconditions: None
// Postconditions: Creates new Wizard with valid values        
Wizard::Wizard() {

  // initializing values.
  m_name = "";
  m_toughness = 0;
  m_level = 1;
  m_wins = 0;
  m_losses = 0;
  
}

// Name: Wizard() Overloaded Constructor
// Preconditions: Requires valid name
// Postconditions: Creates new Wizard with m_Toughness between 150 and 300
//                 and m_Level = 1 with passed name        
Wizard::Wizard(string name) {
  SetName(name);
  m_toughness = (rand() % (MAX_START_TOUGH - MIN_START_TOUGH + 1)) + MIN_START_TOUGH;
  m_level = 1;
  m_wins = 0;
  m_losses = 0;
}

// Name: GetName()
// Preconditions: None
// Postconditions: Returns m_name     
string Wizard::GetName() {
  return m_name;
}

// Name: GetToughness()
// Preconditions: None
// Postconditions: Returns m_toughness     
int Wizard::GetToughness() {
  return m_toughness;
}

// Name: GetWins()
// Preconditions: None
// Postconditions: Returns m_wins    
int Wizard::GetLevel() {
  return m_level;
}

// Name: GetWins()
// Preconditions: None
// Postconditions: Returns m_wins   
int Wizard::GetWins() {
  return m_wins;
}

// Name: GetLosses()
// Preconditions: None
// Postconditions: Returns m_losses     
int Wizard::GetLosses() {
  return m_losses;
}

// Setters.

// Name: SetName()
// Preconditions: Requires valid string name
// Postconditions: Updates m_name   
void Wizard::SetName(string name) {
  m_name = name;
}

// Name: SetToughness()
// Preconditions: Requires valid int toughness
// Postconditions: Updates m_toughness      
void Wizard::SetToughness(int toughness) {
  m_toughness = toughness;
}

// Name: InsertFoundable()
// Preconditions: Requires a valid Foundable (from m_allFoundables)
// Postconditions: Adds copy Foundable to m_foundables   
void Wizard::InsertFoundable(Foundable newFoundable) {

  // indexing the foundable.
  int i = m_wins;
  
  // Inserting at the respective index using getter from
  // all foundables.
  m_foundables[i].SetName(newFoundable.GetName());
  m_foundables[i].SetType(newFoundable.GetType());
  m_foundables[i].SetRarity(newFoundable.GetRarity());
  m_foundables[i].SetToughness(newFoundable.GetToughness());
  
}

// Name: CheckFoundable()
// Preconditions: Requires valid Foundable
// Postconditions: Returns true if exists in m_foundables else false  
bool Wizard::CheckFoundable(Foundable newFoundable) {

  // initializing boolean flag.
  bool myFlag = false;

  // looping through the defeated foundables list to check
  // and set the flag to true, if it was defeated. 
  for (int i = 0; i < m_wins; i++) {
    if ((m_foundables[i].GetName() == newFoundable.GetName())
        && (m_foundables[i].GetToughness() == newFoundable.GetToughness())) {
      myFlag = BOOL_FLAG;
    }
  }
  return myFlag;
}

// Name: AttackFoundable()
// Preconditions: Requires valid enemy (Foundable pointer)
// Postconditions: Compares Wizard toughness to the enemy toughness
//                 (tie goes to enemy) Returns result of comparison  
bool Wizard::AttackFoundable(Foundable enemy) {

  // initializing boolean flag.
  bool myBool = false;

  // condition to compare if wizard toughness is greater than
  // the foundable. If yes, inserting it to wizard list,
  // incrementing the level and wins.
  if (CheckFoundable(enemy) != BOOL_FLAG) {
    if (m_toughness > enemy.GetToughness()) {
      InsertFoundable(enemy);
      IncreaseLevel();
      m_wins++;
      myBool = BOOL_FLAG;
    }
  }

  // if not, increment the losses.
  else {
    m_losses += 1;
  }
  
  return myBool;  
}

// Name: PrintMyFoundables()
// Preconditions: None
// Postconditions: Displays a list of all foundables found by Wizard else indicates none found
void Wizard::PrintMyFoundables() {

  // if the user did not defeat any foundables.
  if (m_wins == 0) {
    cout << "You have not defeated any foundables yet." << endl;
  }

  // if they did, using for loop to print the defeated foundables.
  else {
    cout << "\t\v THE WIZARD DEFEATED: \n" << endl;
    for (int i = 0; i < m_wins; i++) {
      cout << (i+1) << ". "
	   << m_foundables[i].GetName() << " | "
	   << m_foundables[i].GetType() << " | "
	   << m_foundables[i].GetRarity() << " | "
	   << m_foundables[i].GetToughness() << endl;

    }
  }
}

// Name: IncreaseLevel()                                                                        
// Preconditions: None                                                                   
// Postconditions: Updates m_level by one and increases toughness from 0 to 100                  
void Wizard::IncreaseLevel() {

  // increasing level and toughness randomly.
  int toughInc = (rand() % LEVEL_TOUGH_INCREASE);
  m_level++;
  m_toughness += toughInc;
  
}
