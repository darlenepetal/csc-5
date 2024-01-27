/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 3, 2024, 8:17 PM
 * Purpose: Savitch Chapter 1 Practice Program 3
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int firstNumber, secondNumber, quotient;
    cout << "Press return after entering a number.\n";
    cout << "Enter a number: \n";
    cin >> firstNumber;
    cout << "Enter another number: \n";
    cin >> secondNumber;
    quotient = firstNumber / secondNumber;
    cout << "The quotient of ";
    cout << firstNumber;
    cout << " and ";
    cout << secondNumber;
    cout << " is ";
    cout << quotient;
    cout  << ".\n";
    return 0;
}
