/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 14, 2024, 7:19 PM
 * Purpose: Savitch_9thEd_Chap3_PracProb1_RockPaperScissors
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
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

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    char p1throw, p2throw;
    
    //Initialize or input i.e. set variable values
    cout << "Rock Paper Scissors Game" << endl;
    cout << "Input Player 1 and Player 2 Choices" << endl;
    
    p1throw = getThrow();        
    p2throw = getThrow();
    //Map inputs -> outputs

    //Display the outputs
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
    //Exit stage right or left!
    return 0;
}