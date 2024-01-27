/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 17, 2024, 10:56 AM
 * Purpose: Savitch_9thEd_Chap4_Prob1_MPG
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float L_PER_G = 0.264179f;

//Function Prototypes
float calc_mpg(short miles, short liters);

//Execution Begins Here!

int main(int argc, char** argv) {
    
    char again;
    again = 'y';
    
    while (again == 'y') {
        short   liters, miles;
        float   mpg;
        
        cout << "Enter number of liters of gasoline:" << endl << endl;
        cin >> liters;
        
        cout << "Enter number of miles traveled:" << endl << endl;
        cin >> miles;
        
        cout << "miles per gallon:" << endl;
        cout << fixed << setprecision(2) << showpoint;
        cout << calc_mpg(miles, liters) << endl;
        
        cout << "Again:" << endl;
        cin >> again;
        again = tolower(again);
        if (again == 'y') {
            cout << endl;
        }
    }

    return 0;
}

float calc_mpg(short miles, short liters) {
    return miles / (liters * L_PER_G);
}