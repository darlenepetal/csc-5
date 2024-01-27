/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 10, 2024, 5:32 PM
 * Purpose: Paycheck
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    short payRate, hours, hoursOT;
    float paycheck;

    //Initialize or input i.e. set variable values
    cout << "This program calculates the gross paycheck." << endl;
    cout << "Input the pay rate in $'s/hr and the number of hours." << endl;
    cin >> payRate >> hours;
    hoursOT = 0;
    
    //Map inputs -> outputs
    if (hours > 40) {
        hoursOT = (hours - 40);
        hours = 40;
    }
    
    paycheck = (hours * payRate) + (hoursOT * (payRate * 2));
    
    //Display the outputs
    cout << fixed << setprecision(2);
    cout << "Paycheck = $" << setw(7) << paycheck;
    //Exit stage right or left!
    return 0;
}