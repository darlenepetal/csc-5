/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 16, 2024, 4:38 PM
 * Purpose: Gaddis_9thEd_Chap5_Prob1_Sum
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
    short   input;
    int     sum;
    //Initialize or input i.e. set variable values
    cin >> input;
    while (input < 0) {
        cout << "Please enter a positive number." << endl;
        cin >> input;
    }
    sum = 0;
    //Map inputs -> outputs
    while (input > 0) {
        sum += input;
        input -= 1;
    }
    //Display the outputs
    cout << "Sum = " << sum;
    //Exit stage right or left!
    return 0;
}