/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 5, 2024, 3:19 PM
 * Purpose: BinarySearch_SelectionSort
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Function Prototypes
void init(int [], int);
void print(int [], int, int);
void selSrt(int [], int);
bool binSrch(int [], int, int, int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    const int   SIZE = 100;
    int         array[SIZE];
    int         indx,
                val;
    
    //Initialize or input i.e. set variable values
    init(array, SIZE);

    //Sorted List
    selSrt(array, SIZE);
    
    //Display the outputs
    print(array, SIZE, 10);
    cout << endl << "Input the value to find in the array" << endl;
    cin >> val;
    if(binSrch(array, SIZE, val, indx))
        cout << val << " was found at indx = " << indx << endl;

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

void selSrt(int arr[], int arrSize) {
    int minIndx, temp;
    for (int i = 0; i < arrSize; i++) {
        int minIndx = temp = i;
        
        for (int j = i+1; j < arrSize; j++) {
            if (arr[j] < arr[minIndx]) minIndx = j;
        }
        
        if (minIndx != i) {
            temp = arr[i];
            arr[i] = arr[minIndx];
            arr[minIndx] = temp;
        }
    }
    return;
}

bool binSrch(int arr[], int arrSize, int toFind, int &indx) {
    int first, 
        middle,
        last;
    
    first = 0;
    last = arrSize-1;
    
    while (first <= last) {
        middle = (first + last)/2;
        if (arr[middle] == toFind) {
            indx = middle;
            return true;
        }
        else if (arr[middle] > toFind) last = middle-1;
        else if (arr[middle] < toFind) first = middle+1;
    }
    
    return false;
}