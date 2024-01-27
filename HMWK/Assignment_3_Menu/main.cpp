/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 16, 2024, 12:26 PM
 * Purpose: Assignment 3 Menu
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const char SORTNAMES_NO = 3;
const char BANK_WIDTH = 9;
const char RUNNERS_NO = 3;
const char RUNNERS_WIDTH = 3;

//Function Prototypes
void    sortNames();
void    addName(string curName, string names[]);
void    books();
void    bankCharges();
void    race();
void    ISP();
void    RPS();
char    getThrow();
void    romanConversion();
void    compatibleSigns();
string  getSign();
string  getElem(string sign);


//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare Variables
    unsigned char option,//Option to choose from menu
                  nOpshun;//Number of options
    
    //The Process -> Map Inputs to Outputs
    nOpshun='8';//In this case we have 3 options
    do{
        //Display user choice
        cout<<"Choose from the options displayed"<<endl;
        cout<<"1 -> Sort Names"<<endl;
        cout<<"2 -> Books"<<endl;
        cout<<"3 -> Bank Charges"<<endl;
        cout<<"4 -> Race"<<endl;
        cout<<"5 -> ISP"<<endl;
        cout<<"6 -> Rock Paper Scissors"<<endl;
        cout<<"7 -> Roman Conversion"<<endl;
        cout<<"8 -> Compatible Signs"<<endl;
        cin>>option;//Read in the option
        //Use a switch case to implement
        switch(option){
            case '1':   sortNames();cout<<endl<<endl;break;
            case '2':   books();cout<<endl<<endl;break;
            case '3':   bankCharges();cout<<endl<<endl;break;
            case '4':   race();cout<<endl<<endl;break;
            case '5':   ISP();cout<<endl<<endl;break;
            case '6':   RPS();cout<<endl<<endl;break;
            case '7':   romanConversion();cout<<endl<<endl;break;
            case '8':   compatibleSigns();cout<<endl<<endl;break;
            default:    cout<<endl<<"Exit Program"<<endl<<endl;
        }
    }while(option<=nOpshun);
    
    //Exit the Program
    return 0;
}


void sortNames() {
    string names[SORTNAMES_NO];

    cout << "Sorting Names" << endl;
    cout << "Input 3 names" << endl;

    for (char i = 0; i < SORTNAMES_NO; i++) {
        string curName;
        cin >> curName;
        addName(curName, names);
    }

    for (char i = 0; i < SORTNAMES_NO; i++) {
        if (i + 1 == SORTNAMES_NO) {
            cout << names[i];
            continue;
        }
        cout << names[i] << endl;
    }

    return;
}


void addName(string curName, string names[]) {
    string held = curName;
    for (char i = 0; i < SORTNAMES_NO; i++) {
        string compared = names[i];
        if (compared == "") {
            names[i] = held;
            return;
        }
        else if (held < compared) {
            names[i] = held;
            held = compared;
        }        
    }
}


void books() {
    unsigned short books, points;

    cout << "Book Worm Points" << endl;
    cout << "Input the number of books purchased this month." << endl;
    cin >> books;
    
    switch (books)
    {
        case 0:     points = 0;
                    break;
        case 1:     points = 5;
                    break;
        case 2:     points = 15;
                    break;
        case 3:     points = 30;
                    break;
        default:    points = 60;
                    break;
    }
    cout << "Books purchased =" << setw(3) << books << endl;
    cout << "Points earned   =" << setw(3) << points;
    
    return;
}


