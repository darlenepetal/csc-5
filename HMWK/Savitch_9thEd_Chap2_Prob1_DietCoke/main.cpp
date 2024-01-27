/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 10, 2024, 6:38 PM
 * Purpose: Savitch_9thEd_Chap2_Prob1_DietCoke
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const char lethlGs = 5;
const char mouseGs = 35;
const float humnGs = 45359.2;
const float gPerCan = 0.001f * 350;
const float humnCan = (((float)lethlGs/mouseGs)*humnGs)/gPerCan;

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    float userLbs, userGs;
    int userCan;
    
    //Initialize or input i.e. set variable values
    cout << "Program to calculate the limit of Soda Pop Consumption." << endl;
    cout << "Input the desired dieters weight in lbs." << endl;
    cin >> userLbs;
    
    userGs = userLbs * (humnGs / 100);
    userCan = (userGs/humnGs) * humnCan;
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "The maximum number of soda pop cans" << endl;
    cout << "which can be consumed is " << userCan << " cans";
    //Exit stage right or left!
    return 0;
}