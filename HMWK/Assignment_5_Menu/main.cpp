/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 31, 2024, 1:09 PM
 * Purpose: Assignment_5_Menu
 */

#include <iostream> 
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

void    p1();
void    minmax(int, int, int, int&, int&);
void    p2();
int     fctrl(int);
void    p3();
bool    isPrime(int);
void    p4();
int     collatz(int);
void    p5();
int     outCltz(int);
void    p6();
void    p7();
bool    spltTim(string, short&, short&);
void    cnvtTim(short&, char&);
void    prntTim(string, short, short, char);
void    p8();
float   psntVal(float, float, int);
void    p9();
void    getScre(int&, int&, int&, int&, int&);
float   calcAvg(int, int, int, int, int);
int     fndLwst(int, int, int, int, int);

int main(int argc, char** argv) {    
    
    unsigned short  option,   
                    nOption;  
    
    nOption = 9;    
    do{
        
        cout << "Choose from the options displayed" << endl;
        cout << "1 -> MinMax" << endl;
        cout << "2 -> Factorial" << endl;
        cout << "3 -> IsPrime" << endl;
        cout << "4 -> Collatz Sequence" << endl;
        cout << "5 -> Collatz Sequence With Sequence Output" << endl;
        cout << "6 -> Time Clock" << endl;
        cout << "7 -> Time Converter" << endl;
        cout << "8 -> Present Value" << endl;
        cout << "9 -> Average" << endl;
        cin >> option;
        
        switch(option){
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
            case 9:     p9();
                        break;
            default:    cout << endl << "Exit Program";
        }
        cout << endl << endl;
    } while (option > 0 && option < 9);
    
    return 0;
}

