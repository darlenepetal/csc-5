/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 29, 2024, 1:47 PM
 * Purpose: MinMax
 */

//System Libraries
#include <iostream>
using namespace std;

void minmax(int, int, int, int&, int&);//Function to find the min and max

int main(int argc, char** argv) {

    int num1, num2, num3, min, max;
    
    cout << "Input 3 numbers" << endl;
    cin >> num1 >> num2 >> num3;
    min = max = num1;

    minmax(num1, num2, num3, min, max);
    
    cout << "Min = " << min << endl;
    cout << "Max = " << max;
    
    return 0;
}

void minmax(int num1, int num2, int num3, int& min, int& max) {
    if (num1 > max) max = num1;
    if (num2 > max) max = num2;
    if (num3 > max) max = num3;
    
    if (num1 < min) min = num1;
    if (num2 < min) min = num2;
    if (num3 < min) min = num3;
    return;
}