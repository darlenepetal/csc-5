/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 19, 2024, 1:32 PM
 * Purpose: Assignment 4 Menu
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float L_PER_G = 0.264179f;

//Function Prototypes
void    sum();
void    payInPennies();
void    minMax();
void    rectangle();
void    pattern();
void    mpg();
void    fuelEff();
void    inflation();
void    estCost();
void    twoThreeMax();
float   calc_mpg(short miles, short liters);
float   inf_rate(float curPric, float oldPric);
float   inf_price(float curPric, float infPerc);
float   max(float param1, float param2);
float   max(float param1, float param2, float param3);

int main(int argc, char** argv) {
    
    unsigned short  option,   //Option to choose from menu
                    nOpshun;  //Number of options
    
    //The Process -> Map Inputs to Outputs
    nOpshun = 10;    //In this case we have 3 options
    do{
        //Display user choice
        cout<<"Choose from the options displayed"<<endl;
        cout<<"1 -> Sum"<<endl;
        cout<<"2 -> Pay in Pennies"<<endl;
        cout<<"3 -> MinMax"<<endl;
        cout<<"4 -> Rectangle"<<endl;
        cout<<"5 -> Pattern"<<endl;
        cout<<"6 -> MPG"<<endl;
        cout<<"7 -> Fuel Efficiency"<<endl;
        cout<<"8 -> Inflation"<<endl;
        cout<<"9 -> Estimated Cost"<<endl;
        cout<<"10-> 2 or 3 Max"<<endl;
        cin>>option;    //Read in the option
        //Use a switch case to implement
        switch(option){
            case 1:     sum();cout<<endl<<endl;break;
            case 2:     payInPennies();cout<<endl<<endl;break;
            case 3:     minMax();cout<<endl<<endl;break;
            case 4:     rectangle();cout<<endl<<endl;break;
            case 5:     pattern();cout<<endl<<endl;break;
            case 6:     mpg();cout<<endl<<endl;break;
            case 7:     fuelEff();cout<<endl<<endl;break;
            case 8:     inflation();cout<<endl<<endl;break;
            case 9:     estCost();cout<<endl<<endl;break;
            case 10:    twoThreeMax();cout<<endl<<endl;break;
            default:    cout<<endl<<"Exit Program"<<endl<<endl;
        }
    }while(option<=nOpshun);
    
    //Exit the Program
    return 0;
}

void sum() {
    short   input;
    int     sum;
    
    cin >> input;
    while (input < 0) {
        cout << "Please enter a positive number." << endl;
        cin >> input;
    }
    sum = 0;
    
    while (input > 0) {
        sum += input;
        input -= 1;
    }
    
    cout << "Sum = " << sum;
    return;
}

void payInPennies() {
    short   days;
    double  temp;
    double  pay;

    cin >> days;
    while (days < 1) {
        cout << "Days entered must be greater than zero.";
        cin >> days;
    }
    pay = 0;
    temp = 0.01;
    
    for (short i = 1; i <= days; i++) {
        pay += temp;
        temp *= 2;
    }
    
    cout << fixed << setprecision(2) << showpoint;
    cout << "Pay = $" << pay;
    return;
}

void minMax() {
    int     smallest, largest;
    short   i;
    
    i = 0;
    while (true) {
        int temp;
        cin >> temp;
        if (temp == -99) {
            break;
        }
        else if (i == 0) {
            smallest = temp;
            largest = temp;
            i++;
        }
        else if (temp > largest) {
            largest = temp;
        }
        else if (temp < smallest) {
            smallest = temp;
        }
    }
    
    cout << "Smallest number in the series is " << smallest << endl;
    cout << "Largest  number in the series is " << largest;
    return;
}

void rectangle() {
    short   inSize;
    char    inChar;

    cin >> inSize >> inChar;

    for (short i = inSize; i > 0; i--) {
        for (short j = inSize; j > 0; j--) {
            cout << inChar;
        }
        if (i != 1) {
            cout << endl;
        }
    }
    
    return;
}

void pattern() {
    short input;

    cin >> input;

    for (short i = 1; i <= input; i++) {
        for (short j = i; j > 0; j--) {
            cout << "+";
        }
        cout << endl << endl;
    }
    for (short i = input; i > 0; i--) {
        for (short j = i; j > 0; j--) {
            cout << "+";
        }
        if (i != 1) {
            cout << endl << endl;
        }
    }
    return;
}

