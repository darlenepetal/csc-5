/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 15, 2024, 2:58 PM
 * Purpose: Savitch_9thEd_Chap3_Prob3_Roman_Conversion
 *          Is this solution goofy? Probably.
 *          But you can't say it doesn't work!
 *          And, hey, it uses less memory!
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    short   araYear;
    string  romYear;
    
    //Initialize or input i.e. set variable values
    cout << "Arabic to Roman numeral conversion." << endl;
    cout << "Input the integer to convert." << endl;
    
    cin >> araYear;
    if (araYear < 1000 || araYear > 3000) {
        cout << araYear << " is Out of Range!";
        return 0;
    }
    
    cout << araYear << " is equal to ";
    
    //Map inputs -> outputs
    while (araYear >= 1000) {
        romYear += "M";
        araYear -= 1000;
    }
    while (araYear >= 900) {
        romYear += "CM";
        araYear -= 900;
    }
    while (araYear >= 500) {
        romYear += "D";
        araYear -= 500;
    }
    while (araYear >= 400) {
        romYear += "CD";
        araYear -= 400;
    }
    while (araYear >= 100) {
        romYear += "C";
        araYear -= 100;
    }
    while (araYear >= 90) {
        romYear += "XC";
        araYear -= 90;
    }
    while (araYear >= 50) {
        romYear += "L";
        araYear -= 50;
    }
    while (araYear >= 40) {
        romYear += "XL";
        araYear -= 40;
    }
    while (araYear >= 10) {
        romYear += "X";
        araYear -= 10;
    }
    while (araYear >= 9) {
        romYear += "IX";
        araYear -= 9;
    }
    while (araYear >= 5) {
        romYear += "V";
        araYear -= 5;
    }
    while (araYear >= 4) {
        romYear += "IV";
        araYear -= 4;
    }
    while (araYear >= 1) {
        romYear += "I";
        araYear -= 1;
    }

    //Display the outputs
    cout << romYear;
    //Exit stage right or left!
    return 0;
}