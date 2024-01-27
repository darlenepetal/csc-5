/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 19, 2024, 8:57 AM
 * Purpose: Savitch_9Ed_Chap4_Prob2_FuelEff
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float L_PER_G = 0.264179f;

//Function Prototypes
float calc_mpg(short miles, short liters);

//Execution Begins Here!

int main(int argc, char** argv) {
    
    char again;
    again = 'y';
    
    while (again == 'y') {
        short   liters[2], miles[2];
        float   mpg[2];
        
        for (char i = 0; i < 2; i++) {
            cout << "Car " << i + 1 << endl;
            cout << "Enter number of liters of gasoline:" << endl;
            cin >> liters[i];

            cout << "Enter number of miles traveled:" << endl;
            cin >> miles[i];

            mpg[i] = calc_mpg(miles[i], liters[i]);

            cout << "miles per gallon: ";
            cout << fixed << setprecision(2) << showpoint;
            cout << mpg[i] << endl << endl;
        }
        
        if (mpg[0] > mpg[1]) {
            cout << "Car 1 is more fuel efficient" << endl << endl;
        }
        else if (mpg[0] < mpg[1]) {
            cout << "Car 2 is more fuel efficient" << endl << endl;
        }
        else {
            cout << "Both cars are equally fuel efficient" << endl << endl;
        }
        
        cout << "Again:" << endl;
        cin >> again;
        if (tolower(again) == 'y') {
            cout << endl;
        }
    }

    //Exit stage right or left!
    return 0;
}

float calc_mpg(short miles, short liters) {
    return miles / (liters * L_PER_G);
}