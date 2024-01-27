/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 9, 2024, 11:37 AM
 * Purpose: Gaddis_9thEd_Chap3_Prob8_Insurance
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
    float housVal;
    //Initialize or input i.e. set variable values
    cout << "Insurance Calculator" << endl;
    cout << "How much is your house worth?" << endl;
    cin >> housVal;
    //Map inputs -> outputs

    //Display the outputs
    cout << "You need $" << (housVal * 0.8f) << " of insurance.";
    //Exit stage right or left!
    return 0;
}