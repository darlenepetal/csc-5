/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 11, 2024, 3:47 PM
 * Purpose: Savitch_9thEd_Chap2_Prob9_Sums
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
    short posSum, negSum, allSum;

    //Initialize or input i.e. set variable values
    cout << "Input 10 numbers, any order, positive or negative" << endl;
    posSum = 0;
    negSum = 0;
    allSum = 0;

    //Map inputs -> outputs
    for (char i = 0; i < 10; i++) {
        short currNum;
        cin >> currNum;

        (currNum>0) ? (posSum+=currNum) : (negSum+=currNum);
        allSum += currNum;
    }
    //Display the outputs
    cout << "Negative sum =" << setw(4) << negSum << endl;
    cout << "Positive sum =" << setw(4) << posSum << endl;
    cout << "Total sum    =" << setw(4) << allSum;
    //Exit stage right or left!
    return 0;
}