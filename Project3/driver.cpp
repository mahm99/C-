/**********************************************************
* File:        driver.cpp
* Author:      Mahmood Ul Mohasin Aziz
* 
* Description:
* This file contains the main function that calls the
* Decay class to run the simulation  and the control is
* passed over to Decay until the user chooses to quit.
********************************************************/

#include "Decay.h"
#include "Node.h"
#include "DecayList.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
  
  srand(time(nullptr));

  Decay simulation;
  
  simulation.Start();

  return 0;
}

