/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 16, 2024, 4:57 PM
 * Purpose: Gaddis_9thEd_Chap5_Prob13_MinMax
 */

//System Libraries
#include <iostream> //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    int     smallest, largest;
    short   i;
    
    //Initialize or input i.e. set variable values
    i = 0;
    while (true) {
        int temp;
        cin >> temp;
        if (temp == -99) {
            break;
        }
        else if (i == 0) {
            smallest = temp;
            largest = temp;
            i++;
        }
        else if (temp > largest) {
            largest = temp;
        }
        else if (temp < smallest) {
            smallest = temp;
        }
    }
    
    //Display the outputs
    cout << "Smallest number in the series is " << smallest << endl;
    cout << "Largest  number in the series is " << largest;
    //Exit stage right or left!
    return 0;
}