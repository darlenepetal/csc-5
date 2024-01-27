/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 19, 2024, 10:14 AM
 * Purpose: Savitch_9Ed_Chap4_Prob5_EstCost
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
float inf_price(float curPric, float infPerc);

//Execution Begins Here!

int main(int argc, char** argv) {

    char again;
    again = 'y';
    
    while (again == 'y') {
        float curPric, oldPric, infPerc, ftrPric;
        
        cout << "Enter current price:" << endl;
        cin >> curPric;
        cout << "Enter year-ago price:" << endl;
        cin >> oldPric;
        infPerc = inf_rate(curPric, oldPric);
        ftrPric = inf_price(curPric, infPerc);
        
        cout << fixed << setprecision(2) << showpoint;
        cout << "Inflation rate: " << infPerc;
        cout << "%" << endl << endl;
        cout << "Price in one year: $" << ftrPric << endl;
        cout << "Price in two year: $";
        cout << inf_price(ftrPric, infPerc) << endl << endl;
        
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

float inf_price(float curPric, float infPerc) {
    return curPric + (curPric * (infPerc / 100));
}