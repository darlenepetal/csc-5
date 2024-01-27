/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 19, 2024, 11:09 AM
 * Purpose: Savitch_9Ed_Chap4_Prob9_2or3Max
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
float max(float param1, float param2);
float max(float param1, float param2, float param3);

//Execution Begins Here!

int main(int argc, char** argv) {
    
    float params[3];
    
    cout << "Enter first number:" << endl;
    cin >> params[0];
    cout << endl << "Enter Second number:" << endl;
    cin >> params[1];
    cout << endl << "Enter third number:" << endl;
    cin >> params[2];
    
    cout << fixed << setprecision(1) << showpoint;
    cout << endl << "Largest number from two parameter function:" << endl;
    cout << max(params[0], params[1]) << endl;
    
    cout << endl << "Largest number from three parameter function:" << endl;
    cout << max(params[0], params[1], params[2]) << endl;
    return 0;
}

float max(float param1, float param2) {
    float temp = (param1 > param2) ? param1 : param2;
    return temp;
}

float max(float param1, float param2, float param3) {
    float temp = max(param1, param2);
    if (param3 > temp) temp = param3;
    return temp;
}