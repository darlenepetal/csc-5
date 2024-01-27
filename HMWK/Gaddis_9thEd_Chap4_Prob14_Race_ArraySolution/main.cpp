/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 13, 2024, 5:57 PM
 * Purpose: Gaddis_9thEd_Chap4_Prob14_Race
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const char NUM_RUNNERS = 5;
const char OUT_WIDTH = 3;

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    string rnrName[NUM_RUNNERS];
    short rnrTime[NUM_RUNNERS];

    //Initialize or input i.e. set variable values
    cout << "Race Ranking Program" << endl;
    cout << "Input 3 Runners" << endl;
    cout << "Their names, then their times" << endl;
    
    for (char i = 0; i < NUM_RUNNERS; i++) {
        cin >> rnrName[i] >> rnrTime[i];
        while (rnrTime[i] < 0) {
            cout << "Runner time must be a positive number." << endl;
            cin >> rnrTime[i];
        }
    }
    
    for (short i = 0; i < NUM_RUNNERS - 1; i++) {
        bool swapped = false;
        for (short j = 0; j < NUM_RUNNERS - i - 1; j++) {
            short   time1 = rnrTime[j];
            string  name1 = rnrName[j];
            short   time2 = rnrTime[j + 1];
            string  name2 = rnrName[j + 1];
            if (time2 < time1) {
                rnrTime[j]      = time2;
                rnrTime[j + 1]  = time1;
                rnrName[j]      = name2;
                rnrName[j + 1]  = name1;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
    
    //Map inputs -> outputs

    //Display the outputs
    for (char i = 0; i < NUM_RUNNERS; i++) {
        cout << rnrName[i] << "\t" << setw(OUT_WIDTH) << rnrTime[i];
        if (i + 1 != NUM_RUNNERS) {
            cout << endl;
        }
    }
    //Exit stage right or left!
    return 0;
}