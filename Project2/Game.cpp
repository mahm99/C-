/**********************************************************
* File:        Game.cpp
* Project:     CMSC 202, Project 02, Fall 2019
* Author:      Mahmood Ul Mohasin Aziz
* Date:        10/10/2019
* Section:     13
* Email:       rg66173@umbc.edu
* 
* This file contains c++ program code for the class Game
* that determines how the game is being played, provides 
* user with menu options and asks them choose what they 
* want to do. Depending on the option chosen makes call 
* to respective functions and provides the outcome to 
* the user. 
********************************************************/

#include "Game.h"


// Name: Game() (Default constructor)
// Preconditions: Foundable file must be loaded successfully into m_allFoundables
// Postconditions: Creates new game      
Game::Game() {

  // printing the welcome statement and calling respective
  // functions to begin the game.
  cout << "\vWelcome to Harry Potter: Wizards Unite" << endl;
  cout << LoadFoundables() << " Foundables Loaded. " << endl;
  GetWizardName();
  MainMenu();
  
}

// Name: GetWizardName()                                                           
// Preconditions: Requires valid string name                                                      
// Postconditions: Returns wizard name 
void Game::GetWizardName() {

  // inintializing identifier to get the input.
  string myWizard = "";
  cout << "What is your wizard's name? " << endl;
  getline(cin, myWizard);

  // setting the wizard name in the class wizard.
  m_wizard = Wizard(myWizard);
}

// Name: MainMenu()
// Preconditions: Requires valid string name and populated m_allFoundables
// Postconditions: Manages win condition and game  
void Game::MainMenu() {

  // identifier that will hold the user choice
  // from the menu.
  int myChoice = 0;

  // running the loop to check if the user chose to quit or
  // if they found all the variables.
  while ((myChoice != MAX_RARITY) && (m_wizard.GetWins() != NUM_FOUNDABLE)) {

    // displaying menu options and getting valid user choice.
    do {
      cout << "\vWhat would you like to do "
	   << m_wizard.GetName() << "?"<< endl;
      cout << "1. Wizard Information" << endl;
      cout << "2. List My Foundables" << endl;
      cout << "3. List All Foundables" << endl;
      cout << "4. Attack Foundable" << endl;
      cout << "5. Quit" << endl;

      cout << "Please enter you choice: " << endl;
      cin >> myChoice;
    } while ((myChoice < MIN_RARITY) || (myChoice > MAX_RARITY));

    // switch cases for the choice made.
    switch (myChoice) {

      // case 1 prints the wizard statistics. 
    case 1:
      WizardStat();
      break;

      // case 2 prints the user defeated foundables.
    case 2:
      PrintMyFoundables();
      break;

      // case 3 prints all the foundables that were loaded.
    case 3:
      PrintFoundables();
      break;

      // case 4 allows user to attack the foundable.
    case 4:
      AttackFoundable();
      break;
      
    }
  }
  // print statement for the user winning the game.
  if (m_wizard.GetWins() == NUM_FOUNDABLE) {
    cout << "\vCongratulations, " << m_wizard.GetName()
	 <<" you've defeated all the foundables!" << endl;
  }
}

// Name: LoadFoundables()
// Preconditions: Requires valid file name and input file
// Postconditions: Populates m_allFoundables  
int Game::LoadFoundables() {

  // initializing identifier that will hold and return a value
  // of the foundables loaded during the start of game.
  int counter = 0;

  // opening the file.
  ifstream myFile;
  myFile.open(FILE_NAME);

  // initializing variables that will hold the strings
  // separated by delimiters.
  string foundName;
  string foundType;
  string foundRarity;
  string foundToughness;
  int newRarity;
  int newToughness;

  // running a loop to iterate and load strings
  // using getline from the text file.
  for (int i = 0; i < NUM_FOUNDABLE; i++) {

    getline(myFile, foundName, ',');
    getline(myFile, foundType, ',');
    getline(myFile, foundRarity, ',');
    getline(myFile, foundToughness, '\n');

    // converting rarity and toughness from string
    // to int, and incrementing the count.
    newRarity = stoi(foundRarity);
    newToughness = stoi(foundToughness);
    counter++;

    // setting the respective item loaded from text file in to
    // class array m_allFoundables using setters within the loop.
    m_allFoundables[i] = Foundable(foundName, foundType, newRarity, newToughness);
  }

  myFile.close();

  return counter;
}

