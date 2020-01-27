 /*******************************************************                                                                                                                                                 
 * Author: MAHMOOD UL MOHASIN AZIZ                                                                                                                                                   
 ********************************************************/


// including libraries.                                                                                                                                                              
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

// Global Constants.                                                                                                                                                                                        
const char RABBIT = 'R';
const char FARMER = 'F';
const char WINNER = 'W';
const char EMPTY = ' ';

const int ROW_COL = 10;
const int MIN = 0;
const int MAX = 9;

/******************************FUNCTION PROTOTYPES*******************************************/

// Function name:  createBoard                                                                                                                                                                              
// Pre-condition:  pass a 2D array of the datatype char.                                                                                                                                                    
// Post-condition: updates the 2D array with empty spaces.                                                                                                                                                  
void createBoard(char playBoard[][ROW_COL]);

// Function name:  updateBoard                                                                                                                                                                              
// Pre-condition:  pass a 2D array, row, col, and character to                                                                                                                                              
//                 update the board.                                                                                                                                                                        
// Post-condition: displays the board with the characters placed                                                                                                                                            
//                 at their respective spots.                                                                                                                                                               
void updateBoard(char interactBoard[][ROW_COL], int myRow, int myCol, char character);

// Function name:  myPlayer                                                                                                                                                                                 
// Pre-condition:  pass the 2D array, and one dimensional array                                                                                                                                             
//                 of the data type int that will hold the user                                                                                                                                             
//                 row and col.                                                                                                                                                                             
// Post-condition: asks the user row and col when game begins and updates                                                                                                                                   
//                 2D array, and 1D array that will hold the user row and col.
void myPlayer(char gameBoard[][ROW_COL], int madeMove[2]);

// Function name:  myMove                                                                                                                                                                                   
// Pre-condition:  pass the 2D board, and the 1D array holding values of                                                                                                                                    
//                 user moves while the game is running.                                                                                                                                                    
// Post-condition: updates the board, and the values of user moves inside the                                                                                                                               
//                 1D array.                                                                                                                                                                                
void myMove(char takeBoard[][ROW_COL], int myBound[2]);

// Function name:  computerPlayer                                                                                                                                                                           
// Pre-condition:  pass the 2D board, and the 1D array holding the values                                                                                                                                   
//                 of computer moves while the game is running.                                                                                                                                             
// Post-condition: updates the board, and the values of computer moves                                                                                                                                      
//                 inside the 1D array.                                                                                                                                                                     
void computerPlayer(char takeBoard[][ROW_COL], int playerRowCol[2], int compRowCol[2]);

// Function name:  computerDirection                                                                                                                                                                        
// Pre-condition:  pass both 1D array's holding the values of                                                                                                                                               
//                 computer's and player's move.                                                                                                                                                            
// Post-condition: determines the direction of the rabbit in relation                                                                                                                                       
//                 to the farmer.                                                                                                                                                                           
void computerDirect(int playerArr[2], int compArr[2]);

// Function name:  checkWinner                                                                                                                                                                              
// Pre-condition:  pass the 1D array's of both the user and the computer.                                                                                                                                   
// Post-condition: rules out if the user won the game by comparing                                                                                                                                          
//                 the values rows and columns.                                                                                                                                                             
bool checkWinner(int player[2], int computer[2]);

/*************************** PROGRAM STARTS HERE *********************************/

