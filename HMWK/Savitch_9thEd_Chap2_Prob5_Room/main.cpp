/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 11, 2024, 3:41 PM
 * Purpose: Savitch_9thEd_Chap2_Prob5_Room
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    short maxPpl, numPpl;

    //Initialize or input i.e. set variable values
    cout << "Input the maximum room capacity and the number of people" << endl;
    cin >> maxPpl >> numPpl;
    //Map inputs -> outputs
    
    if (numPpl >= maxPpl) {
        cout << "Meeting cannot be held." << endl;
        cout << "Reduce number of people by " << numPpl - maxPpl;
        cout << " to avoid fire violation.";
    } else {
        cout << "Meeting can be held." << endl;
        cout << "Increase number of people by " << maxPpl - numPpl;
        cout << " will be allowed without violation.";
    }

    //Display the outputs

    //Exit stage right or left!
    return 0;
}