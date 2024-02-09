/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 5, 2024, 4:26 PM
 * Purpose: Assignment_6_Menu
 */

// system libraries
#include <iostream> 
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

// global constants
const int COLS = 6;

void    p1();
void    p2();
void    p3();
void    p4();
void    p5();
void    p6();
void    p7();
void    p8();
void    sumTbl  (int [][COLS], int);
void    prodTbl (int [][COLS], int);
void    prntSum (const int [][COLS], int);
void    prntPrd (const int [][COLS], int);
void    init    (int [], int);
void    print   (int [], int, int);
void    revrse  (int [], int);
void    initFlt (float [], int);
float   avgX    (float [], int);
float   stdX    (float [], int);
void    prntStr (const string&, short);
void    read    (string&, short&);
int     compare (const string&, const string&, string&);
bool    linSrch (int [], int, int, int&);
void    selSrt  (int [], int);
bool    binSrch (int [], int, int, int&);
void    bublSrt (int [], int);

int main(int argc, char** argv) {    
    
    unsigned short  option,   
                    nOption;  
    
    nOption = 8;    
    do {
        cout << "Choose from the options displayed" << endl;
        cout << "1 -> Dice Table Sum" << endl;
        cout << "2 -> Product Table" << endl;
        cout << "3 -> Reverse Array Contents" << endl;
        cout << "4 -> Standard Deviation" << endl;
        cout << "5 -> Grading Like A Scantron" << endl;
        cout << "6 -> Linear Search" << endl;
        cout << "7 -> Binary Search And Selection Sort" << endl;
        cout << "8 -> Binary Search With Bubble Sort" << endl;
        cin >> option;
        
        switch (option) 
        {
            case 1:     p1();
                        break;
            case 2:     p2();
                        break;
            case 3:     p3();
                        break;
            case 4:     p4();
                        break;
            case 5:     p5();
                        break;
            case 6:     p6();
                        break;
            case 7:     p7();
                        break;
            case 8:     p8();
                        break;
            default:    cout << endl << "Exit Program";
        }
        cout << endl << endl;
    } while (option > 0 && option <= nOption);
    
    return 0;
}

void p1() {
    //Declare Variables
    const int   ROWS = 6;
    int         tablSum[ROWS][COLS];
    
    //Initialize or input i.e. set variable values
    sumTbl(tablSum, ROWS);
    
    //Display the outputs
    prntSum(tablSum, ROWS);
}

void p2() {
    //Declare Variables
    const int   ROWS = 6;
    int         tablSum[ROWS][COLS];
    
    //Initialize or input i.e. set variable values
    prodTbl(tablSum, ROWS);
    
    //Display the outputs
    prntPrd(tablSum, ROWS);
    return;
}

void p3() {
    //Declare Variables
    const int   SIZE = 50;
    int         test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test, SIZE);
    
    //Reverse the Values
    revrse(test, SIZE);
    
    //Display the outputs
    print(test, SIZE, 10);
    return;
}

void p4() {
    //Declare Variables
    const int   SIZE = 20;
    float       test[SIZE];
    
    //Initialize or input i.e. set variable values
    cout << fixed << setprecision(7) << showpoint;
    initFlt(test, SIZE);
    
    cout << "The average            = " << avgX(test, SIZE) << endl;
    cout << "The standard deviation = " << stdX(test, SIZE) << endl;
    return;
}

void p5() {
    //Declare Variables
    float   pRight;
    short   keyLen;
    string  key,
            answers,
            score;
    
    //Initialize or input i.e. set variable values
    keyLen = 0;
    read(key, keyLen);
    read(answers, keyLen);
    
    //Score the exam
    pRight = compare(key, answers, score);
    
    //Display the outputs
    cout << "C/W     ";
    prntStr(score, keyLen);
    cout << "Percentage Correct = ";
    cout << pRight/keyLen * 100 << "%" << endl;

    return;
}

