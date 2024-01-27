/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 12, 2024, 5:07 PM
 * Purpose: Gaddis_9thEd_Chap4_Prob12_BankCharges
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const char OUT_WIDTH = 9;

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    float   feeVar;
    int     iBal;
    short   checNum;
    
    //Initialize or input i.e. set variable values
    cout << "Monthly Bank Fees" << endl;
    cout << "Input Current Bank Balance and Number of Checks" << endl;
    
    cin >> iBal;
    if (iBal < 0) {
        cout << "WARNING: ACCOUNT IS OVERDRAWN" << endl;
    }
    
    cin >> checNum;
    while (checNum < 0) {
        cout << "ERROR: NUMBER OF CHECKS MUST BE POSITIVE" << endl;
        cin >> checNum;
    }
    
    cout << fixed << showpoint << setprecision(2);
    cout << "Balance     $" << setw(OUT_WIDTH) << (float)iBal << endl;
    
    if (checNum < 20) {
        feeVar = checNum * 0.10f;
    }
    else if (checNum < 40) {
        feeVar = checNum * 0.08f;
    }
    else if (checNum < 60) {
        feeVar = checNum * 0.06f;
    }
    else {
        feeVar = checNum * 0.04f;
    }
    
    cout << "Check Fee   $" << setw(OUT_WIDTH) << feeVar << endl;
    cout << "Monthly Fee $" << setw(OUT_WIDTH) << 10.0f << endl;
    feeVar += 10;
    
    if (iBal < 400) {
        cout << "Low Balance $" << setw(OUT_WIDTH) << 15.0f << endl;
        feeVar += 15;
    }
    else {
        cout << "Low Balance $" << setw(OUT_WIDTH) << 0.0f << endl;
    }
    
    //Map inputs -> outputs

    //Display the outputs
    cout << "New Balance $" << setw(OUT_WIDTH) << iBal - feeVar;
    //Exit stage right or left!
    return 0;
}