void mpg() {
    char again;
    again = 'y';
    
    while (again == 'y') {
        short   liters, miles;
        float   mpg;
        
        cout << "Enter number of liters of gasoline:" << endl << endl;
        cin >> liters;
        
        cout << "Enter number of miles traveled:" << endl << endl;
        cin >> miles;
        
        cout << "miles per gallon:" << endl;
        cout << fixed << setprecision(2) << showpoint;
        cout << calc_mpg(miles, liters) << endl;
        
        cout << "Again:" << endl;
        cin >> again;
        again = tolower(again);
        if (again == 'y') {
            cout << endl;
        }
    }
    return;
}

void fuelEff() {
    char again;
    again = 'y';
    
    while (again == 'y') {
        short   liters[2], miles[2];
        float   mpg[2];
        
        for (char i = 0; i < 2; i++) {
            cout << "Car " << i + 1 << endl;
            cout << "Enter number of liters of gasoline:" << endl;
            cin >> liters[i];

            cout << "Enter number of miles traveled:" << endl;
            cin >> miles[i];

            mpg[i] = calc_mpg(miles[i], liters[i]);

            cout << "miles per gallon: ";
            cout << fixed << setprecision(2) << showpoint;
            cout << mpg[i] << endl << endl;
        }
        
        if (mpg[0] > mpg[1]) {
            cout << "Car 1 is more fuel efficient" << endl << endl;
        }
        else if (mpg[0] < mpg[1]) {
            cout << "Car 2 is more fuel efficient" << endl << endl;
        }
        else {
            cout << "Both cars are equally fuel efficient" << endl << endl;
        }
        
        cout << "Again:" << endl;
        cin >> again;
        if (tolower(again) == 'y') {
            cout << endl;
        }
    }
    return;
}

void inflation() {
    char again;
    again = 'y';
    
    while (again == 'y') {
        float curPric, oldPric;
        
        cout << "Enter current price:" << endl;
        cin >> curPric;
        cout << "Enter year-ago price:" << endl;
        cin >> oldPric;
        
        cout << fixed << setprecision(2) << showpoint;
        cout << "Inflation rate: " << inf_rate(curPric, oldPric);
        cout << "%" << endl << endl;
        
        cout << "Again:" << endl;
        cin >> again;
        if (tolower(again) == 'y') {
            cout << endl;
        }
    }
    return;
}

void estCost() {
    char again;
    again = 'y';
    
    while (again == 'y') {
        float curPric, oldPric, infPerc, ftrPric;
        
        cout << "Enter current price:" << endl;
        cin >> curPric;
        cout << "Enter year-ago price:" << endl;
        cin >> oldPric;
        infPerc = inf_rate(curPric, oldPric);
        ftrPric = inf_price(curPric, infPerc);
        
        cout << fixed << setprecision(2) << showpoint;
        cout << "Inflation rate: " << infPerc;
        cout << "%" << endl << endl;
        cout << "Price in one year: $" << ftrPric << endl;
        cout << "Price in two year: $";
        cout << inf_price(ftrPric, infPerc) << endl << endl;
        
        cout << "Again:" << endl;
        cin >> again;
        if (tolower(again) == 'y') {
            cout << endl;
        }
    }
    return;
}

void twoThreeMax() {
    float params[3];
    
    cout << "Enter first number:" << endl;
    cin >> params[0];
    cout << endl << "Enter Second number:" << endl;
    cin >> params[1];
    cout << endl << "Enter third number:" << endl;
    cin >> params[2];
    
    cout << fixed << setprecision(1) << showpoint;
    cout << endl << "Largest number from two parameter function:" << endl;
    cout << max(params[0], params[1]) << endl;
    
    cout << endl << "Largest number from three parameter function:" << endl;
    cout << max(params[0], params[1], params[2]) << endl;
    return;
}

float calc_mpg(short miles, short liters) {
    return miles / (liters * L_PER_G);
}

float inf_rate(float curPric, float oldPric) {
    return (curPric - oldPric) / oldPric * 100;
}

float inf_price(float curPric, float infPerc) {
    return curPric + (curPric * (infPerc / 100));
}

float max(float param1, float param2) {
    float temp = (param1 > param2) ? param1 : param2;
    return temp;
}

float max(float param1, float param2, float param3) {
    float temp = max(param1, param2);
    if (param3 > temp) temp = param3;
    return temp;
}