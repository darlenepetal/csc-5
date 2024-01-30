/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 29, 2024, 8:54 PM
 * Purpose: Project1_Blackjack_V6
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
    float           usrCash,
                    betAmnt;
    bool            validIn,
                    crdUniq,
                    hndOver,
                    usrWins,
                    usrStnd,
                    dblDown,
                    dlrShow;
    unsigned char   crdFace,
                    crdsDlt,
                    dlrCrds,
                    usrCrds,
                    dlrAces,
                    usrAces,
                    usrInpt;
    unsigned short  tempVal,
                    readVal,
                    dlrHand,
                    usrHand;
    string          tempStr,
                    crdSuit;
    fstream         outVals,
                    outStrs,
                    inVals,
                    inStrs;

    //Initialize or input i.e. set variable values
    usrCash = 1000.0f;
    
    while (true) {
        outVals.open("crdVals.dat", ios::out);
        outStrs.open("crdStrs.dat", ios::out);
        
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

        cout << " O-----------BLACKJACK----------O" << endl;
        cout << " |    DEALER MUST STAND ON 17   |" << endl;
        cout << " |     BLACKJACK PAYS 3 TO 1    |" << endl;
        cout << " |     FIVE CARD PAYS 5 TO 1    |" << endl;
        cout << " O-----------*˖°.+.°˖*----------O" << endl;

        cout << fixed << setprecision(2) << showpoint;
        cout << endl << "You have: $" << usrCash << endl;
        cout << "How much would you like to bet?" << endl << endl;
        cout << "Minimum bet is 50." << endl;
        cout << "Input a bet of 0 to walk away" << endl; 
        cout << "with your current cash." << endl << endl;

        do {
            cout << "Enter bet: ";
            cin >> betAmnt;
            cout << endl;

            if (betAmnt < 50.0f && betAmnt > 0) {
                validIn = false;
                cout << "Bet must be at least 50." << endl;
            }
            else if (betAmnt > usrCash) {
                validIn = false;
                cout << "You can't bet more than you have, wise guy." << endl;
            }
            else if (betAmnt < 0.0f) {
                validIn = false;
                cout << "You can't bet a negative amount. Nice try." << endl;
            }
            else {
                validIn = true;
                }
        } while (validIn == false);

        if (betAmnt == 0) {
            cout << "You walked away with $" << usrCash;
            (usrCash > 1000.0f) ? (cout << "!") : (cout << ".");
            cout << endl;
            return 0;
        }
        else usrCash -= betAmnt;

        usrCrds = dlrCrds = 2;
        dblDown = usrStnd = dlrShow = hndOver = false;

        do {
            usrHand = dlrHand = usrAces = dlrAces = 0;
            crdsDlt = usrCrds + dlrCrds;

            // calculate hand totals before cards are displayed
            // calculate totals separately to avoid excessive ace checks
            // calculate dealer total first
            inVals.open("crdVals.dat", ios::in);
            for (char curCard = char(1); curCard <= crdsDlt; curCard++) {
                inVals >> tempVal;
                if (curCard > 2 && curCard <= usrCrds+2) continue;

                tempVal = (tempVal-1)%13+1;
                if (tempVal > 10) tempVal = 10;
                else if (tempVal == 1) dlrAces++;
                
                
                if (dlrHand+11 >= 17 && dlrAces > 0) {
                    dlrHand += tempVal;
                }
                if (dlrHand <= 10 && dlrAces > 0) dlrHand += 11;
                else dlrHand += tempVal;
                
                while (dlrHand > 21 && dlrAces > 0) {
                    dlrHand -= 10;
                    dlrAces--;
                }
            }
            inVals.close();

            // calculate player total last
            inVals.open("crdVals.dat", ios::in);
            for (char curCard = char(1); curCard <= usrCrds+2; curCard++) {
                inVals >> tempVal;
                if (curCard <= 2) {
                    continue;
                }

                tempVal = (tempVal-1)%13+1;
                if (tempVal > 10) tempVal = 10;
                else if (tempVal == 1) usrAces++;

                if (usrHand+11 >= 17 && usrAces > 0) {
                    usrHand += tempVal;
                }
                else if (usrHand <= 10 && usrAces > 0) usrHand += 11;
                else usrHand += tempVal;
                
                while (usrHand > 21 && usrAces > 0) {
                    usrHand -= 10;
                    usrAces--;
                }
            }
            inVals.close();
            
            if (usrStnd || dblDown || usrHand>20) dlrShow = true;
            
            (dlrShow && dlrHand > usrHand)  ? hndOver = true :
            (dlrShow && dlrHand >= 17)      ? hndOver = true :
            (usrHand >= 22)                 ? hndOver = true :
            (dlrHand >= 22)                 ? hndOver = true :
            (usrCrds == 5)                  ? hndOver = true :
            (dlrCrds == 5)                  ? hndOver = true : hndOver = false;
            
            if (hndOver) dlrShow = true;

            // display dealer cards & total first
            inStrs.open("crdStrs.dat", ios::in);
            for (char curCard = char(1); curCard <= crdsDlt; curCard++) {
                inStrs >> tempStr;
                if (curCard == 1) {
                    cout << "Dealer: ";
                    if (dlrShow) (cout << dlrHand);
                    cout << endl << tempStr << " ";
                }
                else if (curCard == 2) {
                    cout << (dlrShow ? tempStr : "??") << " ";
                }
                else if (curCard <= usrCrds+2) {
                    continue;
                }
                else if (curCard <= crdsDlt) {
                    cout << tempStr << " ";
                }
            }
            inStrs.close();
            cout << endl << endl;

            // display player cards & total last
            inStrs.open("crdStrs.dat", ios::in);
            for (char curCard = char(1); curCard <= usrCrds+2; curCard++) {
                inStrs >> tempStr;
                if (curCard <= 2) {
                    continue;
                }
                else if (curCard == 3) {
                    cout << "Player: " << usrHand << endl << tempStr << " ";
                }
                else if (curCard <= usrCrds+2) {
                    cout << tempStr << " ";
                }
            }
            inStrs.close();
            cout << endl << endl;
            
            if (!usrStnd && !dblDown && !dlrShow && !hndOver) {
                cout <<     "Pot total: $" << betAmnt << endl;
                cout <<     "You have: $" << usrCash << endl << endl;
                cout <<     "What would you like to do?" << endl;
                cout <<     "Type S to Stand" << endl;
                cout <<     "Type H to Hit" << endl;
                if (usrCash >= betAmnt) {
                    cout << "Type D to Double Down" << endl;
                }
                
                do {
                    cout << "Enter decision: ";
                    cin >> usrInpt;
                    validIn = true;
                    
                    switch (usrInpt) 
                    {
                        case 's':   
                        case 'S':   usrStnd = true;
                                    break;
                        case 'h':   
                        case 'H':   usrCrds++;
                                    break;
                        case 'd':
                        case 'D':   if (usrCash < betAmnt) validIn = false;
                                    else {
                                        usrStnd = true;
                                        usrCrds++;
                                        usrCash -= betAmnt;
                                        betAmnt += betAmnt;
                                    }
                                    break;
                        default:    validIn = false;
                    }
                    
                    if (validIn == false) {
                        if (usrInpt == 'd' || usrInpt == 'D') {
                            cout << "You need to have at least" << endl;
                            cout << "$" << betAmnt << " to double down.";
                        }
                        else {
                            cout << "Invalid input.";
                        }
                        cout << endl << endl;
                    }
                    
                } while (validIn == false);
                cout << endl;
            }
            else if (!hndOver) {
                cout << "Enter any text to continue." << endl;
                cin >> tempStr;
                cout << endl;
            }
            
            if (dlrShow && !hndOver && dlrHand < 17) {
                cout << "DEALER HITS" << endl << endl;
                dlrCrds++;
            }
            
        } while (!hndOver);
        
        outVals.close();
        outStrs.close();
        
        if (usrHand > 21) {
            cout << "YOU BUST" << endl;
            cout << "DEALER WINS" << endl;
        }
        else if (dlrHand > 21) {
            cout << "DEALER BUSTS" << endl;
            cout << "YOU WIN!" << endl;
            usrCash += betAmnt*2;
        }
        else if (usrCrds == 5 || dlrCrds == 5) {
            cout << "FIVE CARDS" << endl;
            if (usrCrds == 5) {
                cout << "YOU WIN!" << endl;
                usrCash += betAmnt*6;
            }
            else {
                cout << "DEALER WINS" << endl;
            }
        }
        else if (usrHand == dlrHand) {
            if (dlrHand >= 17) {
                cout << "DEALER STANDS" << endl;
            }
            cout << "TIE" << endl;
            usrCash += betAmnt;
        }
        else if ((usrCrds==2 && usrHand==21) || (dlrHand==21 && dlrCrds==2)) {
            cout << "BLACKJACK" << endl;
            if (usrHand == 21 && usrCrds == 2) {
                cout << "YOU WIN!" << endl;
                usrCash += betAmnt*4;
            }
            else {
                cout << "DEALER WINS" << endl;
            }
        }
        else {
            cout << "DEALER STANDS" << endl;
            if (usrHand > dlrHand) {
                cout << "YOU WIN!" << endl;
                usrCash += betAmnt*2;
            }
            else {
                cout << "DEALER WINS" << endl;
            }
        }
        cout << endl;
        
        if (usrCash == 0) {
            cout << "You ran out of money and were" << endl;
            cout << "kicked out of the casino." << endl;
            cout << "GAME OVER" << endl;
            return 0;
        }
        cout << endl;
    }
    
    return 0;
}
