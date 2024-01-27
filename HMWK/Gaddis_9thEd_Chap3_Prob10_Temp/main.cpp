/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 9, 2024, 11:46 AM
 * Purpose: Gaddis_9thEd_Chap3_Prob10_Temp
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float cToF = 5.0f/9.0f;

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    float inTemp;
    
    //Initialize or input i.e. set variable values
    cout << "Temperature Converter" << endl;
    cout << "Input Degrees Fahrenheit" << endl;
    cin >> inTemp;
    //Map inputs -> outputs
    
    //Display the outputs
    cout << fixed << setprecision(1);
    cout << inTemp << " Degrees Fahrenheit = ";
    cout << ((inTemp - 32) * cToF) << " Degrees Centigrade";
    //Exit stage right or left!
    return 0;
}