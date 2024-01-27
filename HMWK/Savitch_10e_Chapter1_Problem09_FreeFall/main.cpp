/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 5, 2024, 5:52 PM
 * Purpose: Savitch Chapter 1 Practice Program 9 FreeFall
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int seconds, distance;    
    
    cout << "Input a number of seconds and press enter:\n";
    cin >> seconds;
    
    distance = (32 * seconds * seconds) / 2;
    cout << "An object in freefall for ";
    cout << seconds;
    cout << " seconds\n";
    cout << "would travel ";
    cout << distance;
    cout << " feet.\n";

    return 0;
}
