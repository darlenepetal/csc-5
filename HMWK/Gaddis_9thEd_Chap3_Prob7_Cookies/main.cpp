/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 9, 2024, 11:22 AM
 * Purpose: Gaddis_9thEd_Chap3_Prob7_Cookies
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
    short cookies;
    //Initialize or input i.e. set variable values
    cout << "Calorie Counter" << endl;
    cout << "How many cookies did you eat?" << endl;
    cin >> cookies;
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "You consumed " << (cookies * 75) << " calories.";
    //Exit stage right or left!
    return 0;
}