void p1() {
    int num1, num2, num3, min, max;
    
    cout << "Input 3 numbers" << endl;
    cin >> num1 >> num2 >> num3;
    min = max = num1;

    minmax(num1, num2, num3, min, max);
    
    cout << "Min = " << min << endl;
    cout << "Max = " << max;
    
    return;
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

void p2() {
    int inptNum;
    
    cout << "This program calculates the factorial using a function ";
    cout << "prototype found in the template for this problem." << endl;
    cout << "Input the number for the function." << endl;
    cin >> inptNum;
    
    cout << inptNum << "! = " << fctrl(inptNum);
    
    return;
}

int fctrl(int num) {
    int accum = 1;
    for (int i = num; i > 0 ; i--) accum *= i;
    return accum;
}

void p3() {
    int inptNum;
    
    cout << "Input a number to test if Prime." << endl;
    cin >> inptNum;
    
    cout << inptNum << " is ";
    if (!isPrime(inptNum)) cout << "not ";
    cout << "prime.";

    return;
}

bool isPrime(int num) {
    for (int i = sqrt(num); i > 1; i--) if (num % i == 0) return false;
    return true;
}

void p4() {
    int n;
    
    cout << "Collatz Conjecture Test" << endl;
    cout << "Input a sequence start" << endl;
    cin >> n;
    
    cout << "Sequence start of " << n << " cycles to 1 in ";
    cout << collatz(n) << " steps";
    
    return;
}

int collatz(int num) {
    int i = 1;
    while (num != 1) {
        (num % 2 == 0 ) ? (num /= 2) : (num = num * 3 + 1);
        i++;
    }
    return i;
}

void p5() {
    int n;
    
    cout << "Collatz Conjecture Test" << endl;
    cout << "Input a sequence start" << endl;
    cin >> n;
    
    outCltz(n);
    
    return;
}

int outCltz(int num) {
    int i = 1;
    int copy = num;
    
    while (num != 1) {
        cout << num << ", ";
        (num % 2 == 0 ) ? (num /= 2) : (num = num * 3 + 1);
        i++;
    }
    cout << num << endl;
    cout << "Sequence start of " << copy << " cycles to 1 in ";
    cout << i << " steps";
    return i;
}

void p6() {
    char    amOrPm,
            again;
    short   hour,
            minute,
            wait;
         
    do {
        cout << "Enter hour:" << endl;
        cin >> hour;
        cout << endl;
        
        cout << "Enter minutes:" << endl;
        cin >> minute;
        cout << endl;
        
        cout << "Enter A for AM, P for PM:" << endl;
        cin >> amOrPm;
        cout << endl;
        
        cout << "Enter waiting time:" << endl;
        cin >> wait;
        cout << endl;
        
        amOrPm = tolower(amOrPm);
        
        cout << "Current time = ";
        if (hour < 10) cout << "0";        
        cout << hour << ":";
        if (minute < 10) cout << "0";
        cout << minute << " ";
        
        if (amOrPm == 'a') cout << "AM";
        else cout << "PM";
        cout << endl;

        amOrPm = (amOrPm == 'p') ? 12 : 0;
        
        cout << "Time after waiting period = ";
        if ((hour%12 + (minute + wait)/60) % 12 < 10) cout << "0";   
        cout << (hour%12 + (minute + wait)/60) % 12 << ":";
        if ((minute+wait)%60 < 10) cout << "0";
        cout << (minute+wait)%60 << " ";
        
        if (((minute+wait)/60+hour+amOrPm)/12%2 == 0) cout << "AM";
        else cout << "PM";
        cout << endl << endl;
                
        cout << "Again:" << endl;
        cin >> again;
        if (again == 'y') cout << endl;
    } while (again == 'y');
    
    return;
}

void p7() {
    char    amOrPm,
            again;
    short   hour,
            minute;
    string  inTime;
    
    cout << "Military Time Converter to Standard Time" << endl;
    cout << "Input Military Time hh:mm" << endl;
    
    do {
        hour = minute = 0;
        cin >> inTime;

        if (!spltTim(inTime, hour, minute)) {
            cout << inTime << " is not a valid time" << endl;
        }
        else {
            cnvtTim(hour, amOrPm);
            prntTim(inTime, hour, minute, amOrPm);
        }
        
        cout << "Would you like to convert another time (y/n)" << endl;
        cin >> again;
    } while (again == 'y' || again == 'Y');
    
    return;
}

bool spltTim(string time, short& hour, short& minute) {
    for (char i = char(0); i < 2; i++) {
        hour += (i == 1)    ? time[i]-48    : (time[i]-48)*10;
        minute += (i == 1)  ? time[i+3]-48  : (time[i+3]-48)*10;
    }
    
    if (hour > 23 || minute > 59) return false;
    else return true;
}

void cnvtTim(short& hour, char& amOrPm) {
    if (hour > 12) {
        hour -= 12;
        amOrPm = 'p';
    }
    else if (hour == 12) {
        amOrPm = 'p';
    }
    else {
        if (hour == 0) hour += 12;
        amOrPm = 'a';
    }
    
    return;
}

void prntTim(string inTime, short hour, short minute, char amOrPm) {
    cout << inTime << " = ";
    cout << hour << ":";
    cout << minute << " ";
    (amOrPm == 'a') ? (cout << "AM") : (cout << "PM");
    cout << endl;
}

void p8() {
    int     years;
    float   endAmnt, 
            intRate;

    cout << "This is a Present Value Computation" << endl;
    cout << "Input the Future Value in Dollars" << endl;
    cin >> endAmnt;
    cout << "Input the Number of Years" << endl;
    cin >> years;
    cout << "Input the Interest Rate %/yr" << endl;
    cin >> intRate;
    intRate /= 100;

    cout << fixed << setprecision(2) << showpoint;
    cout << "The Present Value = $" << psntVal(endAmnt, intRate, years);

    return;
}

float psntVal(float end, float rate, int yrs) {
    return end/pow(1+rate, yrs);
}

void p9() {
    int v1,
        v2,
        v3,
        v4,
        v5;

    cout << "Find the Average of Test Scores" << endl;
    cout << "by removing the lowest value." << endl;
    cout << "Input the 5 test scores." << endl;

    getScre(v1, v2, v3, v4, v5);

    cout << fixed << setprecision(1) << showpoint;
    cout << "The average test score = " << calcAvg(v1, v2, v3, v4, v5);

    return;
}

void getScre(int& v1, int& v2, int& v3, int& v4, int& v5) {
    do cin >> v1; while (v1 < 1 || v1 > 100);
    do cin >> v2; while (v2 < 1 || v2 > 100);
    do cin >> v3; while (v3 < 1 || v3 > 100);
    do cin >> v4; while (v4 < 1 || v4 > 100);
    do cin >> v5; while (v5 < 1 || v5 > 100);
    return;
}

float calcAvg(int v1, int v2, int v3, int v4, int v5) {
    int lowest = fndLwst(v1, v2, v3, v4, v5);
    return (v1 + v2 + v3 + v4 + v5 - lowest) / 4;
}

int fndLwst(int v1, int v2, int v3, int v4, int v5) {
    int lowest = v1;
    if (v2 < lowest) lowest = v2;
    if (v3 < lowest) lowest = v3;
    if (v4 < lowest) lowest = v4;
    if (v5 < lowest) lowest = v5;
    return lowest;
}