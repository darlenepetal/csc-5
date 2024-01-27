/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 14, 2024, 6:50 PM
 * Purpose: Gaddis_9thEd_Chap4_Prob23_ISP
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
    char    pkg;
    short   hrs;
    float   bill;
    
    //Initialize or input i.e. set variable values
    cout << "ISP Bill" << endl;
    cout << "Input Package and Hours" << endl;
    
    cin >> pkg;
    while (pkg != 'A' && pkg != 'B' && pkg != 'C') {
        cout << "Please select only package A, B, or C" << endl;
        cin >> pkg;
    }
    
    cin >> hrs;
    while (hrs > 744) {
        cout << "Please select a number of hours less than 744" << endl;
        cin >> hrs;
    }
    
    //Map inputs -> outputs
    switch (pkg)
    {
        case 'A':   bill = 9.95;
                    if (hrs > 10) {
                        bill += (hrs - 10) * 2;
                    }
                    break;
        case 'B':   
                    bill = 14.95;
                    if (hrs > 20) {
                        bill += (hrs - 20);
                    }
                    break;
        case 'C':   
                    bill = 19.95;
                    break;
    }
    //Display the outputs
    cout << fixed << setprecision(2) << showpoint;
    cout << "Bill = $" << setw(6) << bill;
    //Exit stage right or left!
    return 0;
}