/**********************************************************
 * File:        proj2.cpp
 * Author:      Mahmood Ul Mohasin Aziz
 * 
 * This file contains c++ program code for the game 
 * Harry potter - Wizards Unite. The main function calls
 * the class Game which handles the program from the 
 * the beginning to the end.
 ********************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Foundable.h"
#include "Wizard.h"
#include "Game.h"

using namespace std;

int main () {
  srand(time(NULL));
  Game();
  return 0;
}
