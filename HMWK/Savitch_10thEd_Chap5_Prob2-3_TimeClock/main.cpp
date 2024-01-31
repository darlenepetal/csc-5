/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 30, 2024, 2:27 PM
 * Purpose: Savitch_10thEd_Chap5_Prob2-3_TimeClock
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
    
    char    amOrPm,
            again;
    short   hour,
            minute,
            wait;
         
    do {
        cout << "Enter hour:" << endl;
        cin >> hour;
        cout << endl;
        
        cout << "Enter minutes:" << endl;
        cin >> minute;
        cout << endl;
        
        cout << "Enter A for AM, P for PM:" << endl;
        cin >> amOrPm;
        cout << endl;
        
        cout << "Enter waiting time:" << endl;
        cin >> wait;
        cout << endl;
        
        amOrPm = tolower(amOrPm);
        
        cout << "Current time = ";
        if (hour < 10) cout << "0";        
        cout << hour << ":";
        if (minute < 10) cout << "0";
        cout << minute << " ";
        
        if (amOrPm == 'a') cout << "AM";
        else cout << "PM";
        cout << endl;

        amOrPm = (amOrPm == 'p') ? 12 : 0;
        
        cout << "Time after waiting period = ";
        if ((hour%12 + (minute + wait)/60) % 12 < 10) cout << "0";   
        cout << (hour%12 + (minute + wait)/60) % 12 << ":";
        if ((minute+wait)%60 < 10) cout << "0";
        cout << (minute+wait)%60 << " ";
        
        if (((minute+wait)/60+hour+amOrPm)/12%2 == 0) cout << "AM";
        else cout << "PM";
        cout << endl << endl;
                
        cout << "Again:" << endl;
        cin >> again;
        if (again == 'y') cout << endl;
    } while (again == 'y');
    
    return 0;
}