/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 5, 2024, 5:42 PM
 * Purpose: Savitch Chapter 1 Practice Program 8 CoinSum
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int quarters, dimes, nickels, total;
    
    cout << "Input number of quarters and press enter:\n";
    cin >> quarters;
    cout << "Input number of dimes and press enter:\n";
    cin >> dimes;
    cout << "Input number of nickels and press enter:\n";
    cin >> nickels;
    
    total = (quarters * 25) + (dimes * 10) + (nickels * 5);
    cout << "The coins entered total ";
    cout << total;
    cout << " cents.";
    
    return 0;
}
