/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 30, 2024, 10:17 AM
 * Purpose: Factorial
 */

//System Libraries
#include <iostream>
using namespace std;

int fctrl(int);//Function to write for this problem

int main(int argc, char** argv) {
    
    int inptNum;
    
    cout << "This program calculates the factorial using a function ";
    cout << "prototype found in the template for this problem." << endl;
    cout << "Input the number for the function." << endl;
    cin >> inptNum;
    
    //Output data
    cout << inptNum << "! = " << fctrl(inptNum);
    
    return 0;
}

int fctrl(int num) {
    int accum = 1;
    for (int i = num; i > 0 ; i--) accum *= i;
    return accum;
}