/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 31, 2024, 12:29 PM
 * Purpose: Gaddis_9thEd_Chap6_Prob10_Average
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void    getScre(int&, int&, int&, int&, int&);
float   calcAvg(int, int, int, int, int);
int     fndLwst(int, int, int, int, int);

int main(int argc, char** argv) {
    
    //Declare Variables
    int v1,
        v2,
        v3,
        v4,
        v5;

    //Initialize or input i.e. set variable values
    cout << "Find the Average of Test Scores" << endl;
    cout << "by removing the lowest value." << endl;
    cout << "Input the 5 test scores." << endl;

    //Map inputs -> outputs
    getScre(v1, v2, v3, v4, v5);

    //Display the outputs
    cout << fixed << setprecision(1) << showpoint;
    cout << "The average test score = " << calcAvg(v1, v2, v3, v4, v5);

    //Exit stage right or left!
    return 0;
}

void getScre(int& v1, int& v2, int& v3, int& v4, int& v5) {
    do cin >> v1; while (v1 < 1 || v1 > 100);
    do cin >> v2; while (v2 < 1 || v2 > 100);
    do cin >> v3; while (v3 < 1 || v3 > 100);
    do cin >> v4; while (v4 < 1 || v4 > 100);
    do cin >> v5; while (v5 < 1 || v5 > 100);
    return;
}

float calcAvg(int v1, int v2, int v3, int v4, int v5) {
    int lowest = fndLwst(v1, v2, v3, v4, v5);
    return (v1 + v2 + v3 + v4 + v5 - lowest) / 4;
}

int fndLwst(int v1, int v2, int v3, int v4, int v5) {
    int lowest = v1;
    if (v2 < lowest) lowest = v2;
    if (v3 < lowest) lowest = v3;
    if (v4 < lowest) lowest = v4;
    if (v5 < lowest) lowest = v5;
    return lowest;
}