int main() {

  // initializing 2D array and calling createBoard() to set empty spaces.                                                                                                                                   
  char myBoard[ROW_COL][ROW_COL] = {};
  createBoard(myBoard);

  // initializinng identifiers to hold random                                                                                                                                                               
  // row/col values for computer.                                                                                                                                                                           
  srand(time(NULL));
  int compRow = rand() % 10;
  int compCol = rand() % 10;
  // array holding the row and col for computer.                                                                                                                                                            
  int comp_row_col[2] = {compRow, compCol};

  // array that will hold the player row and col.                                                                                                                                                           
  int player_row_col[2] = {};

  // identifier to run the while loop each time                                                                                                                                                             
  // after the game ends.                                                                                                                                                                                   
  char myYesOrNo = 'y';

  // while loop to ask the user if they want to play                                                                                                                                                        
  // again.                                                                                                                                                                                                 
  while (myYesOrNo != 'n') {

    // welcome message.                                                                                                                                                                                     
    cout << "\vWelcome to Chase the Rabbit" << endl;

    // calling myPlayer() to begin the game, and in myPlayer()
        // myMove to update the move and board.                                                                                                                                                                 
    myPlayer(myBoard, player_row_col);

    // calling computerPlayer() to make, update and show                                                                                                                                                    
    // the directions of it moves.                                                                                                                                                                          
    computerPlayer(myBoard, player_row_col, comp_row_col);

    // initializing bool flag to run the next loop and calling                                                                                                                                              
    // checkWinner to determine the bool value.                                                                                                                                                             
    bool callCheck = checkWinner(player_row_col, comp_row_col);

    // loop to keep the game running until the user wins.                                                                                                                                                   
    while (callCheck != true) {

      // to get direction from the user while the game is running.                                                                                                                                          
      myMove(myBoard, player_row_col);

      // make computer move after user makes move.                                                                                                                                                          
      computerPlayer(myBoard, player_row_col, comp_row_col);

      // checking again if the user won the game.                                                                                                                                                           
      callCheck = checkWinner(player_row_col, comp_row_col);

      // using condition to print statements if the user                                                                                                                                                    
      // wins the game.                                                                                                                                                                                     
      if (callCheck == true) {
        cout << "The farmer has found the rabbit!\n"
             << "Congrats you've won!"<< endl;
      }
    }
    cout << "\vPlay again? (y/n)" << endl;
    cin >> myYesOrNo;
  }
  return 0;
}

// creates and resets the board every time the move is made.                                                                                                                                                
void createBoard(char playBoard[ROW_COL][ROW_COL]) {

  // updates the 2D array with spaces.                                                                                                                                                                      
  for (int i = 0; i < ROW_COL; i++) {
    for (int j = 0; j < ROW_COL; j++) {
      playBoard[i][j] = EMPTY;
    }

  }
}

void updateBoard(char interactBoard[ROW_COL][ROW_COL], int myRow, int myCol, char character) {

  // setting the character at the given row and col.                                                                                                                                                        
  interactBoard[myRow][myCol] = character;

  // displays and resets the board only after rabbit                                                                                                                                                        
  // makes its move and places FARMER on the board                                                                                                                                                          
  // if user wins the game.                                                                                                                                                                                 
  interactBoard[myRow][myCol] = character;

  if (character == RABBIT || character == WINNER) {

    if (character == WINNER){
      interactBoard[myRow][myCol] = FARMER;
    }

    for (int i = 0; i < ROW_COL; i++) {
      cout << "|" ;
      for (int j = 0; j < ROW_COL; j++) {
        cout << interactBoard[i][j] << "|";
      }
      cout << endl;
    }
    createBoard(interactBoard);
  }
}

// Allows user to choose the bounds they want to start at.                                                                                                                                                  
void myPlayer(char gameBoard[ROW_COL][ROW_COL], int madeMove[2]) {

  // using variables to get the input from the user                                                                                                                                                         
  // for the first time.                                                                                                                                                                                    
  int myRow = 0;
  int myCol = 0;

  cout << "\vWhere would you like to start the farmer? " << endl;

  // getting the column using input validation.                                                                                                                                                             
  cout << "Enter the column(x) (0-9)" << endl;
  cin >> myCol;
  while ((myCol < MIN) || (myCol > MAX)) {
    cout << "Please enter between (0-9)" << endl;
    cin >> myCol;
  }

  // getting the column using input validation.                                                                                                                                                             
  cout << "Enter the row(y) (0-9)" << endl;
  cin >> myRow;
  while ((myRow < MIN) || (myRow > MAX)) {
    cout << "Please enter between (0-9)" << endl;
    cin >> myRow;
  }

  // assigning the input values to the array.                                                                                                                                                               
  madeMove[0] = myRow;
  madeMove[1] = myCol;

  // calling myMove to ask user which direction                                                                                                                                                             
  // they want to move in.                                                                                                                                                                                  
  myMove(gameBoard, madeMove);

}

