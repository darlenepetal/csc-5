/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 30, 2024, 9:18 PM
 * Purpose: Savitch_9thEd_Chap5_Prob1_TimeConverter
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>
using namespace std;

//Function Prototypes
bool spltTim(string, short&, short&);
void cnvtTim(short&, char&);
void prntTim(string, short, short, char);

//Execution Begins Here!
int main(int argc, char** argv) {
    
    char    amOrPm,
            again;
    short   hour,
            minute;
    string  inTime;
    
    cout << "Military Time Converter to Standard Time" << endl;
    cout << "Input Military Time hh:mm" << endl;
    
    do {
        hour = minute = 0;
        cin >> inTime;

        if (!spltTim(inTime, hour, minute)) {
            cout << inTime << " is not a valid time" << endl;
        }
        else {
            cnvtTim(hour, amOrPm);
            prntTim(inTime, hour, minute, amOrPm);
        }
        
        cout << "Would you like to convert another time (y/n)" << endl;
        cin >> again;
    } while (again == 'y' || again == 'Y');
    
    
    return 0;
}

bool spltTim(string time, short& hour, short& minute) {
    for (char i = char(0); i < 2; i++) {
        hour += (i == 1)    ? time[i]-48    : (time[i]-48)*10;
        minute += (i == 1)  ? time[i+3]-48  : (time[i+3]-48)*10;
    }
    
    if (hour > 23 || minute > 59) return false;
    else return true;
}

void cnvtTim(short& hour, char& amOrPm) {
    if (hour > 12) {
        hour -= 12;
        amOrPm = 'p';
    }
    else if (hour == 12) {
        amOrPm = 'p';
    }
    else {
        if (hour == 0) hour += 12;
        amOrPm = 'a';
    }
    
    return;
}

void prntTim(string inTime, short hour, short minute, char amOrPm) {
    cout << inTime << " = ";
    cout << hour << ":";
    cout << minute << " ";
    (amOrPm == 'a') ? (cout << "AM") : (cout << "PM");
    cout << endl;
}