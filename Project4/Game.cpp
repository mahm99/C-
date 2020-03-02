/*************************************************************
* File: Game.cpp
* Author: Mahmood Ul Mohasin Aziz
* Description:
* This file contains the program code for the class Game.h.
* This class  mainly handles the whole game including dynamically 
* creating new objects of other classes, deallocating dynamic 
* memory, displaying stats, updating health, and checking if 
* both user and monster are dead. 
************************************************************/
#include "Game.h"

const int ZERO = 0;

// Name: Game() - Default Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: After asking for a file name, loads map, creates char and starts.
Game::Game() {}

// Name: Game(string filename) - Overloaded Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: Uses filesname to LoadMap, calls create character,
//                 and sets both numRests and m_numSpecial using constants.
Game::Game(string fileName) {
  // loading file, creating charadcter, & starting game.
  LoadMap(fileName);
  CharacterCreation();
  StartGame();
}

// Name: ~Game
// Description: Destructor
// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated in Game
Game::~Game() {
  // emptying the vector.
  for (unsigned int i = 0; i < m_myMap.size(); i++) {
    delete m_myMap.at(i);
    m_myMap.at(i) = nullptr;
  }
  delete m_curMonster;
  m_curMonster = nullptr;
  delete m_myCharacter;
  m_myCharacter = nullptr;
}

// Name: LoadMap(string fileName)
// Description: Dynamically creates rooms and inserts them into the m_myMap vector
// Precondition: File contains map information
// Postcondition: Map is populated with Room objects.
void Game::LoadMap(string fileName) {
  
  string roomId = "", roomNorth = "", roomEast = "", roomSouth = "", roomWest = "";
  string roomName = "", roomDesc = "";

  int rID = ZERO, rNorth = ZERO, rEast = ZERO, rSouth = ZERO, rWest = ZERO;
  Room* newRoom;
  
  ifstream fileInput;
  fileInput.open(fileName);

  // reading in the file.
  while (getline(fileInput, roomId, '|') && getline(fileInput, roomName, '|')
	 && getline(fileInput, roomDesc, '|') && getline(fileInput, roomNorth, '|')
	 && getline(fileInput, roomEast, '|') && getline(fileInput, roomSouth, '|')
	 && getline(fileInput, roomWest, '|')) {

    // converting strings.
    rID = stoi(roomId);
    rNorth = stoi(roomNorth);
    rEast = stoi(roomEast);
    rSouth = stoi(roomSouth);
    rWest = stoi(roomWest);

    // creting room obejct and pushing back into the vector.
    newRoom = new Room(rID, roomName, roomDesc, rNorth, rEast, rSouth, rWest);
    m_myMap.push_back(newRoom);
  }
  fileInput.close();
}

// Name: CharacterCreation()
// Description: Allows user to create a new character (or child) to play with. May
//              be either character, paladin, rogue, or wizard.
// Preconditions: None
// Postconditions: m_myCharacter is populated
void Game::CharacterCreation() {

  string userName = "";
  int userChoice = ZERO;

  cout << "Welcome to UMBC Adventure!\nCharacter name: ";
  getline(cin, userName);

  do {
    cout << "Select a class: \n"
	 << "1. Rogue\n" << "2. Wizard\n"
	 << "3. Paladin\n" << "4. No class\n";
    cin >> userChoice;
  } while ((userChoice < 1) || (userChoice > 4)); // validating input.

  // creating a character object using user entered choice.
  switch (userChoice)
    {
    case 1:
      m_myCharacter = new Rogue(userName, ROGUE_HEALTH);
      break;
    case 2:
      m_myCharacter = new Wizard(userName, WIZARD_HEALTH);
      break;
    case 3:
      m_myCharacter = new Paladin(userName, PALADIN_HEALTH);
      break;
    case 4:
      m_myCharacter = new Character(userName, CHAR_HEALTH);
      break;      
    }
  m_numRests = NUM_RESTS;
  
  if (userChoice != 4)  {
    m_numSpecial = NUM_SPECIAL;
  }
  else { // no special attacks for a non-specialized object.
    cout << "\nNo special attacks for non-specialized character!" << endl;
    m_numSpecial = ZERO;
  }
}

