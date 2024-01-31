/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 30, 2024, 11:45 AM
 * Purpose: Collatz_Sequence
 */

//System Libraries
#include <iostream>
using namespace std;

int collatz(int);//3n+1 sequence

int main(int argc, char** argv) {

    int n;
    
    cout << "Collatz Conjecture Test" << endl;
    cout << "Input a sequence start" << endl;
    cin >> n;
    
    cout << "Sequence start of " << n << " cycles to 1 in ";
    cout << collatz(n) << " steps";
    
    return 0;
}

int collatz(int num) {
    int i = 1;
    while (num != 1) {
        (num % 2 == 0 ) ? (num /= 2) : (num = num * 3 + 1);
        i++;
    }
    return i;
}