// Allows user to decide their moves.                                                                                                                                                                       
void myMove(char takeBoard[ROW_COL][ROW_COL], int myBound[2]) {

  // identifier to store the user choice.                                                                                                                                                                   
  int myChoice = 0;

  // using input validation to get the choice.
                                                                                                                                                                
  do {
    cout << "\vWhat would you like to do?" << endl;
    cout<< "1. Search north.\n";
    cout<< "2. Search east.\n";
    cout<< "3. Search south.\n";
    cout<< "4. Search west.\n";

    cin >> myChoice;

  } while ((myChoice < 1) || (myChoice > 4));

  // switch cases that will determine what to do based                                                                                                                                                      
  // upon the choice the user made.                                                                                                                                                                         
  switch (myChoice) {

  case 1:
    if (myBound[0] != MIN) {
      myBound[0] = myBound[0] - 1;
      cout << "The farmer moves north" << endl;
      updateBoard(takeBoard, myBound[0], myBound[1], FARMER);
    }
    else {
      cout << "The farmer can't leave the field" << endl;
      updateBoard(takeBoard, myBound[0], myBound[1], FARMER);
    }
    break;

  case 2:
    if (myBound[1] != MAX) {
      myBound[1] = myBound[1] + 1;
      cout << "The farmer moves east" << endl;
      updateBoard(takeBoard, myBound[0], myBound[1], FARMER);
    }
    else {
      cout << "The farmer can't leave the field" << endl;
      updateBoard(takeBoard, myBound[0], myBound[1], FARMER);
    }
    break;

  case 3:
    if (myBound[0] != MAX) {
      myBound[0] = myBound[0] + 1;
      cout << "The farmer moves south" << endl;
      updateBoard(takeBoard, myBound[0], myBound[1], FARMER);
    }
    else {
      cout << "The farmer can't leave the field" << endl;
      updateBoard(takeBoard, myBound[0], myBound[1], FARMER);
    }
    break;

  case 4:
    if (myBound[1] != MIN) {
      myBound[1] = myBound[1] - 1;
      cout << "The farmer moves west" << endl;
      updateBoard(takeBoard, myBound[0], myBound[1], FARMER);
    }
  else {
        cout << "The farmer can't leave the field" << endl;
        updateBoard(takeBoard, myBound[0], myBound[1], FARMER);
    } 
    break;
  
  }

}