void bankCharges() {
    float   feeVar;
    int     iBal;
    short   checNum;
    
    cout << "Monthly Bank Fees" << endl;
    cout << "Input Current Bank Balance and Number of Checks" << endl;
    
    cin >> iBal;
    if (iBal < 0) {
        cout << "WARNING: ACCOUNT IS OVERDRAWN" << endl;
    }
    
    cin >> checNum;
    while (checNum < 0) {
        cout << "ERROR: NUMBER OF CHECKS MUST BE POSITIVE" << endl;
        cin >> checNum;
    }
    
    cout << fixed << showpoint << setprecision(2);
    cout << "Balance     $" << setw(BANK_WIDTH) << (float)iBal << endl;
    
    if (checNum < 20) {
        feeVar = checNum * 0.10f;
    }
    else if (checNum < 40) {
        feeVar = checNum * 0.08f;
    }
    else if (checNum < 60) {
        feeVar = checNum * 0.06f;
    }
    else {
        feeVar = checNum * 0.04f;
    }
    
    cout << "Check Fee   $" << setw(BANK_WIDTH) << feeVar << endl;
    cout << "Monthly Fee $" << setw(BANK_WIDTH) << 10.0f << endl;
    feeVar += 10;
    
    if (iBal < 400) {
        cout << "Low Balance $" << setw(BANK_WIDTH) << 15.0f << endl;
        feeVar += 15;
    }
    else {
        cout << "Low Balance $" << setw(BANK_WIDTH) << 0.0f << endl;
    }

    cout << "New Balance $" << setw(BANK_WIDTH) << iBal - feeVar;
    
    return;
}


