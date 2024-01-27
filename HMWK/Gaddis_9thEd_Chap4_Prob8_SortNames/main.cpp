/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 12, 2024, 2:44 PM
 * Purpose: Gaddis_9thEd_Chap4_Prob8_SortNames
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const char TOTAL_NAMES = 3;

//Function Prototypes
void addName(string curName, string names[]) {
    string held = curName;
    for (char i = 0; i < TOTAL_NAMES; i++) {
        string compared = names[i];
        if (compared == "") {
            names[i] = held;
            return;
        }
        else if (held < compared) {
            names[i] = held;
            held = compared;
        }        
    }
}

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    string names[TOTAL_NAMES];

    //Initialize or input i.e. set variable values
    cout << "Sorting Names" << endl;
    cout << "Input 3 names" << endl;
    
    //Map inputs -> outputs
    for (char i = 0; i < TOTAL_NAMES; i++) {
        string curName;
        cin >> curName;
        addName(curName, names);
    }
    
    //Display the outputs
    for (char i = 0; i < TOTAL_NAMES; i++) {
        if (i + 1 == TOTAL_NAMES) {
            cout << names[i];
            continue;
        }
        cout << names[i] << endl;
    }
    
    //Exit stage right or left!
    return 0;
}