/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 16, 2024, 5:29 PM
 * Purpose: Gaddis_9thEd_Chap5_Prob23_Pattern
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
    short input;
    //Initialize or input i.e. set variable values
    cin >> input;
    //Map inputs -> outputs
    for (short i = 1; i <= input; i++) {
        for (short j = i; j > 0; j--) {
            cout << "+";
        }
        cout << endl << endl;
    }
    for (short i = input; i > 0; i--) {
        for (short j = i; j > 0; j--) {
            cout << "+";
        }
        if (i != 1) {
            cout << endl << endl;
        }
    }
    //Display the outputs

    //Exit stage right or left!
    return 0;
}