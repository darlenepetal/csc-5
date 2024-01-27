/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Noah Garthwaite
 * Created on January 12, 2024, 4:15 PM
 * Purpose: Gaddis_9thEd_Chap4_Prob11_Books
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    unsigned short books, points;

    //Initialize or input i.e. set variable values
    cout << "Book Worm Points" << endl;
    cout << "Input the number of books purchased this month." << endl;
    cin >> books;
    
    //Map inputs -> outputs
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
    //Display the outputs
    cout << "Books purchased =" << setw(3) << books << endl;
    cout << "Points earned   =" << setw(3) << points;
    //Exit stage right or left!
    return 0;
}