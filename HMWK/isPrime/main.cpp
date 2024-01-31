/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 30, 2024, 11:32 AM
 * Purpose: isPrime
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int);//Determine if the input number is prime.

int main(int argc, char** argv) {
    
    int inptNum;
    
    cout << "Input a number to test if Prime." << endl;
    cin >> inptNum;
    
    cout << inptNum << " is ";
    if (!isPrime(inptNum)) cout << "not ";
    cout << "prime.";

    return 0;
}

bool isPrime(int num) {
    for (int i = sqrt(num); i > 1; i--) if (num % i == 0) return false;
    return true;
}