void p6() {
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
    return;
}

void p7() {
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
    return;
}

void p8() {
    //Declare Variables
    const int   SIZE = 100;
    int         array[SIZE];
    int         indx,
                val;
    
    //Initialize or input i.e. set variable values
    init(array, SIZE);

    //Sorted List
    bublSrt(array, SIZE);
    
    //Display the outputs
    print(array, SIZE, 10);
    cout << endl << "Input the value to find in the array" << endl;
    cin >> val;
    if(binSrch(array, SIZE, val, indx))
        cout << val << " was found at indx = " << indx << endl;
    return;
}

void sumTbl(int table[][COLS], int rows) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < COLS; col++) {
            table[row][col] = (row+1) + (col+1);
        }
    }
    return;
}

void prodTbl(int table[][COLS], int rows) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < COLS; col++) {
            table[row][col] = (row+1) * (col+1);
        }
    }
    return;
}

void prntSum(const int table[][COLS], int rows) {
    cout << "Think of this as the Sum of Dice Table" << endl;
    cout << "           C o l u m n s" << endl;
    cout << "     |   1   2   3   4   5   6" << endl;
    cout << "----------------------------------" << endl;
    for (int row = 0; row < rows; row++) {
        (row == 1) ? cout << 'R' :
        (row == 2) ? cout << 'O' :
        (row == 3) ? cout << 'W' : 
        (row == 4) ? cout << 'S' : cout << ' ';
        cout << "  " << row+1 << " |";
        for (int col = 0; col < COLS; col++) {
            cout << setw(4) << table[col][row];
        }
        cout << endl;
    }
    return;
}

void prntPrd(const int table[][COLS], int rows) {
    cout << "Think of this as a Product/Muliplication Table" << endl;
    cout << "           C o l u m n s" << endl;
    cout << "     |   1   2   3   4   5   6" << endl;
    cout << "----------------------------------" << endl;
    for (int row = 0; row < rows; row++) {
        (row == 1) ? cout << 'R' :
        (row == 2) ? cout << 'O' :
        (row == 3) ? cout << 'W' : 
        (row == 4) ? cout << 'S' : cout << ' ';
        cout << "  " << row+1 << " |";
        for (int col = 0; col < COLS; col++) {
            cout << setw(4) << table[col][row];
        }
        cout << endl;
    }
    return;
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
    return;
}

void revrse(int arr[], int arrSize) {
    int temp[arrSize];
    for (int i = 0; i < arrSize; i++) temp[i] = arr[i];
    for (int i = 0; i < arrSize; i++) arr[i] = temp[arrSize-1-i];
    return;
}

void initFlt(float arr[], int arrSize) {
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

void prntStr(const string& curStr, short len) {
    for (short i = 0; i < len; i++) cout << curStr[i] << " ";
    cout << endl;
    return;
}

void read(string& readStr, short& len) {
    string next;
    cin >> next;
    // check if entering key, which comes first
    if (next[1]) {
        cin >> next;
        while (!next[1]) {
            readStr += next;
            len++;
            cin >> next;
        }
    }
    // check if entering student answers
    else for (short i = 0; i < len; i++) {
        readStr += next;
        cin >> next;
    }
    return;
}

int compare(const string& key, const string& answers, string& score) {
    short correct = 0;
    for (short i = 0; i < key.size(); i++) {
        if (answers[i] == key[i]) {
            score[i] = 'C';
            correct++;
        }
        else score[i] = 'W';
    }
    return correct;
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

void bublSrt(int arr[], int arrSize) {
    int     i,
            temp;
    bool    swapped;
    
    i = 0;
    do {
        swapped = false;
        for (int j = 0; j < arrSize-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp        = arr[j];
                arr[j]      = arr[j+1];
                arr[j+1]    = temp;
                swapped     = true;
            }
        }
        i++;
    } while (swapped == true);
    return;
}