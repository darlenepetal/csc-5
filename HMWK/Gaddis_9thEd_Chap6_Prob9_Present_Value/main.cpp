/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 31, 2024, 11:09 AM
 * Purpose: Gaddis_9thEd_Chap6_Prob9_Present_Value
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <cmath>
using namespace std;

//Function Prototypes
float psntVal(float, float, int);

int main(int argc, char** argv) {

    //Declare Variables
    int     years;
    float   endAmnt, 
            intRate;

    //Initialize or input i.e. set variable values
    cout << "This is a Present Value Computation" << endl;
    cout << "Input the Future Value in Dollars" << endl;
    cin >> endAmnt;
    cout << "Input the Number of Years" << endl;
    cin >> years;
    cout << "Input the Interest Rate %/yr" << endl;
    cin >> intRate;
    intRate /= 100;

    cout << fixed << setprecision(2) << showpoint;
    cout << "The Present Value = $" << psntVal(endAmnt, intRate, years);

    return 0;
}

float psntVal(float end, float rate, int yrs) {
    return end/pow(1+rate, yrs);
}