/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 5, 2024, 3:11 PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Function Prototypes
void init(int [], int);
bool linSrch(int [], int, int, int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    const int   SIZE = 100;
    int         array[SIZE];
    int         indx,
                val;
    
    //Initialize or input i.e. set variable values
    val = 50;
    init(array, SIZE);
    
    //Display the outputs
    if (linSrch(array, SIZE, val, indx))
        cout << val << " was found at indx = " << indx << endl;
    
    return 0;
}

void init(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) cin >> arr[i];
    return;
}

bool linSrch(int arr[], int arrSize, int toFind, int &indx) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == toFind) {
            indx = i;
            return true;
        }
    }
    return false;
}