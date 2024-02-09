/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 27, 2024, 5:04 PM
 * Purpose: Project1_Blackjack_V1
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const unsigned char N_CARDS = 52;

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    char    crdFace;
    string  crdSuit;
    fstream outFile;

    //Initialize or input i.e. set variable values
    outFile.open("crdDeck.dat", ios::out);
    
    //Map inputs -> outputs
    for (short i = 0; i < N_CARDS; i++) {
        
        switch (i % 13)
        {
            case 0:     crdFace = 'A';
                        break;
            case 1:     crdFace = '2';
                        break;
            case 2:     crdFace = '3';
                        break;
            case 3:     crdFace = '4';
                        break;
            case 4:     crdFace = '5';
                        break;
            case 5:     crdFace = '6';
                        break;
            case 6:     crdFace = '7';
                        break;
            case 7:     crdFace = '8';
                        break;
            case 8:     crdFace = '9';
                        break;
            case 9:     crdFace = 'T';
                        break;
            case 10:    crdFace = 'J';
                        break;
            case 11:    crdFace = 'Q';
                        break;
            default:    crdFace = 'K';
        }
        switch (i / 13) {
            case 0:     crdSuit = "♠";
                        break;
            case 1:     crdSuit = "♣";
                        break;
            case 2:     crdSuit = "♥";
                        break;
            default:    crdSuit = "♦";
        }
        
    }

    //Display the outputs
    
    /*
     * found out that netbeans output support these cute unicode
     * symbols for the suits! i think i want the player to be able
     * to select which style they want (empty or filled)
     * maybe an option to use "S C H D" instead
     * of "♤ ♧ ♡ ♢"
     */
    cout << "A♠" << endl << "A♤" << endl;
    cout << "A♣" << endl << "A♧" << endl;
    cout << "A♥" << endl << "A♡" << endl;
    cout << "A♦" << endl << "A♢" << endl;

    //Exit stage right or left!
    return 0;
}