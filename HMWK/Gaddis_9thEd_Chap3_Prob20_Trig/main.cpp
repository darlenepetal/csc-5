/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 9, 2024, 5:30 PM
 * Purpose: Gaddis_9thEd_Chap3_Prob20_Trig
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float PI = 3.14159265;
//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    short degrees;
    float outSin, outCos, outTan;
    //Initialize or input i.e. set variable values
    cout << "Calculate trig functions" << endl;
    cout << "Input the angle in degrees." << endl;
    cin >> degrees;
    //Map inputs -> outputs
    outSin = sin(degrees * PI / 180.0);
    outCos = cos(degrees * PI / 180.0);
    outTan = tan(degrees * PI / 180.0);
    //Display the outputs
    cout << fixed << setprecision(4);
    cout << "sin(" << degrees << ") = " << outSin << endl;
    cout << "cos(" << degrees << ") = " << outCos << endl;
    cout << "tan(" << degrees << ") = " << outTan;
    //Exit stage right or left!
    return 0;
}