/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 15, 2024, 4:01 PM
 * Purpose: Savitch_9thEd_Chap3_PracProb4_CompatibleSigns
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
string getSign() {
    string input;
    string signs[12] = {
        "Cancer", "Scorpio", "Pisces", "Aries", 
        "Leo", "Sagittarius", "Taurus", "Virgo", 
        "Capricorn", "Gemini", "Libra", "Aquarius" 
    };
    bool error = false;
    
    do {
        if (error == true) {
            cout << "User must input a valid horoscope sign." << endl;
        }
        cin >> input;
        error = true;
        
        input[0] = toupper(input[0]);
        for (short i = 1; i < sizeof(input)/sizeof(input[0]); i++) {
            input[i] = tolower(input[i]);
        }
        
        for (short i = 0; i < 12; i++) {
            if (signs[i] == input) {
                error = false;
                break;
            }
        }
    }
    while (error == true);
    
    return input;
}

string getElem(string sign) {
    string elem;
    if (sign == "Cancer" || sign == "Scorpio" || sign == "Pisces") {
        elem = "Water";
    }
    else if (sign == "Gemini" || sign == "Libra" || sign == "Aquarius") {
        elem = "Air";
    }
    else if (sign == "Taurus" || sign == "Virgo" || sign == "Capricorn") {
        elem = "Earth";
    }
    else if (sign == "Aries" || sign == "Leo" || sign == "Sagittarius") {
        elem = "Fire";
    }
    return elem;
}
//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    string  sign1, sign2, elem1, elem2;

    //Initialize or input i.e. set variable values
    cout << "Horoscope Program which examines compatible signs." << endl;
    cout << "Input 2 signs." << endl;
    
    sign1 = getSign();
    sign2 = getSign();
    
    elem1 = getElem(sign1);
    elem2 = getElem(sign2);
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << sign1 << " and " << sign2 << " are ";
    if (elem1 != elem2) {
        cout << "not compatible signs.";
    }
    else {
        cout << "compatible " << elem1 << " signs.";
    }
    //Exit stage right or left!
    return 0;
}