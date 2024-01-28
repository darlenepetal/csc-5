/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 28, 2024, 11:04 AM
 * Purpose: Project1_Blackjack_V2
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const unsigned char N_CARDS = char(52);
const unsigned char N_DEAL  = char(9);

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    bool            crdUniq;
    unsigned char   crdFace, 
                    input;
    unsigned short  tempVal,
                    readVal;
    string          crdSuit,
                    crdStr1,
                    crdStr2,
                    crdStr3,
                    crdStr4,
                    crdStr5,
                    crdStr6,
                    crdStr7,
                    crdStr8,
                    crdStr9;
    fstream         outDeck,
                    outDeal,
                    inDeck,
                    inDeal;

    //Initialize or input i.e. set variable values
    outDeck.open("crdDeck.dat", ios::out);
    outDeal.open("crdDeal.dat", ios::out);

    
    //Map inputs -> outputs
    for (short i = 0; i < N_CARDS; i++) {
        // generate deck
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
        switch (i / 13) 
        {
            case 0:     crdSuit = "♤";
                        break;
            case 1:     crdSuit = "♧";
                        break;
            case 2:     crdSuit = "♡";
                        break;
            default:    crdSuit = "♢";
        }
        outDeck << crdFace << crdSuit << endl;
    }
    outDeck.close();
    
    /* in (this version of) blackjack, the player automatically
     * wins the hand if they are dealt 5 cards without busting.
     * this is called a "5-card charlie" and is controversial.
     * http://tinyurl.com/y6pv4mjz
     * 
     * this program simulates the rules of blackjack according
     * to the blackjack minigame found in the 2006 playstation 2
     * game "GOD HAND", a game i have played a lot.
     * http://tinyurl.com/ds4nyvvk
     * 
     * these are not casino rules by any means - but i find them
     * to be more fun because the player is slightly more at an
     * advantage than in a true game of casino blackjack.
     * 
     * these rules mean that the maximum number of cards that
     * can be used in one hand is 9, which would occur if the
     * player stands on 4 cards before the dealer wins with
     * a 5-card charlie.
     * 
     * this is why N_DEAL == 9, and the loop below generates
     * 9 unique cards to use during the current hand.
     * 
     * the player could cheat by reading crdDeal.dat as they
     * play, but if you're playing this game in an IDE like
     * my professor will, you could already cheat anyway
     */
    for (char i = char(0); i < N_DEAL; i++) {
        do {
            inDeal.open("crdDeal.dat", ios::in);
            tempVal = rand() % N_CARDS + 1;
            crdUniq = true;
            while (inDeal >> readVal) {     // this took me quite a
                if (tempVal == readVal) {   // while to get working
                    crdUniq = false;        // properly because i
                    break;                  // didn't realize that
                }                           // inDeal needs to be
            }                               // opened and closed
            inDeal.close();                 // each time it is read
        } while (crdUniq == false);         // ...and because i wrote
        outDeal << tempVal << endl;         // crdUniq == true instead
    }                                       // of crdUniq = true...

    //Display the outputs
    
    /*
     * found out that netbeans output support these cute unicode
     * symbols for the suits! i think i want the player to be able
     * to select which style they want (empty or filled)
     * maybe an option to use "S C H D" instead
     * of "♤ ♧ ♡ ♢"
     * Suit Variations:
     * A♠ A♤ 
     * A♣ A♧ 
     * A♥ A♡ 
     * A♦ A♢ 
     */
    

    //Exit stage right or left!
    return 0;
}