// Name: StartGame()
// Description: After LoadMap and CharacterCreation, current room
//              is set (0 by default) and Action is called
// Preconditions: LoadMap and CharacterCreation must have been completed
// Postconditions: m_numRests, m_numSpecial and curRoom populated and action called
void Game::StartGame() {
  // setting the default room and starting the game.
  m_curRoom = START_ROOM;
  m_myMap[m_curRoom]->PrintRoom();
  m_curMonster = RandomMonster();
  Action();
}

// Name: Action()
// Description: Menu for game
// Preconditions: Everything in start has been completed
// Postconditions: Game continues until quit or player dies
void Game::Action() {

  int userChoice = 0;

  enum CHOICE {LOOK = 1, MOVE, MONSTER, REST, CHECKSTATS, QUIT};
  
  bool exit = false;

  while (!exit) {
    
    if (m_myCharacter->GetHealth() == ZERO) {
      cout << "\nYou're dead :(\n" << endl;
      exit = true;
    }

    else {
      
      do {
	cout << "What would you like to do? \n"
	     << "1. Look\n" << "2. Move\n"
	     << "3. Attack Monster\n" << "4. Rest\n"
	     << "5. Check Stats\n" << "6. Quit\n";
	cin >> userChoice;
      } while((userChoice < LOOK) && (userChoice > QUIT)); // validating input.

      if (userChoice == LOOK) { // to print the room.
	m_myMap[m_curRoom]->PrintRoom();                                                          
      }
      
      else if (userChoice == MOVE) {
	Move(); // to move from room to room.
      }
      
      else if (userChoice == MONSTER) {
	Attack(); // to allow attacking.
      }
      
      else if (userChoice == REST) {

	if (m_numRests > ZERO) { // restoring health and specials.
	  cout << "\nRestored character health and special attack.\n\n";
	  m_myCharacter->SetHealth(m_myCharacter->GetHealth() + REST_HEAL);
	  m_numSpecial = NUM_SPECIAL;
	  m_numRests--;
	}
	else {
	  cout << "\nYou're  out of rests" << endl;
	}
      }
      
      else if (userChoice == CHECKSTATS) {
	Stats(); // player statistics.
      }
      
      else if (userChoice == QUIT) {
	// quitting the game and deallocating memory.
	cout << "\nGood Bye!\n";
	exit = true;
      }
    }
  }
}
// Name: RandomMonster()
// Description: Used to randomly create a dynamically allocated monster
//              of Baby Dragon, Goblin, or Skeleton
// Preconditions: Has an entity pointer to hold monster child
// Postconditions: Returns object of type Baby Dragon, Goblin, or Skeleton
Entity* Game::RandomMonster() {

  int randMonsta = (rand() % 4) + 1; // used to create a monster object.

  Entity* newMonster;

  // using randomly generated number to run the switch.
  switch (randMonsta)
    {
    case 1: // no monster.
      cout << "It is peaceful here.\n" << endl;
      newMonster = nullptr;
      break;
      
    case 2: // skeleton monster.
      cout << "A Skeleton lumbers around the room.\n" << endl;
      newMonster = (new Skeleton("Skeleton", SKELETON_HEALTH));
      break;
      
    case 3: // goblin monster.
      cout << "A Goblin is here picking his nose.\n" << endl;
      newMonster = (new Goblin("Goblin", GOBLIN_HEALTH));
      break;
      
    case 4: // babydragon monster.     
      cout << "The Baby Dragon is trying to be nice to you.\n" << endl;
      newMonster = (new BabyDragon("Baby Dragon", DRAGON_HEALTH));
      break;
    }
  return newMonster; // returning the newly created monster object.
}

// Name: Move
// Description: Moves a player from one room to another (updates m_curRoom)
// Preconditions: Must be valid move (room must exist)
// Postconditions: Displays room information, checks for new monster (deletes old)
void Game::Move() {

  char newChar;
  int prev = m_curRoom;
  Entity* temp;

  cout << endl;
  do {
    cout << "Which direction? (N E S W)\n";
    cin >> newChar;
    prev = m_myMap.at(m_curRoom)->CheckDirection(newChar);
  } while (prev < 0); // validating input.
  m_curRoom = prev; // setting current toom.
  m_myMap.at(m_curRoom)->PrintRoom();
  temp = m_curMonster;
  m_curMonster = RandomMonster();
  delete temp; // deleting monster in the previous room.
  temp = nullptr;
}