// Name: PrintFoundables()
// Preconditions: Requires populated m_allFoundables
// Postconditions: Displays all Foundables in game    
void Game::PrintFoundables() {

  // using for loop to arrange and print all of the
  // foundables that were loaded into m_allFoundables.
  for (int i = 0; i < NUM_FOUNDABLE; i++) {
    cout << (i+1) << ". " << m_allFoundables[i].GetName()  << " | "
	 << m_allFoundables[i].GetType() << " | "
	 << m_allFoundables[i].GetRarity() << " | "
	 << m_allFoundables[i].GetToughness() << endl;;
  }
  
}

// Name: WizardStat()
// Preconditions: Requires Wizard to be created and populated
// Postconditions: None (display function)  
void Game::WizardStat() {

  // initializing variables to calculate win rate.
  double sum = (m_wizard.GetWins() + m_wizard.GetLosses());
  double winRate = 0;

  // Wizard's statistic table.
  cout << "\v***********************************************" << endl;
  cout << "\vInformation About Wizard " << m_wizard.GetName()<< endl;
  cout << "Level: "  << m_wizard.GetLevel() << endl;
  cout << "Toughness: " << m_wizard.GetToughness() << endl;
  cout << "Foundables Found: " <<  m_wizard.GetWins() <<endl;
  cout << "Wins: " << m_wizard.GetWins() << " Loses: " << m_wizard.GetLosses()<<  endl;

  // setting the decimal point conditions.
  if (sum > 0) {
    // updating win rate.
    winRate = ((m_wizard.GetWins()/sum) * 100);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Win Rate: "  << winRate << "%" << endl;  
  } else {
    cout << noshowpoint;
    cout << "Win Rate: "  << winRate << "%" << endl;
  }
  cout << "\v***********************************************" << endl;

}

// Name: PrintMyFoundables()
// Preconditions: Requires m_foundables in Wizard to be populated
// Postconditions: None (display function)  
void Game::PrintMyFoundables() {

  // calling  print my foundables function in the wizard
  // class to print the defeated foundables.
  m_wizard.PrintMyFoundables();

}

// Name: AttackFoundable
// Preconditions: Requires m_allFoundables to be populated
// Postconditions: Wizard attacks a Foundable of a specific rarity
//                 No duplicate Foundables can be attacked.   
void Game::AttackFoundable() {

  // variable that will hold the user entered rarity.
  int rarityChoice = 0;

  // variable and an 1D array to filter and keep
  // track of left over foundables.
  int count = 0;
  int trackIndex[NUM_FOUNDABLE] = {};

  // getting the rarity the user wants to attack.
  cout << "What rarity of Foundable would you like to challenge (1-5)?" << endl;
  cin >> rarityChoice;
  while ((rarityChoice < MIN_RARITY) || (rarityChoice > MAX_RARITY)) {
    cout << "What rarity of Foundable would you like to challenge (1-5)?" << endl;
    cin >> rarityChoice;
  }

  // filtering the left-over foundables to defeat.
  for (int i = 0; i < NUM_FOUNDABLE; i++) {
    if ((m_allFoundables[i].GetRarity() == rarityChoice)
	&& (m_wizard.CheckFoundable(m_allFoundables[i]) != BOOL_FLAG)) {
      //cout << count << ". Testing ..... :" << i << endl;
      trackIndex[count] = i;
      count++;
    }
  }

  //  cout << "Testing ..... :" << trackIndex[0] << endl;

  // generating random number to pick one among the left over
  // foundables.
  int compRand = (rand() % (count + 1));
  int foundIndex = trackIndex[compRand];
  //cout << foundIndex << " Index Picking....."  << endl;
  // if the user has already defeated all the                                                                                                                                                          
  // foundables of the specific rarity entered.

  if (count == 0) {

    cout << "\vYou have already defeated foundables of that specific rarity." << endl;
  }

  else {

    if (m_wizard.CheckFoundable(m_allFoundables[foundIndex]) != BOOL_FLAG) {

      cout << "\vThe Wizard " << m_wizard.GetName() << " attacks "
	   << m_allFoundables[foundIndex].GetName() << "!!!" << endl;
      
      // condition calling AttackFoundable() and determining if the user defeated.
      if ((m_allFoundables[foundIndex].GetRarity() == rarityChoice)
	  && (m_wizard.AttackFoundable(m_allFoundables[foundIndex]) == BOOL_FLAG)) {
	
	cout << "You defeat the "
	     << m_allFoundables[foundIndex].GetName()
	     << "!!" << endl;
      }
      // if the user did not defeat print the statement. 
      else { 
	cout << "You do not successfully defeat the foundable." << endl;
      }
    }
  }
}

