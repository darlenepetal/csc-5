/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 11, 2024, 3:03 PM
 * Purpose: Savitch_9thEd_Chap2_Prob2_Pay
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float payIncr = 0.076;

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    short pvAnSal;
    float rPayDue, nwAnSal, nwMnSal;

    //Initialize or input i.e. set variable values
    cout << "Input previous annual salary." << endl;
    cin >> pvAnSal;
    
    //Map inputs -> outputs
    rPayDue = (pvAnSal / 2) * payIncr;
    nwAnSal = pvAnSal + (pvAnSal * payIncr);
    nwMnSal = nwAnSal / 12;
    
    //Display the outputs
    cout << fixed << showpoint << setprecision(2);
    cout << "Retroactive pay    = $";
    cout << setw(7) << rPayDue << endl;
    cout << "New annual salary  = $";
    cout << setw(7) << nwAnSal << endl;
    cout << "New monthly salary = $";
    cout << setw(7) << nwMnSal;
    
    //Exit stage right or left!
    return 0;
}