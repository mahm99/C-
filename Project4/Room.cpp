/*************************************************************                                     
* File: Room.cpp                                                                                                                                             
* Author: Mahmood Ul Mohasin Aziz                                                                                                                                            
* Description:                                                                                    
* This file contains program code for the class Room.h.
* This class mainly handles the program execution related
* to room objects including setting the room values and
* descriptions. It also allows Game.cpp to print room info.
************************************************************/
#include "Room.h"

//Name: Room (Overloaded Constructor)                                                             
//Precondition: Must have valid input for each part of a room                                     
//Postcondition: Creates a new room                                                               
Room::Room(int myID, string myRoom, string myDesc, int north, int east, int south, int west) {
  // setting member variables.
  m_ID = myID;
  m_name = myRoom;
  m_desc = myDesc;
  m_direction[N] = north;
  m_direction[E] = east;
  m_direction[S] = south;
  m_direction[W] = west;

}

//Name: GetName                                                                                   
//Precondition: Must have valid room                                                              
//Postcondition: Returns room name as string                                                      
string Room::GetName() {
  return m_name;
}

//Name: GetID                                                                                     
//Precondition: Must have valid room                                                              
//Postcondition: Returns room id as int                                                           
int Room::GetID() {
  return m_ID;
}

//Name: GetDesc                                                                                   
//Precondition: Must have valid room                                                              
//Postcondition: Returns room desc as string                                                      
string Room::GetDesc() {
  return m_desc;
}

//Name: CheckDirection                                                                            
//Precondition: Must have valid room                                                              
//You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it                       
//returns the ID of the room in that direction                                                    
//Postcondition: Returns id of room in that direction if the exit exists                          
//If there is no exit in that direction, returns -1                                               
int Room::CheckDirection(char myDirection) {

  // conditions to validate input, and return direction.
  int direction = 0;
  if ((myDirection == 'N') || (myDirection == 'n')) {
    direction = m_direction[n];
  }
  else if ((myDirection == 'E') || (myDirection == 'e')) {
    direction = m_direction[e]; 
  }
  else if ((myDirection == 'S') || (myDirection == 's')) {
    direction = m_direction[s];
  }
  else if ((myDirection == 'W') || (myDirection == 'w')) {
   direction = m_direction[w];
  }
  return direction;
}

//Name: PrintRoom                                                                                 
//Precondition: Room must be complete                                                             
//Postcondition: Outputs the room name, room desc, then possible exits                            
void Room::PrintRoom() {

  // room name and desc.
  cout << "\v" << m_name
       << "\n" << m_desc
       << endl;

  // possible exits.
  cout << "Possible Exits: ";
  for (int i = 0; i < 4; i++) {
    if (m_direction[i] != -1) {
      if (i == 0) {
	cout << "N";
      }
      else if (i == 1) {
	cout << " E";
      }
      else if (i == 2) {
	cout << " S";
      }
      else if (i == 3) {
	cout << " W";
      }
    }
  }
  cout << endl << endl;
}