void computerPlayer(char takeBoard[ROW_COL][ROW_COL], int playerRowCol[2], int compRowCol[2]) {

  // identifier holding the random value for computer choice.                                                                                                                                               
  int randomOne = rand() % 5;
  bool checkWin;

  // switch cases to determine the moves the computer will make                                                                                                                                             
  // based upon the random value generated.                                                                                                                                                                 
  switch (randomOne)  {
    // case 0 moves no where.                                                                                                                                                                               
  case 0:
    cout << "The rabbit nibbles on some food and decides to stay there " << endl;
    computerDirect(playerRowCol, compRowCol);
    checkWin = checkWinner(playerRowCol, compRowCol);
    if (checkWin == true) {
      updateBoard(takeBoard, compRowCol[0], compRowCol[1], WINNER);
    } else {
      updateBoard(takeBoard, compRowCol[0], compRowCol[1], RABBIT);
    }
    break;
   // case 1 for north.                                                                                                                                                                                    
  case 1:

    if (compRowCol[0] != MIN) {
      compRowCol[0] = compRowCol[0] - 1;
      cout << "The rabbit moves to another location in search of food " << endl;
      computerDirect(playerRowCol, compRowCol);
      checkWin = checkWinner(playerRowCol, compRowCol);
      if (checkWin == true) {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], WINNER);
      } else {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], RABBIT);
      }

    } else {
      cout << "The rabbit nibbles on some food and decides to stay there " << endl;
      computerDirect(playerRowCol, compRowCol);
      checkWin = checkWinner(playerRowCol, compRowCol);
      if (checkWin == true) {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], WINNER);
      } else {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], RABBIT);
      }
    }
    break;
    // case 2 moves east.                                                                                                                                                                                   
  case 2:
    if (compRowCol[1] != MAX) {
      compRowCol[1] = compRowCol[1] + 1;
      cout << "The rabbit moves to another location in search of food " << endl;
      computerDirect(playerRowCol, compRowCol);
      checkWin = checkWinner(playerRowCol, compRowCol);
      if (checkWin == true) {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], WINNER);
      } else {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], RABBIT);
      }
    } else {
      cout << "The rabbit nibbles on some food and decides to stay there " << endl;
      computerDirect(playerRowCol, compRowCol);
      checkWin = checkWinner(playerRowCol, compRowCol);
      if (checkWin == true) {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], WINNER);
      } else {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], RABBIT);
      }
    }
    break;
    // case 3 moves south.                                                                                                                                                                                  
  case 3:
    if (compRowCol[0] != MAX) {
      compRowCol[0] = compRowCol[0] + 1;
      cout << "The rabbit moves to another location in search of food "  << endl;
      computerDirect(playerRowCol, compRowCol);
      checkWin = checkWinner(playerRowCol, compRowCol);
      if (checkWin == true) {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], WINNER);
      } else {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], RABBIT);
      }
    } else {
      cout << "The rabbit nibbles on some food and decides to stay there " << endl;
      computerDirect(playerRowCol, compRowCol);
      checkWin = checkWinner(playerRowCol, compRowCol);
      if (checkWin == true) {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], WINNER);
      } else {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], RABBIT);
      }
    }
    break;
    // case 4 moves west.                                                                                                                                                                                   
  case 4:
    if (compRowCol[1] != MIN) {
      compRowCol[1] = compRowCol[1] - 1;
      cout << "The rabbit moves to another location in search of food " << endl;
      computerDirect(playerRowCol, compRowCol);
      checkWin = checkWinner(playerRowCol, compRowCol);
      if (checkWin == true) {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], WINNER);
      } else {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], RABBIT);
      }

    } else {
      cout << "The rabbit nibbles on some food and decides to stay there " << endl;
      computerDirect(playerRowCol, compRowCol);
      checkWin = checkWinner(playerRowCol, compRowCol);
      if (checkWin == true) {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], WINNER);
      } else {
      cout << "The rabbit nibbles on some food and decides to stay there " << endl;
      computerDirect(playerRowCol, compRowCol);
      checkWin = checkWinner(playerRowCol, compRowCol);
      if (checkWin == true) {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], WINNER);
      } else {
        updateBoard(takeBoard, compRowCol[0], compRowCol[1], RABBIT);
      }
    }
    break;
    }
  }
}

// To check the directions of the rabbit.                                                                                                                                                                   

void computerDirect(int playerArr[2], int compArr[2]) {

  // condition that checks if the rabbit is east or west to the farmer                                                                                                                                      
  // by comparing the absolute values of rows and columns.                                                                                                                                                  
  if (((abs(compArr[1] - playerArr[1])) >= (abs(compArr[0] - playerArr[0]))) || (compArr[0] == playerArr[0])) {

    if (compArr[1] > playerArr[1]) {
      cout << "The rabbit is east of the farmer " << endl;
    }
    else if (compArr[1] < playerArr[1]) {
      cout << "The rabbit is west of the farmer " << endl;
    }
  }

  // condition that checks if the rabbit is south or north to the farmer                                                                                                                                    
  // by comparing the absolute values of rows and columns.                                                                                                                                                  
  else if (((abs(compArr[1] - playerArr[1])) <= (abs(compArr[0] - playerArr[0]))) || (compArr[1] == playerArr[1])) {

    if (compArr[0] > playerArr[0]) {
      cout << "The rabbit is south of the farmer " << endl;
    }
    else if (compArr[0] < playerArr[0]) {
      cout << "The rabbit is north of the farmer " << endl;
    }
  }
}
//checks if the user won.                                                                                                                                                                                   
bool checkWinner(int player[2], int computer[2]) {

  // initializing identifier.                                                                                                                                                                               
  bool myBool = false;

  // comparing the values and returning true if they're the same.                                                                                                                                           
  if ((computer[0] == player[0]) && (computer[1] == player[1])) {
    myBool = true;
  }

  return myBool;
}
