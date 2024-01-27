/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 19, 2024, 9:13 AM
 * Purpose: Savitch_9Ed_Chap4_Prob4_Inflation
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
float inf_rate(float curPric, float oldPric);

//Execution Begins Here!

int main(int argc, char** argv) {

    char again;
    again = 'y';
    
    while (again == 'y') {
        float curPric, oldPric;
        
        cout << "Enter current price:" << endl;
        cin >> curPric;
        cout << "Enter year-ago price:" << endl;
        cin >> oldPric;
        
        cout << fixed << setprecision(2) << showpoint;
        cout << "Inflation rate: " << inf_rate(curPric, oldPric);
        cout << "%" << endl << endl;
        
        cout << "Again:" << endl;
        cin >> again;
        if (tolower(again) == 'y') {
            cout << endl;
        }
    }

    //Exit stage right or left!
    return 0;
}

float inf_rate(float curPric, float oldPric) {
    return (curPric - oldPric) / oldPric * 100;
}