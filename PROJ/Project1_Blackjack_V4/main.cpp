/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 29, 2024, 9:59 AM
 * Purpose: Project1_Blackjack_V4
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
const unsigned char N_DECK = char(52);
const unsigned char N_DEAL = char(9);

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    bool            crdUniq,
                    usrDone,
                    dHasAce,
                    uHasAce;
    unsigned char   crdFace,
                    crdsDlt,
                    dlrCrds,
                    usrCrds,
                    usrInpt;
    unsigned short  tempVal,
                    readVal,
                    dlrHand,
                    usrHand;
    float           usrCash;
    string          tempStr,
                    crdSuit;
    fstream         outVals,
                    outStrs,
                    inVals,
                    inStrs;

    //Initialize or input i.e. set variable values
    outVals.open("crdVals.dat", ios::out);
    outStrs.open("crdStrs.dat", ios::out);
    usrCash = 1000.00f;
    
    //Map inputs -> outputs
    
    
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
     * the player could cheat by reading crdStrs.dat as they
     * play, but if you're playing this game in an IDE like
     * my professor will, you could already cheat anyway
     */
    for (char i = char(0); i < N_DEAL; i++) {
        do {
            inVals.open("crdVals.dat", ios::in);
            tempVal = rand() % N_DECK + 1;
            crdUniq = true;
            while (inVals >> readVal && crdUniq == true) {     
                if (tempVal == readVal) crdUniq = false;                               
            }                               
            inVals.close();                 
        } while (crdUniq == false);  
        outVals << tempVal << endl;

        switch ((tempVal-1) % 13)
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
        switch ((tempVal-1) / 13) 
        {
            case 0:     crdSuit = "♤";
                        break;
            case 1:     crdSuit = "♧";
                        break;
            case 2:     crdSuit = "♡";
                        break;
            default:    crdSuit = "♢";
        }
        outStrs << crdFace << crdSuit << endl;
    }                                       
    
    cout << fixed << setprecision(2) << showpoint;
    cout << " ♦ ♥ ♣ ♠ BLACKJACK ♠ ♣ ♥ ♦ " << endl;
    cout << "      DEALER MUST STAND ON 17" << endl;
    cout << "       BLACKJACK PAYS 3 TO 1" << endl << endl;
    
    usrCrds = 1;
    dlrCrds = 2;
    crdsDlt = 3;
    usrDone = true;
    
    do {
        usrHand = dlrHand = 0;
        dHasAce = uHasAce = false;
        
        // calculate hand totals before cards are displayed
        // calculate totals separately to avoid excessive ace checks
        inVals.open("crdVals.dat", ios::in);
        for (char curCard = char(1); curCard <= crdsDlt; curCard++) {
            inVals >> tempVal;
            
            if (curCard > 2 && curCard <= usrCrds+2) continue;
            
            tempVal %= 13;
            if (tempVal > 10) tempVal = 10;
            else if (tempVal == 1) dHasAce = true;
            
            dlrHand += tempVal;
            if (dlrHand <= 11 && dHasAce) dlrHand += 10;
            
        }
        
        // display dealer cards & total first
        inStrs.open("crdStrs.dat", ios::in);
        for (char curCard = char(1); curCard <= crdsDlt; curCard++) {
            inStrs >> tempStr;
            if (curCard == 1) {
                cout << "Dealer: ";
                if (usrDone) (cout << dlrHand);
                cout << endl << tempStr << " ";
            }
            else if (curCard == 2) {
                cout << (usrDone ? tempStr : "??") << endl << endl;
            }
            else if (curCard <= usrCrds+2) {
                continue;
            }
            else if (curCard != crdsDlt) {
                cout << tempStr << " ";
            }
            else {
                cout << endl << endl;
            }
        }
        inStrs.close();
        
        // display player cards & total last
        inStrs.open("crdStrs.dat", ios::in);
        for (char curCard = char(1); curCard <= crdsDlt-usrCrds+2; curCard++) {
            inStrs >> tempStr;
            if (curCard <= 2) {
                continue;
            }
            else if (curCard == 3) {
                cout << "Player: " << usrHand << endl << tempStr << " ";
            }
            else if (curCard < usrCrds+2) {
                cout << tempStr << " ";
            }
            else {
                cout << endl << endl;
            }
        }
        inStrs.close();
        inVals.close();
        
        cout << "You have: $" << usrCash << endl;
    } while (crdsDlt < N_DEAL && crdsDlt < usrCrds+dlrCrds);
    
    
    
    
    
    
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
