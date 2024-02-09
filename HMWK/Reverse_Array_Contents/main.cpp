/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 4, 2024, 6:13 PM
 * Purpose: Reverse_Array_Contents
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Function Prototypes
void init(int [], int);         //Initialize the array
void print(int [], int, int);   //Print the array
void revrse(int [], int);       //Reverse the array


//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    const int SIZE = 50;
    int test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test, SIZE);
    
    //Reverse the Values
    revrse(test, SIZE);
    
    //Display the outputs
    print(test, SIZE, 10);

    return 0;
}

void init(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) cin >> arr[i];
    return;
}

void print(int arr[], int arrSize, int rowWdth) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
        if ((i+1) % rowWdth == 0) cout << endl;
    }
}

void revrse(int arr[], int arrSize) {
    int temp[arrSize];
    for (int i = 0; i < arrSize; i++) temp[i] = arr[i];
    for (int i = 0; i < arrSize; i++) arr[i] = temp[arrSize-1-i];
    return;
}