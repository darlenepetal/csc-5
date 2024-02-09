/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 4, 2024, 4:12 PM
 * Purpose: Dice_Table_Sum
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int COLS=6;

//Function Prototypes
void fillTbl(int [][COLS], int);
void prntTbl(const int [][COLS], int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int   ROWS = 6;
    int         tablSum[ROWS][COLS];
    
    //Initialize or input i.e. set variable values
    fillTbl(tablSum, ROWS);
    
    //Display the outputs
    prntTbl(tablSum, ROWS);

    return 0;
}

void fillTbl(int table[][COLS], int rows) {
    for (int row = 1; row <= rows; row++) {
        for (int col = 1; col <= COLS; col++) {
            table[row][col] = row + col;
        }
    }
    return;
}

void prntTbl(const int table[][COLS], int rows) {
    cout << "Think of this as the Sum of Dice Table" << endl;
    cout << "           C o l u m n s" << endl;
    cout << "     |   1   2   3   4   5   6" << endl;
    cout << "----------------------------------" << endl;
    for (int row = 1; row <= rows; row++) {
        (row == 2) ? cout << 'R' :
        (row == 3) ? cout << 'O' :
        (row == 4) ? cout << 'W' : 
        (row == 5) ? cout << 'S' : cout << ' ';
        cout << "  " << row << " |";
        for (int col = 1; col <= COLS; col++) {
            cout << setw(4) << table[col][row];
        }
        cout << endl;
    }
    return;
}