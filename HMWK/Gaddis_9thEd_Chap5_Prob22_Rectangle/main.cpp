/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 16, 2024, 5:15 PM
 * Purpose: Gaddis_9thEd_Chap5_Prob22_Rectangle
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
    short   inSize;
    char    inChar;

    //Initialize or input i.e. set variable values
    cin >> inSize >> inChar;

    //Display the outputs
    for (short i = inSize; i > 0; i--) {
        for (short j = inSize; j > 0; j--) {
            cout << inChar;
        }
        if (i != 1) {
            cout << endl;
        }
    }
    
    //Exit stage right or left!
    return 0;
}