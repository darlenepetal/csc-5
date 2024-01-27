/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 3, 2024, 8:17 PM
 * Purpose: Savitch Chapter 1 Practice Program 7 AsciiCS
 */

#include <iostream>
#include <string>
using namespace std;

// allows more concise repeating of char + space pairs
string operator * (string str, unsigned int num) {
    string output = "";
    while (num > 0) {
        output += str;
        num--;
    }
    return output;
}

int main(int argc, char** argv) {
    string asterisks = string(51, '*');
    string spaces = "  ";
    string c = "C ";
    string s = "S ";
    string exclamation = " !!";
    
    cout << asterisks << endl << endl;
    
    /* 
     * below, blocks of three lines of code -> one printed line
     * each line in block -> one line of one ascii art character
     * line one -> C
     * line two -> S
     * line three -> exclamation point
     */
    
    cout << (spaces * 5) << (c * 3) << (spaces * 6);
    cout << (s * 4) << (spaces * 3);
    cout << exclamation << endl;
    
    cout << (spaces * 4) << c << (spaces * 3) << c << (spaces * 4); 
    cout << s << (spaces * 4) << s << (spaces * 2);
    cout << exclamation << endl;
    
    cout << (spaces * 3) << " C" << (spaces * 8);
    cout << " S" << (spaces * 8);
    cout << exclamation << endl;
    
    cout << (spaces * 3) << c << (spaces * 9);
    cout << s << (spaces * 4) << (spaces * 3);
    cout << exclamation << endl;
    
    cout << (spaces * 3) << c << (spaces * 9);
    cout << ' ' << (s * 4) << ' ' << (spaces * 3);
    cout << exclamation << endl;        
    
    cout << (spaces * 3) << c << (spaces * 14);
    cout << s << (spaces * 2);
    cout << exclamation << endl;
    
    cout << (spaces * 3) << ' ' << c << (spaces * 14);
    cout << s << ' ' << spaces;
    cout << exclamation << endl;
    
    cout << (spaces * 4) << c << (spaces * 3) << c << (spaces * 4); 
    cout << s << (spaces * 4) << s << (spaces * 2);
    cout << endl;
    
    cout << (spaces * 5) << (c * 3) << (spaces * 6);
    cout << (s * 4) << (spaces * 3);
    cout << " 00" << endl;
    
    cout << endl << asterisks << endl;
    
    cout << (spaces * 4) << "Computer Science is Cool Stuff!!!" << endl;
    
    return 0;
}
