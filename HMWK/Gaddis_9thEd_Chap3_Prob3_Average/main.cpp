/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 8, 2024, 5:18 PM
 * Purpose: Gaddis_9thEd_Chap3_Prob3_Average
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
    float average = 0;
    //Initialize or input i.e. set variable values
    cout << "Input 5 numbers to average." << endl;
    
    for (char i = 0; i < 5; i++) {
        float score;
        cin >> score;
        average += score;
    }
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "The average = ";
    cout << fixed << setprecision(1) << (average / 5);
    //Exit stage right or left!
    return 0;
}