// Name: Attack
// Description: Allows player to attack an enemy entity.
// Preconditions: Must have enemy monster in room
// Postconditions: Indicates who wins and updates health(hp) as battle continues.
//                 May need to deallocate enemy monster to prevent memory leaks.
void Game::Attack() {

  int userChoice = 0;
  int compChoice = (rand() % 4) + 1; // to generate random num for monster attack.
  enum MONSTER_ATTACK{NORMAL_1 = 1, NORMAL_2, NORMAL_3, SPECIAL};
  
  cout << endl;
  // if the room is empty or monster was killed already.
  if (!m_curMonster) {
      cout << "Empty room! Move to another room.\n" << endl;
  }
  else {
    while ((m_myCharacter->GetHealth() > ZERO)
	   && (m_curMonster->GetHealth() > ZERO)) {

      do {
	cout << "1. Normal Attack\n"
	     << "2. Special Attack\n";
	cin >> userChoice;
      } while ((userChoice < 1) || (userChoice > 2));

      int attack = ZERO;
      int prevHealth = ZERO; // to keep track of the health before and after attack. 
      
      // using switch cases to carry the type of attack chosen.
      switch (userChoice)
	{
	case 1: // normal attack.
	  cout << endl << m_myCharacter->GetName();
	  prevHealth = m_curMonster->GetHealth();
	  attack = m_myCharacter->Attack();
	  if (prevHealth - attack > ZERO) {
	    m_curMonster->SetHealth(prevHealth - attack);
	    cout << attack << " damage!" << endl;
	  } else {
	    m_curMonster->SetHealth(ZERO);
	  }
	  break;
	  
	case 2: // special attack
	  
	  if (m_numSpecial < 1) { // if out special attacks.
	    cout << "\nNo special attacks left!\n" << endl;
	  }
	  else {
	    cout << endl << m_myCharacter->GetName();
	    prevHealth = m_curMonster->GetHealth();
	    attack = m_myCharacter->SpecialAttack();
	    if (prevHealth - attack > ZERO) {
	      m_curMonster->SetHealth(prevHealth - attack);
	      cout << m_myCharacter->GetName()
		   << " deals " << attack
		   << " damage!\n" << endl;
	    } else {
	      m_curMonster->SetHealth(ZERO);
	    }
	    m_numSpecial--; // decreasing special count.
	  }      
	  break;
	}
      
      // using randomly generared choice for normal attack.
      if ((compChoice == NORMAL_1) || (compChoice == NORMAL_2)
	  ||  (compChoice == NORMAL_3)) { 
	cout << m_curMonster->GetName();                                                     
	prevHealth = m_myCharacter->GetHealth();                                                    
	attack = m_curMonster->Attack();                                                           
	if (prevHealth - attack > ZERO) {
	  m_myCharacter->SetHealth(prevHealth - attack);
	} else {
	  m_myCharacter->SetHealth(ZERO);
	}
      }
      else if ( compChoice == SPECIAL) {
	cout << m_curMonster->GetName();                                                  
	prevHealth = m_myCharacter->GetHealth();                                                  
	attack = m_curMonster->SpecialAttack();
	if (prevHealth - attack > ZERO) {
	  m_myCharacter->SetHealth(prevHealth - attack);  
	} else {
	  m_myCharacter->SetHealth(ZERO);
	}
      }
      // using overloaded operator to print statistics.
      cout << *m_myCharacter << *m_curMonster << endl;
      
    }
    // checking if monster is defeated and deleting pointer so that if user chooses to
    // attack again in the same room it will prompt move to next room.
    if (m_curMonster->GetHealth() == ZERO) {
      cout << "You have defeated the "
	   << m_curMonster->GetName() << "!"
	   << endl;
      delete m_curMonster;
      m_curMonster = nullptr;
    } 
  }
}
// Name: Stats()
// Description: Displays the information about the player (name, hp, rests, specials)
// Preconditions: None
// Postconditions: None
void Game::Stats() {

  // displaying the statistics.
  cout << "\nName: " << m_myCharacter->GetName()
       <<  "\nHP: " << m_myCharacter->GetHealth()
       << "\nRests: " << m_numRests
       << "\nSpecial: "  << m_numSpecial
       << endl << endl;
}