void race() {
    string rnrName[RUNNERS_NO];
    short rnrTime[RUNNERS_NO];

    cout << "Race Ranking Program" << endl;
    cout << "Input 3 Runners" << endl;
    cout << "Their names, then their times" << endl;
    
    for (char i = 0; i < RUNNERS_NO; i++) {
        cin >> rnrName[i] >> rnrTime[i];
        while (rnrTime[i] < 0) {
            cout << "Runner time must be a positive number." << endl;
            cin >> rnrTime[i];
        }
    }
    
    for (short i = 0; i < RUNNERS_NO - 1; i++) {
        bool swapped = false;
        for (short j = 0; j < RUNNERS_NO - i - 1; j++) {
            short   time1 = rnrTime[j];
            string  name1 = rnrName[j];
            short   time2 = rnrTime[j + 1];
            string  name2 = rnrName[j + 1];
            if (time2 < time1) {
                rnrTime[j]      = time2;
                rnrTime[j + 1]  = time1;
                rnrName[j]      = name2;
                rnrName[j + 1]  = name1;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }

    for (char i = 0; i < RUNNERS_NO; i++) {
        cout << rnrName[i] << "\t" << setw(RUNNERS_WIDTH) << rnrTime[i];
        if (i + 1 != RUNNERS_NO) {
            cout << endl;
        }
    }
    
    return;
}


void ISP() {
    char    pkg;
    short   hrs;
    float   bill;
    
    cout << "ISP Bill" << endl;
    cout << "Input Package and Hours" << endl;
    
    cin >> pkg;
    while (pkg != 'A' && pkg != 'B' && pkg != 'C') {
        cout << "Please select only package A, B, or C" << endl;
        cin >> pkg;
    }
    
    cin >> hrs;
    while (hrs > 744) {
        cout << "Please select a number of hours less than 744" << endl;
        cin >> hrs;
    }
    
    switch (pkg)
    {
        case 'A':   bill = 9.95;
                    if (hrs > 10) {
                        bill += (hrs - 10) * 2;
                    }
                    break;
        case 'B':   
                    bill = 14.95;
                    if (hrs > 20) {
                        bill += (hrs - 20);
                    }
                    break;
        case 'C':   
                    bill = 19.95;
                    break;
    }
    cout << fixed << setprecision(2) << showpoint;
    cout << "Bill = $" << setw(6) << bill;
    
    return;
}


void RPS() {
    char p1throw, p2throw;
    
    cout << "Rock Paper Scissors Game" << endl;
    cout << "Input Player 1 and Player 2 Choices" << endl;
    
    p1throw = getThrow();        
    p2throw = getThrow();

    switch (p1throw) 
    {
        case 'R':
            switch (p2throw)
            {
                case 'P':
                    cout << "Paper covers rock.";
                    break;
                case 'S':
                    cout << "Rock breaks scissors.";
                    break;
            }
            break;
            
        case 'P':
            switch (p2throw)
            {
                case 'R':
                    cout << "Paper covers rock.";
                    break;
                case 'S':
                    cout << "Scissors cuts paper.";
                    break;
            }
            break;
            
        case 'S':
            switch (p2throw)
            {
                case 'R':
                    cout << "Rock breaks scissors.";
                    break;
                case 'P':
                    cout << "Scissors cuts paper.";
                    break;
            }
            break;
            
        default:
            cout << "Nobody wins.";
    }
    
    return;
}


char getThrow() {
    char input;
    bool error = false;
    do {
        if (error == true) {
            cout << "User must input 'R', 'P', or 'S'" << endl;
        }
        cin >> input;
        input = static_cast<char>(toupper(input));
        error = true;
    }
    while (input != 'R' && input != 'P' && input != 'S');
    
    return input;
}


void romanConversion() {
    short   araYear;
    string  romYear;
    
    cout << "Arabic to Roman numeral conversion." << endl;
    cout << "Input the integer to convert." << endl;
    
    cin >> araYear;
    if (araYear < 1000 || araYear > 3000) {
        cout << araYear << " is Out of Range!";
        return;
    }
    
    cout << araYear << " is equal to ";
    
    while (araYear >= 1000) {
        romYear += "M";
        araYear -= 1000;
    }
    while (araYear >= 900) {
        romYear += "CM";
        araYear -= 900;
    }
    while (araYear >= 500) {
        romYear += "D";
        araYear -= 500;
    }
    while (araYear >= 400) {
        romYear += "CD";
        araYear -= 400;
    }
    while (araYear >= 100) {
        romYear += "C";
        araYear -= 100;
    }
    while (araYear >= 90) {
        romYear += "XC";
        araYear -= 90;
    }
    while (araYear >= 50) {
        romYear += "L";
        araYear -= 50;
    }
    while (araYear >= 40) {
        romYear += "XL";
        araYear -= 40;
    }
    while (araYear >= 10) {
        romYear += "X";
        araYear -= 10;
    }
    while (araYear >= 9) {
        romYear += "IX";
        araYear -= 9;
    }
    while (araYear >= 5) {
        romYear += "V";
        araYear -= 5;
    }
    while (araYear >= 4) {
        romYear += "IV";
        araYear -= 4;
    }
    while (araYear >= 1) {
        romYear += "I";
        araYear -= 1;
    }

    cout << romYear;
    
    return;
}


void compatibleSigns() {
    string  sign1, sign2, elem1, elem2;

    cout << "Horoscope Program which examines compatible signs." << endl;
    cout << "Input 2 signs." << endl;
    
    sign1 = getSign();
    sign2 = getSign();
    
    elem1 = getElem(sign1);
    elem2 = getElem(sign2);
    
    cout << sign1 << " and " << sign2 << " are ";
    if (elem1 != elem2) {
        cout << "not compatible signs.";
    }
    else {
        cout << "compatible " << elem1 << " signs.";
    }

    return;
}


string getSign() {
    string input;
    string signs[12] = {
        "Cancer", "Scorpio", "Pisces", "Aries", 
        "Leo", "Sagittarius", "Taurus", "Virgo", 
        "Capricorn", "Gemini", "Libra", "Aquarius" 
    };
    bool error = false;
    
    do {
        if (error == true) {
            cout << "User must input a valid horoscope sign." << endl;
        }
        cin >> input;
        error = true;
        
        input[0] = toupper(input[0]);
        for (short i = 1; i < sizeof(input)/sizeof(input[0]); i++) {
            input[i] = tolower(input[i]);
        }
        
        for (short i = 0; i < 12; i++) {
            if (signs[i] == input) {
                error = false;
                break;
            }
        }
    }
    while (error == true);
    
    return input;
}


string getElem(string sign) {
    string elem;
    if (sign == "Cancer" || sign == "Scorpio" || sign == "Pisces") {
        elem = "Water";
    }
    else if (sign == "Gemini" || sign == "Libra" || sign == "Aquarius") {
        elem = "Air";
    }
    else if (sign == "Taurus" || sign == "Virgo" || sign == "Capricorn") {
        elem = "Earth";
    }
    else if (sign == "Aries" || sign == "Leo" || sign == "Sagittarius") {
        elem = "Fire";
    }
    return elem;
}