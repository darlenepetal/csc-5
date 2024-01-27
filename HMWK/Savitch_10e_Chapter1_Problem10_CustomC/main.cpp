/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 5, 2024, 6:03 PM
 * Purpose: Savitch Chapter 1 Practice Program 10 CustomC
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    char c;
    
    cout << "Input a single character and press enter:\n";
    cin >> c;
    cout << endl;
    
    for (int i = 0; i < 9; i++) {
        if (i == 0 || i == 8) {
            cout << "  " << c << " " << c << " " << c << endl;
        }
        else if (i == 1 || i == 7) {
            cout << " " << c << "    " << c << endl;
        }
        else {
            cout << c << endl;
        }
    }
    
    return 0;
}
