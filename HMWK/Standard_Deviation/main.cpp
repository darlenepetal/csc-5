/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 5, 2024, 12:31 PM
 * Purpose: Standard_Deviation
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <cmath>     //Math Library
using namespace std;

//Function Prototypes
void  init  (float [], int);          //Initialize the array
float avgX  (float [], int);          //Calculate the Average
float stdX  (float [], int);          //Calculate the standard deviation

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    const int SIZE = 20;
    float test[SIZE];
    
    //Initialize or input i.e. set variable values
    cout << fixed << setprecision(7) << showpoint;
    init(test, SIZE);
    
    cout << "The average            = " << avgX(test, SIZE) << endl;
    cout << "The standard deviation = " << stdX(test, SIZE) << endl;

    return 0;
}

void init(float arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) cin >> arr[i];
    return;
}

float avgX(float arr[], int arrSize) {
    float sum = 0;
    for (int i = arrSize-1; i >= 0; i--) sum += arr[i];
    return sum/arrSize;
}

float stdX(float arr[], int arrSize) {
    float mean, devSum;
    mean = devSum = 0;
    for (int i = 0; i < arrSize; i++) mean += arr[i];
    mean /= arrSize;
    for (int i = 0; i < arrSize; i++) devSum += pow(arr[i] - mean, 2);
    return sqrt(devSum/(arrSize-1));
}