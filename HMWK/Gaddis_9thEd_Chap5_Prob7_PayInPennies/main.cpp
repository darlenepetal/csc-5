/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 16, 2024, 4:43 PM
 * Purpose: Gaddis_9thEd_Chap5_Prob7_PayInPennies
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
    short   days;
    double  temp;
    double  pay;
    //Initialize or input i.e. set variable values
    cin >> days;
    while (days < 1) {
        cout << "Days entered must be greater than zero.";
        cin >> days;
    }
    pay = 0;
    temp = 0.01;
    //Map inputs -> outputs
    for (short i = 1; i <= days; i++) {
        pay += temp;
        temp *= 2;
    }
    //Display the outputs
    cout << fixed << setprecision(2) << showpoint;
    cout << "Pay = $" << pay;
    //Exit stage right or left!
    return 0;
}